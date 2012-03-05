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
	import org.casalib.events.LoadEvent;
	import org.casalib.math.Percent;
	
	/**
		An event dispatched from {@link VideoLoad}.
		
		@author Aaron Clinger
		@version 04/19/09
	*/
	class VideoLoadEvent extends LoadEvent {
		
		public var buffer(getBuffer, setBuffer) : Percent;
		public var millisecondsUntilBuffered(getMillisecondsUntilBuffered, setMillisecondsUntilBuffered) : Int;
		inline public static var BUFFERED:String = 'buffered';
		inline public static var PROGRESS:String = 'progress';
		var _buffer:Percent ;
		var _millisecondsUntilBuffered:Int ;
		
		
		/**
			Creates a new VideoLoadEvent.
			
			@param type: The type of event.
			@param bubbles: Determines whether the Event object participates in the bubbling stage of the event flow.
			@param cancelable: Determines whether the Event object can be canceled.
		*/
		public function new(type:String, ?bubbles:Bool = false, ?cancelable:Bool = false) {
			
			_buffer = new Percent();
			_millisecondsUntilBuffered = -1;
			super(type, bubbles, cancelable);
		}
		
		/**
			The time remaining in milliseconds until the video has completely buffered.
			
			@usageNote {@link VideoLoad} will report <code>-1</code> milliseconds until two seconds of load time has elapsed.
		*/
		private function getMillisecondsUntilBuffered():Int{
			return this._millisecondsUntilBuffered;
		}
		
		private function setMillisecondsUntilBuffered(milliseconds:Int):Int{
			this._millisecondsUntilBuffered = milliseconds;
			return milliseconds;
		}
		
		/**
			The percent the video has buffered.
			
			@usageNote {@link VideoLoad} will report <code>0</code> percent until two seconds of load time has elapsed.
		*/
		private function getBuffer():Percent{
			return this._buffer.clone();
		}
		
		private function setBuffer(percent:Percent):Percent{
			this._buffer = percent.clone();
			return percent;
		}
		
		#if flash
		/**
			@return A string containing all the properties of the event.
		*/
		public override function toString():String {
			return this.formatToString('VideoLoadEvent', 'bytesLoaded', 'bytesTotal', 'httpStatus', 'latency', 'millisecondsUntilBuffered');
		}
		#end
		
		/**
			@return Duplicates an instance of the event.
		*/
		public override function clone():Event {
			var e:VideoLoadEvent        = new VideoLoadEvent(this.type, this.bubbles, this.cancelable);
			e.attempts                  = this.attempts;
			e.Bps                       = this.Bps;
			e.buffer                    = this.buffer;
			e.bytesLoaded               = this.bytesLoaded;
			e.bytesTotal                = this.bytesTotal;
			e.httpStatus                = this.httpStatus;
			e.latency                   = this.latency;
			e.millisecondsUntilBuffered = this.millisecondsUntilBuffered;
			e.progress                  = this.progress;
			e.retries                   = this.retries;
			e.time                      = this.time;
			
			return e;
		}
	}
