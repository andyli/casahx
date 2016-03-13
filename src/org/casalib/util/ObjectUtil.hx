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
package org.casalib.util;
	
	/**
		Utilities for working with Objects.
		
		@author Aaron Clinger
		@author David Nelson
		@version 10/27/08
	*/
	class ObjectUtil  {
		
		/**
			Searches the first level properties of an object for a another object.
			
			@param obj: Object to search in.
			@param member: Object to search for.
			@return Returns <code>true</code> if object was found; otherwise <code>false</code>.
		*/
		public static function contains(obj:Dynamic, member:Dynamic):Bool {
			for ( prop in ObjectUtil.getKeys(obj)) {
				var val = Reflect.getProperty(obj,prop);
				if ( val != null && val == member){
					return true;
				}
			}
			
			return false;
		}
		
		/**
			Makes a clone of the original Object.
			
			@param obj: Object to make the clone of.
			@return Returns a duplicate Object.
			@example
				<code>
					this._author      = new Person();
					this._author.name = "Aaron";
					
					registerClassAlias("Person", Person);
					
					var humanClone:Person = Person(ObjectUtil.clone(this._author));
					
					trace(humanClone.name);
				</code>
		*/
		public static function clone<T>(obj:Dynamic):T {
			var s = new haxe.Serializer();
			s.useCache = true;
			s.serialize(obj);
			return cast haxe.Unserializer.run(s.toString());
		}
		
		/**
			Creates an Array comprised of all the keys in an Object.
			
			@param obj: Object in which to find keys.
			@return Array containing all the string key names.
		*/
		public static function getKeys(obj:Dynamic):Array<String> {
			#if !flash
				return Reflect.fields(obj);
			#else
				var keys:Array<String> = Reflect.fields(obj);
				
				if (keys.length > 0) return keys;
				
				var c = Type.getClass(obj);
				var xml : flash.xml.XML = untyped __global__["flash.utils.describeType"](c);
				if (xml.factory.length() == 0) return keys;
				var vars = xml.factory[0].child("variable");
				for( i in 0...vars.length() ) {
					var f = vars[i].attribute("name").toString();
					if( !obj.hasOwnProperty(f) )
						continue;
					keys.push(f);
				}
				return keys;
			#end
		}
		
		/**
			Uses the strict equality operator to determine if object is <code>undefined</code>.
			
			@param obj: Object to determine if <code>undefined</code>.
			@return Returns <code>true</code> if object is <code>undefined</code>; otherwise <code>false</code>.
		*/
		inline public static function isUndefined(obj:Dynamic):Bool {
			return obj == null;
		}
		
		/**
			Uses the strict equality operator to determine if object is <code>null</code>.
			
			@param obj: Object to determine if <code>null</code>.
			@return Returns <code>true</code> if object is <code>null</code>; otherwise <code>false</code>.
		*/
		inline public static function isNull(obj:Dynamic):Bool {
			return obj == null;
		}
		
		/**
			Determines if object contains no value(s).
			
			@param obj: Object to derimine if empty.
			@return Returns <code>true</code> if object is empty; otherwise <code>false</code>.
			@example
				<code>
					var testNumber:Number;
					var testArray:Array   = new Array();
					var testString:String = "";
					var testObject:Object = new Object();
					
					trace(ObjectUtil.isEmpty(testNumber)); // traces "true"
					trace(ObjectUtil.isEmpty(testArray));  // traces "true"
					trace(ObjectUtil.isEmpty(testString)); // traces "true"
					trace(ObjectUtil.isEmpty(testObject)); // traces "true"
				</code>
		*/
		public static function isEmpty(obj:Dynamic):Bool {
			if (obj == null)
				return true;
			
			if (Std.is( obj, Float) || Std.is( obj, Int))
				return Math.isNaN(obj);
			
			if (Std.is( obj, Array) || Std.is( obj, String))
				return obj.length == 0;
			
			return ObjectUtil.getKeys(obj).length == 0;
		}
	}