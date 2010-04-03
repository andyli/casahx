package test;

import org.casalib.events.LoadEvent;
import org.casalib.events.VideoLoadEvent;
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
		var load:LoadItem;
		
		#if flash
		testSwfLoad();
		
		load = new VideoLoad("../assets/android.flv");
		flash.Lib.current.addChild(cast(load,VideoLoad).video);
		groupLoad.addLoad(load);
		#end
		
		#if !neko
		load = new ImageLoad("../assets/logo_haxe.gif");
		load.addEventListener(LoadEvent.COMPLETE,function(e:LoadEvent):Void{
			trace("image loaded!");
		});
		groupLoad.addLoad(load);
		#end
		
		load = new DataLoad("../assets/README");
		load.addEventListener(LoadEvent.COMPLETE, function(e:LoadEvent):Void {
			var load:DataLoad = cast e.target;
			trace("text loaded!"+load.dataAsString.substr(0,20)+"...");
		});
		groupLoad.addLoad(load);
		
		groupLoad.addEventListener(LoadEvent.COMPLETE, function(e:LoadEvent):Void{
			trace("groupLoad all loaded!");
		});
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
	#end
	
	static public function main():Void {
		neash.Lib.Init("Test",400,300);
		flash.Lib.current.addChild(new TestLoad());
		neash.Lib.Run();
	}
}
