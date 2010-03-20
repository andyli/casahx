package test;

import haxe.unit.TestRunner;
import org.casalib.math.Percent;

class Test extends TestRunner{
	public static function main(){
		#if !(flash || php)
		neash.Lib.Init("Test",400,300);
		#end
		var runner = new Test();
		#if flash runner.add(new TestLoad()); #end
		runner.add(new TestMath());
		runner.add(new TestUtil());
		runner.run();
		//#if !(flash || php)
		//neash.Lib.Run();
		//#end
	}
}
