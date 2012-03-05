package test;

#if cpp
import cpp.Sys;
#elseif neko
import neko.Sys;
#end

class Test extends haxe.unit.TestRunner{
	public static function main(){
		#if cpp
			nme.Lib.create(function():Void{
				var runner = new Test();
				runner.add(new TestMath());
				runner.add(new TestUtil());
				runner.run();

				Sys.exit(0);
			},400,300,24,0xFFFFFF,nme.Lib.RESIZABLE);
		#elseif neko
			var runner = new Test();
			runner.add(new TestMath());
			//runner.add(new TestUtil()); need fixing...
			runner.run();

			Sys.exit(0);
		#else
			var runner = new Test();
			runner.add(new TestMath());
			runner.add(new TestUtil());
			runner.run();
		#end
	}
}
