package test;

import haxe.unit.TestCase;
import flash.geom.Point;
import org.casalib.math.Percent;
import org.casalib.math.Range;
import org.casalib.math.geom.Ellipse;
import org.casalib.math.geom.Point3d;

class TestMath extends TestCase {
	public function testPercent():Void {
		var p1 = new Percent(1.5,true);
		var p2 = new Percent(150,false);
		var p3 = p1.clone();
		var p4 = new Percent(-1);
		this.assertTrue(p1.equals(p2));
		this.assertTrue(p2.equals(p3));
		this.assertFalse(p4.equals(p1));
	}
	
	public function testRange():Void {
		var r1 = new Range(0,100);
		var r2 = r1.clone();
		var r3 = new Range(-100,100);
		this.assertTrue(r1.equals(r2));
		this.assertFalse(r2.equals(r3));
		this.assertEquals(0.2,r1.getPercentOfValue(20).decimalPercentage);
		this.assertEquals(-30.0,r2.getValueOfPercent(new Percent(-0.3)));
		this.assertTrue(r3.isWithinRange(-99.99));
		this.assertTrue(r1.overlaps(r3));
		this.assertFalse(r1.contains(r3));
	}
	
	public function testEllipse():Void {
		var e1 = new Ellipse(10,20,20,30);
		var e2 = e1.clone();
		var e3 = new Ellipse(20,-1,60,40);
		this.assertTrue(e1.equals(e2));
		this.assertFalse(e3.equals(e1));
		this.assertTrue(e1.containsPoint(e1.center));
		this.assertEquals(e3.area,e1.area*4);
		this.assertEquals(e3.perimeter,e1.perimeter*2);
		e1.height = 20;
		this.assertTrue(e1.getPointOfDegree(45).equals(e1.getPointOfDegree(405)));
	}
	
	public function testPoint3d():Void{
		var p1 = new Point3d(-1,0,1);
		var p2 = p1.clone();
		var p3 = new Point3d(12,54,-123);
		var p4 = Point3d.interpolate(p1,p3,new Percent(0.2));
		this.assertTrue(p1.equals(p2));
		this.assertEquals(Point3d.distance(p1,p3),Point3d.distance(p1,p4)*5);
		this.assertTrue(p1.subtract(p2).equals(new Point3d()));
	}
}
