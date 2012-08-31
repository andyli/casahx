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
	import org.casalib.core.UInt;
	import org.casalib.process.Process;
	import org.casalib.time.EnterFrame;
	
	/**
		Creates a callback after one or more frames. The class helps prevent race conditions by allowing recently created MovieClips, Classes, etc. a frame to initialize before proceeding.
		
		@author Aaron Clinger
		@version 02/11/10
		@example
			<code>
				package {
					import org.casalib.display.CasaMovieClip;
					import org.casalib.time.FrameDelay;
					
					
					public class MyExample extends CasaMovieClip {
						protected var _frameDelay:FrameDelay;
						
						
						public function MyExample() {
							super();
							
							this._frameDelay = new FrameDelay(this._onInitComplete);
							this._frameDelay.start();
						}
						
						protected function _onInitComplete():void{
							this._frameDelay.destroy();
							this._frameDelay = null;
							
							trace("Ready!");
						}
					}
				}
			</code>
	*/
	class FrameDelay extends Process {
		
		var _arguments:Array<Dynamic>;
		var _callBack:Dynamic;
		var _count:UInt;
		var _frames:UInt;
		var _enterFrameInstance:EnterFrame;
		
		
		/**
			Runs a function at a specified periodic interval.
			
			@param closure: The function to execute.
			@param frames: The amount of frames to delay.
			@param arguments: Arguments to be passed to the function when executed.
		*/
		public function new(closure:Dynamic, ?frames:UInt = 1, arguments:Array<Dynamic>) {
			super();
			
			this._callBack           = closure;
			this._frames             = frames;
			this._arguments          = arguments;
			this._enterFrameInstance = EnterFrame.getInstance();
		}
		
		/**
			Starts or restarts the delay.
		*/
		override public function start():Void {
			super.start();
		
			this._count = 0;
			this._enterFrameInstance.addEventListener(Event.ENTER_FRAME, this._onEnterFrame, false, 0, true);
		}
		
		/**
			Stops the delay from completing.
		*/
		override public function stop():Void {
			super.stop();
			
			this._enterFrameInstance.removeEventListener(Event.ENTER_FRAME, this._onEnterFrame);
		}
		
		override public function destroy():Void {
			this._enterFrameInstance.removeEventListener(Event.ENTER_FRAME, this._onEnterFrame);
			
			this._arguments = null;
			this._callBack  = null;
			
			super.destroy();
		}
		
		function _onEnterFrame(e:Event):Void {
			if (++_count >= untyped _frames) {
				this._enterFrameInstance.removeEventListener(Event.ENTER_FRAME, this._onEnterFrame);
				
				Reflect.callMethod(this,_callBack,this._arguments);
				
				this._complete();
			}
		}
	}
