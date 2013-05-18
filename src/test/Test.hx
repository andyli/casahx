package test;

class Test extends haxe.unit.TestRunner{
	public static function main():Void {
		var runner = new Test();
		runner.add(new TestMath());
		runner.add(new TestUtil());
		var success = runner.run();
		
		#if sys
		Sys.exit(success ? 0 : 1);
		#end
	}
}
