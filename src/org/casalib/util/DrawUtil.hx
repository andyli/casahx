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
	import flash.display.Graphics;
	import flash.geom.Point;
	import org.casalib.core.UInt;
	import org.casalib.errors.ArrayContentsError;
	import org.casalib.math.geom.Ellipse;
	
	/**
		Utilities for drawing shapes.
		
		@author Aaron Clinger
		@version 03/26/10
	*/
	class DrawUtil  {
		/**
			Draws a path through the defined points.
			
			@param graphics: The location where drawing should occur.
			@param points: An Array comprised of at least two <code>Point</code>s to be use to draw a path.
			@throws ArrayContentsError if the Array is comprised of elements other than <code>Point</code> objects.
			@throws Error if the Array has less than two <code>Point</code>s.
			@example
				<code>
					this.graphics.lineStyle(4, 0x00FF00);
					DrawUtil.drawPath(this.graphics, new Array(new Point(50, 25), new Point(25, 50), new Point(50, 75), new Point(25, 100)));
					this.graphics.endFill();
				</code>
		*/
		inline public static function drawPath(graphics:Graphics, points:Array<Point>):Void {
			var i:UInt = points.length;
			
			if (points.length < 2)
				throw 'At least three Points are needed to draw a shape.';
			
			graphics.moveTo(points[0].x, points[0].y);
			
			i = 0;
			while (++i < points.length)
				graphics.lineTo(points[i].x, points[i].y);
		}
		
		/**
			Draws a closed shape with the defined points.
			
			@param graphics: The location where drawing should occur.
			@param points: An Array comprised of at least three <code>Point</code>s to be use to draw a shape.
			@throws ArrayContentsError if the Array is comprised of elements other than <code>Point</code> objects.
			@throws Error if the Array has less than three <code>Point</code>s.
			@usageNote This method will automatically connect the last point to the starting point.
			@example
				<code>
					this.graphics.beginFill(0xFF00FF);
					DrawUtil.drawShape(this.graphics, new Array(new Point(50, 25), new Point(75, 75), new Point(25, 75)));
					this.graphics.endFill();
				</code>
		*/
		inline public static function drawShape(graphics:Graphics, points:Array<Point>):Void {
			if (points.length < 3)
				throw 'At least three Points are needed to draw a shape.';
			
			DrawUtil.drawPath(graphics, points);
			
			graphics.lineTo(points[0].x, points[0].y);
		}
		
		/**
			Draws a circular wedge.
			
			@param graphics: The location where drawing should occur.
			@param ellipse: An Ellipse object that contains the size and position of the shape.
			@param startAngle: The starting angle of wedge in degrees.
			@param arc: The sweep of the wedge in degrees.
			@usage
				<code>
					this.graphics.beginFill(0xFF00FF);
					DrawUtil.drawWedge(this.graphics, new Ellipse(0, 0, 300, 200), 0, 300);
					this.graphics.endFill();
				</code>
		*/
		public static function drawWedge(graphics:Graphics, ellipse:Ellipse, startAngle:Float, arc:Float):Void {
			if (Math.abs(arc) >= 360) {
				graphics.drawEllipse(ellipse.x, ellipse.y, ellipse.width, ellipse.height);
				return;
			}
			
			startAngle += 90;
			
			var radius:Float   = ellipse.width * .5;
			var yRadius:Float  = ellipse.height * .5;
			var x:Float        = ellipse.x + radius;
			var y:Float        = ellipse.y + yRadius;
			var segs:Int       = Math.ceil(Math.abs(arc) / 45);
			var segAngle:Float = -arc / segs;
			var theta:Float    = -(segAngle / 180) * Math.PI;
			var angle:Float    = -(startAngle / 180) * Math.PI;
			var ax:Float       = x + Math.cos(startAngle / 180 * Math.PI) * radius;
			var ay:Float       = y + Math.sin(-startAngle / 180 * Math.PI) * yRadius;
			var angleMid:Float;
			
			graphics.moveTo(x, y);
			graphics.lineTo(ax, ay);
			
			var i:Int = -1;
			while (++i < segs) {
				angle += theta;
				angleMid = angle - (theta * .5);
				
				graphics.curveTo(x + Math.cos(angleMid) * (radius / Math.cos(theta * .5)), y + Math.sin(angleMid) * (yRadius / Math.cos(theta * .5)), x + Math.cos(angle) * radius, y + Math.sin(angle) * yRadius);
			}
			
			graphics.lineTo(x, y);
		}
		
		
		/**
			Draws a rounded rectangle. Act identically to <code>Graphics.drawRoundRect</code> but allows the specification of which corners are rounded.
			
			@param graphics: The location where drawing should occur.
			@param x: The horizontal position of the rectangle.
			@param y: The vertical position of the rectangle.
			@param width: The width of the rectangle.
			@param height: The height of the rectangle.
			@param ellipseWidth: The width in pixels of the ellipse used to draw the rounded corners.
			@param ellipseHeight: The height in pixels of the ellipse used to draw the rounded corners. 
			@param topLeft: Specifies if the top left corner of the rectangle should be rounded <code>true</code>, or should be square <code>false</code>.
			@param topRight:Specifies if the top right corner of the rectangle should be rounded <code>true</code>, or should be square <code>false</code>. 
			@param bottomRight: Specifies if the bottom right corner of the rectangle should be rounded <code>true</code>, or should be square <code>false</code>.
			@param bottomLeft: Specifies if the bottom left corner of the rectangle should be rounded <code>true</code>, or should be square <code>false</code>.
			@usage
				<code>
					this.graphics.beginFill(0xFF00FF);
					DrawUtil.drawRoundRect(this.graphics, 10, 10, 200, 200, 50, 50, true, false, true, false);
					this.graphics.endFill();
				</code>
		*/
		public static function drawRoundRect(graphics:Graphics, x:Float, y:Float, width:Float, height:Float, ellipseWidth:Float, ellipseHeight:Float, ?topLeft:Bool = true, ?topRight:Bool = true, ?bottomRight:Bool = true, ?bottomLeft:Bool = true):Void {
			var radiusWidth:Float  = ellipseWidth * 0.5;
			var radiusHeight:Float = ellipseHeight * 0.5;
			
			if (topLeft)
				graphics.moveTo(x + radiusWidth, y);
			else
				graphics.moveTo(x, y);
			
			if (topRight) {
				graphics.lineTo(x + width - radiusWidth, y);
				graphics.curveTo(x + width, y, x + width, y + radiusHeight);
			} else
				graphics.lineTo(x + width, y);
			
			if (bottomRight) {
				graphics.lineTo(x + width, y + height - radiusHeight);
				graphics.curveTo(x + width, y + height, x + width - radiusWidth, y + height);
			} else
				graphics.lineTo(x + width, y + height);
			
			if (bottomLeft) {
				graphics.lineTo(x + radiusWidth, y + height);
				graphics.curveTo(x, y + height, x, y + height - radiusHeight);
			} else
				graphics.lineTo(x, y + height);
			
			if (topLeft) {
				graphics.lineTo(x, y + radiusHeight);
				graphics.curveTo(x, y, x + radiusWidth, y);
			} else
				graphics.lineTo(x, y);
		}
	}
