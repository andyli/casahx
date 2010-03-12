/*	CASA Lib for ActionScript 3.0	Copyright (c) 2009, Aaron Clinger & Contributors of CASA Lib	All rights reserved.		Redistribution and use in source and binary forms, with or without	modification, are permitted provided that the following conditions are met:		- Redistributions of source code must retain the above copyright notice,	  this list of conditions and the following disclaimer.		- Redistributions in binary form must reproduce the above copyright notice,	  this list of conditions and the following disclaimer in the documentation	  and/or other materials provided with the distribution.		- Neither the name of the CASA Lib nor the names of its contributors	  may be used to endorse or promote products derived from this software	  without specific prior written permission.		THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"	AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE	IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE	ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE	LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR	CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF	SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS	INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN	CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)	ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE	POSSIBILITY OF SUCH DAMAGE.*/package org.casalib.util; 
	import org.casalib.core.UInt;	import org.casalib.util.NumberUtil;			/**		Utilities for sorting, searching and manipulating Arrays.				@author Aaron Clinger		@author David Nelson		@author Jon Adams		@version 08/05/09	*/	class ArrayUtil  {
	
		/**
			Searches for an item in an array and returns the index position of the item.
		*/
		public static function indexOf(inArray:Array<Dynamic>, match:Dynamic, ?fromIndex:Int = 0):Int {
			var i = fromIndex-1;
			while (++i < inArray.length) {
				if (inArray[i] == match) return i;
			}
			return -1;
		}
		
		/**
			Searches for an item in an array, working backward from the last item, and returns the index position of the matching item.
		*/
		public static function lastIndexOf(inArray:Array<Dynamic>, match:Dynamic, ?fromIndex:UInt):Int {
			var i:UInt;
			if (fromIndex == null) {
				i = inArray.length;
			} else {
				i = Math.round(Math.min(inArray.length,fromIndex+1));
			}
			
			while (--i > 0) {
				if (inArray[i] == match) return i;
			}
			return -1;
		}
		
		/**
			Executes a test function on each item in the array and constructs a new array for all items that return true for the specified function. If an item returns false, it is not included in the new array.
			
		*/
		inline public static function filter<T>(inArray:Array<T>, callBack:Dynamic):Array<T> {
			var newArray = [];
			var iter = new IntIter(0,inArray.length);
			for (i in iter) {
				if (callBack(inArray[i],i,inArray)) {
					newArray.push(inArray[i]);
				}
			}
			return newArray;
		}
		
		/**
			http://livedocs.adobe.com/flex/3/langref/Array.html#sortOn()
			
			Options are:
				ArrayUtil.SORT_CASEINSENSITIVE
				ArrayUtil.SORT_DESCENDING
				ArrayUtil.SORT_UNIQUESORT
				ArrayUtil.SORT_RETURNINDEXEDARRAY
				ArrayUtil.SORT_NUMERIC
			For fieldNames, it must be a Array. Even if you use only single field, you need to put it into an Array.
			When using SORT_RETURNINDEXEDARRAY and two elements are the same, instead of return 0, it returns [];
		*/
		inline public static function sortOn(inArray:Array<Dynamic>, fieldNames:Array<String>, ?options:Int = 0):Array<Dynamic> {
			#if flash
			
			var result:Dynamic = untyped inArray.sortOn(fieldNames, options);
			return Std.is(result,Array) ? result : [];
			
			#else
			
			var result:Array<Dynamic> = [];
			if (inArray.length != 0) {
				var oNumeric = options >> 4 & 1 == 1;
				var oReturnindexedarray = options >> 3 & 1 == 1;
				var oUniquesort = options >> 2 & 1 == 1;
				var oDescending = options >> 1 & 1 == 1;
				var oCaseinsensitive = options & 1 == 1;
				
				var hasDup = false;
				if (oUniquesort) {
					var testCase = new Array<Array<Dynamic>>();
					for (i in 0...inArray.length) {
						testCase[i] = new Array<Dynamic>();
						for (f in fieldNames) {
							var fi = Reflect.field(inArray[i],f);
							var isString = !(Std.is(fi,Float) || Std.is(fi,Int));
							var ele = (oCaseinsensitive && isString) ? Std.string(fi).toLowerCase() : inArray[i];
							testCase[i].push(ele);
						}
					}
					var removedDup = ArrayUtil.removeDuplicates2(testCase);
					if (removedDup.length != testCase.length) hasDup = true;
				}
				if (!hasDup){
					var sortArray = oReturnindexedarray ? inArray.copy() : inArray;
					sortArray.sort(getSortingFunction(oNumeric, oReturnindexedarray, oUniquesort, oDescending, oCaseinsensitive,fieldNames));
			
					if (!oReturnindexedarray) {
						result = sortArray;
					} else {
						var usedArray = new Array<Bool>();
						for (e in inArray){
							usedArray.push(false);
						}
						for (e in inArray){
							var index = 0;
							do {
								index = ArrayUtil.indexOf(sortArray,e,index);
							} while ((index < usedArray.length) && (usedArray[index] == true));
							usedArray[index] = true;
					
							result.push(index);
						}
					}
				}
			}
			return result;
			#end
		}
		
		public static function getSortingFunction(oNumeric:Bool, oReturnindexedarray:Bool, oUniquesort:Bool, oDescending:Bool, oCaseinsensitive:Bool, fieldNames:Array<String>):Dynamic {
			return function (a,b):Int {
						var r = 0;
						for (f in fieldNames){
							var af:Dynamic = Reflect.field(a,f);
							var bf:Dynamic = Reflect.field(b,f);
						
							if (!oNumeric){
								if (Std.is(af,Float) || Std.is(af,Int)) {
									af = Std.string(af);
								}
								if (Std.is(bf,Float) || Std.is(bf,Int)) {
									bf = Std.string(bf);
								}
							}
						
							if (oCaseinsensitive) {
								if (Std.is(af,String)) {
									af = af.toLowerCase();
								}
								if (Std.is(bf,String)) {
									bf = bf.toLowerCase();
								}
							}
							
							if (af != bf){
								if (!oDescending) {
									if (!oNumeric){
										r = strcmp(af,bf) > 0 ? 1 : -1;
									} else {
										r = af>bf ? 1 : -1;
									}
								} else {
									if (!oNumeric){
										r = strcmp(af,bf) < 0 ? 1 : -1;
									} else {
										r = af<bf ? 1 : -1;
									}
								}
							}
						}
						return r;
					}
		}
		
		inline public static var SORT_CASEINSENSITIVE(_CASEINSENSITIVE,null):Int;
		inline public static var SORT_DESCENDING(_DESCENDING,null):Int;
		inline public static var SORT_UNIQUESORT(_UNIQUESORT,null):Int;
		inline public static var SORT_RETURNINDEXEDARRAY(_RETURNINDEXEDARRAY,null):Int;
		inline public static var SORT_NUMERIC(_NUMERIC,null):Int;
		
		inline private static function _CASEINSENSITIVE():Int {
			return 1;
		}
		
		inline private static function _DESCENDING():Int {
			return 2;
		}
		
		inline private static function _UNIQUESORT():Int {
			return 4;
		}
		
		inline private static function _RETURNINDEXEDARRAY():Int {
			return 8;
		}
		
		inline private static function _NUMERIC():Int {
			return 16;
		}
		
		private static function strcmp(s0:String,s1:String):Float {
			var r:Float = s0.length-s1.length;
			for (i in 0...Math.floor(Math.min(s0.length,s1.length))){
				if (s0.charAt(i) != s1.charAt(i)) {
					#if!php
					r = s0.charCodeAt(i) - s1.charCodeAt(i);
					#else
					var c0 = s0.charAt(i);
					var c1 = s1.charAt(i);
					r = untyped __php__("ord($c0)-ord($c1)");
					#end
					break;
				}
			}
			return r;
		}
		
		inline private static function removeDuplicates2<T>(inArray:Array<Array<T>>):Array<Array<T>> {
			var i = 0;
			var cp = inArray.copy();
			var outArray:Array<Array<T>> = inArray.copy();
			for (i in cp){
				for (j in 1...ArrayUtil.contains2(outArray,i)){
					outArray.remove(i);
				}
			}
			return outArray;		}
		
		private static function contains2<T>(inArray:Array<Array<T>>, item:Array<T>):UInt {			var i:Int  = indexOf(inArray, item, 0);			var t:UInt = 0;						while (i != -1) {				i = indexOf2(inArray, item, i + 1);				t++;			}						return t;		}
		
		private static function indexOf2<T>(inArray:Array<Array<T>>, match:Array<T>, ?fromIndex:Int = 0):Int {
			var i = fromIndex-1;
			while (++i < inArray.length) {
				if (ArrayUtil.equals(inArray[i],match)) return i;
			}
			return -1;
		}
				/**			Returns the first element that matches <code>match</code> for the property <code>key</code>.						@param inArray: Array to search for an element with a <code>key</code> that matches <code>match</code>.			@param key: Name of the property to match.			@param match: Value to match against.			@return Returns matched <code>Object</code>; otherwise <code>null</code>.		*/		public static function getItemByKey<T>(inArray:Array<T>, key:String, match:Dynamic):T {			for (item in inArray){
				var value = Reflect.field(item,key);				if (value == match)					return item;
			}						return null;		}				/**			Returns every element that matches <code>match</code> for the property <code>key</code>.						@param inArray: Array to search for object with <code>key</code> that matches <code>match</code>.			@param key: Name of the property to match.			@param match: Value to match against.			@return Returns all the matched elements.		*/		inline public static function getItemsByKey<T>(inArray:Array<T>, key:String, match:Dynamic):Array<T> {			var t:Array<T> = new Array<T>();						for (item in inArray) {
				var value = Reflect.field(item,key);
				if (value == match)					t.push(item);
			}						return t;		}				/**			Returns the first element that is compatible with a specific data type, class, or interface.						@param inArray: Array to search for an element of a specific type.			@param type: The type to compare the elements to.			@return Returns all the matched elements.		*/		public static function getItemByType<T>(inArray:Array<Dynamic>, type:Class<T>):T {			for (item in inArray)				if (Std.is( item, type))					return item;						return null;		}				/**			Returns every element that is compatible with a specific data type, class, or interface.						@param inArray: Array to search for elements of a specific type.			@param type: The type to compare the elements to.			@return Returns all the matched elements.		*/		inline public static function getItemsByType<T>(inArray:Array<Dynamic>, type:Class<T>):Array<T> {			var t:Array<T> = new Array();						for (item in inArray)				if (Std.is( item, type))					t.push(item);						return t;		}				/**			Determines if two Arrays contain the same objects at the same index.						@param first: First Array to compare to the <code>second</code>.			@param second: Second Array to compare to the <code>first</code>.			@return Returns <code>true</code> if Arrays are the same; otherwise <code>false</code>.		*/		inline public static function equals<T>(first:Array<T>, second:Array<T>):Bool {			var i:UInt = first.length;
			var result:Bool = true;
						if (i != second.length) {
				result = false;
			} else {
				while (i-- > 0) {
					if (first[i] != second[i]) {
						result = false;
						break;
					}
				}
			}
			
			return result;		}				/**			Modifies original Array by adding all the elements from another Array at a specified position.						@param tarArray: Array to add elements to.			@param items: Array of elements to add.			@param index: Position where the elements should be added.			@return Returns <code>true</code> if the Array was changed as a result of the call; otherwise <code>false</code>.			@example				<code>					var alphabet:Array = new Array("a", "d", "e");					var parts:Array    = new Array("b", "c");										ArrayUtil.addItemsAt(alphabet, parts, 1);										trace(alphabet);				</code>		*/		inline public static function addItemsAt<T>(tarArray:Array<T>, items:Array<T>, ?index:Int = 0x7FFFFFFF):Bool {
					if (items.length == 0) {
				return false;
			} else {
				var i = -1;
				while (++i<items.length) {
					tarArray.insert(index++,items[i]);
				}
							return true;
			}		}				/**			Creates new Array composed of only the non-identical elements of passed Array.						@param inArray: Array to remove equivalent items.			@return A new Array composed of only unique elements.			@example				<code>					var numberArray:Array = new Array(1, 2, 3, 4, 4, 4, 4, 5);					trace(ArrayUtil.removeDuplicates(numberArray));				</code>		*/		inline public static function removeDuplicates<T>(inArray:Array<T>):Array<T> {
			var i = 0;
			var cp = inArray.copy();
			var outArray = inArray.copy();
			for (i in cp){
				for (j in 1...ArrayUtil.contains(outArray,i)){
					outArray.remove(i);
				}
			}
			return outArray;		}				/**			Modifies original Array by removing all items that are identical to the specified item.						@param tarArray: Array to remove passed <code>item</code>.			@param item: Element to remove.			@return The amount of removed elements that matched <code>item</code>, if none found returns <code>0</code>.			@example				<code>					var numberArray:Array = new Array(1, 2, 3, 7, 7, 7, 4, 5);					trace("Removed " + ArrayUtil.removeItem(numberArray, 7) + " items.");					trace(numberArray);				</code>		*/		inline public static function removeItem<T>(tarArray:Array<T>, item:T):UInt {			var i:Int  = indexOf(tarArray, item);			var f:UInt = 0;						while (i != -1) {				tarArray.splice(i, 1);								i = indexOf(tarArray, item, i);								f++;			}						return f;		}				/**			Removes only the specified items in an Array.						@param tarArray: Array to remove specified items from.			@param items: Array of elements to remove.			@return Returns <code>true</code> if the Array was changed as a result of the call; otherwise <code>false</code>.			@example				<code>					var numberArray:Array = new Array(1, 2, 3, 7, 7, 7, 4, 5);					ArrayUtil.removeItems(numberArray, new Array(1, 3, 7, 5));					trace(numberArray);				</code>		*/		inline public static function removeItems<T>(tarArray:Array<T>, items:Array<T>):Bool {			var removed:Bool = false;			var l:UInt = tarArray.length;						while (l-- > 0) {				if (indexOf(items, tarArray[l]) > -1) {					tarArray.splice(l, 1);					removed = true;				}			}
						return removed;		}				/**			Retains only the specified items in an Array.						@param tarArray: Array to remove non specified items from.			@param items: Array of elements to keep.			@return Returns <code>true</code> if the Array was changed as a result of the call; otherwise <code>false</code>.			@example				<code>					var numberArray:Array = new Array(1, 2, 3, 7, 7, 7, 4, 5);					ArrayUtil.retainItems(numberArray, new Array(2, 4));					trace(numberArray);				</code>		*/		inline public static function retainItems<T>(tarArray:Array<T>, items:Array<T>):Bool {			var removed:Bool = false;			var l:UInt = tarArray.length;						while (l-- > 0) {				if (indexOf(items,tarArray[l]) == -1) {					tarArray.splice(l, 1);					removed = true;				}			}						return removed;		}				/**			Finds out how many instances of <code>item</code> Array contains.						@param inArray: Array to search for <code>item</code> in.			@param item: Object to find.			@return The amount of <code>item</code>'s found; if none were found returns <code>0</code>.			@example				<code>					var numberArray:Array = new Array(1, 2, 3, 7, 7, 7, 4, 5);					trace("numberArray contains " + ArrayUtil.contains(numberArray, 7) + " 7's.");				</code>		*/		public static function contains<T>(inArray:Array<T>, item:T):UInt {			var i:Int  = indexOf(inArray, item, 0);			var t:UInt = 0;						while (i != -1) {				i = indexOf(inArray, item, i + 1);				t++;			}						return t;		}				/**			Determines if Array contains all items.						@param inArray: Array to search for <code>items</code> in.			@param items: Array of elements to search for.			@return Returns <code>true</code> if <code>inArray</code> contains all elements of <code>items</code>; otherwise <code>false</code>.			@example				<code>					var numberArray:Array = new Array(1, 2, 3, 4, 5);					trace(ArrayUtil.containsAll(numberArray, new Array(1, 3, 5)));				</code>		*/		public static function containsAll<T>(inArray:Array<T>, items:Array<T>):Bool {			var l:UInt = items.length;						while (l-- > 0)				if (indexOf(inArray, items[l]) == -1)					return false;						return true;		}				/**			Determines if Array <code>inArray</code> contains any element of Array <code>items</code>.						@param inArray: Array to search for <code>items</code> in.			@param items: Array of elements to search for.			@return Returns <code>true</code> if <code>inArray</code> contains any element of <code>items</code>; otherwise <code>false</code>.			@example				<code>					var numberArray:Array = new Array(1, 2, 3, 4, 5);					trace(ArrayUtil.containsAny(numberArray, new Array(9, 3, 6)));				</code>		*/		public static function containsAny<T>(inArray:Array<T>, items:Array<T>):Bool {			var l:UInt = items.length;						while (l-- > 0)				if (indexOf(inArray, items[l]) > -1)					return true;						return false;		}				/**			Compares two Arrays and finds the first index where they differ.						@param first: First Array to compare to the <code>second</code>.			@param second: Second Array to compare to the <code>first</code>.			@param fromIndex: The location in the Arrays from which to start searching for a difference.			@return The first position/index where the Arrays differ; if Arrays are identical returns <code>-1</code>.			@example				<code>					var color:Array     = new Array("Red", "Blue", "Green", "Indigo", "Violet");					var colorsAlt:Array = new Array("Red", "Blue", "Green", "Violet");										trace(ArrayUtil.getIndexOfDifference(color, colorsAlt)); // Traces 3				</code>		*/		public static function getIndexOfDifference<T>(first:Array<T>, second:Array<T>, ?fromIndex:UInt = 0):Int {			var i:UInt = fromIndex - 1;						while (++i < first.length)				if (first[i] != second[i])					return i;						return -1;		}				/**			Creates new Array composed of passed Array's items in a random order.						@param inArray: Array to create copy of, and randomize.			@return A new Array composed of passed Array's items in a random order.			@example				<code>					var numberArray:Array = new Array(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);					trace(ArrayUtil.randomize(numberArray));				</code>		*/		public static function randomize<T>(inArray:Array<T>):Array<T> {			var t:Array<T>  = new Array<T>();
			var c:Array<T> = inArray.copy();						while (c.length > 0)				t.push(c.splice(NumberUtil.randomIntegerWithinRange(0,c.length-1),1)[0]);						return t;		}				/**			Adds all items in <code>inArray</code> and returns the value.						@param inArray: Array composed only of numbers.			@return The total of all numbers in <code>inArray</code> added.			@example				<code>					var numberArray:Array = new Array(2, 3);					trace("Total is: " + ArrayUtil.sum(numberArray));				</code>		*/		public static function sum(inArray:Array<Dynamic>):Float {			var t:Float = 0;			var l:UInt = inArray.length;						while (l-- > 0)				t += inArray[l];						return t;		}				/**			Averages the values in <code>inArray</code>.						@param inArray: Array composed only of numbers.			@return The average of all numbers in the <code>inArray</code>.			@example				<code>					var numberArray:Array = new Array(2, 3, 8, 3);					trace("Average is: " + ArrayUtil.average(numberArray));				</code>		*/		public static function average(inArray:Array<Dynamic>):Float {			if (inArray.length == 0)				return 0;						return ArrayUtil.sum(inArray) / inArray.length;		}				/**			Finds the lowest value in <code>inArray</code>.						@param inArray: Array composed only of numbers.			@return The lowest value in <code>inArray</code>.			@example				<code>					var numberArray:Array = new Array(2, 1, 5, 4, 3);					trace("The lowest value is: " + ArrayUtil.getLowestValue(numberArray));				</code>		*/		public static function getLowestValue(inArray:Array<Dynamic>):Float {
			var lowest = inArray[0];
			for (i in inArray) {
				lowest = NumberUtil.min(i,lowest);
			}			return lowest;		}				/**			Finds the highest value in <code>inArray</code>.						@param inArray: Array composed only of numbers.			@return The highest value in <code>inArray</code>.			@example				<code>					var numberArray:Array = new Array(2, 1, 5, 4, 3);					trace("The highest value is: " + ArrayUtil.getHighestValue(numberArray));				</code>		*/		public static function getHighestValue(inArray:Array<Dynamic>):Float {			var lowest = inArray[0];
			for (i in inArray) {
				lowest = NumberUtil.max(i,lowest);
			}			return lowest;		}	}
