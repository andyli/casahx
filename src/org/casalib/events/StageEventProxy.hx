﻿/*
	CASA Framework for ActionScript 3.0
	Copyright (c) 2011, Contributors of CASA Framework
	All rights reserved.
	
	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:
	
	- Redistributions of source code must retain the above copyright notice,
	  this list of conditions and the following disclaimer.
	
	- Redistributions in binary form must reproduce the above copyright notice,
	  this list of conditions and the following disclaimer in the documentation
	  and/or other materials provided with the distribution.
	
	- Neither the name of the CASA Framework nor the names of its contributors
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
package org.casalib.events; 
	import org.casalib.core.Destroyable;
	import org.casalib.core.UInt;
	import org.casalib.events.ListenerManager;
	import org.casalib.events.IRemovableEventDispatcher;
	import org.casalib.util.StageReference;
	import flash.display.Stage;
	import flash.events.Event;
	
	
	/**
		Created an event proxy between the Stage that implements {@link IRemovableEventDispatcher} and {@link IDestroyable}.
		
		@author Aaron Clinger
		@version 02/11/10
		@usageNote You must first initialize {@link StageReference} before using this class.
		@example
			<code>
				package {
					import flash.events.KeyboardEvent;
					import org.casalib.display.CasaMovieClip;
					import org.casalib.events.StageEventProxy;
					import org.casalib.util.StageReference;
					
					
					public class MyExample extends CasaMovieClip {
						protected var _stageEventProxy:StageEventProxy;
						
						
						public function MyExample() {
							super();
							
							StageReference.setStage(this.stage);
							
							this._stageEventProxy = new StageEventProxy();
							this._stageEventProxy.addEventListener(KeyboardEvent.KEY_DOWN, this._onKeyDown);
							this._stageEventProxy.addEventListener(KeyboardEvent.KEY_UP, this._onKeyUp);
						}
						
						protected function _onKeyDown(e:KeyboardEvent):void {
							trace("Key down " + e.keyCode);
							
							if (e.keyCode == 65) {
								trace("a key pressed!");
								
								this._stageEventProxy.removeEventListeners();
							}
						}
						
						protected function _onKeyUp(e:KeyboardEvent):void {
							trace("Key up " + e.keyCode);
						}
					}
				}
			</code>
	*/
	class StageEventProxy extends Destroyable, implements IRemovableEventDispatcher {
		
		var _listenerManager:ListenerManager;
		var _stage:Stage;
		
		
		/**
			Created a new StageEventProxy.
			
			@param stageId: An identifier that corresponds to a stored Stage in {@link StageReference}.
			@usageNote You must first initialize {@link StageReference} before using this class.
		*/
		public function new(?stageId:String = StageReference.STAGE_DEFAULT) {
			super();
			
			this._stage           = StageReference.getStage(stageId);
			this._listenerManager = new ListenerManager(this._stage);
		}
		
		/**
			@see "IEventDispatcher documention for this method."
		*/
		public function dispatchEvent(event:Event):Bool {
			if (this._stage.willTrigger(event.type))
				return this._stage.dispatchEvent(event);
			
			return true;
		}
		
		/**
			@see "IEventDispatcher documention for this method."
		*/
		#if flash
		public function addEventListener(type:String, listener:Dynamic->Void, ?useCapture:Bool = false, ?priority:Int = 0, ?useWeakReference:Bool = false):Void {
			this._stage.addEventListener(type, listener, useCapture, priority, useWeakReference);
			this._listenerManager.addEventListener(type, listener, useCapture, priority, useWeakReference);
		}
		#else
		public function addEventListener(type:String, listener:Dynamic->Void, ?useCapture:Bool, ?priority:Int, ?useWeakReference:Bool):Int {
			var val = this._stage.addEventListener(type, listener, useCapture, priority, useWeakReference);
			this._listenerManager.addEventListener(type, listener, useCapture, priority, useWeakReference);
			return val;
		}
		#end
		
		/**
			@see "IEventDispatcher documention for this method."
		*/
		public function removeEventListener(type:String, listener:Dynamic->Void, ?useCapture:Bool #if flash = false #end):Void {
			this._stage.removeEventListener(type, listener, useCapture);
			this._listenerManager.removeEventListener(type, listener, useCapture);
		}
		
		/**
			@see "IEventDispatcher documention for this method."
		*/
		public function hasEventListener(type:String):Bool {
			return this._stage.hasEventListener(type);
		}
		
		/**
			@see "IEventDispatcher documention for this method."
		*/
		public function willTrigger(type:String):Bool {
			return this._stage.willTrigger(type);
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
		
		public function getTotalEventListeners(type:String = null):UInt {
			return this._listenerManager.getTotalEventListeners(type);
		}
		
		public override function destroy():Void {
			this._listenerManager.destroy();
			
			super.destroy();
		}
	}