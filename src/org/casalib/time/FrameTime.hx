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
package org.casalib.time; 
	import flash.events.Event;
	
	/**
		Creates a common time which isn't affected by delays caused by code execution; the time is only updated every frame.
		
		@author Aaron Clinger
		@author Mike Creighton
		@version 03/08/08
	*/
	class FrameTime  {
		
		public var time(getTime, null) : Float ;
		static var _frameTimeInstance:FrameTime;
		var _enterFrame:EnterFrame;
		var _time:Float;
		
		
		/**
			@return {@link FrameTime} instance.
		*/
		public static function getInstance():FrameTime {
			if (FrameTime._frameTimeInstance == null)
				FrameTime._frameTimeInstance = new FrameTime();
			
			return FrameTime._frameTimeInstance;
		}
		
		/**
			@exclude
		*/
		private function new() {
			this._enterFrame = EnterFrame.getInstance();
			this._enterFrame.addEventListener(Event.ENTER_FRAME, this._updateTime);
			
			this._updateTime(new Event(Event.ENTER_FRAME));
		}
		
		/**
			@return Returns the number of milliseconds from when the SWF started playing to the last <code>enterFrame</code> event.
		*/
		private function getTime():Float {
			return this._time;
		}
		
		function _updateTime(e:Event):Void {
			this._time = haxe.Timer.stamp()*1000;
		}
	}
