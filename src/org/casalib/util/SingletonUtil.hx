/*
	CASA Framework for ActionScript 3.0
	Copyright (c) 2011, Contributors of CASA Framework
	All rights reserved.
	
	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:
	
	- Redistributions of source code must retain the above copyright notice,
	  this list of conditions and the following disclaimer.
	
	- Redistributions in binary form must reproduce the above copyright notice,
	  this list of conditions and the following disclaimer in the documentation
	  and/or other materials provided with the distribution.
	
	- Neither the name of the CASA Framework nor the names of its contributors
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
		Provides utility functions for creating and managing singletons and multitons.
		
		@author Aaron Clinger
		@version 05/04/11
	*/
	class SingletonUtil {
		static var _singletonMap:Map<String, Dynamic>;
		static var _multitonMap:Map<String, Map<String, Dynamic>>;
		
		/**
			Creates a singleton out of a class without adapting or extending the class itself.
			
			@param type: The class you want a to created a singleton from.
			@return The singleton instance of the class.
			@example
				<code>
					var stopwatch:Stopwatch = SingletonUtil.singleton(Stopwatch);
					stopwatch.start();
				</code>
		*/
		public static function singleton<T>(c:Class<T>):T {
			if (SingletonUtil._singletonMap == null)
				SingletonUtil._singletonMap = new Map<String, Dynamic>();
			
			var name = Type.getClassName(c);
			
			if (!SingletonUtil._singletonMap.exists(name)) {
				var ins = Type.createInstance(c,[]);
				SingletonUtil._singletonMap.set(name,ins);
			}
			return SingletonUtil._singletonMap.get(name);
		}
		
		/**
			Creates a multiton out of a class without adapting or extending the class itself.
			
			@param type: The class you want a to created a multiton from.
			@param id: An unique name per <code>Class</code> <code>type</code>.
			@return The multiton instance of the class.
			@example
				<code>
					var stopwatch:Stopwatch = SingletonUtil.multiton(Stopwatch, "MyUniqueWatchId");
					stopwatch.start();
				</code>
		*/
		public static function multiton<T>(type:Class<T>, id:String):T {
			if (SingletonUtil._multitonMap == null)
				SingletonUtil._multitonMap = new Map<String, Map<String, Dynamic>>();
			
			var typeName = Type.getClassName(type);
			
			if (!SingletonUtil._multitonMap.exists(typeName))
				SingletonUtil._multitonMap.set(typeName, new Map<String, Dynamic>());
			
			if (!SingletonUtil._multitonMap.get(typeName).exists(id))
				SingletonUtil._multitonMap.get(typeName).set(id, Type.createInstance(type, []));
			
			return SingletonUtil._multitonMap.get(typeName).get(id);
		}
	}
