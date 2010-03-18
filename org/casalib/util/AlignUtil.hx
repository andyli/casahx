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
	import flash.geom.Rectangle;
	import flash.display.DisplayObject;
	
	/**
		Provides utility functions aligning DisplayObjects.
		
		@author Aaron Clinger
		@author Jon Adams
		@version 05/29/09
	*/
	class AlignUtil  {
		/**
			Aligns a DisplayObject to the left side of the bounding Rectangle.
			
			@param displayObject: The DisplayObject to align.
			@param bounds: The area in which to align the DisplayObject.
			@param snapToPixel: Force the position to whole pixels <code>true</code>, or to let the DisplayObject be positioned on sub-pixels <code>false</code>.
			@param outside: Align the DisplayObject to the outside of the bounds <code>true</code>, or the inside <code>false</code>.
		*/
		public static function alignLeft(displayObject:DisplayObject, bounds:Rectangle, ?snapToPixel:Bool = true, ?outside:Bool = false):Void {
			var x:Float    = outside ? bounds.left - displayObject.width : bounds.left;
			displayObject.x = snapToPixel ? Math.round(x) : x;
		}
		
		/**
			Aligns a DisplayObject to the right side of the bounding Rectangle.
			
			@param displayObject: The DisplayObject to align.
			@param bounds: The area in which to align the DisplayObject.
			@param snapToPixel: Force the position to whole pixels <code>true</code>, or to let the DisplayObject be positioned on sub-pixels <code>false</code>.
			@param outside: Align the DisplayObject to the outside of the bounds <code>true</code>, or the inside <code>false</code>.
		*/
		public static function alignRight(displayObject:DisplayObject, bounds:Rectangle, ?snapToPixel:Bool = true, ?outside:Bool = false):Void {
			var x:Float    = outside ? bounds.right : bounds.right - displayObject.width;
			displayObject.x = snapToPixel ? Math.round(x) : x;
		}
		
		/**
			Aligns a DisplayObject to the top of the bounding Rectangle.
			
			@param displayObject: The DisplayObject to align.
			@param bounds: The area in which to align the DisplayObject.
			@param snapToPixel: Force the position to whole pixels <code>true</code>, or to let the DisplayObject be positioned on sub-pixels <code>false</code>.
			@param outside: Align the DisplayObject to the outside of the bounds <code>true</code>, or the inside <code>false</code>.
		*/
		public static function alignTop(displayObject:DisplayObject, bounds:Rectangle, ?snapToPixel:Bool = true, ?outside:Bool = false):Void {
			var y:Float    = outside ? bounds.top - displayObject.height : bounds.top;
			displayObject.y = snapToPixel ? Math.round(y) : y;
		}
		
		/**
			Aligns a DisplayObject to the bottom of the bounding Rectangle.
			
			@param displayObject: The DisplayObject to align.
			@param bounds: The area in which to align the DisplayObject.
			@param snapToPixel: Force the position to whole pixels <code>true</code>, or to let the DisplayObject be positioned on sub-pixels <code>false</code>.
			@param outside: Align the DisplayObject to the outside of the bounds <code>true</code>, or the inside <code>false</code>.
		*/
		public static function alignBottom(displayObject:DisplayObject, bounds:Rectangle, ?snapToPixel:Bool = true, ?outside:Bool = false):Void {
			var y:Float    = outside ? bounds.bottom : bounds.bottom - displayObject.height;
			displayObject.y = snapToPixel ? Math.round(y) : y;
		}
		
		/**
			Aligns a DisplayObject to the horizontal center of the bounding Rectangle.
			
			@param displayObject: The DisplayObject to align.
			@param bounds: The area in which to align the DisplayObject.
			@param snapToPixel: Force the position to whole pixels <code>true</code>, or to let the DisplayObject be positioned on sub-pixels <code>false</code>.
		*/
		public static function alignCenter(displayObject:DisplayObject, bounds:Rectangle, ?snapToPixel:Bool = true):Void {
			var centerX:Float = bounds.width * 0.5 - displayObject.width * 0.5 + bounds.x;
			displayObject.x    = snapToPixel ? Math.round(centerX) : centerX;
		}
		
		/**
			Aligns a DisplayObject to the vertical middle of the bounding Rectangle.
			
			@param displayObject: The DisplayObject to align.
			@param bounds: The area in which to align the DisplayObject.
			@param snapToPixel: Force the position to whole pixels <code>true</code>, or to let the DisplayObject be positioned on sub-pixels <code>false</code>.
		*/
		public static function alignMiddle(displayObject:DisplayObject, bounds:Rectangle, ?snapToPixel:Bool = true):Void {
			var centerY:Float = bounds.height * 0.5 - displayObject.height * 0.5 + bounds.y;
			displayObject.y    = snapToPixel ? Math.round(centerY) : centerY;
		}
		
		/**
			Aligns a DisplayObject to the horizontal center and vertical middle of the bounding Rectangle.
			
			@param displayObject: The DisplayObject to align.
			@param bounds: The area in which to align the DisplayObject.
			@param snapToPixel: Force the position to whole pixels <code>true</code>, or to let the DisplayObject be positioned on sub-pixels <code>false</code>.
		*/
		public static function alignCenterMiddle(displayObject:DisplayObject, bounds:Rectangle, ?snapToPixel:Bool = true):Void {
			AlignUtil.alignCenter(displayObject, bounds, snapToPixel);
			AlignUtil.alignMiddle(displayObject, bounds, snapToPixel);
		}
	}
