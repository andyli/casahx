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
	import flash.display.Bitmap;
	import flash.display.BitmapData;
	import flash.display.Stage;
	import flash.events.Event;
	import flash.display.PixelSnapping;
	import org.casalib.core.IDestroyable;
	import org.casalib.core.UInt;
	import org.casalib.events.IRemovableEventDispatcher;
	import org.casalib.events.ListenerManager;
	import org.casalib.util.StageReference;
	
	
	/**
		A base Bitmap that implements {@link IRemovableEventDispatcher} and {@link IDestroyable}.
		
		@author Aaron Clinger
		@version 02/11/10
	*/
	class CasaBitmap extends Bitmap, implements IRemovableEventDispatcher, implements IDestroyable {
		
		public var destroyed(getDestroyed, null) : Bool ;
		//public var stage(getStage, null) : Stage ;
		var _listenerManager:ListenerManager;
		var _isDestroyed:Bool;
		
		
		/**
			Creates a new CasaBitmap.
			
			@param bitmapData: The BitmapData object being referenced.
			@param pixelSnapping: Whether or not the Bitmap object is snapped to the nearest pixel.
			@param smoothing: Whether or not the bitmap is smoothed when scaled.
		*/
		public function new(?bitmapData:BitmapData = null, ?pixelSnapping:PixelSnapping, ?smoothing:Bool = false) {
			super(bitmapData, pixelSnapping == null ? PixelSnapping.AUTO : pixelSnapping, smoothing);
			
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
		
		private function getDestroyed():Bool {
			return this._isDestroyed;
		}
		
		/**
			{@inheritDoc}
			
			Calling <code>destroy()</code> on a CASA display object also removes it from its current parent.
		*/
		public function destroy():Void {
			this._listenerManager.destroy();
			
			this._isDestroyed = true;
			
			if (this.parent != null)
				this.parent.removeChild(this);
		}
	}
