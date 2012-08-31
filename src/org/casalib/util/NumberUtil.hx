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
	import org.casalib.math.Percent;
	import org.casalib.core.UInt;
	
	/**
		Provides utility functions for manipulating numbers.
		
		@author Aaron Clinger
		@author David Nelson
		@author Mike Creighton
		@version 05/19/11
	*/
	class NumberUtil  {
		/**
			Determines if the two values are equal, with the option to define the precision.
			
			@param val1: A value to compare.
			@param val2: A value to compare.
			@param precision: The maximum amount the two values can differ and still be considered equal.
			@return Returns <code>true</code> the values are equal; otherwise <code>false</code>.
			@example
				<code>
					trace(NumberUtil.isEqual(3.042, 3, 0)); // Traces false
					trace(NumberUtil.isEqual(3.042, 3, 0.5)); // Traces true
				</code>
		*/
		inline public static function isEqual(val1:Float, val2:Float, ?precision:Float = 0):Bool {
			return Math.abs(val1 - val2) <= Math.abs(precision);
		}
		
		/**
			Evaluates <code>val1</code> and <code>val2</code> and returns the smaller value. Unlike <code>Math.min</code> this method will return the defined value if the other value is <code>null</code> or not a number.
			
			@param val1: A value to compare.
			@param val2: A value to compare.
			@return Returns the smallest value, or the value out of the two that is defined and valid.
			@example
				<code>
					trace(NumberUtil.min(5, null)); // Traces 5
					trace(NumberUtil.min(5, "CASA")); // Traces 5
					trace(NumberUtil.min(5, 13)); // Traces 5
				</code>
		*/
		@:noUsing
		public static function min(val1:Dynamic, val2:Dynamic):Float {
			if (val1 == Math.NaN && val2 == Math.NaN || val1 == null && val2 == null)
				return Math.NaN;
			
			if (val1 == null || val2 == null)
				return (val2 == null) ? val1 : val2;
			
			if (val1 == Math.NaN || val2 == Math.NaN)
				return val2 == Math.NaN ? val1 : val2;
				
			if (!Std.is(val1,Float) || !Std.is(val2,Float))
				return Std.is(val1,Float) ? val1 : val2;
			
			return Math.min(val1, val2);
		}
		
		/**
			Evaluates <code>val1</code> and <code>val2</code> and returns the larger value. Unlike <code>Math.max</code> this method will return the defined value if the other value is <code>null</code> or not a number.
			
			@param val1: A value to compare.
			@param val2: A value to compare.
			@return Returns the largest value, or the value out of the two that is defined and valid.
			@example
				<code>
					trace(NumberUtil.max(-5, null)); // Traces -5
					trace(NumberUtil.max(-5, "CASA")); // Traces -5
					trace(NumberUtil.max(-5, -13)); // Traces -5
				</code>
		*/
		@:noUsing
		public static function max(val1:Dynamic, val2:Dynamic):Float {
			if (val1 == Math.NaN && val2 == Math.NaN || val1 == null && val2 == null)
				return Math.NaN;
			
			if (val1 == null || val2 == null)
				return (val2 == null) ? val1 : val2;
			
			if (val1 == Math.NaN || val2 == Math.NaN)
				return (val2 == Math.NaN) ? val1 : val2;
				
			if (!Std.is(val1,Float) || !Std.is(val2,Float))
				return Std.is(val1,Float) ? val1 : val2;
			
			return Math.max(val1, val2);
		}
		
		/**
			Creates a random number within the defined range.
			
			@param min: The minimum value the random number can be.
			@param min: The maximum value the random number can be.
			@return Returns a random number within the range.
		*/
		inline public static function randomWithinRange(min:Float, max:Float):Float {
			return min + (Math.random() * (max - min));
		}
		
		/**
			Creates a random integer within the defined range.
			
			@param min: The minimum value the random integer can be.
			@param min: The maximum value the random integer can be.
			@return Returns a random integer within the range.
		*/
		inline public static function randomIntegerWithinRange(min:Int, max:Int):Int {
			return Math.floor(Math.random() * (1 + max - min) + min);
		}
		
		/**
			Determines if the number is even.
			
			@param value: A number to determine if it is divisible by <code>2</code>.
			@return Returns <code>true</code> if the number is even; otherwise <code>false</code>.
			@example
				<code>
					trace(NumberUtil.isEven(7)); // Traces false
					trace(NumberUtil.isEven(12)); // Traces true
				</code>
		*/
		inline public static function isEven(value:Int):Bool {
			return (value & 1) == 0;
		}
		
		/**
			Determines if the number is odd.
			
			@param value: A number to determine if it is not divisible by <code>2</code>.
			@return Returns <code>true</code> if the number is odd; otherwise <code>false</code>.
			@example
				<code>
					trace(NumberUtil.isOdd(7)); // Traces true
					trace(NumberUtil.isOdd(12)); // Traces false
				</code>
		*/
		inline public static function isOdd(value:Int):Bool {
			return (value & 1) != 0;
		}
		
		/**
			Determines if the number is an integer.
			
			@param value: A number to determine if it contains no decimal values.
			@return Returns <code>true</code> if the number is an integer; otherwise <code>false</code>.
			@example
				<code>
					trace(NumberUtil.isInteger(13)); // Traces true
					trace(NumberUtil.isInteger(1.2345)); // Traces false
				</code>
		*/
		inline public static function isInteger(value:Float):Bool {
			#if php
			return value - Math.round(value) == 0;
			#else
			return (value % 1) == 0;
			#end
		}
		
		/**
			Determines if the number is prime.
			
			@param value: A number to determine if it is only divisible by <code>1</code> and itself.
			@return Returns <code>true</code> if the number is prime; otherwise <code>false</code>.
			@example
				<code>
					trace(NumberUtil.isPrime(13)); // Traces true
					trace(NumberUtil.isPrime(4)); // Traces false
				</code>
		*/
		public static function isPrime(value:Int):Bool {
			if (value == 1 || value == 2)
				return true;
			
			if (NumberUtil.isEven(value))
				return false;
			
			var s:Float = Math.sqrt(value);
			for (i in 3...Std.int(s))
				if (value % i == 0)
					return false;
			
			return true;
		}
		
		/**
			Rounds a number's decimal value to a specific place.
			
			@param value: The number to round.
			@param place: The decimal place to round.
			@return Returns the value rounded to the defined place. 
			@example
				<code>
					trace(NumberUtil.roundToPlace(3.14159, 2)); // Traces 3.14
					trace(NumberUtil.roundToPlace(3.14159, 3)); // Traces 3.142
				</code>
		*/
		inline public static function roundDecimalToPlace(value:Float, place:Float):Float {
			var p:Float = Math.pow(10, place);
			
			return Math.round(value * p) / p;
		}
		
		/**
			Determines if index is included within the collection length otherwise the index loops to the beginning or end of the range and continues.
			
			@param index: Index to loop if needed.
			@param length: The total elements in the collection.
			@return A valid zero-based index.
			@example
				<code>
					var colors:Array = new Array("Red", "Green", "Blue");
					
					trace(colors[NumberUtil.loopIndex(2, colors.length)]); // Traces Blue
					trace(colors[NumberUtil.loopIndex(4, colors.length)]); // Traces Green
					trace(colors[NumberUtil.loopIndex(-6, colors.length)]); // Traces Red
				</code>
		*/
		inline public static function loopIndex(index:Int, length:UInt):UInt {
			if (index < 0)
				index = length + index % length;
			
			if (index >= untyped length)
				index %= length;
			
			return index;
		}
		
		/**
			Determines if the value is included within a range.
			
			@param value: Number to determine if it is included in the range.
			@param firstValue: First value of the range.
			@param secondValue: Second value of the range.
			@return Returns <code>true</code> if the number falls within the range; otherwise <code>false</code>.
			@usageNote The range values do not need to be in order.
			@example
				<code>
					trace(NumberUtil.isBetween(3, 0, 5)); // Traces true
					trace(NumberUtil.isBetween(7, 0, 5)); // Traces false
				</code>
		*/
		inline public static function isBetween(value:Float, firstValue:Float, secondValue:Float):Bool {
			return !(value < Math.min(firstValue, secondValue) || value > Math.max(firstValue, secondValue));
		}
		
		/**
			Determines if value falls within a range; if not it is snapped to the nearest range value.
			
			@param value: Number to determine if it is included in the range.
			@param firstValue: First value of the range.
			@param secondValue: Second value of the range.
			@return Returns either the number as passed, or its value once snapped to nearest range value.
			@usageNote The constraint values do not need to be in order.
			@example
				<code>
					trace(NumberUtil.constrain(3, 0, 5)); // Traces 3
					trace(NumberUtil.constrain(7, 0, 5)); // Traces 5
				</code>
		*/
		inline public static function constrain(value:Float, firstValue:Float, secondValue:Float):Float {
			return Math.min(Math.max(value, Math.min(firstValue, secondValue)), Math.max(firstValue, secondValue));
		}
		
		/**
			Creates evenly spaced numerical increments between two numbers.
			
			@param begin: The starting value.
			@param end: The ending value.
			@param steps: The number of increments between the starting and ending values.
			@return Returns an Array comprised of the increments between the two values.
			@example
				<code>
					trace(NumberUtil.createStepsBetween(0, 5, 4)); // Traces 1,2,3,4
					trace(NumberUtil.createStepsBetween(1, 3, 3)); // Traces 1.5,2,2.5
				</code>
		*/
		inline public static function createStepsBetween(begin:Float, end:Float, steps:Float):Array<Float> {
			steps++;
			
			var i:UInt = 0;
			var stepsBetween = new Array<Float>();
			var increment:Float = (end - begin) / steps;
			
			while (++i < steps)
				stepsBetween.push((i * increment) + begin);
			
			return stepsBetween;
		}
		
		/**
			Determines a value between two specified values.
			
			@param amount: The level of interpolation between the two values. If <code>0%</code>, <code>begin</code> value is returned; if <code>100%</code>, <code>end</code> value is returned.
			@param begin: The starting value.
			@param end: The ending value.
			@example
				<code>
					trace(NumberUtil.interpolate(new Percent(0.5), 0, 10)); // Traces 5
				</code>
		*/
		inline public static function interpolate(amount:Percent, begin:Float, end:Float):Float {
			return begin + (end - begin) * amount.decimalPercentage;
		}
		
		/**
			Determines a percentage of a value in a given range.
			
			@param value: The value to be converted.
			@param minimum: The lower value of the range.
			@param maximum: The upper value of the range.
			@example
				<code>
					trace(NumberUtil.normalize(8, 4, 20).decimalPercentage); // Traces 0.25
				</code>
		*/
		public static function normalize(value:Float, minimum:Float, maximum:Float):Percent {
			return new Percent((value - minimum) / (maximum - minimum));
		}
		
		/**
			Maps a value from one coordinate space to another.
			
			@param value: Value from the input coordinate space to map to the output coordinate space.
			@param min1: Starting value of the input coordinate space.
			@param max1: Ending value of the input coordinate space.
			@param min2: Starting value of the output coordinate space.
			@param max2: Ending value of the output coordinate space.
			@example
				<code>
					trace(NumberUtil.map(0.75, 0, 1, 0, 100)); // Traces 75
				</code>
		*/
		inline public static function map(value:Float, min1:Float, max1:Float, min2:Float, max2:Float):Float {
			return min2 + (max2 - min2) * ((value - min1) / (max1 - min1));
		}
		
		/**
			Low pass filter alogrithm for easing a value toward a destination value. Works best for tweening values when no definite time duration exists and when the destination value changes.
			
			If <code>(0.5 < n < 1)</code>, then the resulting values will overshoot (ping-pong) until they reach the destination value. When <code>n</code> is greater than 1, as its value increases, the time it takes to reach the destination also increases. A pleasing value for <code>n</code> is 5.
			
			@param value: The current value.
			@param dest: The destination value.
			@param n: The slowdown factor.
			@return The weighted average.
		*/
		inline public static function getWeightedAverage(value:Float, dest:Float, n:Float):Float {
			return value + (dest - value) / n;
		}
		
		/**
			Formats a number as a string.
			
			@param value: The number you wish to format.
			@param kDelim: The character used to seperate thousands; defaults to <code>""</code>.
			@param minLength: The minimum length of the number; defaults to <code>0 </code>.
			@param fillChar: The leading character used to make the number the minimum length; defaults to <code>"0"</code>.
			@return Returns the formatted number as a String.
			@example
				<code>
					trace(NumberUtil.format(1234567, 8, ",", 8)); // Traces 01,234,567
				</code>
		*/
		public static function format(value:Float, kDelim:String = ",", minLength:UInt = 0, fillChar:String = "0"):String {
			var remainder:Float  = value % 1;
			var num:String       = Std.string(Math.floor(value));
			var len:UInt         = num.length;
			
			if (minLength != 0 && minLength > len) {
				minLength -= len;
				
				var addChar:String = fillChar == "" ? '0' : fillChar;
				
				while (minLength-- > 0)
					num = addChar + num;
			}
			
			if (kDelim != null && num.length > 3) {
				var totalDelim  = Math.floor(num.length / 3);
				var totalRemain = num.length % 3;
				var numSplit:Array<String> = num.split('');
				var i:Int                  = -1;
				
				while (++i < totalDelim)
					numSplit.insert(totalRemain + (4 * i), kDelim);
				
				if (totalRemain == 0)
					numSplit.shift();
				
				num = numSplit.join('');
			}
			
			if (remainder != 0)
				num += Std.string(remainder).substr(1);
			
			return num;
		}
		
		/**
		 * Stole from polygonal(https://github.com/polygonal) ;p
		 * Fast integer exponentiation for base <code>a</code> and exponent <code>n</code>.
		 */
		inline public static function exp(a:Int, n:Int):Int
		{
			var t = 1;
			var r = 0;
			while (true)
			{
				if (n & 1 != 0) t = a * t;
				n >>= 1;
				if (n == 0)
				{
					r = t;
					break;
				}
				else
					a *= a;
			}
			return r;
		}
			
		/**
		 * Stole from polygonal(https://github.com/polygonal) ;p
		 * Returns a string representation of the number <code>x</code> in fixed-point notation.
		 * @param decimalPlaces the number of decimal places.
		 */
		public static function toFixed(x:Float, decimalPlaces:Int):String
		{
			if (Math.isNaN(x))
				return 'NaN';
			else
			{
				var t = exp(10, decimalPlaces);
				var s = Std.string(Std.int(x * t) / t);
				var i = s.indexOf('.');
				if (i != -1)
				{
					for (i in s.substr(i + 1).length...decimalPlaces)
						s += '0';
				}
				else
				{
					s += '.';
					for (i in 0...decimalPlaces)
						s += '0';
				}
				return s;
			}
		}
		
		/**
			Formats a number as a currency string.
			
			@param value: The number you wish to format.
			@param forceDecimals: If the number should always have two decimal places <code>true</code>, or only show decimals is there is a decimals value <code>false</code>; defaults to <code>true</code>.
			@param kDelim: The character used to seperate thousands; defaults to <code>","</code>.
			@return Returns the formatted number as a String.
			@example
				<code>
					trace(NumberUtil.formatCurrency(1234.5)); // Traces "1,234.50"
				</code>
		*/
		public static function formatCurrency(value:Float, forceDecimals:Bool = true, kDelim:String = ","):String {
			var remainder = value % 1;
			var currency:String = NumberUtil.format(Math.floor(value), kDelim);
			
			if (remainder != 0 || forceDecimals)
				currency += toFixed(remainder, 2).substr(1);
			
			return currency;
		} 
		
		/**
			Finds the english ordinal suffix for the number given.
			
			@param value: Number to find the ordinal suffix of.
			@return Returns the suffix for the number, 2 characters.
			@example
				<code>
					trace(32 + NumberUtil.getOrdinalSuffix(32)); // Traces 32nd
				</code>
		*/
		public static function getOrdinalSuffix(value:Int):String {
			if (value >= 10 && value <= 20)
				return 'th';
				
			if (value == 0)
				return '';
			
			switch (value % 10) {
				case 3 :
					return 'rd';
				case 2 :
					return 'nd';
				case 1 :
					return 'st';
				default :
					return 'th';
			}
		}
		
		/**
			Adds a leading zero for numbers less than ten.
			
			@param value: Number to add leading zero.
			@return Number as a String; if the number was less than ten the number will have a leading zero.
			@example
				<code>
					trace(NumberUtil.addLeadingZero(7)); // Traces 07
					trace(NumberUtil.addLeadingZero(11)); // Traces 11
				</code>
		*/
		public static function addLeadingZero(value:Float):String {
			return (value < 10) ? '0' + value : Std.string(value);
		}
		
		/**
			Spells the provided number.
			
			@param value: Number to spell. Needs to be less than 999999999.
			@return The number spelled out as a String.
			@throws <code>Error</code> if <code>value</code> is greater than 999999999.
			@example
				<code>
					trace(NumberUtil.spell(0)); // Traces Zero
					trace(NumberUtil.spell(23)); // Traces Twenty-Three
					trace(NumberUtil.spell(2005678)); // Traces Two Million, Five Thousand, Six Hundred Seventy-Eight
				</code>
		*/
		public static function spell(value:UInt):String {
			if (value > 999999999)
				throw 'Value too large for this method.';
			
			var onesSpellings:Array<String> = ['', 'One', 'Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine', 'Ten', 'Eleven', 'Twelve', 'Thirteen', 'Fourteen', 'Fifteen', 'Sixteen', 'Seventeen', 'Eighteen', 'Nineteen'];
			var tensSpellings:Array<String> = ['', '', 'Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety'];
			var spelling:String             = '';
			
			var millions = value / 1000000;
			value       %= 1000000;
			
			var thousands = value / 1000;
			value        %= 1000;
			
			var hundreds = value / 100;
			value       %= 100;
			
			var tens = value / 10;
			value   %= 10;
			
			var ones = value % 10;
			
			if (millions != 0) {
				spelling += (spelling.length == 0) ? '' : ', ';
				spelling += NumberUtil.spell(Std.int(millions)) + ' Million';
			}
			
			if (thousands != 0) {
				spelling += (spelling.length == 0) ? '' : ', ';
				spelling += NumberUtil.spell(Std.int(thousands)) + ' Thousand';
			}
			
			if (hundreds != 0) {
				spelling += (spelling.length == 0) ? '' : ', ';
				spelling += NumberUtil.spell(Std.int(hundreds)) + ' Hundred';
			}
			
			if (tens != 0 || ones != 0) {
				spelling += (spelling.length == 0) ? '' : ' ';
				
				if (tens < 2)
					spelling += onesSpellings[Std.int(tens * 10 + ones)];
				else {
					spelling += tensSpellings[Std.int(tens)];
					
					if (ones != 0)
						spelling += '-' + onesSpellings[ones];
				}
			}
			
			if (spelling.length == 0)
				return 'Zero';
			
			return spelling;
		}

	}
