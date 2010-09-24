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
#if (flash || js || neko)
import org.casalib.display.ReversibleMovieClip; //TO-DO for cpp
#end

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
		#if (flash || js)
		new ReversibleMovieClip();
		#end
	}

	static public function main():Void {
		var init = function(){
			flash.Lib.current.addChild(new TestDisplay());
		}

		#if (cpp || neko)
		nme.Lib.create(init,400,300,25,0xFFFFFF,nme.Lib.RESIZABLE);
		#else
		init();
		#end
	}
}
