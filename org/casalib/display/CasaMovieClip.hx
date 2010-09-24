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
package org.casalib.display; 
	import flash.display.MovieClip;
	import flash.display.Stage;
	import flash.events.Event;
	import org.casalib.events.IRemovableEventDispatcher;
	import org.casalib.events.ListenerManager;
	import org.casalib.core.IDestroyable;
	import org.casalib.core.UInt;
	import org.casalib.util.StageReference;
	import org.casalib.util.DisplayObjectUtil;
	
	
	/**
		A base MovieClip that implements {@link IRemovableEventDispatcher} and {@link ICasaDisplayObjectContainer}.
		
		@author Aaron Clinger
		@author Mike Creighton
		@version 02/11/10
	*/
	class CasaMovieClip extends MovieClip, implements IRemovableEventDispatcher, implements IDestroyable, implements Dynamic<Dynamic> {
		
		public var destroyed(getDestroyed, null) : Bool ;
		//public var stage(getStage, null) : Stage ;
		var _listenerManager:ListenerManager;
		var _isDestroyed:Bool;
		
		
		/**
			Creates a new CasaMovieClip.
		*/
		public function new() {
			super();
			
			this._listenerManager = new ListenerManager(this);
		}
		
		/**
			@exclude
		*/
		public override function dispatchEvent(event:Event):Bool {
			if (this.willTrigger(event.type))
				return super.dispatchEvent(event);
			
			return true;
		}
		
		/**
			@exclude
		*/
		#if (flash || cpp || neko)
		public override function addEventListener(type:String, listener:Dynamic->Void, ?useCapture:Bool = false, ?priority:Int = 0, ?useWeakReference:Bool = false):Void {
			super.addEventListener(type, listener, useCapture, priority, useWeakReference);
			this._listenerManager.addEventListener(type, listener, useCapture, priority, useWeakReference);
		}
		#else
		public override function addEventListener(type:String, listener:Dynamic->Void, ?useCapture:Bool, ?priority:Int, ?useWeakReference:Bool):Int {
			var val = super.addEventListener(type, listener, useCapture, priority, useWeakReference);
			this._listenerManager.addEventListener(type, listener, useCapture, priority, useWeakReference);
			return val;
		}
		#end
		
		/**
			@exclude
		*/
		public override function removeEventListener(type:String, listener:Dynamic->Void, ?useCapture:Bool #if (flash || cpp || neko) = false #end):Void {
			super.removeEventListener(type, listener, useCapture);
			this._listenerManager.removeEventListener(type, listener, useCapture);
		}
		
		public function removeEventsForType(type:String):Void {
			this._listenerManager.removeEventsForType(type);
		}
		
		public function removeEventsForListener(listener:Dynamic):Void {
			this._listenerManager.removeEventsForListener(listener);
		}
		
		public function removeEventListeners():Void {
			this._listenerManager.removeEventListeners();
		}
		
		public function getTotalEventListeners(?type:String = null):UInt {
			return this._listenerManager.getTotalEventListeners(type);
		}
		
		/**
			The Stage of the display object or if the display object is not added to the display list and {@link StageReference} is defined <code>stage</code> will return the {@link StageReference#STAGE_DEFAULT default stage}; otherwise <code>null</code>.
		
		public override function getStage():Stage {
			if (super.stage == null) {
				try {
					return StageReference.getStage();
				} catch (e:Error) {}
			}
			
			return super.stage;
		}*/
		
		/**
			Removes and optionally destroys children of the CasaMovieClip.
			
			@param destroyChildren: If a child implements {@link IDestroyable} call its {@link IDestroyable#destroy destroy} method <code>true</code>, or don't destroy <code>false</code>; defaults to <code>false</code>.
			@param recursive: Call this method with the same arguments on all of the children's children (all the way down the display list) <code>true</code>, or leave the children's children <code>false</code>; defaults to <code>false</code>.
		*/
		public function removeChildren(?destroyChildren:Bool = false, ?recursive:Bool = false):Void {
			DisplayObjectUtil.removeChildren(this, destroyChildren, recursive);
		}
		
		/**
			Removes and optionally destroys children of the CasaMovieClip then destroys itself.
			
			@param destroyChildren: If a child implements {@link IDestroyable} call its {@link IDestroyable#destroy destroy} method <code>true</code>, or don't destroy <code>false</code>; defaults to <code>false</code>.
			@param recursive: Call this method with the same arguments on all of the children's children (all the way down the display list) <code>true</code>, or leave the children's children <code>false</code>; defaults to <code>false</code>.
		*/
		public function removeChildrenAndDestroy(?destroyChildren:Bool = false, ?recursive:Bool = false):Void {
			this.removeChildren(destroyChildren, recursive);
			this.destroy();
		}
		
		private function getDestroyed():Bool {
			return this._isDestroyed;
		}
		
		/**
			{@inheritDoc}
			
			Calling <code>destroy()</code> on a CASA display object also removes it from its current parent.
		*/
		public function destroy():Void {
			this.removeEventListeners();
			this._listenerManager.destroy();
			
			this.stop();
			
			this._isDestroyed = true;
			
			if (this.parent != null)
				this.parent.removeChild(this);
		}
	}
