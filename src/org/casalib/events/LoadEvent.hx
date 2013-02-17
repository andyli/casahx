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
	import org.casalib.core.UInt;
	import org.casalib.math.Percent;
	
	/**
		An event dispatched during loading.
		
		@author Aaron Clinger
		@version 02/01/10
	*/
	class LoadEvent extends Event {
		
		public var bytesLoaded(get_bytesLoaded,set_bytesLoaded) : Float;
		public var bytesTotal(get_bytesTotal,set_bytesTotal): Float;
		public var Bps(get_Bps, set_Bps) : Int;
		public var attempts(get_attempts, set_attempts) : UInt;
		public var httpStatus(get_httpStatus, set_httpStatus) : UInt;
		public var latency(get_latency, set_latency) : UInt;
		public var progress(get_progress, set_progress) : Percent;
		public var retries(get_retries, set_retries) : UInt;
		public var time(get_time, set_time) : Float;
		inline public static var COMPLETE:String = 'complete';
		inline public static var PROGRESS:String = 'progress';
		inline public static var START:String    = 'start';
		inline public static var STOP:String     = 'stop';
		var _progress:Percent;
		var _bytesLoaded:Float;
		var _bytesTotal:Float;
		var _Bps:Int;
		var _time:Float;
		var _httpStatus:UInt;
		var _attempts:UInt;
		var _retries:UInt;
		var _latency:UInt;
		
		
		/**
			Creates a new LoadEvent.
			
			@param type: The type of event.
			@param bubbles: Determines whether the Event object participates in the bubbling stage of the event flow.
			@param cancelable: Determines whether the Event object can be canceled.
		*/
		public function new(type:String, ?bubbles:Bool = false, ?cancelable:Bool = false) {
			super(type, bubbles, cancelable);
		}
		
		/**
			The percent that the requested file has loaded.
		*/
		private function get_progress():Percent{
			return this._progress.clone();
		}
		
		private function set_progress(per:Percent):Percent{
			this._progress = per.clone();
			return per;
		}
		
		/**
			The number of additional times the file has attempted to load.
		*/
		private function get_attempts():UInt{
			return this._attempts;
		}
		
		private function set_attempts(a:UInt):UInt{
			return this._attempts = a;
		}
		
		/**
			The number of additional load retries the class will attempt before failing.
		*/
		private function get_retries():UInt{
			return this._retries;
		}
		
		private function set_retries(r:UInt):UInt{
			return this._retries = r;
		}
		
		/**
			The current download speed of the requested file in bytes per second.
		*/
		private function get_Bps():Int{
			return this._Bps;
		}
		
		private function set_Bps(bytes:Int):Int{
			return this._Bps = bytes;
		}
		
		/**
			The number of bytes loaded when the listener processed the event.
		*/
		private function get_bytesLoaded():Float {
			return this._bytesLoaded;
		}
		
		private function set_bytesLoaded(bytes:Float):Float {
			return this._bytesLoaded = bytes;
		}
		
		/**
			The total number of bytes that will be loaded if the loading process succeeds.
		*/
		private function get_bytesTotal():Float {
			return this._bytesTotal;
		}
		
		private function set_bytesTotal(bytes:Float):Float {
			return this._bytesTotal = bytes;
		}
		
		/**
			The current time duration in milliseconds the load has taken.
		*/
		private function get_time():Float{
			return this._time;
		}
		
		private function set_time(milliseconds:Float):Float{
			return this._time = milliseconds;
		}
		
		/**
			The time in milliseconds that the server took to respond.
		*/
		private function get_latency():UInt{
			return this._latency;
		}
		
		private function set_latency(l:UInt):UInt{
			return this._latency = l;
		}
		
		/**
			The HTTP status code returned by the server; or <code>0</code> if no status has/can been received or the load is a stream.
		*/
		private function get_httpStatus():UInt{
			return this._httpStatus;
		}
		
		private function set_httpStatus(status:UInt):UInt{
			return this._httpStatus = status;
		}
		
		#if flash
		/**
			@return A string containing all the properties of the event.
		*/
		public override function toString():String {
			return this.formatToString('LoadEvent', 'attempts', 'Bps', 'bytesLoaded', 'bytesTotal', 'httpStatus');
		}
		#end
		
		/**
			@return Duplicates an instance of the event.
		*/
		public override function clone():Event {
			var e:LoadEvent = new LoadEvent(this.type, this.bubbles, this.cancelable);
			e.attempts      = this.attempts;
			e.Bps           = this.Bps;
			e.bytesLoaded   = this.bytesLoaded;
			e.bytesTotal    = this.bytesTotal;
			e.httpStatus    = this.httpStatus;
			e.latency       = this.latency;
			e.progress      = this.progress;
			e.retries       = this.retries;
			e.time          = this.time;
			
			return e;
		}
	}