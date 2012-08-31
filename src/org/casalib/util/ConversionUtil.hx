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
		Utilities for converting units.
		
		@author Aaron Clinger
		@author David Bliss
		@author David Nelson
		@version 03/11/08
	*/
	class ConversionUtil  {
		
		/**
			Converts bits to bytes.
			
			@param bits: The number of bits. 
			@return Returns the number of bytes.
		*/
		inline public static function bitsToBytes(bits:Float):Float {
			return bits / 8;
		}
		
		/**
			Converts bits to kilobits.
			
			@param bits: The number of bits.
			@return Returns the number of kilobits.
		*/
		inline public static function bitsToKilobits(bits:Float):Float {
			return bits / 1024;
		}
		
		/**
			Converts bits to kilobytes.
			
			@param bits: The number of bits. 
			@return Returns the number of kilobits.
		*/
		inline public static function bitsToKilobytes(bits:Float):Float {
			return bits / 8192;
		}
		
		/**
			Converts bytes to bits.
			
			@param bytes: The number of bytes.
			@return Returns the number of bits.
		*/
		inline public static function bytesToBits(bytes:Float):Float {
			return bytes * 8;
		}
		
		/**
			Converts bytes to kilobits.
			
			@param bytes: The number of bytes.
			@return Returns the number of kilobits.
		*/
		inline static function bytesToKilobits(bytes:Float):Float {
			return bytes / 128;
		}
		
		/**
			Converts bytes to kilobytes.
			
			@param bytes: The number of bytes.
			@return Returns the number of kilobytes.
		*/
		inline public static function bytesToKilobytes(bytes:Float):Float {
			return bytes / 1024;
		}
		
		/**
			Converts kilobits to bits.
			
			@param kilobits: The number of kilobits.
			@return Returns the number of bits.
		*/
		inline public static function kilobitsToBits(kilobits:Float):Float {
			return kilobits * 1024;
		}
		
		/**
			Converts kilobits to bytes.
			
			@param kilobits: The number of kilobits.
			@return Returns the number of bytes.
		*/
		inline public static function kilobitsToBytes(kilobits:Float):Float {
			return kilobits * 128;
		}
			
		/**
			Converts kilobits to kilobytes.
			
			@param kilobytes: The number of kilobits.
			@return Returns the number of kilobytes.
		*/
		inline public static function kilobitsToKilobytes(kilobits:Float):Float {
			return kilobits / 8;
		}
		
		/**
			Converts kilobytes to bits.
			
			@param kilobytes: The number of kilobytes.
			@return Returns the number of bits.
		*/
		inline public static function kilobytesToBits(kilobytes:Float):Float {
			return kilobytes * 8192;
		}
		
		/**
			Converts kilobytes to bytes.
			
			@param kilobytes: The number of kilobytes.
			@return Returns the number of bytes.
		*/
		inline public static function kilobytesToBytes(kilobytes:Float):Float {
			return kilobytes * 1024;
		}
		
		/**
			Converts kilobytes to kilobits.
			
			@param kilobytes: The number of kilobytes.
			@return Returns the number of kilobits.
		*/
		inline public static function kilobytesToKilobits(kilobytes:Float):Float {
			return kilobytes * 8;
		}
		
		/**
			Converts milliseconds to seconds.
			
			@param milliseconds: The number of milliseconds.
			@return Returns the number of seconds.
		*/
		inline public static function millisecondsToSeconds(milliseconds:Float):Float {
			return milliseconds / 1000;
		}
		
		/**
			Converts milliseconds to minutes.
			
			@param milliseconds: The number of milliseconds.
			@return Returns the number of minutes.
		*/
		inline public static function millisecondsToMinutes(milliseconds:Float):Float {
			return ConversionUtil.secondsToMinutes(ConversionUtil.millisecondsToSeconds(milliseconds));
		}
		
		/**
			Converts milliseconds to hours.
			
			@param milliseconds: The number of milliseconds.
			@return Returns the number of hours.
		*/
		inline public static function millisecondsToHours(milliseconds:Float):Float {
			return ConversionUtil.minutesToHours(ConversionUtil.millisecondsToMinutes(milliseconds));
		}
		
		/**
			Converts milliseconds to days.
			
			@param milliseconds: The number of milliseconds.
			@return Returns the number of days.
		*/
		inline public static function millisecondsToDays(milliseconds:Float):Float {
			return ConversionUtil.hoursToDays(ConversionUtil.millisecondsToHours(milliseconds));
		}
		
		/**
			Converts seconds to milliseconds.
			
			@param seconds: The number of seconds.
			@return Returns the number of milliseconds.
		*/
		inline public static function secondsToMilliseconds(seconds:Float):Float {
			return seconds * 1000;
		}
		
		/**
			Converts seconds to minutes.
			
			@param seconds: The number of seconds.
			@return Returns the number of minutes.
		*/
		inline public static function secondsToMinutes(seconds:Float):Float {
			return seconds / 60;
		}
		
		/**
			Converts seconds to hours.
			
			@param seconds: The number of seconds.
			@return Returns the number of hours.
		*/
		inline public static function secondsToHours(seconds:Float):Float {
			return ConversionUtil.minutesToHours(ConversionUtil.secondsToMinutes(seconds));
		}
		
		/**
			Converts seconds to days.
			
			@param seconds: The number of seconds.
			@return Returns the number of days.
		*/
		inline public static function secondsToDays(seconds:Float):Float {
			return ConversionUtil.hoursToDays(ConversionUtil.secondsToHours(seconds));
		}
		
		/**
			Converts minutes to milliseconds.
			
			@param minutes: The number of minutes.
			@return Returns the number of milliseconds.
		*/
		inline public static function minutesToMilliseconds(minutes:Float):Float {
			return ConversionUtil.secondsToMilliseconds(ConversionUtil.minutesToSeconds(minutes));
		}
		
		/**
			Converts minutes to seconds.
			
			@param minutes: The number of minutes.
			@return Returns the number of seconds.
		*/
		inline public static function minutesToSeconds(minutes:Float):Float {
			return minutes * 60;
		}
		
		/**
			Converts minutes to hours.
			
			@param minutes: The number of minutes.
			@return Returns the number of hours.
		*/
		inline public static function minutesToHours(minutes:Float):Float {
			return minutes / 60;
		}
		
		/**
			Converts minutes to days.
			
			@param minutes: The number of minutes.
			@return Returns the number of days.
		*/
		inline public static function minutesToDays(minutes:Float):Float {
			return ConversionUtil.hoursToDays(ConversionUtil.minutesToHours(minutes));
		}
		
		/**
			Converts hours to milliseconds.
			
			@param hours: The number of hours.
			@return Returns the number of milliseconds.
		*/
		inline public static function hoursToMilliseconds(hours:Float):Float {
			return ConversionUtil.secondsToMilliseconds(ConversionUtil.hoursToSeconds(hours));
		}
		
		/**
			Converts hours to seconds.
			
			@param hours: The number of hours.
			@return Returns the number of seconds.
		*/
		inline public static function hoursToSeconds(hours:Float):Float {
			return ConversionUtil.minutesToSeconds(ConversionUtil.hoursToMinutes(hours));
		}
		
		/**
			Converts hours to minutes.
			
			@param hours: The number of hours.
			@return Returns the number of minutes.
		*/
		inline public static function hoursToMinutes(hours:Float):Float {
			return hours * 60;
		}
		
		/**
			Converts hours to days.
			
			@param hours: The number of hours.
			@return Returns the number of days.
		*/
		inline public static function hoursToDays(hours:Float):Float {
			return hours / 24;
		}
		
		/**
			Converts days to milliseconds.
			
			@param days: The number of days.
			@return Returns the number of milliseconds.
		*/
		inline public static function daysToMilliseconds(days:Float):Float {
			return ConversionUtil.secondsToMilliseconds(ConversionUtil.daysToSeconds(days));
		}
		
		/**
			Converts days to seconds.
			
			@param days: The number of days.
			@return Returns the number of seconds.
		*/
		inline public static function daysToSeconds(days:Float):Float {
			return ConversionUtil.minutesToSeconds(ConversionUtil.daysToMinutes(days));
		}
		
		/**
			Converts days to minutes.
			
			@param days: The number of days.
			@return Returns the number of minutes.
		*/
		inline public static function daysToMinutes(days:Float):Float {
			return ConversionUtil.hoursToMinutes(ConversionUtil.daysToHours(days));
		}

		/**
			Converts days to hours.
			
			@param days: The number of days.
			@return Returns the number of hours.
		*/
		inline public static function daysToHours(days:Float):Float {
			return days * 24;
		}
		
		/**
			Converts degrees to radians.
			
			@param degrees: The number of degrees.
			@return Returns the number of radians.
		*/
		inline public static function degreesToRadians(degrees:Float):Float {
			return degrees * (Math.PI / 180);
		}
		
		/**
			Converts radians to degrees.
			
			@param radians: The number of radians.
			@return Returns the number of degrees.
		*/
		inline public static function radiansToDegrees(radians:Float):Float {
			return radians * (180 / Math.PI);
		}
	}
