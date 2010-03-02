package test;

import haxe.unit.TestRunner;
import org.casalib.math.Percent;

class Test extends TestRunner{
	public static function main(){
		var runner = new Test();
		runner.add(new TestMath());
		runner.add(new TestUtil());
		runner.run();
	}
}
