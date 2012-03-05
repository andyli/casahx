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
package org.casalib.events; 
	import flash.events.Event;
	
	/**
		An event dispatched from {@link Inactivity}.
		
		@author Aaron Clinger
		@version 10/27/08
	*/
	class InactivityEvent extends Event {
		
		public var milliseconds(getMilliseconds, setMilliseconds) : Float;
		inline public static var INACTIVE:String  = 'inactive';
		inline public static var ACTIVATED:String = 'activated';
		var _milliseconds:Float;
		
		
		/**
			Creates a new InactivityEvent.
			
			@param type: The type of event.
			@param bubbles: Determines whether the Event object participates in the bubbling stage of the event flow.
			@param cancelable: Determines whether the Event object can be canceled.
		*/
		public function new(type:String, ?bubbles:Bool = false, ?cancelable:Bool = false) {
			super(type, bubbles, cancelable);
		}
		
		/**
			The length of time an user has been inactive.
		*/
		private function getMilliseconds():Float{
			return this._milliseconds;
		}
		
		private function setMilliseconds(time:Float):Float{
			this._milliseconds = time;
			return time;
		}
		
		#if flash
		/**
			@return A string containing all the properties of the event.
		*/
		public override function toString():String {
			return formatToString('InactivityEvent', 'type', 'bubbles', 'cancelable', 'milliseconds');
		}
		#end
		
		/**
			@return Duplicates an instance of the event.
		*/
		public override function clone():Event {
			var e:InactivityEvent = new InactivityEvent(this.type, this.bubbles, this.cancelable);
			e.milliseconds        = this.milliseconds;
			
			return e;
		}
	}
