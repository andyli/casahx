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
	import org.casalib.core.UInt;
	import org.casalib.errors.ArrayContentsError;
	import org.casalib.util.ArrayUtil;
	
	/**
		Class for storing keyboard key code combinations.
		
		@author Aaron Clinger
		@version 10/27/08
	*/
	class KeyCombo  {
		
		public var keyCodes(getKeyCodes, null) : Array<Int> ;
		var _keyCodes:Array<Int>;
		
		
		/**
			Creates and defines a KeyCombo.
			
			@param keyCodes: An Array of <code>uint</code> key codes that define a key combination.
			@throws ArrayContentsError if <code>keyCodes</code> Array contains a value not of type <code>uint</code> or if the Array contains less than 2 values.
		*/
		public function new(keyCodes:Array<Int>) {
			if (keyCodes.length < 2)
				throw new ArrayContentsError();
			
			var l:UInt = keyCodes.length;
			while (l-- > 0)
				if (!(Std.is( keyCodes[l], Int)))
					throw new ArrayContentsError();
			
			this._keyCodes = keyCodes.copy();
		}
		
		/**
			The key codes that compose this KeyCombo.
		*/
		public function getKeyCodes():Array<Int> {
			return this._keyCodes.copy();
		}
		
		/**
			Determines if the KeyCombo specified in the <code>keyCombo</code> parameter is equal to this KeyCombo.
			
			@param keyCombo: The KeyCombo class to compare to this class.
			@return Returns <code>true</code> if the two KeyCombo classes contain the same key codes in the same order; otherwise <code>false</code>.
		*/
		public function equals(keyCombo:KeyCombo):Bool {
			if (keyCombo == this)
				return true;
			
			return ArrayUtil.equals(this.keyCodes, keyCombo.keyCodes);
		}
	}
