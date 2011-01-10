/*
	CASA Lib for ActionScript 3.0
	Copyright (c) 2010, Aaron Clinger & Contributors of CASA Lib
	All rights reserved.
	
	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:
	
	- Redistributions of source code must retain the above copyright notice,
	  this list of conditions and the following disclaimer.
	
	- Redistributions in binary form must reproduce the above copyright notice,
	  this list of conditions and the following disclaimer in the documentation
	  and/or other materials provided with the distribution.
	
	- Neither the name of the CASA Lib nor the names of its contributors
	  may be used to endorse or promote products derived from this software
	  without specific prior written permission.
	
	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
	AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
	LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
	CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
	SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
	INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
	CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
	ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
	POSSIBILITY OF SUCH DAMAGE.
*/
package org.casalib.load; 
	//import flash.errors.IOError;
	import flash.events.Event;
	#if flash 
	import flash.events.HTTPStatusEvent; 
	import flash.events.ProgressEvent;
	#end
	import flash.events.IEventDispatcher;
	import flash.events.IOErrorEvent;
	import flash.net.URLRequest;
	import haxe.Timer;
	import org.casalib.core.UInt;
	import org.casalib.errors.ArguementTypeError;
	import org.casalib.events.LoadEvent;
	import org.casalib.events.RetryEvent;
	import org.casalib.math.Percent;
	import org.casalib.process.Process;
	import org.casalib.util.LoadUtil;
	import org.casalib.util.StringUtil;
	
	
	/*[Event(name="complete", type="org.casalib.events.LoadEvent")]*/
	/*[Event(name="ioError", type="flash.events.IOErrorEvent")]*/
	/*[Event(name="open", type="flash.events.Event")]*/
	/*[Event(name="progress", type="org.casalib.events.LoadEvent")]*/
	/*[Event(name="retry", type="org.casalib.events.RetryEvent")]*/
	/*[Event(name="start", type="org.casalib.events.LoadEvent")]*/
	/*[Event(name="stop", type="org.casalib.events.LoadEvent")]*/
	
	/**
		Base class used by load classes. LoadItem is not designed to be used on its own and needs to be extended to function.
		
		@author Aaron Clinger
		@version 02/13/10
	*/
	class LoadItem extends Process {
		static private var nextId:Int = 0;
		public var id(default,null):Int;
		
		public var errored(getErrored,null):Bool;
		public var Bps(getBps, null) : Int ;
		public var attempts(getAttempts, null) : UInt ;
		public var bytesLoaded(getBytesLoaded, null) : Float ;
		public var bytesTotal(getBytesTotal, null) : Float ;
		public var httpStatus(getHttpStatus, null) : UInt ;
		public var latency(getLatency, null) : UInt ;
		public var loaded(getLoaded, null) : Bool ;
		public var loading(getLoading, null) : Bool ;
		public var preventCache(getPreventCache, setPreventCache) : Bool;
		public var progress(getProgress, null) : Percent ;
		public var retries(getRetries, setRetries) : UInt;
		public var time(getTime, null) : Float ;
		public var url(getUrl, null) : String ;
		public var urlRequest(getUrlRequest, null) : URLRequest ;
		var _attempts:UInt;
		var _loaded:Bool;
		var _errrored:Bool;
		var _preventCache:Bool;
		var _retries:UInt;
		var _dispatcher:IEventDispatcher;
		var _Bps:Int;
		var _time:Float;
		var _latency:UInt;
		var _httpStatus:UInt;
		var _loadItem:Dynamic;
		var _progress:Percent;
		var _request:URLRequest;
		var _startTime:Float;
		var _url:String;
		
		
		/**
			Defines the load object and file location.
			
			@param load: The load object.
			@param request: A <code>String</code> or an <code>URLRequest</code> reference to the file you wish to load.
			@throws ArguementTypeError if you pass a type other than a <code>String</code> or an <code>URLRequest</code> to parameter <code>request</code>.
			@throws Error if you try to load an empty <code>String</code> or <code>URLRequest</code>.
		*/
		public function new(load:Dynamic, request:Dynamic) {
			super();
			
			this._createRequest(request);
			
			this._loadItem = load;
			this._retries  = 2;
			this._Bps      = -1;
			this._progress = new Percent();
			
			id = nextId++;
		}
		
		/**
			Begins the loading process.
			
			@sends LoadEvent#START - Dispatched when a load is started.
		*/
		public override function start():Void {
			if (this.loading)
				return;
			
			super.start();
			
			this._loaded    = false;
			this._errrored = false;
			this._startTime = Timer.stamp()*1000;
			this._attempts  = 0;
			this._progress  = new Percent();
			this._Bps       = -1;
			this._time      = 0;
			
			if (this._preventCache) {
				var cache:String = 'casaCache=' + Std.int(1000 * Math.random());
				#if flash
				this._request.url = (this._request.url.indexOf('?') == -1) ? this._request.url + '?' + cache : this._request.url + '&' + cache;
				#end
			}
			
			this._load();
			
			this.dispatchEvent(this._createDefinedLoadEvent(LoadEvent.START));
		}
		
		/**
			Cancels the currently loading file from completing.
			
			@sends LoadEvent#STOP - Dispatched if the load is stopped during the loading process.
		*/
		public override function stop():Void {
			if (!this.loading || this.loaded)
				return;
			
			if (this.bytesTotal == this.bytesLoaded && this.bytesLoaded > 0)
				return;
			
			super.stop();
			
			try{
				this._loadItem.close();
			} catch (error:Dynamic) {}
			
			this.dispatchEvent(this._createDefinedLoadEvent(LoadEvent.STOP));
		}
		
		/**
			Specifies if a random value name/value pair should be appended to the query string to help prevent caching <code>true</code>, or not append <code>false</code>; defaults to <code>false</code>.
		*/
		private function getPreventCache():Bool{
			return this._preventCache;
		}
		
		private function setPreventCache(cache:Bool):Bool{
			this._preventCache = cache;
			return cache;
		}
		
		/**
			The total number of bytes of the requested file.
		*/
		private function getBytesTotal():Float {
			return (this._loadItem.bytesTotal == 0 && this.bytesLoaded != 0) ? Math.POSITIVE_INFINITY : this._loadItem.bytesTotal;
		}
		
		/**
			The number of bytes loaded of the requested file.
		*/
		private function getBytesLoaded():UInt {
			return this._loadItem.bytesLoaded;
		}
		
		/**
			The percent that the requested file has loaded.
		*/
		private function getProgress():Percent {
			return this._progress.clone();
		}
		
		/**
			The number of additional times the file has attempted to load after {@link #start start} was called.
		*/
		private function getAttempts():UInt {
			return this._attempts;
		}
		
		/**
			The number of additional load retries the class should attempt before failing; defaults to <code>2</code> additional retries / <code>3</code> total load attempts.
		*/
		private function getRetries():UInt{
			return this._retries;
		}
		
		private function setRetries(amount:UInt):UInt{
			this._retries = amount;
			return amount;
		}
		
		/**
			The URLRequest reference to the requested file.
		*/
		private function getUrlRequest():URLRequest {
			return this._request;
		}
		
		/**
			The URL of the requested file.
		*/
		private function getUrl():String {
			return this._url;
		}
		
		/**
			Determines if the requested file is loading <code>true</code>, or if it isn't currently loading <code>false</code>.
		*/
		private function getLoading():Bool {
			return this.running;
		}
		
		/**
			Determines if the requested file has loaded <code>true</code>, or hasn't finished loading <code>false</code>.
		*/
		private function getLoaded():Bool {
			return this._loaded;
		}
		
		/**
			Determines if the requested file could not complete because of an error <code>true</code>, or hasn't encountered an error <code>false</code>.
		*/
		private function getErrored():Bool {
			return this._errrored;
		}
		
		/**
			The current download speed of the requested file in bytes per second.
		*/
		private function getBps():Int {
			return this._Bps;
		}
		
		/**
			The current time duration in milliseconds the load has taken.
		*/
		private function getTime():Float {
			return this._time;
		}
		
		/**
			The time in milliseconds that the server took to respond.
		*/
		private function getLatency():UInt {
			return this._latency;
		}
		
		/**
			The HTTP status code returned by the server; or <code>0</code> if no status has/can been received or the load is a stream.
		*/
		private function getHttpStatus():UInt {
			return this._httpStatus;
		}
		
		public override function destroy():Void {
			this._dispatcher.removeEventListener(Event.COMPLETE, this._onComplete);
			this._dispatcher.removeEventListener(Event.OPEN, this._onOpen);
			this._dispatcher.removeEventListener(IOErrorEvent.IO_ERROR, this._onLoadError);
			#if flash
			this._dispatcher.removeEventListener(ProgressEvent.PROGRESS, this._onProgress);
			#end
			
			super.destroy();
		}
		
		function _initListeners(dispatcher:IEventDispatcher):Void {
			this._dispatcher = dispatcher;
			
			this._dispatcher.addEventListener(Event.COMPLETE, this._onComplete, false, 0, true);
			this._dispatcher.addEventListener(Event.OPEN, this._onOpen, false, 0, true);
			this._dispatcher.addEventListener(IOErrorEvent.IO_ERROR, this._onLoadError, false, 0, true);
			#if flash
			this._dispatcher.addEventListener(ProgressEvent.PROGRESS, this._onProgress, false, 0, true);
			#end
		}
		
		function _load():Void {
			this._loadItem.load(this._request);
		}
		
		function _createRequest(request:Dynamic):Void {
			if (Std.is( request, String)) {
				request = StringUtil.trim(request);
				
				if (request == '')
					throw 'Cannot load an empty reference/String';
				
				request = new URLRequest(request);
			} else if (!(Std.is( request, URLRequest)))
				throw new ArguementTypeError('request');
			
			this._request = request;
			this._url = this._request.url;
		}
		
		/**
			@sends RetryEvent#RETRY - Dispatched if the download attempt failed and the class is going to attempt to download the file again.
			@sends IOErrorEvent#IO_ERROR - Dispatched if requested file cannot be loaded and the download terminates.
		*/
		function _onLoadError(error:Event):Void {
			if (++this._attempts <= untyped this._retries) {
				var retry:RetryEvent = new RetryEvent(RetryEvent.RETRY);
				retry.attempts       = this._attempts;
				
				this.dispatchEvent(retry);
				
				this._load();
			} else {
				this._errrored = true;
				
				super._complete();
				
				this.dispatchEvent(error);
			}
		}
		
		/**
			@sends Event#OPEN - Dispatched when a load operation starts.
		*/
		function _onOpen(e:Event):Void {
			this._latency = Std.int(Timer.stamp()*1000 - this._startTime);
			
			this.dispatchEvent(e);
		}
		
		#if flash
		function _onHttpStatus(e:HTTPStatusEvent):Void {
			this._httpStatus = e.status;
			
			this.dispatchEvent(e);
		}
		
		function _onProgress(progress:ProgressEvent):Void {
			this._calculateLoadProgress();
		}
		#end
		
		/**
			@sends LoadEvent#PROGRESS - Dispatched as data is received during the download process.
		*/
		function _calculateLoadProgress():Void {
			var currentTime:Float = Timer.stamp()*1000;
			
			this._Bps  = Std.int(LoadUtil.calculateBps(this.bytesLoaded, this._startTime, currentTime));
			this._time = currentTime - this._startTime;
			
			this._progress.decimalPercentage = Math.min(this.bytesLoaded / this.bytesTotal, 1);
			
			this.dispatchEvent(this._createDefinedLoadEvent(LoadEvent.PROGRESS));
		}
		
		/**
			@sends LoadEvent#COMPLETE - Dispatched when file has completely loaded.
		*/
		function _onComplete(?complete:Event = null):Void {
			this._complete();
			
			this.dispatchEvent(this._createDefinedLoadEvent(LoadEvent.COMPLETE));
		}
		
		function _createDefinedLoadEvent(type:String):LoadEvent {
			var loadEvent:LoadEvent = new LoadEvent(type);
			loadEvent.attempts      = this.attempts;
			loadEvent.Bps           = this.Bps;
			loadEvent.bytesLoaded   = this.bytesLoaded;
			loadEvent.bytesTotal    = this.bytesTotal;
			loadEvent.latency       = this.latency;
			loadEvent.progress      = this.progress;
			loadEvent.retries       = this.retries;
			loadEvent.time          = this.time;
			
			return loadEvent;
		}
		
		override function _complete():Void {
			var currentTime:Float            = Timer.stamp()*1000;
			this._Bps                        = Std.int(LoadUtil.calculateBps(this.bytesTotal, this._startTime, currentTime));
			this._time                       = currentTime - this._startTime;
			this._loaded                     = true;
			this._progress.decimalPercentage = 1;
			
			super._complete();
		}
		
		function _dispatchEvent(e:Event) {
			this.dispatchEvent(e);
		}
	}
