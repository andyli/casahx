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
package org.casalib.math.geom; 
	import flash.geom.Point;
	
	/**
		Stores position and size of an ellipse (circle or oval).
		
		@author Aaron Clinger
		@author Mike Creighton
		@version 04/13/08
	*/
	class Ellipse  {
		
		public var area(get_area, null) : Float ;
		public var center(get_center, set_center) : Point;
		public var height(get_height, set_height) : Float;
		public var perimeter(get_perimeter, null) : Float ;
		public var size(get_size, null) : Point ;
		public var width(get_width, set_width) : Float;
		public var x(get_x, set_x) : Float;
		public var y(get_y, set_y) : Float;
		var _x:Float;
		var _y:Float;
		var _width:Float;
		var _height:Float;
		
		
		/**
			Creates new Ellipse object.
			
			@param x: The horizontal position of the ellipse.
			@param y: The vertical position of the ellipse.
			@param width: Width of the ellipse at its widest horizontal point.
			@param height: Height of the ellipse at its tallest point.
		*/
		public function new(x:Float, y:Float, width:Float, height:Float) {
			this.x      = x;
			this.y      = y;
			this.width  = width;
			this.height = height;
		}
		
		/**
			The horizontal coordinate of the point.
		*/
		inline public function get_x():Float{
			return this._x;
		}
		
		inline public function set_x(xPos:Float):Float{
			return this._x = xPos;
		}
		
		/**
			The vertical coordinate of the point.
		*/
		inline public function get_y():Float{
			return this._y;
		}
		
		inline public function set_y(yPos:Float):Float{
			return this._y = yPos;
		}
		
		/**
		 	The width of the ellipse.
		*/
		inline public function get_width():Float{
			return this._width;
		}
		
		inline public function set_width(width:Float):Float{
			return this._width = width;
		}
		
		/**
		 	The height of the rectangle.
		*/
		inline public function get_height():Float{
			return this._height;
		}
		
		inline public function set_height(height:Float):Float{
			return this._height = height;
		}
		
		/**
			The center of the ellipse.
		*/
		inline public function get_center():Point{
			return new Point(this.x + this.width * 0.5, this.y + this.height * 0.5);
		}
		
		inline public function set_center(c:Point):Point{
			this.x = c.x - this.width * 0.5;
			this.y = c.y - this.height * 0.5;
			return c;
		}
		
		/**
			The size of the ellipse, expressed as a Point object with the values of the width and height properties.
		*/
		inline public function get_size():Point {
			return new Point(this.width, this.height);
		}
		
		/**
			The circumference of the ellipse.
			
			@usageNote Calculating the circumference of an ellipse is difficult; this is an approximation but should be accurate for most cases.
		*/
		inline public function get_perimeter():Float {
			return (Math.sqrt(0.5 * (Math.pow(this.width, 2) + Math.pow(this.height, 2))) * Math.PI * 2) * 0.5;
		}
		
		/**
			The area of the ellipse.
		*/
		inline public function get_area():Float {
			return Math.PI * (this.width * 0.5) * (this.height * 0.5);
		}
		
		/**
			Finds the <code>x</code>, <code>y</code> position of the degree along the circumference of the ellipse.
			
			@param degree: Number representing a degree on the ellipse.
			@return A Point object.
			@usageNote <code>degree</code> can be over 360 or even negitive numbers; minding <code>0 = 360 = 720</code>, <code>540 = 180</code>, <code>-90 = 270</code>, etc.
		*/
		public function getPointOfDegree(degree:Float):Point {
			var radian:Float  = (degree - 90) * (Math.PI / 180);
			var xRadius:Float = this.width * 0.5;
			var yRadius:Float = this.height * 0.5;
			
			return new Point(this.x + xRadius + Math.cos(radian) * xRadius, this.y + yRadius + Math.sin(radian) * yRadius);
		}
		
		/**
			Finds if a point is contained inside of the ellipse perimeter.
			
			@param point: A Point object.
			@return Returns <code>true</code> if shape's area contains point; otherwise <code>false</code>.
		*/
		public function containsPoint(point:Point):Bool {
			var xRadius:Float = this.width * 0.5;
			var yRadius:Float = this.height * 0.5;
			var xTar:Float    = point.x - this.x - xRadius;
			var yTar:Float    = point.y - this.y - yRadius;
			
			return Math.pow(xTar / xRadius, 2) + Math.pow(yTar / yRadius, 2) <= 1;
		}
		
		/**
			Determines if the Ellipse specified in the <code>ellipse</code> parameter is equal to this Ellipse object.
			
			@param ellipse: An Ellipse object.
			@return Returns <code>true</code> if object is equal to this Ellipse; otherwise <code>false</code>.
		*/
		public function equals(ellipse:Ellipse):Bool {
			return this.x == ellipse.x && this.y == ellipse.y && this.width == ellipse.width && this.height == ellipse.height;
		}
		
		/**
			@return A new Ellipse object with the same values as this Ellipse.
		*/
		public function clone():Ellipse {
			return new Ellipse(this.x, this.y, this.width, this.height);
		}
	}
