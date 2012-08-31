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
package org.casalib.transitions; 
	
	/**
		A simple property tween class that extends {@link Tween}.
		
		@author Aaron Clinger
		@author Mike Creighton
		@author Jon Adams
		@version 05/04/11
		@example
			<code>
				package {
					import fl.motion.easing.Bounce;
					import org.casalib.display.CasaMovieClip;
					import org.casalib.display.CasaSprite;
					import org.casalib.transitions.PropertyTween;
					
					
					public class MyExample extends CasaMovieClip {
						protected var _box:CasaSprite;
						protected var _tween:PropertyTween;
						
						
						public function MyExample() {
							super();
							
							this._box = new CasaSprite();
							this._box.graphics.beginFill(0xFF00FF);
							this._box.graphics.drawRect(0, 0, 25, 25);
							this._box.graphics.endFill();
							
							this.addChild(this._box);
							
							this._tween = new PropertyTween(this._box, "x", Bounce.easeOut, 200, 5);
							this._tween.start();
						}
					}
				}
			</code>
		@usageNote If you want to tween a value other than a property use {@link Tween}.
	*/
	class PropertyTween extends Tween {
		
		override public var position(getPosition, setPosition) : Float;
		public var property(getProperty, null) : String ;
		public var scope(getScope, null) : Dynamic ;
		var _scope:Dynamic;
		var _property:String;
		
		
		/**
			A convenience method that creates and starts a new PropertyTween and {@link Tween#start starts} it automatically.
			
			@param scope: An object that contains the property specified by <code>property</code>.
			@param property: Name of the property you want to tween.
			@param equation: The tween equation.
			@param endPos: The ending value of the transition.
			@param duration: Length of time of the transition.
			@param useFrames: Indicates to use frames <code>true</code>, or seconds <code>false</code> in relation to the value specified in the <code>duration</code> parameter.
			@return: A {@PropertyTween property}.
		 */
		public static function to(scope:Dynamic, property:String, equation:Dynamic, endPos:Float, duration:Float, ?useFrames:Bool = false):PropertyTween {
			var pt:PropertyTween = new PropertyTween(scope, property, equation, endPos, duration, useFrames);
			pt.start();
			
			return pt;
		}
		
		/**
			A convenience method that creates and starts a new PropertyTween and {@link Tween#start starts} it automatically.
			
			@param scope: An object that contains the property specified by <code>property</code>.
			@param property: Name of the property you want to tween.
			@param equation: The tween equation.
			@param startPos: The beginning value of the transition.
			@param duration: Length of time of the transition.
			@param useFrames: Indicates to use frames <code>true</code>, or seconds <code>false</code> in relation to the value specified in the <code>duration</code> parameter.
			@return: A {@PropertyTween property}.
		 */
		public static function from(scope:Dynamic, property:String, equation:Dynamic, startPos:Float, duration:Float, ?useFrames:Bool = false):PropertyTween {
			var endPos:Float = Reflect.getProperty(scope,property);
			Reflect.setProperty(scope,property,startPos);
			
			var pt:PropertyTween = new PropertyTween(scope, property, equation, endPos, duration, useFrames);
			pt.start();
			
			return pt;
		}
		
		/**
			Creates and defines a new PropertyTween.
			
			@param scope: An object that contains the property specified by <code>property</code>.
			@param property: Name of the property you want to tween.
			@param equation: The tween equation.
			@param endPos: The ending value of the transition.
			@param duration: Length of time of the transition.
			@param useFrames: Indicates to use frames <code>true</code>, or seconds <code>false</code> in relation to the value specified in the <code>duration</code> parameter.
			@usageNote The function specified in the <code>equation</code> parameter must follow the (currentTime, startPosition, endPosition, totalTime) parameter standard.
		*/
		public function new(scope:Dynamic, property:String, equation:Dynamic, endPos:Float, duration:Float, ?useFrames:Bool = false) {
			this._scope    = scope;
			this._property = property;
			
			super(equation, this.position, endPos, duration, useFrames);
		}
		
		/**
			@exclude
		*/
		public override function start():Void {
			this._initPropertyTween();
			
			super.start();
		}
		
		/**
			@exclude
		*/
		public override function continueTo(endPos:Float, duration:Float):Void {
			this._initPropertyTween();
			
			super.continueTo(endPos, duration);
		}
		
		/**
			@exclude
		*/
		private override function getPosition():Float{
			return Reflect.getProperty(scope,property);
		}
		
		/**
			@exclude
		*/
		private override function setPosition(pos:Float):Float{
			Reflect.setProperty(scope,property,pos);
			return pos;
		}
		
		/**
			Retrieves the object defined as scope in the class' constructor.
		*/
		private function getScope():Dynamic {
			return this._scope;
		}
		
		/**
			Retrieves the property as a String defined in the class' constructor.
		*/
		private function getProperty():String {
			return this._property;
		}
		
		function _initPropertyTween():Void {
			this._begin   = this.position;
			this._diff    = this._end - this._begin;
		}
	}
