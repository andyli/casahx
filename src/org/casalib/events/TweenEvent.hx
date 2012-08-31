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
package org.casalib.events; 
	import flash.events.Event;
	import org.casalib.math.Percent;
	
	/**
		An event dispatched from {@link Tween}.
		
		@author Mike Creighton
		@author Aaron Clinger
		@version 10/27/08
	*/
	class TweenEvent extends Event {
		
		public var position(getPosition, setPosition) : Float;
		public var progress(getProgress, setProgress) : Percent;
		inline public static var COMPLETE:String = 'complete';
		inline public static var RESUME:String   = 'resume';
		inline public static var START:String    = 'start';
		inline public static var STOP:String     = 'stop';
		inline public static var UPDATE:String   = 'update';
		var _position:Float;
		var _progress:Percent;
		
		
		/**
			Creates a new TweenEvent.
			
			@param type: The type of event.
			@param bubbles: Determines whether the Event object participates in the bubbling stage of the event flow.
			@param cancelable: Determines whether the Event object can be canceled.
		*/
		public function new(type:String, ?bubbles:Bool = false, ?cancelable:Bool = false) {
			super(type, bubbles, cancelable);
		}
		
		/**
			The current position of the tween.
		*/
		private function getPosition():Float{
			return this._position;
		}
		
		private function setPosition(value:Float):Float{
			this._position = value;
			return value;
		}
		
		/**
			The percent completed of the tween's duration.
		*/
		private function getProgress():Percent{
			return this._progress.clone();
		}
		
		private function setProgress(percent:Percent):Percent{
			this._progress = percent.clone();
			return percent;
		}
		
		#if flash
		/**
			@return A string containing all the properties of the event.
		*/
		public override function toString():String {
			return formatToString('TweenEvent', 'type', 'bubbles', 'cancelable', 'position', 'progress');
		}
		#end
		
		/**
			@return Duplicates an instance of the event.
		*/
		public override function clone():Event {
			var e:TweenEvent = new TweenEvent(this.type, this.bubbles, this.cancelable);
			e.position       = this.position;
			e.progress       = this.progress;
			
			return e;
		}
	}
