package test;

import flash.display.Sprite;
import flash.events.Event;

import org.casalib.events.InactivityEvent;
import org.casalib.time.EnterFrame;
import org.casalib.time.FrameDelay;
import org.casalib.time.FrameTime;
import org.casalib.time.FrameTimeStopwatch;
import org.casalib.time.Inactivity;
import org.casalib.time.Interval;
import org.casalib.time.Sequence;
import org.casalib.time.Stopwatch;
import org.casalib.util.StageReference;

class TestTime extends Sprite {
	var enterFrame:Sprite;

	public function new(){
		super();
		
		StageReference.setStage(flash.Lib.current.stage);
		
		var stopwatch:Stopwatch = new Stopwatch();
		stopwatch.start();
		
		enterFrame = new Sprite();
		enterFrame.graphics.beginFill(0,1);
		enterFrame.graphics.drawRect(0,0,10,10);
		this.addChild(enterFrame);
		
		EnterFrame.getInstance().addEventListener(Event.ENTER_FRAME, onEnterFrame);
		
		var fd = new FrameDelay(onFrameDelay,30,["passed 30 frames"]);
		fd.start();
		
		var ina = new Inactivity(1000);
		ina.addEventListener(InactivityEvent.INACTIVE,onInactive);
		ina.addEventListener(InactivityEvent.ACTIVATED,onActive);
		ina.start();
		
		Interval.setTimeout(function(msg:String):Void{
			trace(msg);
		},5000,["interval 500 passed"]).start();
		
		var s = new Sequence();
		s.addTask(function(){trace("Sequence 1");});
		s.addTask(function(){trace("Sequence 2");});
		s.addTask(function(){trace("Sequence 3...");});
		s.addTask(function(){trace("Sequence 4");},500);
		s.start();
		
		trace("stopwatch" + stopwatch.time);
	}
	
	function onEnterFrame(e:Event):Void {
		enterFrame.visible = !enterFrame.visible;
	}
	
	function onFrameDelay(msg:String):Void {
		trace(msg);
		trace(FrameTime.getInstance().time);
	}
	
	function onInactive(e:InactivityEvent):Void {
		trace("you've been inactive for " + e.milliseconds);
	}
	
	function onActive(e:InactivityEvent):Void {
		trace("you're active again");
	}
	
	
	static public function main():Void {
		var init = function(){
			flash.Lib.current.addChild(new TestTime());
		}

		#if (cpp || neko)
		nme.Lib.create(init,400,300,25,0xFFFFFF,nme.Lib.RESIZABLE);
		#else
		init();
		#end
	}
}
