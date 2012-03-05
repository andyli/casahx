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
package org.casalib.util; 
	import flash.display.DisplayObject;
	import flash.geom.Point;
	import flash.geom.Rectangle;
	import org.casalib.core.UInt;
	import org.casalib.util.DisplayObjectUtil;
	
	
	/**
		Provides utility functions for aligning.
		
		@author Aaron Clinger
		@author Jon Adams
		@version 03/28/10
	*/
	class AlignUtil  {
		inline public static var BOTTOM:String        = 'bottom';
		inline public static var BOTTOM_CENTER:String = 'bottomCenter';
		inline public static var BOTTOM_LEFT:String   = 'bottomLeft';
		inline public static var BOTTOM_RIGHT:String  = 'bottomRight';
		inline public static var CENTER:String        = 'center';
		inline public static var LEFT:String          = 'left';
		inline public static var MIDDLE:String        = 'middle';
		inline public static var MIDDLE_CENTER:String = 'middleCenter';
		inline public static var MIDDLE_LEFT:String   = 'middleLeft';
		inline public static var MIDDLE_RIGHT:String  = 'middleRight';
		inline public static var RIGHT:String         = 'right';
		inline public static var TOP:String           = 'top';
		inline public static var TOP_CENTER:String    = 'topCenter';
		inline public static var TOP_LEFT:String      = 'topLeft';
		inline public static var TOP_RIGHT:String     = 'topRight';
		
		
		/**
			Aligns a <code>DisplayObject</code> to the bounding <code>Rectangle</code> acording to the defined alignment.
			
			@param align: The alignment type/position.
			@param displayObject: The <code>DisplayObject</code> to align.
			@param bounds: The area in which to align the <code>DisplayObject</code>.
			@param snapToPixel: Force the position to whole pixels <code>true</code>, or to let the <code>DisplayObject</code> be positioned on sub-pixels <code>false</code>.
			@param outside: Align the <code>DisplayObject</code> to the outside of the bounds <code>true</code>, or the inside <code>false</code>.
		*/
		inline public static function align(alignment:String, displayObject:DisplayObject, bounds:Rectangle, ?snapToPixel:Bool = true, ?outside:Bool = false):Void {
			var targetPosition:Point = AlignUtil._getPosition(alignment, Std.int(displayObject.width), Std.int(displayObject.height), bounds, outside);
			var offsetPosition:Point = DisplayObjectUtil.getOffsetPosition(displayObject);
			
			displayObject.x = targetPosition.x + offsetPosition.x;
			displayObject.y = targetPosition.y + offsetPosition.y;
			
			if (snapToPixel)
				AlignUtil.alignToPixel(displayObject);
		}
		
		/**
			Aligns a <code>Rectangle</code> to another <code>Rectangle</code>.
			
			@param align: The alignment type/position.
			@param rectangle: The <code>Rectangle</code> to align.
			@param bounds: The area in which to align the <code>Rectangle</code>.
			@param snapToPixel: Force the position to whole pixels <code>true</code>, or to let the <code>Rectangle</code> be positioned on sub-pixels <code>false</code>.
			@param outside: Align the <code>Rectangle</code> to the outside of the bounds <code>true</code>, or the inside <code>false</code>.
			@return A new aligned <code>Rectangle</code>.
		*/
		public static function alignRectangle(alignment:String, rectangle:Rectangle, bounds:Rectangle, ?snapToPixel:Bool = true, ?outside:Bool = false):Rectangle {
			var alignedRectangle:Rectangle = rectangle.clone();
			
			alignedRectangle.offsetPoint(AlignUtil._getPosition(alignment, Std.int(rectangle.width), Std.int(rectangle.height), bounds, outside));
			
			if (snapToPixel) {
				alignedRectangle.x = Math.round(alignedRectangle.x);
				alignedRectangle.y = Math.round(alignedRectangle.y);
			}
			
			return alignedRectangle;
		}
		
		/**
			Aligns a <code>DisplayObject</code> to the nearest Pixel.
			
			@param displayObject: The <code>DisplayObject</code> to align.
		*/
		inline public static function alignToPixel(displayObject:DisplayObject):Void {
			displayObject.x = Math.round(displayObject.x);
			displayObject.y = Math.round(displayObject.y);
		}
		
		/**
			Aligns a <code>DisplayObject</code> to the bottom of the bounding <code>Rectangle</code>.
			
			@param displayObject: The <code>DisplayObject</code> to align.
			@param bounds: The area in which to align the <code>DisplayObject</code>.
			@param snapToPixel: Force the position to whole pixels <code>true</code>, or to let the <code>DisplayObject</code> be positioned on sub-pixels <code>false</code>.
			@param outside: Align the <code>DisplayObject</code> to the outside of the bounds <code>true</code>, or the inside <code>false</code>.
		*/
		public static function alignBottom(displayObject:DisplayObject, bounds:Rectangle, ?snapToPixel:Bool = true, ?outside:Bool = false):Void {
			AlignUtil.align(AlignUtil.BOTTOM, displayObject, bounds, snapToPixel, outside);
		}
		
		/**
			Aligns a <code>DisplayObject</code> to the bottom left of the bounding <code>Rectangle</code>.
			
			@param displayObject: The <code>DisplayObject</code> to align.
			@param bounds: The area in which to align the <code>DisplayObject</code>.
			@param snapToPixel: Force the position to whole pixels <code>true</code>, or to let the <code>DisplayObject</code> be positioned on sub-pixels <code>false</code>.
			@param outside: Align the <code>DisplayObject</code> to the outside of the bounds <code>true</code>, or the inside <code>false</code>.
		*/
		public static function alignBottomLeft(displayObject:DisplayObject, bounds:Rectangle, ?snapToPixel:Bool = true, ?outside:Bool = false):Void {
			AlignUtil.align(AlignUtil.BOTTOM_LEFT, displayObject, bounds, snapToPixel, outside);
		}
		
		/**
			Aligns a <code>DisplayObject</code> to the bottom and horizontal center of the bounding <code>Rectangle</code>.
			
			@param displayObject: The <code>DisplayObject</code> to align.
			@param bounds: The area in which to align the <code>DisplayObject</code>.
			@param snapToPixel: Force the position to whole pixels <code>true</code>, or to let the <code>DisplayObject</code> be positioned on sub-pixels <code>false</code>.
			@param outside: Align the <code>DisplayObject</code> to the outside of the bounds <code>true</code>, or the inside <code>false</code>.
		*/
		public static function alignBottomCenter(displayObject:DisplayObject, bounds:Rectangle, ?snapToPixel:Bool = true, ?outside:Bool = false):Void {
			AlignUtil.align(AlignUtil.BOTTOM_CENTER, displayObject, bounds, snapToPixel, outside);
		}
		
		/**
			Aligns a <code>DisplayObject</code> to the bottom right of the bounding <code>Rectangle</code>.
			
			@param displayObject: The <code>DisplayObject</code> to align.
			@param bounds: The area in which to align the <code>DisplayObject</code>.
			@param snapToPixel: Force the position to whole pixels <code>true</code>, or to let the <code>DisplayObject</code> be positioned on sub-pixels <code>false</code>.
			@param outside: Align the <code>DisplayObject</code> to the outside of the bounds <code>true</code>, or the inside <code>false</code>.
		*/
		public static function alignBottomRight(displayObject:DisplayObject, bounds:Rectangle, ?snapToPixel:Bool = true, ?outside:Bool = false):Void {
			AlignUtil.align(AlignUtil.BOTTOM_RIGHT, displayObject, bounds, snapToPixel, outside);
		}
		
		/**
			Aligns a <code>DisplayObject</code> to the horizontal center of the bounding <code>Rectangle</code>.
			
			@param displayObject: The <code>DisplayObject</code> to align.
			@param bounds: The area in which to align the <code>DisplayObject</code>.
			@param snapToPixel: Force the position to whole pixels <code>true</code>, or to let the <code>DisplayObject</code> be positioned on sub-pixels <code>false</code>.
		*/
		public static function alignCenter(displayObject:DisplayObject, bounds:Rectangle, ?snapToPixel:Bool = true):Void {
			AlignUtil.align(AlignUtil.CENTER, displayObject, bounds, snapToPixel);
		}
		
		/**
			Aligns a <code>DisplayObject</code> to the left side of the bounding <code>Rectangle</code>.
			
			@param displayObject: The <code>DisplayObject</code> to align.
			@param bounds: The area in which to align the <code>DisplayObject</code>.
			@param snapToPixel: Force the position to whole pixels <code>true</code>, or to let the <code>DisplayObject</code> be positioned on sub-pixels <code>false</code>.
			@param outside: Align the <code>DisplayObject</code> to the outside of the bounds <code>true</code>, or the inside <code>false</code>.
		*/
		public static function alignLeft(displayObject:DisplayObject, bounds:Rectangle, ?snapToPixel:Bool = true, ?outside:Bool = false):Void {
			AlignUtil.align(AlignUtil.LEFT, displayObject, bounds, snapToPixel, outside);
		}
		
		/**
			Aligns a <code>DisplayObject</code> to the vertical middle of the bounding <code>Rectangle</code>.
			
			@param displayObject: The <code>DisplayObject</code> to align.
			@param bounds: The area in which to align the <code>DisplayObject</code>.
			@param snapToPixel: Force the position to whole pixels <code>true</code>, or to let the <code>DisplayObject</code> be positioned on sub-pixels <code>false</code>.
		*/
		public static function alignMiddle(displayObject:DisplayObject, bounds:Rectangle, ?snapToPixel:Bool = true):Void {
			AlignUtil.align(AlignUtil.MIDDLE, displayObject, bounds, snapToPixel);
		}
		
		/**
			Aligns a <code>DisplayObject</code> to the vertical middle and left side of the bounding <code>Rectangle</code>.
			
			@param displayObject: The <code>DisplayObject</code> to align.
			@param bounds: The area in which to align the <code>DisplayObject</code>.
			@param snapToPixel: Force the position to whole pixels <code>true</code>, or to let the <code>DisplayObject</code> be positioned on sub-pixels <code>false</code>.
			@param outside: Align the <code>DisplayObject</code> to the outside of the bounds <code>true</code>, or the inside <code>false</code>.
		*/
		public static function alignMiddleLeft(displayObject:DisplayObject, bounds:Rectangle, ?snapToPixel:Bool = true, ?outside:Bool = false):Void {
			AlignUtil.align(AlignUtil.MIDDLE_LEFT, displayObject, bounds, snapToPixel, outside);
		}
		
		/**
			Aligns a <code>DisplayObject</code> to the vertical middle and horizontal center of the bounding <code>Rectangle</code>.
			
			@param displayObject: The <code>DisplayObject</code> to align.
			@param bounds: The area in which to align the <code>DisplayObject</code>.
			@param snapToPixel: Force the position to whole pixels <code>true</code>, or to let the <code>DisplayObject</code> be positioned on sub-pixels <code>false</code>.
		*/
		public static function alignMiddleCenter(displayObject:DisplayObject, bounds:Rectangle, ?snapToPixel:Bool = true):Void {
			AlignUtil.align(AlignUtil.MIDDLE_CENTER, displayObject, bounds, snapToPixel);
		}
		
		/**
			Aligns a <code>DisplayObject</code> to the vertical middle and right side of the bounding <code>Rectangle</code>.
			
			@param displayObject: The <code>DisplayObject</code> to align.
			@param bounds: The area in which to align the <code>DisplayObject</code>.
			@param snapToPixel: Force the position to whole pixels <code>true</code>, or to let the <code>DisplayObject</code> be positioned on sub-pixels <code>false</code>.
			@param outside: Align the <code>DisplayObject</code> to the outside of the bounds <code>true</code>, or the inside <code>false</code>.
		*/
		public static function alignMiddleRight(displayObject:DisplayObject, bounds:Rectangle, ?snapToPixel:Bool = true, ?outside:Bool = false):Void {
			AlignUtil.align(AlignUtil.MIDDLE_RIGHT, displayObject, bounds, snapToPixel, outside);
		}
		
		/**
			Aligns a <code>DisplayObject</code> to the right side of the bounding <code>Rectangle</code>.
			
			@param displayObject: The <code>DisplayObject</code> to align.
			@param bounds: The area in which to align the <code>DisplayObject</code>.
			@param snapToPixel: Force the position to whole pixels <code>true</code>, or to let the <code>DisplayObject</code> be positioned on sub-pixels <code>false</code>.
			@param outside: Align the <code>DisplayObject</code> to the outside of the bounds <code>true</code>, or the inside <code>false</code>.
		*/
		public static function alignRight(displayObject:DisplayObject, bounds:Rectangle, ?snapToPixel:Bool = true, ?outside:Bool = false):Void {
			AlignUtil.align(AlignUtil.RIGHT, displayObject, bounds, snapToPixel, outside);
		}
		
		/**
			Aligns a <code>DisplayObject</code> to the top of the bounding <code>Rectangle</code>.
			
			@param displayObject: The <code>DisplayObject</code> to align.
			@param bounds: The area in which to align the <code>DisplayObject</code>.
			@param snapToPixel: Force the position to whole pixels <code>true</code>, or to let the <code>DisplayObject</code> be positioned on sub-pixels <code>false</code>.
			@param outside: Align the <code>DisplayObject</code> to the outside of the bounds <code>true</code>, or the inside <code>false</code>.
		*/
		public static function alignTop(displayObject:DisplayObject, bounds:Rectangle, ?snapToPixel:Bool = true, ?outside:Bool = false):Void {
			AlignUtil.align(AlignUtil.TOP, displayObject, bounds, snapToPixel, outside);
		}
		
		/**
			Aligns a <code>DisplayObject</code> to the top left of the bounding <code>Rectangle</code>.
			
			@param displayObject: The <code>DisplayObject</code> to align.
			@param bounds: The area in which to align the <code>DisplayObject</code>.
			@param snapToPixel: Force the position to whole pixels <code>true</code>, or to let the <code>DisplayObject</code> be positioned on sub-pixels <code>false</code>.
			@param outside: Align the <code>DisplayObject</code> to the outside of the bounds <code>true</code>, or the inside <code>false</code>.
		*/
		public static function alignTopLeft(displayObject:DisplayObject, bounds:Rectangle, ?snapToPixel:Bool = true, ?outside:Bool = false):Void {
			AlignUtil.align(AlignUtil.TOP_LEFT, displayObject, bounds, snapToPixel, outside);
		}
		
		/**
			Aligns a <code>DisplayObject</code> to the top side and horizontal center of the bounding <code>Rectangle</code>.
			
			@param displayObject: The <code>DisplayObject</code> to align.
			@param bounds: The area in which to align the <code>DisplayObject</code>.
			@param snapToPixel: Force the position to whole pixels <code>true</code>, or to let the <code>DisplayObject</code> be positioned on sub-pixels <code>false</code>.
			@param outside: Align the <code>DisplayObject</code> to the outside of the bounds <code>true</code>, or the inside <code>false</code>.
		*/
		public static function alignTopCenter(displayObject:DisplayObject, bounds:Rectangle, ?snapToPixel:Bool = true, ?outside:Bool = false):Void {
			AlignUtil.align(AlignUtil.TOP_CENTER, displayObject, bounds, snapToPixel, outside);
		}
		
		/**
			Aligns a <code>DisplayObject</code> to the top right of the bounding <code>Rectangle</code>.
			
			@param displayObject: The <code>DisplayObject</code> to align.
			@param bounds: The area in which to align the <code>DisplayObject</code>.
			@param snapToPixel: Force the position to whole pixels <code>true</code>, or to let the <code>DisplayObject</code> be positioned on sub-pixels <code>false</code>.
			@param outside: Align the <code>DisplayObject</code> to the outside of the bounds <code>true</code>, or the inside <code>false</code>.
		*/
		public static function alignTopRight(displayObject:DisplayObject, bounds:Rectangle, ?snapToPixel:Bool = true, ?outside:Bool = false):Void {
			AlignUtil.align(AlignUtil.TOP_RIGHT, displayObject, bounds, snapToPixel, outside);
		}
		
		inline static function _getPosition(alignment:String, targetWidth:UInt, targetHeight:UInt, bounds:Rectangle, outside:Bool):Point {
			var position:Point = new Point();
			
			switch (alignment) {
				case AlignUtil.BOTTOM_LEFT, AlignUtil.LEFT, AlignUtil.MIDDLE_LEFT, AlignUtil.TOP_LEFT :
					position.x = outside ? bounds.x - targetWidth : bounds.x;
				case AlignUtil.BOTTOM_CENTER, AlignUtil.CENTER, AlignUtil.MIDDLE_CENTER, AlignUtil.TOP_CENTER :
					position.x = (bounds.width - targetWidth) * 0.5 + bounds.x;
				case AlignUtil.BOTTOM_RIGHT, AlignUtil.MIDDLE_RIGHT, AlignUtil.RIGHT, AlignUtil.TOP_RIGHT:
					position.x = outside ? bounds.right : bounds.right - targetWidth;
			}
			
			switch (alignment) {
				case AlignUtil.TOP, AlignUtil.TOP_CENTER, AlignUtil.TOP_LEFT, AlignUtil.TOP_RIGHT:
					position.y = outside ? bounds.y - targetHeight : bounds.y;
				case AlignUtil.MIDDLE, AlignUtil.MIDDLE_CENTER, AlignUtil.MIDDLE_LEFT, AlignUtil.MIDDLE_RIGHT :
					position.y = (bounds.height - targetHeight) * 0.5 + bounds.y;
				case AlignUtil.BOTTOM, AlignUtil.BOTTOM_CENTER, AlignUtil.BOTTOM_LEFT, AlignUtil.BOTTOM_RIGHT:
					position.y = outside ? bounds.bottom : bounds.bottom - targetHeight;
			}
			
			return position;
		}
	}
