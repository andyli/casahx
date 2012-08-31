/*
	CASA Lib for ActionScript 3.0
	Copyright (c) 2011, Aaron Clinger & Contributors of CASA Lib
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
package org.casalib.time; 
	import flash.events.Event;
	import flash.events.TimerEvent;
	import flash.utils.Timer;
	import org.casalib.control.IRunnable;
	import org.casalib.core.IDestroyable;
	import org.casalib.core.UInt;
	import org.casalib.events.IRemovableEventDispatcher;
	import org.casalib.events.ListenerManager;
	
	/**
		To be used instead of <code>flash.utils.setInterval</code> and <code>flash.utils.setTimeout</code> functions.
		
		Advantages over <code>setInterval</code>/<code>setTimeout</code>:
		<ul>
			<li>Ability to stop and start intervals without redefining.</li>
			<li>Change the time (<code>delay</code>), {@link Interval#callBack call back} and {@link Interval#arguments arguments} without redefining.</li>
			<li>Included <code>repeatCount</code> for intervals that only need to fire finitely.</li>
			<li>{@link Interval#setInterval} and {@link Interval#setTimeout} return an object instead of interval id for better OOP structure.</li>
			<li>Built in events/event dispatcher.</li>
		</ul>
		
		@author Aaron Clinger
		@author Mike Creighton
		@version 02/11/10
		@example
			<code>
				package {
					import org.casalib.display.CasaMovieClip;
					import org.casalib.time.Interval;
					
					
					public class MyExample extends CasaMovieClip {
						protected var _interval:Interval;
						
						
						public function MyExample() {
							super();
							
							this._interval = Interval.setInterval(this._repeatingFunction, 1000, "CASA");
							this._interval.repeatCount = 3;
							this._interval.start();
						}
						
						protected function _repeatingFunction(name:String):void {
							trace(name);
						}
					}
				}
			</code>
	*/
	class Interval extends Timer, implements IDestroyable, implements IRemovableEventDispatcher, implements IRunnable {
		
		public var arguments(getArguments, setArguments) : Array<Dynamic>;
		public var callBack(getCallBack, setCallBack) : Dynamic;
		public var destroyed(getDestroyed, null) : Bool ;
		var _callBack:Dynamic;
		var _arguments:Array<Dynamic>;
		var _isDestroyed:Bool;
		var _listenerManager:ListenerManager;
		
		
		/**
			Runs a function at a specified periodic interval.
			
			@param callBack: The function to execute after specified delay.
			@param delay: The time in milliseconds between calls.
			@param arguments: The arguments to be passed to the call back function when executed.
			@return: An {@link Interval} reference.
		*/
		public static function setInterval(callBack:Dynamic, delay:Float, ?arguments:Array<Dynamic>):Interval {
			return new Interval(delay, 0, callBack, arguments);
		}
		
		/**
			Runs a function at a specified periodic interval. Acts identically like {@link Interval#setInterval} except <code>setTimeout</code> defaults <code>repeatCount</code> to <code>1</code>.
			
			@param callBack: The function to execute after specified delay.
			@param delay: The time in milliseconds between calls.
			@param arguments: The arguments to be passed to the call back function when executed.
			@return: An {@link Interval} reference.
		*/
		public static function setTimeout(callBack:Dynamic, delay:Float, ?arguments:Array<Dynamic>):Interval {
			return new Interval(delay, 1, callBack, arguments);
		}
		
		/**
			@exclude
		*/
		public function new(delay:Float, repeatCount:Int, callBack:Dynamic, ?args:Array<Dynamic>) {
			super(delay, repeatCount);
			
			this.callBack         = callBack;
			this.arguments        = args == null ? [] : args;
			this._listenerManager = new ListenerManager(this);
			
			super.addEventListener(TimerEvent.TIMER, this._timerHandler, false, 0, true);
		}
		
		/**
			The function to execute after specified delay.
		*/
		private function getCallBack():Dynamic{
			return this._callBack;
		}
		
		private function setCallBack(cb:Dynamic):Dynamic{
			this._callBack = cb;
			return cb;
		}
		
		/**
			The arguments to be passed to the call back function when executed.
		*/
		private function getArguments():Array<Dynamic>{
			return this._arguments;
		}
		
		private function setArguments(args:Array<Dynamic>):Array<Dynamic>{
			this._arguments = args;
			return args;
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
		#if flash
		public override function addEventListener(type:String, listener:Dynamic->Void, ?useCapture:Bool = false, ?priority:Int = 0, ?useWeakReference:Bool = false):Void{
			super.addEventListener(type, listener, useCapture, priority, useWeakReference);
			this._listenerManager.addEventListener(type, listener, useCapture, priority, useWeakReference);
		}
		#else
		public override function addEventListener(type:String, listener:Dynamic->Void, ?useCapture:Bool, ?priority:Int, ?useWeakReference:Bool):Int{
			super.addEventListener(type, listener, useCapture, priority, useWeakReference);
			this._listenerManager.addEventListener(type, listener, useCapture, priority, useWeakReference);
			
			return -1;
		}
		#end
		
		/**
			@exclude
		*/
		public override function removeEventListener(type:String, listener:Dynamic->Void, ?useCapture:Bool #if flash = false #end):Void {
			super.removeEventListener(type, listener, useCapture);
			this._listenerManager.removeEventListener(type, listener, useCapture);
		}
		
		public function getTotalEventListeners(type:String = null):UInt {
			return this._listenerManager.getTotalEventListeners(type);
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
		
		private function getDestroyed():Bool {
			return this._isDestroyed;
		}
		
		public function destroy():Void {
			this.reset();
			
			this._listenerManager.destroy();
			
			super.removeEventListener(TimerEvent.TIMER, this._timerHandler);
			
			this._isDestroyed = true;
		}
		
		function _timerHandler(e:TimerEvent):Void {
			Reflect.callMethod(this,_callBack,_arguments);
		}
	}
