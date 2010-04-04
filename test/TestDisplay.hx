package test;

import flash.display.Sprite;
import org.casalib.display.CasaBitmap;
import org.casalib.display.CasaMovieClip;
import org.casalib.display.CasaShape;
#if flash
import org.casalib.display.CasaSimpleButton;
#end
import org.casalib.display.CasaSprite;
import org.casalib.display.CasaTextField;
import org.casalib.display.ReversibleMovieClip;

class TestDisplay extends Sprite{
	public function new() {
		super();
		
		new CasaBitmap();
		new CasaMovieClip();
		new CasaShape();
		#if flash
		new CasaSimpleButton();
		#end
		new CasaSprite();
		new CasaTextField();
		new ReversibleMovieClip();
	}

	static public function main():Void {
		neash.Lib.Init("Test",400,300);
		flash.Lib.current.addChild(new TestDisplay());
		neash.Lib.Run();
	}
}
