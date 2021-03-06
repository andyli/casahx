﻿/*
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
package org.casalib.time; 
	import flash.events.Event;
	import flash.events.IEventDispatcher;
	import org.casalib.events.SequenceEvent;
	import org.casalib.core.UInt;
	import org.casalib.control.IResumable;
	import org.casalib.time.Interval;
	import org.casalib.process.Process;
	
	/*[Event(name="start", type="org.casalib.events.SequenceEvent")]*/
	/*[Event(name="stop", type="org.casalib.events.SequenceEvent")]*/
	/*[Event(name="resume", type="org.casalib.events.SequenceEvent")]*/
	/*[Event(name="loop", type="org.casalib.events.SequenceEvent")]*/
	/*[Event(name="complete", type="org.casalib.events.SequenceEvent")]*/
	
	/**
		Creates a sequence of methods calls that wait for a specified event and/or delay.
		
		@author Jon Adams
		@author Aaron Clinger
		@version 09/06/09
		@example
			<code>
				package {
					import org.casalib.display.CasaMovieClip;
					import org.casalib.display.CasaSprite;
					import org.casalib.events.SequenceEvent;
					import org.casalib.time.Sequence;
					
					
					public class MyExample extends CasaMovieClip {
						protected var _sequence:Sequence;
						protected var _box:CasaSprite;
						
						
						public function MyExample() {
							this._box = new CasaSprite();
							this._box.graphics.beginFill(0xFF00FF);
							this._box.graphics.drawRect(0, 0, 250, 250);
							this._box.graphics.endFill();
							
							this.addChild(this._box);
							
							this._sequence = new Sequence(true);
							this._sequence.addTask(this._hideBox, 3000);
							this._sequence.addTask(this._showBox, 1000);
							
							this._sequence.addEventListener(SequenceEvent.LOOP, this._onLoop);
							
							this._sequence.start();
						}
						
						protected function _hideBox():void {
							this._box.visible = false;
						}
						
						protected function _showBox():void {
							this._box.visible = true;
						}
						
						protected function _onLoop(e:SequenceEvent):void {
							trace("Sequence has looped " + e.loops + " times.");
						}
					}
				}
			</code>
			
			With events:
			<code>
				package {
					import fl.motion.easing.Bounce;
					import fl.motion.easing.Elastic;
					import fl.motion.easing.Linear;
					import org.casalib.display.CasaMovieClip;
					import org.casalib.display.CasaSprite;
					import org.casalib.events.TweenEvent;
					import org.casalib.time.Sequence;
					import org.casalib.transitions.PropertyTween;
					
					
					public class MyExample extends CasaMovieClip {
						protected var _sequence:Sequence;
						protected var _box:CasaSprite;
						protected var _slideOver:PropertyTween;
						protected var _slideDown:PropertyTween;
						protected var _rotate:PropertyTween;
						
						
						public function MyExample() {
							this._box = new CasaSprite();
							this._box.graphics.beginFill(0xFF00FF);
							this._box.graphics.drawRect(0, 0, 50, 50);
							this._box.graphics.endFill();
							
							this.addChild(this._box);
							
							this._slideOver = new PropertyTween(this._box, "x", Linear.easeNone, 100, 1);
							this._slideDown = new PropertyTween(this._box, "y", Bounce.easeOut, 200, 4);
							this._rotate    = new PropertyTween(this._box, "rotation", Elastic.easeOut, 720, 10);
							
							this._sequence = new Sequence();
							this._sequence.addTask(this._slideOver.start, 0, this._slideOver, TweenEvent.COMPLETE);
							this._sequence.addTask(this._slideDown.start, 2000, this._slideDown, TweenEvent.COMPLETE);
							this._sequence.addTask(this._rotate.start, 1000, this._rotate, TweenEvent.COMPLETE);
							this._sequence.start();
						}
					}
				}
			</code>
	*/
	class Sequence extends Process implements IResumable {
		
		public var _current(get__current, null) : Task ;
		public var looping(get_looping, set_looping) : Bool;
		public var loops(get_loops, null) : UInt ;
		var _isLooping:Bool;
		var _hasDelayCompleted:Bool;
		var _sequence:Array<Task>;
		var _interval:Interval;
		var _currentTaskId:Int;
		var _loops:UInt;
		
		
		/**
			Creates a new Sequence.
			
			@param isLooping: Indicates if the Sequence repeats once completed <code>true</code>; or stops <code>false</code>.
		*/
		public function new(?isLooping:Bool = false) {
			super();
			
			this.looping   = isLooping;
			this._sequence = new Array<Task>();
			this._interval = Interval.setTimeout(this._delayComplete, 1);
		}
		
		/**
			Adds a method to be called to the Sequence.
			
			@param closure: The function to execute.
			@param delay: The time in milliseconds before the method will be called.
			@param scope: The event dispatcher scope in which to listen for the complete event.
			@param completeEventName: The name of the event the class waits to receive before continuing.
			@param position: Specifies the index of the insertion in the sequence order; defaults to the next position.
		*/
		public function addTask(closure:Dynamic, ?delay:Int = 0, ?scope:IEventDispatcher = null, ?completeEventName:String = null, ?position:Int = -1):Void {
			this._sequence.insert((position == -1) ? this._sequence.length : position, new Task(closure, delay, scope, completeEventName));
		}
		
		/**
			Removes a method from being called by the Sequence.
			
			@param closure: The function to remove from execution.
		*/
		public function removeTask(closure:Dynamic):Void {
			var l:Int = this._sequence.length;
			
			while (l-- > 0) {
				if (this._sequence[l].closure == closure) {
					this._sequence[l] = null;
					this._sequence.splice(l, 1);
				}
			}
		}
		
		/**
			Starts the Sequence from the beginning.
			
			@sends SequenceEvent#START - Dispatched when Sequence starts.
		*/
		public override function start():Void {
			super.start();
			
			this._removeCurrentListener();
			
			this._currentTaskId = -1;
			this._loops         = 0;
			
			resetInterval();
			this._startDelay();
			
			this._createEvent(SequenceEvent.START);
		}
		
		/**
			Stops the Sequence at its current position.
			
			@sends SequenceEvent#STOP - Dispatched when Sequence stops.
		*/
		public override function stop():Void {
			if (!this.running)
				return;
			
			super.stop();
			
			resetInterval();
			
			this._createEvent(SequenceEvent.STOP);
		}
		
		/**
			Resumes sequence from {@link #stop stopped} position.
			
			@sends SequenceEvent#RESUME - Dispatched when Sequence is resumed.
		*/
		public function resume():Void {
			if (this.running)
				return;
			
			if (this._currentTaskId == -1) {
				this.start();
				return;
			}
			
			this._isRunning = true;
			
			if (this._hasDelayCompleted)
				this._startDelay();
			else
				this._interval.start();
			
			this._createEvent(SequenceEvent.RESUME);
		}
		
		/**
			Indicates if the Sequence repeats once completed <code>true</code>; or stops <code>false</code>.
		*/
		private function get_looping():Bool{
			return this._isLooping;
		}
		
		private function set_looping(isLooping:Bool):Bool{
			return this._isLooping = isLooping;
		}
		
		/**
			The number of times the sequence has run since it {@link #start started}.
		*/
		private function get_loops():UInt {
			return this._loops;
		}
		
		public override function destroy():Void {
			this._removeCurrentListener();
			this._interval.destroy();
			while (this._sequence.length > 0)
				this._sequence.pop();
			
			super.destroy();
		}
		
		/**
			@sends SequenceEvent#LOOP - Dispatched when Sequence is completed and is looping.
			@sends SequenceEvent#COMPLETE - Dispatched when Sequence has completed.
		*/
		function _startDelay(?e:Event = null):Void {
			if (this._currentTaskId != -1)
				this._removeCurrentListener();
			
			if (!this.running)
				return;
			
			this._hasDelayCompleted = false;
			
			if (++this._currentTaskId >= this._sequence.length) {
				this._currentTaskId--;
				
				this._removeCurrentListener();
				
				this._currentTaskId = -1;
				this._loops++;
				
				if (this.looping) {
					this._startDelay();
					
					this._createEvent(SequenceEvent.LOOP);
				} else {
					this._complete();
					this._createEvent(SequenceEvent.COMPLETE);
				}
				
				return;
			}
			
			if (this._current.delay <= 0)
				this._delayComplete();
			else {
				resetInterval();
				this._interval.delay = this._current.delay;
				this._interval.start();
			}
		}
		
		function _delayComplete():Void {
			this._hasDelayCompleted = true;
			
			if (this._current.completeEventName == null) {
				this._current.closure();
				this._startDelay();
			} else {
				this._current.scope.addEventListener(this._current.completeEventName, this._startDelay, false, 0, true);
				this._current.closure();
			}
		}
		
		function _removeCurrentListener():Void {
			if (this._currentTaskId == -1 || this._current == null)
				return;
			
			if (this._current.completeEventName != null)
				this._current.scope.removeEventListener(this._current.completeEventName, this._startDelay);
		}
		
		function get__current():Task {
			return this._sequence[this._currentTaskId];
		}
		
		function _createEvent(eventName:String):Void {
			var e:SequenceEvent = new SequenceEvent(eventName);
			e.loops             = this.loops;
			
			this.dispatchEvent(e);
		}
		
		function resetInterval():Void {
			#if cpp 
			if (_interval.running) _interval.stop();
			#elseif js
			this._interval.removeEventListeners();
			this._interval = Interval.setTimeout(this._delayComplete, 1);
			#else
			this._interval.reset();
			#end
		}
	}


private class Task {
	public var closure:Dynamic;
	public var delay:Float;
	public var scope:IEventDispatcher;
	public var completeEventName:String;
	
	
	public function new(closure:Dynamic, delay:Float, scope:IEventDispatcher, completeEventName:String) {
		this.closure           = closure;
		this.delay             = delay;
		this.scope             = scope;
		this.completeEventName = completeEventName;
	}
}