/*
	CASA Lib for ActionScript 3.0
	Copyright (c) 2009, Aaron Clinger & Contributors of CASA Lib
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
package org.casalib.load; 
	import flash.events.Event;
	import flash.events.IEventDispatcher;
	import flash.media.Sound;
	import flash.media.SoundLoaderContext;
	import org.casalib.load.LoadItem;
	
	/*[Event(name="id3", type="flash.events.Event")]*/
	
	/**
		Provides an easy and standardized way to load audio files.
		
		@author Aaron Clinger
		@version 09/06/09
		@example
			<code>
				package {
					import org.casalib.display.CasaMovieClip;
					import org.casalib.events.LoadEvent;
					import org.casalib.load.AudioLoad;
					
					
					public class MyExample extends CasaMovieClip {
						protected var _audioLoad:AudioLoad;
						
						
						public function MyExample() {
							super();
							
							this._audioLoad = new AudioLoad("test.mp3");
							this._audioLoad.addEventListener(LoadEvent.COMPLETE, this._onComplete);
							this._audioLoad.start();
						}
						
						protected function _onComplete(e:LoadEvent):void {
							this._audioLoad.sound.play();
						}
					}
				}
			</code>
	*/
	class AudioLoad extends LoadItem {
		
		public var sound(getSound, null) : Sound ;
		var _context:SoundLoaderContext;
		
		
		/**
			Creates and defines an AudioLoad.
			
			@param request: A <code>String</code> or an <code>URLRequest</code> reference to the file you wish to load.
			@param context: An optional SoundLoaderContext object.
		*/
		public function new(request:Dynamic, ?context:SoundLoaderContext = null) {
			super(new Sound(), request);
			
			this._context = context;
			
			this._initListeners(this._loadItem);
		}
		
		/**
			The Sound object.
		*/
		public function getSound():Sound {
			return cast( this._loadItem, Sound);
		}
		
		public override function destroy():Void {
			this._dispatcher.removeEventListener(Event.ID3, this.dispatchEvent);
			
			super.destroy();
		}
		
		override function _load():Void {
			this._loadItem.load(this._request, this._context);
		}
		
		/**
			@sends Event#ID3 - Dispatched when ID3 data is available.
		*/
		override function _initListeners(dispatcher:IEventDispatcher):Void {
			super._initListeners(dispatcher);
			
			this._dispatcher.addEventListener(Event.ID3, this.dispatchEvent, false, 0, true);
		}
	}
