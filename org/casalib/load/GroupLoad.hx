/*	CASA Lib for ActionScript 3.0	Copyright (c) 2010, Aaron Clinger & Contributors of CASA Lib	All rights reserved.		Redistribution and use in source and binary forms, with or without	modification, are permitted provided that the following conditions are met:		- Redistributions of source code must retain the above copyright notice,	  this list of conditions and the following disclaimer.		- Redistributions in binary form must reproduce the above copyright notice,	  this list of conditions and the following disclaimer in the documentation	  and/or other materials provided with the distribution.		- Neither the name of the CASA Lib nor the names of its contributors	  may be used to endorse or promote products derived from this software	  without specific prior written permission.		THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"	AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE	IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE	ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE	LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR	CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF	SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS	INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN	CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)	ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE	POSSIBILITY OF SUCH DAMAGE.*/package org.casalib.load;
	import flash.events.IOErrorEvent;
	import flash.net.URLRequest;
	import org.casalib.errors.ArguementTypeError;	import org.casalib.events.LoadEvent;	import org.casalib.events.ProcessEvent;	import org.casalib.math.Percent;	import org.casalib.process.Process;	import org.casalib.process.ProcessGroup;	import org.casalib.util.ArrayUtil;
	import org.casalib.util.StringUtil;	import org.casalib.load.LoadItem;	
	/*[Event(name="ioError", type="flash.events.IOErrorEvent")]*/	/*[Event(name="complete", type="org.casalib.events.LoadEvent")]*/	/*[Event(name="progress", type="org.casalib.events.LoadEvent")]*/		/**		Allows multiple loads to be grouped and treated as one larger load.				@author Aaron Clinger		@version 03/26/10		@example			<code>				package {
					import flash.events.IOErrorEvent;					import org.casalib.display.CasaMovieClip;					import org.casalib.events.LoadEvent;					import org.casalib.load.GroupLoad;					import org.casalib.load.ImageLoad;															public class MyExample extends CasaMovieClip {						protected var _groupLoad:GroupLoad;						protected var _imageOne:ImageLoad;						protected var _imageTwo:ImageLoad;						protected var _imageThree:ImageLoad;						protected var _imageFour:ImageLoad;																		public function MyExample() {							super();														this._imageOne   = new ImageLoad("test1.jpg");							this._imageTwo   = new ImageLoad("test2.jpg");							this._imageThree = new ImageLoad("test3.jpg");							this._imageFour  = new ImageLoad("test4.jpg");														this._imageTwo.loader.x   = 10;							this._imageThree.loader.x = 20;							this._imageFour.loader.x  = 30;														this.addChild(this._imageOne.loader);							this.addChild(this._imageTwo.loader);							this.addChild(this._imageThree.loader);							this.addChild(this._imageFour.loader);														this._groupLoad = new GroupLoad();							this._groupLoad.addLoad(this._imageOne);							this._groupLoad.addLoad(this._imageTwo);							this._groupLoad.addLoad(this._imageThree);							this._groupLoad.addLoad(this._imageFour);
							this._groupLoad.addEventListener(IOErrorEvent.IO_ERROR, this._onError);							this._groupLoad.addEventListener(LoadEvent.PROGRESS, this._onProgress);							this._groupLoad.addEventListener(LoadEvent.COMPLETE, this._onComplete);							this._groupLoad.start();						}
						
						protected function _onError(e:IOErrorEvent):void {
							trace("There was an error");
							this._groupLoad.removeLoad(this._groupLoad.erroredLoads[0]);
						}												protected function _onProgress(e:LoadEvent):void {							trace("Group is " + e.progress.percentage + "% loaded at " + e.Bps + "Bps.");						}												protected function _onComplete(e:LoadEvent):void {							trace("Group has loaded.");						}					}				}			</code>	*/	class GroupLoad extends ProcessGroup {
		private static var _instanceMap:Hash<GroupLoad>;
		public var id(getId, null): String;		public var Bps(getBps, null) : Int;		public var completedLoads(getCompletedLoads, null) : Array<LoadItem>;		public var incompletedLoads(getIncompletedLoads, null) : Array<LoadItem>;		public var loaded(getLoaded, null) : Bool;		public var loading(getLoading, null) : Bool;		public var loadingLoads(getLoadingLoads, null) : Array<LoadItem>;		public var loads(getLoads, null) : Array<LoadItem>;		public var preventCache(getPreventCache, setPreventCache) : Bool;		public var progress(getProgress, null) : Percent;		public var queuedLoads(getQueuedLoads, null) : Array<LoadItem>;
		public var erroredLoads(getErroredLoads, null) : Array<LoadItem>;
		public var loadingAndCompletedLoads(getLoadingAndCompletedLoads, null) : Array<LoadItem>;
		public var errored(getErrored, null):Bool;
		public var bytesLoaded(getBytesLoaded, null):Float;
		public var bytesTotal(getBytesTotal, null):Float;		var _preventCacheSet:Bool;		var _preventCache:Bool;		var _progress:Percent;		var _Bps:Int;		var _percentMap:IntHash<Percent>;
		var _id:String;
		
		/**
			Returns an instance of GroupLoad.
			
			@param id: The unique identifier for the GroupLoad instance.
			@return A previously created instance of GroupLoad or <code>null</code> if no instance with that identifier exists.
		*/
		public static function getGroupLoadById(id:String):GroupLoad {
			if (GroupLoad._instanceMap == null)
				return null;
			
			return GroupLoad._instanceMap.get(id);
		}
		
		/**
			Returns the instance of GroupLoad which contains a specific file.
			
			@param request: A <code>String</code> or an <code>URLRequest</code> reference to the file.
			@return The instance of GroupLoad which contains a specific file.
			@throws ArguementTypeError if you pass a type other than a <code>String</code> or an <code>URLRequest</code> to parameter <code>request</code>.
		*/
		public static function getGroupLoadByAsset(request:Dynamic):GroupLoad {
			if (GroupLoad._instanceMap != null)
				for (group in GroupLoad._instanceMap)
					if (group.hasAsset(request, false))
						return group;
			
			return null;
		}						/**			Creates a new GroupLoad.
			
			@param id: The optional unique identifier for the instance of GroupLoad.
			@throws Error if the identifier provided is not unique or <code>null</code>.		*/		public function new(id:String = null) {			super();			
			if (id != null && GroupLoad.getGroupLoadById(id) != null)
				throw 'The identifier provided is not unique.';
				
			if (id==null) {
				do {
					this._id = StringUtil.uuid();
				} while (GroupLoad.getGroupLoadById(_id) != null);
			} else {
				this._id = id;
			}			this._percentMap = new IntHash<Percent>();			this._progress   = new Percent();
			
			if (GroupLoad._instanceMap == null) GroupLoad._instanceMap = new Hash<GroupLoad>();
			GroupLoad._instanceMap.set(id, this);		}				/**			Add a load to the group.
			
			@param load: Load to be added to the group. Can be any class that extends from {@link LoadItem} or another <code>GroupLoad</code> instance.
			@param percentOfGroup: Defines the percentage of the total group the size of the load item represents; defaults to equal increments.
			@throws ArguementTypeError if you pass a type other than a <code>LoadItem</code> or a <code>GroupLoad</code> to parameter <code>load</code>.
			@throws Error if you try to add the same <code>GroupLoad</code> to itself.		*/		public function addLoad(load:Dynamic, ?percentOfGroup:Percent = null):Void {
			if (!Std.is(load, LoadItem) && !Std.is(load, GroupLoad))
				throw new ArguementTypeError('load');
			
			if (load == this)
				throw 'You cannot add the same GroupLoad to itself.';
					super.addProcess(load);						if (this._preventCacheSet)				load.preventCache = this.preventCache;						this._percentMap.set(load.id, (percentOfGroup == null || percentOfGroup.decimalPercentage == 0) ? new Percent(0.01) : percentOfGroup.clone());						if (this.autoStart && !this.completed && this.running)				this._checkTotalPercentValidity();		}				/**			Removes a load item from the group.						@param load: Load to be removed from the group. Can be any class that extends from {@link LoadItem} or another <code>GroupLoad</code> instance.
			@throws ArguementTypeError if you pass a type other than a <code>LoadItem</code> or a <code>GroupLoad</code> to parameter <code>load</code>.		*/		public function removeLoad(load:Dynamic):Void {
			if (!Std.is(load, LoadItem) && !Std.is(load, GroupLoad))
				throw new ArguementTypeError('load');
						this._percentMap.remove(load.id);						super.removeProcess(load);
			
			if (this.running)
				this._checkTotalPercentValidity();		}				/**			Determines if this GroupLoad contains a specific load item.
			
			@param load: The load item to search for. Can be any class that extends from {@link LoadItem} or another <code>GroupLoad</code> instance.
			@param recursive: If any child of this GroupLoad is also a GroupLoad search its children <code>true</code>, or only search this GroupLoad's children <code>false</code>.
			@return Returns <code>true</code> if the GroupLoad contains the load item; otherwise <code>false</code>.
			@throws ArguementTypeError if you pass a type other than a <code>LoadItem</code> or a <code>GroupLoad</code> to parameter <code>load</code>.		*/		public function hasLoad(load:Dynamic, recursive:Bool = true):Bool {
			if (!Std.is(load, LoadItem) && !Std.is(load, GroupLoad))
				throw new ArguementTypeError('load');
			
			return this.hasProcess(load, recursive);
		}
		
		/**
			Gets a load item from this GroupLoad, or a child GroupLoad, by its request.
			
			@param request: A <code>String</code> or an <code>URLRequest</code> reference to the file.
			@return The requested LoadItem instance.
			@throws ArguementTypeError if you pass a type other than a <code>String</code> or an <code>URLRequest</code> to parameter <code>request</code>.
		*/
		public function getLoad(request:Dynamic):LoadItem {
			var url:String = this._getFileUrl(request);
			var items = this.loads;
			var l = items.length;
			var i;
			
			while (l-- > 0) {
				i = items[l];
				
				if (Std.is(i,GroupLoad)) {
					i = cast(i,GroupLoad).getLoad(request);
					
					if (i != null)
						return i;
				} else
					if (i.url == url)
						return i;
			}
			
			return null;
		}
		
		/**
			Determines if this instance of GroupLoad contains a specific file.
			
			@param request: A <code>String</code> or an <code>URLRequest</code> reference to the file.
			@param recursive: If any child of this GroupLoad is also a GroupLoad search its children <code>true</code>, or only search this GroupLoad's children <code>false</code>.
			@return Returns <code>true</code> if this instance contains the file; otherwise <code>false</code>.
			@throws ArguementTypeError if you pass a type other than a <code>String</code> or an <code>URLRequest</code> to parameter <code>request</code>.
		*/
		public function hasAsset(request:Dynamic, recursive:Bool = true):Bool {
			var url:String = this._getFileUrl(request);
			
			if (!recursive)
				return ArrayUtil.getItemByKey(this.loads, 'url', url) != null;
			
			var items = this.loads;
			var l = items.length;
			var i;
			
			while (l-- > 0) {
				i = cast items[l];
				
				if (Std.is(i,GroupLoad)) {
					if (cast(i,GroupLoad).hasAsset(request, true))
						return true;
				} else {
					if (i.url == url)
						return true;
				}
			}
			
			return false;
		}
		
		/**
			The identifier name for this instance of GroupLoad, if specified.
		*/
		private function getId():String {
			return this._id;
		}				/**			The loads that compose the group.		*/		private function getLoads():Array<LoadItem> {			return cast this.processes;		}				/**			The loads that are neither complete nor loading.		*/		private function getQueuedLoads():Array<LoadItem> {			return cast this.queuedProcesses;		}				/**			The loads that are currently loading.		*/		private function getLoadingLoads():Array<LoadItem> {			return cast this.runningProcesses;		}				/**			The loads that have not completed.		*/		private function getIncompletedLoads():Array<LoadItem> {			return cast this.incompletedProcesses;		}
		
		/**
			The loads that could not complete because of an error.
		*/
		private function getErroredLoads():Array<LoadItem> {
			return cast ArrayUtil.getItemsByKey(this.processes, 'errored', true);
		}
		
		/**
			The loads that are either currently loading or that have completed.
		*/
		private function getLoadingAndCompletedLoads():Array<LoadItem> {
			return this.loadingLoads.concat(this.completedLoads);
		}				/**			The loads that have completed.		*/		private function getCompletedLoads():Array<LoadItem> {			return cast this.completedProcesses;		}				/**			Specifies if a random value name/value pair should be appended to every load in GroupLoad <code>true</code>, or not append <code>false</code>; defaults to <code>false</code>.						@see LoadItem#preventCache		*/		private function getPreventCache():Bool{			return this._preventCache;		}				private function setPreventCache(cache:Bool):Bool{			this._preventCacheSet = true;			this._preventCache    = cache;						var items:Array<LoadItem> = this.loads;			var l = items.length;						while (l-- > 0)				items[l].preventCache = this.preventCache;			return cache;		}				/**			The percent that the group is loaded.		*/		private function getProgress():Percent {			return this._progress.clone();		}				/**			Determines if the group is loading <code>true</code>, or if it isn't currently loading <code>false</code>.		*/		private function getLoading():Bool {			return this.running;		}				/**			Determines if all loads in the group are loaded <code>true</code>, or if the group hasn't finished loading <code>false</code>.		*/		private function getLoaded():Bool {			return this.completed;		}
		
		/**
			Determines if the GroupLoad could not complete because of an error <code>true</code>, or hasn't encountered an error <code>false</code>.
		*/
		public function getErrored():Bool {
			return this.erroredLoads.length > 0;
		}				/**			The current download speed of the group in bytes per second.		*/		private function getBps():Int {			return this._Bps;		}
		
		/**	
			The number of bytes loaded.
		*/
		public function getBytesLoaded():Float {
			return ArrayUtil.sum(ArrayUtil.getValuesByKey(this.loadingAndCompletedLoads, 'bytesLoaded'));
		}
		
		/**
			The total number of bytes that will be loaded if the loading process succeeds.
			
			@usageNote Will return <code>Infinity</code> until all loads in group have started loading.
		*/
		public function getBytesTotal():Float {
			var total = this.loads.length;
			var l = this.loadingAndCompletedLoads;
			
			if (total == l.length && total != 0)
				return ArrayUtil.sum(ArrayUtil.getValuesByKey(l, 'bytesTotal'));
			
			return Math.POSITIVE_INFINITY;
		}				/**			@exclude		*/		public override function start():Void {			this._checkTotalPercentValidity();						super.start();		}				/**			@exclude		*/		public override function addProcess(process:Process):Void {			this.addLoad(process);		}				/**			@exclude		*/		public override function removeProcess(process:Process):Void {			if (Std.is( process, LoadItem) || Std.is(process, GroupLoad))				this.removeLoad(process);		}				/**			@exclude		*/		override public function destroyProcesses(recursive:Bool = true):Void {
			this._percentMap = new IntHash<Percent>();
			
			super.destroyProcesses(recursive);
		}				/**
			Calls <code>destroy</code> on all loads in the group and removes them from the GroupLoad.
			
			@param recursive: If any child of this GroupLoad is also a GroupLoad destroy its children <code>true</code>, or only destroy this GroupLoad's children <code>false</code>.
		*/
		public function destroyLoads(recursive:Bool = true):Void {
			this.destroyProcesses(recursive);
		}				public override function destroy():Void {			this._percentMap = null;			this._progress   = null;			this._Bps        = -1;
			
			GroupLoad._instanceMap.remove(id);						super.destroy();		}				function _checkTotalPercentValidity():Void {			var perTotal:Int = 0;						for (i in this._percentMap)				perTotal += Std.int(i.decimalPercentage);						if (perTotal != 1) {
				for (i in this._percentMap.keys()){
					this._percentMap.get(i).decimalPercentage = this._percentMap.get(i).decimalPercentage / perTotal;
				}
			}		}				override function _addProcessListeners(process:Process):Void {			process.addEventListener(LoadEvent.PROGRESS, this._onProgress, false, 0, true);			process.addEventListener(ProcessEvent.STOP, this._onProcessStopped, false, 0, true);
			process.addEventListener(IOErrorEvent.IO_ERROR, this._onLoadError, false, 0, true);			process.addEventListener(LoadEvent.COMPLETE, this._onLoadCompleted, false, 0, true);		}				override function _removeProcessListeners(process:Process):Void {			process.removeEventListener(LoadEvent.PROGRESS, this._onProgress);			process.removeEventListener(ProcessEvent.STOP, this._onProcessStopped);
			process.removeEventListener(IOErrorEvent.IO_ERROR, this._onLoadError);			process.removeEventListener(LoadEvent.COMPLETE, this._onLoadCompleted);		}				/**			@sends LoadEvent#PROGRESS - Dispatched as the loads in the group are downloading.		*/		function _onProgress(e:LoadEvent):Void {			var speed:Array<Int>     = new Array<Int>();			var perTotal:Int         = 0;			var p:Array<Process>     = this.processes;			var l:UInt               = p.length;			var load:Dynamic;						while (l-- > 0) {				load = p[l];								if (load.loading) {					speed.push(load.Bps);					perTotal += Std.int(this._percentMap.get(load.id).decimalPercentage * load.progress.decimalPercentage);				} else if (load.loaded) {					speed.push(load.Bps);					perTotal += Std.int(this._percentMap.get(load.id).decimalPercentage);				}			}						this._Bps      = Std.int(ArrayUtil.average(speed));			
			if (this._Bps != Bps || this._progress.decimalPercentage != perTotal) {
				this._Bps                        = Bps;
				this._progress.decimalPercentage = perTotal;
			}						this.dispatchEvent(this._createDefinedLoadEvent(LoadEvent.PROGRESS));		}
		
		/**
			@sends IOErrorEvent#IO_ERROR - Dispatched if a requested load cannot be loaded and the download terminates.
		*/
		private function _onLoadError(e:IOErrorEvent):Void {
			this.dispatchEvent(e);
			
			this._checkThreads();
		}				function _onLoadCompleted(e:LoadEvent):Void {			this._checkThreads();		}				/**			@sends LoadEvent#COMPLETE - When GroupLoad has completed loading all the loads in the group.		*/		override function _complete():Void {
			if (this.erroredLoads.length > 0)
				return;
					super._complete();						if (this._progress.decimalPercentage != 1) {
				this._progress.decimalPercentage = 1;
				this.dispatchEvent(this._createDefinedLoadEvent(LoadEvent.PROGRESS));
			}						this.dispatchEvent(this._createDefinedLoadEvent(LoadEvent.COMPLETE));		}
		
		private function _getFileUrl(request:Dynamic):String {
			var url:String;
			
			if (Std.is(request, String))
				url = request;
			else if (Std.is(request, URLRequest))
				url = request.url;
			else
				throw new ArguementTypeError('request');
			
			return url;
		}				function _createDefinedLoadEvent(type:String):LoadEvent {			var loadEvent:LoadEvent = new LoadEvent(type);			loadEvent.bytesLoaded   = this.bytesLoaded;			loadEvent.bytesTotal    = this.bytesTotal;			loadEvent.progress      = this.progress;			loadEvent.Bps           = this.Bps;						return loadEvent;		}	}
