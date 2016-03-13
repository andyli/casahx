package test;

class Test {
	public static function main():Void {
		var runner = new haxe.unit.TestRunner();
		runner.add(new TestMath());
		runner.add(new TestUtil());
		var success = runner.run();
		
		#if sys
		Sys.exit(success ? 0 : 1);
		#end
	}
}
