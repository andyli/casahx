package test;

import haxe.unit.TestRunner;
import org.casalib.math.Percent;

class Test extends TestRunner{
	public static function main(){
		#if (cpp || neko)
		nme.Lib.create(function():Void{
			var runner = new Test();
			runner.add(new TestMath());
			runner.add(new TestUtil());
			runner.run();
		},400,300,24,0xFFFFFF,nme.Lib.RESIZABLE);
		return;
		#end
		
		var runner = new Test();
		runner.add(new TestMath());
		runner.add(new TestUtil());
		runner.run();
	}
}
