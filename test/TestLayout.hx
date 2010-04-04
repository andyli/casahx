package test;

class TestLayout extends flash.display.Sprite {
	public function new(){
		super();
		
		var d = new org.casalib.layout.Distribution(100);
		for (i in 0...42) {
			var s = new org.casalib.display.CasaShape();
			s.graphics.beginFill(Std.int(Math.random()*0xFFFFFF),1);
			s.graphics.drawRect(0,0,10,10);
			d.addChild(s);
		}
		for (i in 0...10) {
			var s = new org.casalib.display.CasaShape();
			s.graphics.beginFill(Std.int(Math.random()*0xFFFFFF),1);
			s.graphics.drawRect(0,0,20,20);
			d.addChildWithDimensions(s,30,30);
		}
		d.position();
		this.addChild(d);
	}
	
	static public function main():Void {
		neash.Lib.Init("Test",400,300);
		flash.Lib.current.addChild(new TestLayout());
		neash.Lib.Run();
	}
}
