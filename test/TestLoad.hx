package test;

import org.casalib.events.LoadEvent;
import org.casalib.load.CasaLoader;
import org.casalib.load.ImageLoad;
import org.casalib.load.DataLoad;
import org.casalib.load.GroupLoad;
import org.casalib.load.LoadItem;
#if flash 
import org.casalib.load.AudioLoad;
import org.casalib.load.SwfLoad;
import org.casalib.load.VideoLoad; 
#end

class TestLoad extends flash.display.Sprite {
	public function new(){
		super();
		
		var groupLoad:GroupLoad = new GroupLoad();
		
		#if flash
		testSwfLoad();
		testVideoLoad();
		#end
		
		var load = new DataLoad("../assets/README");
		load.addEventListener(LoadEvent.COMPLETE, function(e:LoadEvent):Void {
			var load:DataLoad = cast e.target;
			trace(load.dataAsString);
		});
		groupLoad.addLoad(load);
		groupLoad.start();
	}
	
	#if flash
	function testSwfLoad():Void {
		var swfL = new SwfLoad("../assets/circle.swf");
		
		var onStart = function (e:LoadEvent):Void{
			trace("swf load started");
		}
		var onStop = function (e:LoadEvent):Void{
			trace("swf load stopped");
		}
		var onComplete = function (e:LoadEvent):Void{
			trace("swf load completed");
			
			var swfl:SwfLoad = cast e.target;
			flash.Lib.current.addChild(swfl.contentAsMovieClip);
		}
		var onProgress = function (e:LoadEvent):Void{
			trace("swf load progress");
		}
		
		swfL.addEventListener(LoadEvent.START,onStart); 
		swfL.addEventListener(LoadEvent.STOP,onStop);
		swfL.addEventListener(LoadEvent.PROGRESS,onProgress);
		swfL.addEventListener(LoadEvent.COMPLETE,onComplete);
		
		swfL.start();
	}
	
	function testVideoLoad():Void {
		var load = new VideoLoad("../assets/android.flv");
		
		var onStart = function (e:LoadEvent):Void{
			trace("video load started");
		}
		var onStop = function (e:LoadEvent):Void{
			trace("video stopped");
		}
		var onComplete = function (e:LoadEvent):Void{
			trace("video completed");
			
			var load:VideoLoad = cast e.target;
			flash.Lib.current.addChild(load.video);
		}
		var onProgress = function (e:LoadEvent):Void{
			trace("video progress");
		}
		
		load.addEventListener(LoadEvent.START,onStart); 
		load.addEventListener(LoadEvent.STOP,onStop);
		load.addEventListener(LoadEvent.PROGRESS,onProgress);
		load.addEventListener(LoadEvent.COMPLETE,onComplete);
	}
	#end
	
	static public function main():Void {
		neash.Lib.Init("Test",400,300);
		flash.Lib.current.addChild(new TestLoad());
		neash.Lib.Run();
	}
}
