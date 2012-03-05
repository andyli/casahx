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
package org.casalib.ui; 
	import flash.events.Event;
	import org.casalib.ui.KeyCombo;
	import flash.events.KeyboardEvent;
	import flash.display.Stage;
	import org.casalib.core.UInt;
	import org.casalib.events.KeyComboEvent;
	import org.casalib.events.RemovableEventDispatcher;
	import org.casalib.util.ArrayUtil;
	import org.casalib.util.StageReference;
	
	/*[Event(name="keyDown", type="flash.events.KeyboardEvent")]*/
	/*[Event(name="keyUp", type="flash.events.KeyboardEvent")]*/
	/*[Event(name="down", type="org.casalib.events.KeyComboEvent")]*/
	/*[Event(name="release", type="org.casalib.events.KeyComboEvent")]*/
	/*[Event(name="sequence", type="org.casalib.events.KeyComboEvent")]*/
	
	/**
		Key class that simplifies listening to global key strokes and adds additional keyboard events. Key enables you to receive events when multiple keys are {@link KeyComboEvent held/released} and when a {@link KeyComboEvent#SEQUENCE sequence of keys are pressed}.
		
		@author Aaron Clinger
		@version 09/06/09
		@usageNote You must first initialize {@link StageReference} before using this class.
		@example
			<code>
				package {
					import flash.events.KeyboardEvent;
					import org.casalib.display.CasaMovieClip;
					import org.casalib.events.KeyComboEvent;
					import org.casalib.ui.Key;
					import org.casalib.ui.KeyCombo;
					import org.casalib.util.StageReference;
					
					
					public class MyExample extends CasaMovieClip {
						protected var _asdfCombo:KeyCombo;
						protected var _casaCombo:KeyCombo;
						protected var _key:Key;
						
						
						public function MyExample() {
							super();
							
							StageReference.setStage(this.stage);
							
							this._key = Key.getInstance();
							
							this._asdfCombo = new KeyCombo(new Array(65, 83, 68, 70));
							this._key.addKeyCombo(this._asdfCombo);
							
							this._casaCombo = new KeyCombo(new Array(67, 65, 83, 65));
							this._key.addKeyCombo(this._casaCombo);
							
							this._key.addEventListener(KeyComboEvent.DOWN, this._onComboDown);
							this._key.addEventListener(KeyComboEvent.RELEASE, this._onComboRelease);
							this._key.addEventListener(KeyComboEvent.SEQUENCE, this._onComboTyped);
							this._key.addEventListener(KeyboardEvent.KEY_DOWN, this._onKeyPressed);
							this._key.addEventListener(KeyboardEvent.KEY_UP, this._onKeyReleased);
						}
						
						protected function _onComboDown(e:KeyComboEvent):void {
							if (this._asdfCombo.equals(e.keyCombo)) {
								trace("User is holding down keys a-s-d-f.");
							}
						}
						
						protected function _onComboRelease(e:KeyComboEvent):void {
							if (this._asdfCombo.equals(e.keyCombo)) {
								trace("User no longer holding down keys a-s-d-f.");
							}
						}
						
						protected function _onComboTyped(e:KeyComboEvent):void {
							if (this._casaCombo.equals(e.keyCombo)) {
								trace("User typed casa.");
							}
						}
						
						protected function _onKeyPressed(e:KeyboardEvent):void {
							trace("User pressed key with code: " + e.keyCode + ".");
						}
						
						protected function _onKeyReleased(e:KeyboardEvent):void {
							trace("User released key with code: " + e.keyCode + ".");
						}
					}
				}
			</code>
	*/
	class Key extends RemovableEventDispatcher {
		
		static var _instance:Key = null;
		var _keysDown:IntHash<Bool>;
		var _keysTyped:Array<Int>;
		var _combosDown:Array<KeyCombo>;
		var _combinations:Array<KeyCombo>;
		var _longestCombo:UInt;
		
		
		/**
			@return The Key instance.
			@usageNote You must first initialize {@link StageReference} before using this class.
		*/
		inline public static function getInstance():Key {
			if (_instance == null) _instance = new Key();
			return Key._instance;
		}
		
		/**
			@exclude
		*/
		private function new() {
			super();
		
			var stage:Stage = StageReference.getStage();
			
			stage.addEventListener(KeyboardEvent.KEY_DOWN, this._onKeyDown);
			stage.addEventListener(KeyboardEvent.KEY_UP, this._onKeyUp);
			stage.addEventListener(Event.DEACTIVATE, this._onDeactivate);
			
			this._keysDown     = new IntHash<Bool>();
			this._keysTyped    = new Array<Int>();
			this._combosDown   = new Array<KeyCombo>();
			this._combinations = new Array<KeyCombo>();
			this._longestCombo = 0;
		}
		
		/**
			Determines if is key is down.
			
			@param keyCode: The key code value assigned to a specific key or a Keyboard class constant associated with the key.
			@return Returns <code>true</code> if key is currently pressed; otherwise <code>false</code>.
		*/
		inline public function isDown(keyCode:UInt):Bool {
			return this._keysDown.get(keyCode);
		}
		
		/**
			Sets a key combination to trigger a {@link KeyComboEvent}.
			
			@param keyCombo: A defined {@link KeyCombo} object.
		*/
		public function addKeyCombo(keyCombo:KeyCombo):Void {
			var l:UInt = this._combinations.length;
			while (l-- > 0)
				if (this._combinations[l].equals(keyCombo))
					return;
			
			this._longestCombo = Std.int(Math.max(this._longestCombo, keyCombo.keyCodes.length));
			
			this._combinations.push(keyCombo);
		}
		
		/**
			Removes a key combination from triggering a {@link KeyComboEvent}.
			
			@param keyCombo: A defined {@link KeyCombo} object.
		*/
		public function removeKeyCombo(keyCombo:KeyCombo):Void {
			var i:Int  = -1;
			var l:UInt = this._combinations.length;
			
			while (l-- > 0) {
				if (this._combinations[l].equals(keyCombo)) {
					i = l;
					break;
				}
			}
			
			if (i == -1)
				return;
			
			this._combinations.splice(i, 1);
			
			if (keyCombo.keyCodes.length == untyped this._longestCombo) {
				var size:UInt = 0;
				
				l = this._combinations.length;
				while (l-- > 0)
					size = Std.int(Math.max(size, this._combinations[l].keyCodes.length));
				
				this._longestCombo = size;
			}
		}
		
		/**
			@throws Error if called. Cannot destroy a singleton.
		*/
		public override function destroy():Void {
			throw 'Cannot destroy a singleton.';
		}
		
		/**
			@sends KeyboardEvent#KEY_DOWN - Dispatched when the user presses a key.
		*/
		function _onKeyDown(e:KeyboardEvent):Void {
			var alreadyDown:Bool   = this._keysDown.get(e.keyCode);
			this._keysDown.set(e.keyCode,true);
			
			this._keysTyped.push(e.keyCode);
			
			if (this._keysTyped.length > untyped this._longestCombo)
				this._keysTyped.splice(0, 1);
			
			var l:UInt = this._combinations.length;
			while (l-- > 0) {
				this._checkedTypedKeys(this._combinations[l]);
				
				if (!alreadyDown)
					this._checkDownKeys(this._combinations[l]);
			}
			
			this.dispatchEvent(e);
		}
		
		/**
			@sends KeyboardEvent#KEY_UP - Dispatched when the user releases a key.
			@sends KeyComboEvent#RELEASE - Dispatched whens all keys in an added {@link KeyCombo} are no longer being held together at once.
		*/
		function _onKeyUp(e:KeyboardEvent):Void {
			var l:UInt = this._combosDown.length;
			while (l-- > 0) {
				if (ArrayUtil.indexOf(this._combosDown[l].keyCodes,e.keyCode) > -1) {
					var keyComboHold:KeyComboEvent = new KeyComboEvent(KeyComboEvent.RELEASE);
					keyComboHold.keyCombo = this._combosDown[l];
					
					this._combosDown.splice(l, 1);
					
					this.dispatchEvent(keyComboHold);
				}
			}
			
			this._keysDown.remove(e.keyCode);
			
			this.dispatchEvent(e);
		}
		
		function _onDeactivate(e:Event):Void {
			var l:UInt = this._combosDown.length;
			while (l-- > 0) {
				var keyComboHold:KeyComboEvent = new KeyComboEvent(KeyComboEvent.RELEASE);
				keyComboHold.keyCombo = this._combosDown[l];
				
				this.dispatchEvent(keyComboHold);
			}
			
			this._combosDown = new Array<KeyCombo>();
			this._keysDown   = new IntHash<Bool>();
		}
		
		/**
			@sends KeyComboEvent#SEQUENCE - Dispatched when all keys in an added {@link KeyCombo} are typed in order.
		*/
		function _checkedTypedKeys(keyCombo:KeyCombo):Void {
			if (ArrayUtil.equals(keyCombo.keyCodes, this._keysTyped.slice(-keyCombo.keyCodes.length))) {
				var keyComboSeq:KeyComboEvent = new KeyComboEvent(KeyComboEvent.SEQUENCE);
				keyComboSeq.keyCombo = keyCombo;
				
				this.dispatchEvent(keyComboSeq);
			}
		}
		
		/**
			@sends KeyComboEvent#DOWN - Dispatched when all keys in an added {@link KeyCombo} are held down together at once.
		*/
		function _checkDownKeys(keyCombo:KeyCombo):Void {
			var uniqueCombo       = ArrayUtil.removeDuplicates(keyCombo.keyCodes);
			var i:UInt            = uniqueCombo.length;
			
			while (i-- > 0)
				if (!this.isDown(uniqueCombo[i]))
					return;
			
			var keyComboDown:KeyComboEvent = new KeyComboEvent(KeyComboEvent.DOWN);
			keyComboDown.keyCombo = keyCombo;
			
			this._combosDown.push(keyCombo);
			
			this.dispatchEvent(keyComboDown);
		}
	}
