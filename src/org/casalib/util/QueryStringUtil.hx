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
		Utility for providing easy access to the browser query string.
		
		@author Aaron Clinger
		@version 03/28/10
	*/
	class QueryStringUtil  {
		
		public static var queryString(get_queryString, null) : String ;
		private static var _query:String;
		private static var _hasRequested:Bool;
		private static var _pairMap:Map<String, Dynamic>;
		
		/**
			The field/value pairs of the browser URL.
		*/
		private static function get_queryString():String {
			if (!QueryStringUtil._hasRequested) {
				QueryStringUtil._hasRequested = true;
				
				var query:String = null;
				#if flash
				if (flash.external.ExternalInterface.available){
					try {
						query = LocationUtil.isWeb(flash.Lib.current) ? flash.external.ExternalInterface.call('document.location.search.toString') : null;
					} catch (e:Dynamic){}
				}
				#elseif js
				query = js.Browser.window.location.search;
				#elseif neko
				query = neko.Web.getParamsString();
				#elseif php
				query = php.Web.getParamsString();
				#end
				
				if (query != null && query != '') {
					QueryStringUtil._query = query.charAt(0) == '?' ? query.substr(1) : query;
					
					var pairs:Array<String> = QueryStringUtil._query.split('&');
					var i:Int = -1;
					var pair:Array<String>;
					
					QueryStringUtil._pairMap = new Map<String, String>();
					
					while (++i < pairs.length) {
						pair = pairs[i].split('=');
						
						QueryStringUtil._pairMap.set(pair[0],pair[1]);
					}
				}
			}
			
			return QueryStringUtil._query;
		}
		
		/**
			Returns a query string value by key.
			
			@param key: The key of the query string value to retrieve.
			@return The string value of the key.
		*/
		public static function getValue(key:String):String {
			if (QueryStringUtil.queryString == null)
				return null;
			
			return QueryStringUtil._pairMap.get(key);
		}
		
		/**
			Checks to if query string key exists.
			
			@param key: The name of the key to check for existence.
			@return Returns <code>true</code> if the key exists; otherwise <code>false</code>.
		*/
		public static function hasKey(key:String):Bool {
			return QueryStringUtil.getValue(key) != null;
		}
	}
