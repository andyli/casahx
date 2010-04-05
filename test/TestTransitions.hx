package test;

import feffects.easing.Elastic;
import org.casalib.events.TweenEvent;
import org.casalib.transitions.Tween;
import org.casalib.transitions.PropertyTween;
import org.casalib.process.ProcessGroup;
import org.casalib.display.CasaShape;

class TestTransitions extends flash.display.Sprite {
	public function new(){
		super();
		
		var seq = new org.casalib.time.Sequence();
		var t:Tween;
		var g:ProcessGroup;
		var s:CasaShape;
		for (i in 0...10) {
			s = new CasaShape();
			s.graphics.beginFill(Std.int(Math.random()*0xFFFFFF),1);
			s.graphics.drawRect(0,0,10,10);
			addChild(s);
			
			g = new ProcessGroup();
			
			t = new PropertyTween(s, "x", Elastic.easeOut,290,1);
			#if js
			t.addEventListener(TweenEvent.UPDATE, onTweenUpdate);
			#end
			g.addProcess(t);
			
			t = new PropertyTween(s, "y", Elastic.easeOut,Math.random()*290,1);
			#if js
			t.addEventListener(TweenEvent.UPDATE, onTweenUpdate);
			#end
			g.addProcess(t);
			
			seq.addTask(g.start,1000);
		}
		seq.start();
	}
	
	#if js
	private function onTweenUpdate(e:TweenEvent):Void{
		var t:PropertyTween = e.target;
		if (t.property == "x")
			t.scope.SetX(t.position);
		else if (t.property == "y")
			t.scope.SetY(t.position);
	}
	#end
	
	static public function main():Void {
		neash.Lib.Init("Test",400,300);
		flash.Lib.current.addChild(new TestTransitions());
		neash.Lib.Run();
	}
}
