package org.casalib.events; 
	import flash.events.Event;
	import org.casalib.core.UInt;
	
	
	/**
		An event dispatched from {@link Sequence}.
		
		@author Jon Adams
		@author Aaron Clinger
		@version 10/27/08
	*/
	class SequenceEvent extends Event {
		
		public var loops(getLoops, setLoops) : UInt;
		inline public static var COMPLETE:String = 'complete';
		inline public static var RESUME:String   = 'resume';
		inline public static var START:String    = 'start';
		inline public static var STOP:String     = 'stop';
		inline public static var LOOP:String     = 'loop';
		var _loops:UInt;
		
		
		/**
			Creates a new SequenceEvent.
			
			@param type: The type of event.
			@param bubbles: Determines whether the Event object participates in the bubbling stage of the event flow.
			@param cancelable: Determines whether the Event object can be canceled.
		*/
		public function new(type:String, ?bubbles:Bool = false, ?cancelable:Bool = false) {
			super(type, bubbles, cancelable);
		}
		
		/**
			The number of times the sequence has run.
		*/
		private function getLoops():UInt{
			return this._loops;
		}
		
		private function setLoops(loops:UInt):UInt{
			this._loops = loops;
			return loops;
		}
		
		#if flash
		/**
			@return A string containing all the properties of the event.
		*/
		public override function toString():String {
			return formatToString('SequenceEvent', 'type', 'bubbles', 'cancelable', 'loops');
		}
		#end
		
		/**
			@return Duplicates an instance of the event.
		*/
		public override function clone():Event {
			var e:SequenceEvent = new SequenceEvent(this.type, this.bubbles, this.cancelable);
			e.loops = this.loops;
			
			return e;
		}
	}
