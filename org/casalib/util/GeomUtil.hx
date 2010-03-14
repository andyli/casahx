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
	import flash.geom.Point;
	import flash.geom.Rectangle;
	import org.casalib.util.ConversionUtil;
	
	/**
		Utilities for positioning, calculating and manipulating geometeric shapes.
		
		@author Aaron Clinger
		@author Jon Adams
		@version 02/19/08
	*/
	class GeomUtil  {
		/**
			Rotates a Point around another Point by the specified angle.
			
			@param point: The Point to rotate.
			@param centerPoint: The Point to rotate this Point around.
			@param angle: The angle (in degrees) to rotate this point.
		*/
		inline public static function rotatePoint(point:Point, centerPoint:Point, angle:Float):Void {
			var radians:Float = ConversionUtil.degreesToRadians(angle);
			var baseX:Float   = point.x - centerPoint.x;
			var baseY:Float   = point.y - centerPoint.y;
			
			point.x = (Math.cos(radians) * baseX) - (Math.sin(radians) * baseY) + centerPoint.x;
			point.y = (Math.sin(radians) * baseX) + (Math.cos(radians) * baseY) + centerPoint.y;
		}
		
		/**
			Determines the angle/degree between the first and second point.
			
			@param first: The first Point.
			@param second: The second Point.
			@return The degree between the two points.
		*/
		inline public static function angle(first:Point, second:Point):Float {
			return Math.atan2(second.y - first.y, second.x - first.x) / (Math.PI / 180);
		}
		
		/**
			Calculates the perimeter of a rectangle.
			
			@param rect: Rectangle to determine the perimeter of.
		*/
		inline public static function getRectanglePerimeter(rect:Rectangle):Float {
			return rect.width * 2 + rect.height * 2;
		}
	}
