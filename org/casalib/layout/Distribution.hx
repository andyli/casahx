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
package org.casalib.layout; 
	import flash.display.DisplayObject;
	import flash.geom.Point;
	import org.casalib.display.CasaSprite;
	import org.casalib.util.DisplayObjectUtil;
	
	using org.casalib.util.ArrayUtil;
	
	typedef DisplayObjectPointLink = {
		displayObject:DisplayObject,
		point:Point
	}
	
	/**
		Creates the mechanism to distribute DisplayObjects to a vertical or horzontal grid of columns and rows.
		
		@author Aaron Clinger
		@author Jon Adams
		@version 03/28/10
		@example
			<code>
				package {
					import org.casalib.display.CasaMovieClip;
					import org.casalib.display.CasaSprite;
					import org.casalib.layout.Distribution;
					import code.org.casalib.util.DisplayObjectUtil;
					
					
					public class MyExample extends CasaMovieClip {
						public var dist:Distribution;
						
						public function MyExample() {
							super();
							
							this.dist = new Distribution(315);
							this.dist.setMargin(0, 5, 5, 0);
							
							this.addChild(this.dist);
							
							var l:uint = 10;
							var s:CasaSprite;
							
							while (l--) {
								s = new CasaSprite();
								s.graphics.beginFill(0xFF00FF);
								s.graphics.drawRect(0, 0, 100, 100);
								s.graphics.endFill();
								
								this.dist.addChild(s);
							}
							
							this.dist.position();
						}
					}
				}
			</code>
	*/
	class Distribution extends CasaSprite {
		
		public var marginBottom(getMarginBottom, setMarginBottom) : Float ;
		public var marginLeft(getMarginLeft, setMarginLeft) : Float ;
		public var marginRight(getMarginRight, setMarginRight) : Float ;
		public var marginTop(getMarginTop, setMarginTop) : Float ;
		public var size(getSize, setSize) : Float ;
		public var vertical(getVertical, setVertical) : Bool ;
		var _dimensions:Array<DisplayObjectPointLink>;
		var _marginTop:Float;
		var _marginRight:Float;
		var _marginBottom:Float;
		var _marginLeft:Float;
		var _size:Float;
		var _isSnap:Bool;
		var _isVert:Bool;
		
		
		/**
			Creates a Distribution.
			
			@param size: The maximum width or height of the distribution. If <code>isVertical</code> argument is <code>false</code> you are setting the width of the distribution before wrapping, if <code>true</code> you're setting the height before wrapping.
			@param isVertical: Indicates to position children left-to-right top-to-bottom <code>false</code>, or to position children top-to-bottom left-to-right <code>true</code>.
			@param snapToPixel: Force the position of all children to whole pixels <code>true</code>, or to let items be positioned on sub-pixels <code>false</code>.
		*/
		public function new(?size:Float, ?isVertical:Bool = false, ?snapToPixel:Bool = true) {
			super();
			
			this.size          = size == null ? Math.POSITIVE_INFINITY : size;
			this.vertical      = isVertical;
			this._dimensions   = new Array<DisplayObjectPointLink>();
			this._isSnap       = snapToPixel;
			this._marginTop    = 0;
			this._marginRight  = 0;
			this._marginBottom = 0;
			this._marginLeft   = 0;
		}
		
		/**
			Allows the child's dimensions for positioning to be defined instead of using the child's native width and height.
			
			@param child: The DisplayObject instance to add as a child of this Distribution container.
			@param width: Specifies the width Distribution should use when positioning the <code>child</code>, or <code>NaN</code> if you want to use the childs native width.
			@param height: Specifies the height Distribution should use when positioning the <code>child</code>, or <code>NaN</code> if you want to use the childs native height.
			@return The DisplayObject instance that you pass in the <code>child</code> parameter.
			@usageNote If you do not wish to define custom dimensions for the child, you can use <code>addChild</code> instead.
		*/
		public function addChildWithDimensions(child:DisplayObject, ?width:Float, ?height:Float):DisplayObject {
			var old = this._dimensions.getItemByKey("displayObject",child);
			if (old != null) this._dimensions.remove(old);
			
			this._dimensions.push({displayObject:child, point:new Point(width == null ? Math.NaN : width, height == null ? Math.NaN : height)});
			
			#if flash
			return this.addChild(child);
			#else
			this.addChild(child);
			return child;
			#end
		}
		
		/**
			Defines the spacing between children in the distribution.
			
			@param top: Sets the top spacing of the children.
			@param right: Sets the right spacing of the children.
			@param bottom: Sets the bottom spacing of the children.
			@param left: Sets the left spacing of the children.
		*/
		public function setMargin(?top:Int = 0, ?right:Int = 0, ?bottom:Int = 0, ?left:Int = 0):Void {
			this.marginTop    = top;
			this.marginRight  = right;
			this.marginBottom = bottom;
			this.marginLeft   = left;
		}
		
		/**
			The top spacing of the children.
		*/
		private function setMarginTop(top:Float):Float {
			this._marginTop = top;
			return top;
		}
		
		private function getMarginTop():Float {
			return this._marginTop;
		}
		
		/**
			The right spacing of the children.
		*/
		private function setMarginRight(right:Float):Float {
			this._marginRight = right;
			return right;
		}
		
		private function getMarginRight():Float {
			return this._marginRight;
		}
		
		/**
			The bottom spacing of the children.
		*/
		private function setMarginBottom(bottom:Float):Float {
			this._marginBottom = bottom;
			return bottom;
		}
		
		private function getMarginBottom():Float {
			return this._marginBottom;
		}
		
		/**
			The left spacing of the children.
		*/
		private function setMarginLeft(left:Float):Float {
			this._marginLeft = left;
			return left;
		}
		
		private function getMarginLeft():Float {
			return this._marginLeft;
		}
		
		/**
			The maximum width or height of the distribution. If {@link #vertical} is <code>false</code> you are setting the width of the distribution before wrapping, if <code>true</code> you're setting the height before wrapping.
		*/
		private function setSize(s:Float):Float {
			this._size = s;
			return s;
		}
		
		private function getSize():Float {
			return this._size;
		}
		
		/**
			Indicates to position children left-to-right top-to-bottom <code>false</code>, or to position children top-to-bottom left-to-right <code>true</code>.
		*/
		private function setVertical(isVertical:Bool):Bool {
			this._isVert = isVertical;
			return isVertical;
		}
		
		private function getVertical():Bool {
			return this._isVert;
		}
		
		/**
			Arranges the children of the Distribution.
		*/
		public function position():Void {
			var i:Int          = -1;
			var column:Int  = 0;
			var row:Int     = 0;
			var largest:Int = 0;
			var item:DisplayObject;
			var size:Point;
			var xPo:Float;
			var yPo:Float;
			var w:Float;
			var h:Float;
			
			while (++i < this.numChildren) {
				item = this.getChildAt(i);
				var pair = this._dimensions.getItemByKey("displayObject",item);
				size = (pair == null) ? new Point(item.width, item.height) : new Point(Math.isNaN(pair.point.x) ? item.width : pair.point.x, Math.isNaN(pair.point.y) ? item.height : pair.point.y);
				
				w = size.x + this._marginLeft + this._marginRight;
				h = size.y + this._marginTop + this._marginBottom;
				
				if (!this.vertical) {
					column += Std.int(w);
					
					if (column > this.size) {
						row += (largest == 0) ? row : largest;
						
						largest = 0;
						column  = Std.int(w);
					}
					
					if (h > largest)
						largest = Std.int(h);
					
					xPo = column - size.x - this._marginRight;
					yPo = row + this._marginTop;
				} else {
					row += Std.int(h);
					
					if (row > this.size) {
						column += (largest == 0) ? column : largest;
						
						largest = 0;
						row     = Std.int(h);
					}
					
					if (w > largest)
						largest = Std.int(w);
					
					xPo = column + this._marginLeft;
					yPo = row - size.y - this._marginBottom;
				}
				
				this._positionItem(item, this._isSnap ? Math.round(xPo) : xPo, this._isSnap ? Math.round(yPo) : yPo);
			}
		}
		
		public override function destroy():Void {
			while (this._dimensions.length > 0) {
				var link = this._dimensions.pop();
				link.displayObject = null;
				link.point = null;	
			}
			
			super.destroy();
		}
		
		function _positionItem(target:DisplayObject, xPo:Float, yPo:Float):Void {
			var offset:Point = DisplayObjectUtil.getOffsetPosition(target);
			
			target.x = xPo + offset.x;
			target.y = yPo + offset.y;
		}
	}
