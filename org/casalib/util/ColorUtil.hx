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
package org.casalib.util; 
	import haxe.Int32;
	import flash.geom.ColorTransform;
	import org.casalib.math.Percent;
	import org.casalib.util.NumberUtil;
	import org.casalib.core.UInt;
	
	/**
		Provides utility functions for dealing with color.
		
		@author Aaron Clinger
		@version 09/23/08
	*/
	class ColorUtil  {
		/**
			Interpolates (tints) between two colors.
			
			@param begin: The start color.
			@param end: The finish color.
			@param amount: The level of interpolation between the two colors.
			@return The new interpolated color.
			@usage
				<code>
					var myColor:ColorTransform = new ColorTransform();
					myColor.color              = 0xFF0000;
					
					var box:Sprite = new Sprite();
					box.graphics.beginFill(0x0000FF);
					box.graphics.drawRect(10, 10, 250, 250);
					box.graphics.endFill();
					
					box.transform.colorTransform = ColorUtil.interpolateColor(new ColorTransform(), myColor, new Percent(0.5));
					
					this.addChild(box);
				</code>
		*/
		inline public static function interpolateColor(begin:ColorTransform, end:ColorTransform, amount:Percent):ColorTransform {
			var interpolation:ColorTransform = new ColorTransform();
			
			interpolation.redMultiplier   = NumberUtil.interpolate(amount, begin.redMultiplier, end.redMultiplier);
			interpolation.greenMultiplier = NumberUtil.interpolate(amount, begin.greenMultiplier, end.greenMultiplier);
			interpolation.blueMultiplier  = NumberUtil.interpolate(amount, begin.blueMultiplier, end.blueMultiplier);
			interpolation.alphaMultiplier = NumberUtil.interpolate(amount, begin.alphaMultiplier, end.alphaMultiplier);
			interpolation.redOffset       = NumberUtil.interpolate(amount, begin.redOffset, end.redOffset);
			interpolation.greenOffset     = NumberUtil.interpolate(amount, begin.greenOffset, end.greenOffset);
			interpolation.blueOffset      = NumberUtil.interpolate(amount, begin.blueOffset, end.blueOffset);
			interpolation.alphaOffset     = NumberUtil.interpolate(amount, begin.alphaOffset, end.alphaOffset);
			
			return interpolation;
		}
		
		/**
			Converts a series of individual RGB(A) values to a 32-bit ARGB color value.
			
			@param r: A uint from 0 to 255 representing the red color value.
			@param g: A uint from 0 to 255 representing the green color value.
			@param b: A uint from 0 to 255 representing the blue color value.
			@param a: A uint from 0 to 255 representing the alpha value. Default is <code>255</code>.
			@return Returns a hexidecimal color as a String.
			@example
				<code>
					var hexColor : String = ColorUtil.getHexStringFromARGB(128, 255, 0, 255);
					trace(hexColor); // Traces 80FF00FF
				</code>
		*/
		#if !php 
		inline 
		#end 
		public static function getColor(r : UInt, g : UInt, b : UInt, ?a : UInt = 255) : UInt {
			#if php
				//simulate integer overflow...
				untyped __php__("$val = ($a << 24) | ($r << 16) | ($g << 8) | $b;");
				return untyped __php__("$val > (float)2147483647? (int)($val-((float)'4294967296')):(int)$val");
			#elseif flash
				return (a << 24) | (r << 16) | (g << 8) | b;
			#else
				return (a << 24) + (r << 16) + (g << 8) + b;
			#end	
		}
		
		/**
			Converts a 32-bit ARGB color value into an ARGB object.
			
			@param color: The 32-bit ARGB color value.
			@return Returns an object with the properties a, r, g, and b defined.
			@example
				<code>
					var myRGB:Object = ColorUtil.getARGB(0xCCFF00FF);
					trace("Alpha = " + myRGB.a);
					trace("Red = " + myRGB.r);
					trace("Green = " + myRGB.g);
					trace("Blue = " + myRGB.b);
				</code>
		*/
		inline public static function getARGB(color : UInt) : {a:UInt,r:UInt,g:UInt,b:UInt} {
			return {a:color >> 24 & 0xFF,r:color >> 16 & 0xFF,g:color >> 8 & 0xFF,b:color & 0xFF};
		}
		
		/**
			Converts a 24-bit RGB color value into an RGB object.
			
			@param color: The 24-bit RGB color value.
			@return Returns an object with the properties r, g, and b defined.
			@example
				<code>
					var myRGB:Object = ColorUtil.getRGB(0xFF00FF);
					trace("Red = " + myRGB.r);
					trace("Green = " + myRGB.g);
					trace("Blue = " + myRGB.b);
				</code>
		*/
		public static function getRGB(color : UInt) : {r:UInt,g:UInt,b:UInt} {
			return {r:color >> 16 & 0xFF,g:color >> 8 & 0xFF,b:color & 0xFF};
		}
		
		/**
			Converts a 32-bit ARGB color value into a hexidecimal String representation.
			
			@param a: A uint from 0 to 255 representing the alpha value.
			@param r: A uint from 0 to 255 representing the red color value.
			@param g: A uint from 0 to 255 representing the green color value.
			@param b: A uint from 0 to 255 representing the blue color value.
			@return Returns a hexidecimal color as a String.
			@example
				<code>
					var hexColor : String = ColorUtil.getHexStringFromARGB(128, 255, 0, 255);
					trace(hexColor); // Traces 80FF00FF
				</code>
		*/
		public static function getHexStringFromARGB(a : UInt, r : UInt, g : UInt, b : UInt) : String {
			var aa: String = StringTools.hex(a,2);
			var rr: String = StringTools.hex(r,2);
			var gg: String = StringTools.hex(g,2);
			var bb: String = StringTools.hex(b,2);
			return (aa + rr + gg + bb).toUpperCase();
		}
		
		/**
			Converts an RGB color value into a hexidecimal String representation.
			
			@param r: A uint from 0 to 255 representing the red color value.
			@param g: A uint from 0 to 255 representing the green color value.
			@param b: A uint from 0 to 255 representing the blue color value.
			@return Returns a hexidecimal color as a String.
			@example
				<code>
					var hexColor : String = ColorUtil.getHexStringFromRGB(255, 0, 255);
					trace(hexColor); // Traces FF00FF
				</code>
		*/
		public static function getHexStringFromRGB(r : UInt, g : UInt, b : UInt) : String {
			var rr: String = StringTools.hex(r,2);
			var gg: String = StringTools.hex(g,2);
			var bb: String = StringTools.hex(b,2);
			return (rr + gg + bb).toUpperCase();
		}
	}
