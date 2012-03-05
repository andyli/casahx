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
	import org.casalib.ui.KeyCombo;
	
	/**
		An event dispatched in response to a user {@link KeyComboEvent#DOWN holding}, {@link KeyComboEvent#RELEASE releasing} or {@link KeyComboEvent#SEQUENCE typing} a combination of keys.
		
		@author Aaron Clinger
		@version 01/19/10
	*/
	class KeyComboEvent extends Event {
		
		inline public var keyCombo(getKeyCombo, setKeyCombo) : KeyCombo;
		inline public static var DOWN:String     = 'down';
		inline public static var RELEASE:String  = 'release';
		inline public static var SEQUENCE:String = 'sequence';
		var _keyCombo:KeyCombo;
		
		
		/**
			Creates a new KeyComboEvent.
			
			@param type: The type of event.
			@param bubbles: Determines whether the Event object participates in the bubbling stage of the event flow.
			@param cancelable: Determines whether the Event object can be canceled.
		*/
		public function new(type:String, ?bubbles:Bool = false, ?cancelable:Bool = false) {
			super(type, bubbles, cancelable);
		}
		
		/**
			The {@link KeyCombo} that contains the key codes that triggered the event.
		*/
		inline private function getKeyCombo():KeyCombo{
			return this._keyCombo;
		}
		
		inline private function setKeyCombo(keyCombo:KeyCombo):KeyCombo{
			this._keyCombo = keyCombo;
			return keyCombo;
		}
		
		#if flash
		/**
			@return A string containing all the properties of the event.
		*/
		public override function toString():String {
			return formatToString('KeyComboEvent', 'type', 'bubbles', 'cancelable', 'keyCombo');
		}
		#end
		
		/**
			@return Duplicates an instance of the event.
		*/
		public override function clone():Event {
			var e:KeyComboEvent = new KeyComboEvent(this.type, this.bubbles, this.cancelable);
			e.keyCombo          = this.keyCombo;
			
			return e;
		}
	}
