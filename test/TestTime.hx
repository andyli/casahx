package test;

import org.casalib.time.EnterFrame;
import org.casalib.time.FrameDelay;
import org.casalib.time.FrameTime;
import org.casalib.time.FrameTimeStopwatch;
import org.casalib.time.Inactivity;
import org.casalib.time.Interval;
import org.casalib.time.Sequence;
import org.casalib.time.Stopwatch;

class TestTime extends flash.display.Sprite {
	public function new(){
		super();
	}
	
	static public function main():Void {
		neash.Lib.Init("Test",400,300);
		flash.Lib.current.addChild(new TestTime());
		neash.Lib.Run();
	}
}
