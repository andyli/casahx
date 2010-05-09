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
package org.casalib.math.geom; 
	import org.casalib.util.NumberUtil;
	import org.casalib.math.Percent;
	
	/**
		Stores location of a point in a three-dimensional coordinate system, where x represents the horizontal axis, y represents the vertical axis, z represents the axis that is vertically perpendicular to the x/y axis or depth.
		
		@author Aaron Clinger
		@author David Bliss
		@author Mike Creighton
		@version 09/23/08
	*/
	class Point3d {
		
		public var x: Float;
		public var y: Float;
		public var z: Float;
		
		
		/**
			Creates a new Point3d.
			
			@param x: The horizontal coordinate of the point.
			@param y: The vertical coordinate of the point.
			@param z: The depth coordinate of the point.
		*/
		public function new(?x:Float = 0, ?y:Float = 0, ?z:Float = 0) {
			this.x = x;
			this.y = y;
			this.z = z;
		}
		
		/**
			Adds the coordinates of another Point3d to the coordinates of this point to create a new Point3d.
			
			@param point: The point to be added.
			@return The new point.
		*/
		inline public function add(point:Point3d):Point3d {
			return new Point3d(this.x + point.x, this.y + point.y, this.z + point.z);
		}
		
		/**
			Subtracts the coordinates of another Point3d from the coordinates of this point to create a new Point3d.
			
			@param point: The point to be subtracted.
			@return The new point.
		*/
		inline public function subtract(point:Point3d):Point3d {
			return new Point3d(this.x - point.x, this.y - point.y, this.z - point.z);
		}
		
		/**
			Offsets the Point object by the specified amount.
			
			@param xOffset: The amount by which to offset the horizontal coordinate.
			@param yOffset: The amount by which to offset the vertical coordinate.
			@param zOffset: The amount by which to offset the depth coordinate.
		*/
		inline public function offset(xOffset:Float, yOffset:Float, zOffset:Float):Void {
			this.x += xOffset;
			this.y += yOffset;
			this.z += zOffset;
		}
		
		/**
			Determines if the point specified in the <code>point</code> parameter is equal to this point object.
			
			@param point: A Point3d object.
			@return Returns <code>true</code> if shape's location is identical; otherwise <code>false</code>.
		*/
		inline public function equals(point:Point3d):Bool {
			return this.x == point.x && this.y == point.y && this.z == point.z;
		}
		
		/**
			Creates a copy of this Point3d object.
			
			@return A new Point3d with the same values as this point.
		*/
		inline public function clone():Point3d {
			return new Point3d(this.x, this.y, this.z);
		}
		
		/**
			Determines the distance between the first and second points in 3D space.
			
			@param firstPoint: The first Point3d.
			@param secondPoint: The second Point3d.
			@return Distance between the two points.
		*/
		inline public static function distance(firstPoint:Point3d, secondPoint:Point3d):Float {
			var x:Float = secondPoint.x - firstPoint.x;
			var y:Float = secondPoint.y - firstPoint.y;
			var z:Float = secondPoint.z - firstPoint.z;
			
			return Math.sqrt(x * x + y * y + z * z);
		}
		
		/**
			Determines a point between two specified points.
			
			@param firstPoint: The first Point3d.
			@param secondPoint: The second Point3d.
			@param amount: The level of interpolation between the two points. If <code>0%</code>, <code>firstPoint</code> is returned; if <code>100%</code>, <code>secondPoint</code> is returned.
			@return The new, interpolated point.
		*/
		inline public static function interpolate(firstPoint:Point3d, secondPoint:Point3d, amount:Percent):Point3d {
			var x:Float = NumberUtil.interpolate(amount, firstPoint.x, secondPoint.x);
			var y:Float = NumberUtil.interpolate(amount, firstPoint.y, secondPoint.y);
			var z:Float = NumberUtil.interpolate(amount, firstPoint.z, secondPoint.z);
			
			return new Point3d(x, y, z);
		}
	}
