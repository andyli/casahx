package test;

import haxe.unit.TestCase;

import org.casalib.events.LoadEvent;
import org.casalib.load.ImageLoad;
import org.casalib.load.SwfLoad;
import org.casalib.load.VideoLoad;

class TestLoad extends TestCase {
	function testSwfLoad():Void {
		var swfL = new SwfLoad("../assets/circle.swf");
		var started = false;
		var completed = false;
		var stopped = false;
		var progressed = false;
		
		var onStart = function (e:LoadEvent):Void{
			started = true;
		}
		var onStop = function (e:LoadEvent):Void{
			stopped = true;
		}
		var onComplete = function (e:LoadEvent):Void{
			completed = true;
		}
		var onProgress = function (e:LoadEvent):Void{
			progressed = true;
		}
		
		swfL.addEventListener(LoadEvent.START,onStart); 
		swfL.addEventListener(LoadEvent.STOP,onStop);
		swfL.addEventListener(LoadEvent.PROGRESS,onProgress);
		swfL.addEventListener(LoadEvent.COMPLETE,onComplete);
		
		swfL.start();
		this.assertTrue(swfL.loading);
		this.assertFalse(swfL.loaded);
		this.assertTrue(started);
	}
	
	function testVideoLoad():Void {
		var load = new VideoLoad("../assets/android.flv");
		var started = false;
		var completed = false;
		var stopped = false;
		var progressed = false;
		
		var onStart = function (e:LoadEvent):Void{
			started = true;
		}
		var onStop = function (e:LoadEvent):Void{
			stopped = true;
		}
		var onComplete = function (e:LoadEvent):Void{
			completed = true;
		}
		var onProgress = function (e:LoadEvent):Void{
			progressed = true;
		}
		
		load.addEventListener(LoadEvent.START,onStart); 
		load.addEventListener(LoadEvent.STOP,onStop);
		load.addEventListener(LoadEvent.PROGRESS,onProgress);
		load.addEventListener(LoadEvent.COMPLETE,onComplete);
		
		load.start();
		this.assertTrue(load.loading);
		this.assertFalse(load.loaded);
		this.assertTrue(started);
	}
}
