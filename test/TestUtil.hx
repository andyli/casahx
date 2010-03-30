package test;

import haxe.unit.TestCase;

#if !php import flash.display.Sprite; #end
import flash.geom.Rectangle;
import flash.geom.Point;

import org.casalib.core.UInt;
import org.casalib.math.Percent;

#if !php import org.casalib.util.AlignUtil; #end
import org.casalib.util.ArrayUtil;
import org.casalib.util.ClassUtil;
import org.casalib.util.ColorUtil;
import org.casalib.util.ConversionUtil;
import org.casalib.util.DateUtil;
#if !php import org.casalib.util.DisplayObjectUtil; #end
#if !php import org.casalib.util.DrawUtil; #end
#if flash import org.casalib.util.FlashVarUtil; #end
#if flash import org.casalib.util.FrameUtil; #end
import org.casalib.util.GeomUtil;
#if flash import org.casalib.util.LibraryManager; #end
import org.casalib.util.LoadUtil;
#if !php import org.casalib.util.LocationUtil; #end
#if !php import org.casalib.util.NavigateUtil; #end
import org.casalib.util.NumberUtil;
import org.casalib.util.ObjectUtil;
import org.casalib.util.PropertySetter;
import org.casalib.util.QueryStringUtil;
import org.casalib.util.RatioUtil;
import org.casalib.util.SingletonUtil;
#if !php import org.casalib.util.StageReference; #end
import org.casalib.util.StringUtil;
#if !php import org.casalib.util.TextFieldUtil; #end
import org.casalib.util.ValidationUtil;

//below modified from AS3's doc
private class User {
	public var name:String;
	public var age:Float;
	public function new(name:String, age:UInt) {
		this.name = name;
		this.age = age;
	}

	public function toString():String {
		return this.name + ":" + this.age;
	}
}

class TestUtil extends TestCase {
	#if flash
	public function testAlignUtil():Void {
		//just run all function once...
		
		var d = new Sprite();
		var b = new Rectangle(0,0,100,100);
		flash.Lib.current.addChild(d);
		AlignUtil.alignBottom(d,b);
		AlignUtil.alignCenter(d,b);
		AlignUtil.alignMiddleCenter(d,b);
		AlignUtil.alignLeft(d,b);
		this.assertEquals(b.x,d.x);
		AlignUtil.alignMiddle(d,b);
		AlignUtil.alignRight(d,b);
		AlignUtil.alignTop(d,b);
		this.assertEquals(b.y,d.y);
	}
	#end

	public function testArrayUtil():Void {
		var a1:Array<Int> = [1,6,3,3,8];
		
		this.assertEquals(2,ArrayUtil.indexOf(a1,3));
		this.assertEquals(3,ArrayUtil.indexOf(a1,3,3));
		
		this.assertEquals(3,ArrayUtil.lastIndexOf(a1,3));
		this.assertEquals(2,ArrayUtil.lastIndexOf(a1,3,2));
		
		var alphabet:Array<String> = ["a", "d", "e"];
		var parts:Array<String>    = ["b", "c"];
		
		this.assertTrue(ArrayUtil.addItemsAt(alphabet, parts, 1));
		this.assertEquals(5,alphabet.length);
		this.assertEquals("a,b,c,d,e",alphabet.join(','));
		
		this.assertTrue(4 == ArrayUtil.average([2, 3, 8, 3]));
		
		this.assertEquals(3, ArrayUtil.contains([1, 2, 3, 7, 7, 7, 4, 5],7));
		
		this.assertTrue(ArrayUtil.containsAll([1,2,3,4,5],[1,3,5]));
		this.assertFalse(ArrayUtil.containsAll([1,2,3,4,5],[1,3,6]));
		
		this.assertTrue(ArrayUtil.containsAny([1,2,3,4,5],[1,6,5]));
		this.assertFalse(ArrayUtil.containsAny([1,2,3,4,5],[-1,0,6]));
		
		this.assertTrue(ArrayUtil.equals([1,2,-1],[1,2,-1]));
		this.assertFalse(ArrayUtil.equals([1,2,-1],[1,2,1]));
		
		this.assertTrue(10 == ArrayUtil.getHighestValue([-123,2,5,6,2,10,-0.11]));
		
		this.assertEquals(3,ArrayUtil.getIndexOfDifference(["Red", "Blue", "Green", "Indigo", "Violet"],["Red", "Blue", "Green", "Violet"]));
		
		var item = {a:123, b:456};
		this.assertEquals(item, ArrayUtil.getItemByKey([{a:0,b:12},{a:0,b:15},item],"b",456));
		
		var array = [1,2,3,4,5,5,7,5,9,0,11,12,13];
		
		this.assertEquals(array, ArrayUtil.getItemByType([14,array,"","asdfn"],Type.getClass(array)));
		
		this.assertEquals(3, ArrayUtil.getItemsByKey([{b:12},{b:15},item,{b:15},{b:15}],"b",15).length);
		
		this.assertEquals(2, ArrayUtil.getItemsByType([14,array,"","asdfn"],String).length);
		
		this.assertTrue(1 == ArrayUtil.getLowestValue([2, 1, 5, 4, 3]));
		
		this.assertFalse(ArrayUtil.equals(ArrayUtil.randomize(array),array));
		
		this.assertEquals(4,ArrayUtil.removeDuplicates(a1).length);
		
		var testAry:Array<Int> = [1,2,1,2];
		this.assertEquals(2,ArrayUtil.removeDuplicates(testAry).length);
		
		this.assertEquals(3,ArrayUtil.removeItem(array,5));
		
		this.assertEquals(3,ArrayUtil.removeItem([1,2,3,4,5,5,[],5,9,0,11,{a:0},13],5));
		
		ArrayUtil.removeItems(array,[1,11]);
		this.assertEquals(8,array.length);
		
		ArrayUtil.retainItems(array,[0]);
		this.assertEquals(0,array[0]);
		
		this.assertEquals(5.0,ArrayUtil.sum([1,1,1,0.25,1.75]));
		
		a1 = [1,2,3,4,5];
		this.assertEquals(1, ArrayUtil.contains(a1,ArrayUtil.random(a1)));
		
		var ta:Array<Dynamic> = [{name: "Aaron", sex: "Male", hair: "Brown"}, {name: "Linda", sex: "Female", hair: "Blonde"}, {name: "Katie", sex: "Female", hair: "Brown"}, {name: "Nikki", sex: "Female", hair: "Blonde"}];
		
		this.assertEquals("Katie", ArrayUtil.getItemByKeys(ta ,{sex: "Female", hair: "Brown"}).name);
		
		var tb:Array<Dynamic> = ArrayUtil.getItemsByKeys(ta,{sex: "Female", hair: "Blonde"});
		this.assertEquals(2,tb.length);
		
		this.assertEquals("Aaron",ArrayUtil.getItemByAnyKey(ta, {sex: "Female", hair: "Brown"}).name);
		
		tb = ArrayUtil.getItemsByAnyKey(ta, {sex: "Female", hair: "Brown"});
		this.assertEquals(4,tb.length);
		
		var tc = ArrayUtil.getValuesByKey(ta, "sex");
		this.assertTrue(ArrayUtil.containsAll(["Male","Female"],cast tc));
		
		//////////Test sortOn...//////////
		var ary:Array<{a:String}> = [{a:"A"},{a:"a"},{a:"z"},{a:"Z"}];
		var dumpAry = function (ary:Array<Dynamic>,?field:String):String {
			var str:String = "[";
			for (i in 0...ary.length){
				str += field == null || ObjectUtil.isEmpty(ary[i]) ? ary[i] : Reflect.field(ary[i],field);
				str += i == ary.length-1?"":",";
			}
			return str + "]";
		}
		var str0:String;
		var str1:String;
		
		str0 = dumpAry([{a:"A"},{a:"Z"},{a:"a"},{a:"z"}]);
		str1 = dumpAry(ArrayUtil.sortOn(ary,["a"]));
		this.assertEquals(str0,str1);
		
		str0 = dumpAry([{a:"A"},{a:"Z"},{a:"a"},{a:"z"}]);
		str1 = dumpAry(ArrayUtil.sortOnLite(ary,["a"]));
		this.assertEquals(str0,str1);
		
		str0 = dumpAry([{a:"z"},{a:"a"},{a:"Z"},{a:"A"}]);
		str1 = dumpAry(ArrayUtil.sortOn(ary,["a"],ArrayUtil.SORT_DESCENDING));
		this.assertEquals(str0,str1);
		
		str0 = dumpAry([{a:"z"},{a:"a"},{a:"Z"},{a:"A"}]);
		str1 = dumpAry(ArrayUtil.sortOnLite(ary,["a"],ArrayUtil.SORT_DESCENDING));
		this.assertEquals(str0,str1);
		
		str0 = dumpAry([{a:"A"},{a:"a"},{a:"Z"},{a:"z"}]);
		str1 = dumpAry(ArrayUtil.sortOn(ary,["a"],ArrayUtil.SORT_CASEINSENSITIVE));
		this.assertEquals(str0.toLowerCase(),str1.toLowerCase());
		
		str0 = dumpAry([{a:"A"},{a:"a"},{a:"Z"},{a:"z"}]);
		str1 = dumpAry(ArrayUtil.sortOnLite(ary,["a"],ArrayUtil.SORT_CASEINSENSITIVE));
		this.assertEquals(str0.toLowerCase(),str1.toLowerCase());
		
		str0 = dumpAry([{a:"Z"},{a:"z"},{a:"A"},{a:"a"}]);
		str1 = dumpAry(ArrayUtil.sortOn(ary,["a"],ArrayUtil.SORT_CASEINSENSITIVE|ArrayUtil.SORT_DESCENDING));
		this.assertEquals(str0.toLowerCase(),str1.toLowerCase());
		
		str0 = dumpAry([{a:"Z"},{a:"z"},{a:"A"},{a:"a"}]);
		str1 = dumpAry(ArrayUtil.sortOnLite(ary,["a"],ArrayUtil.SORT_CASEINSENSITIVE|ArrayUtil.SORT_DESCENDING));
		this.assertEquals(str0.toLowerCase(),str1.toLowerCase());
		
		str0 = dumpAry([{a:"A"},{a:"Z"},{a:"a"},{a:"z"}]);
		str1 = dumpAry(ArrayUtil.sortOn(ary,["a"],ArrayUtil.SORT_UNIQUESORT));
		this.assertEquals(str0,str1);
		
		str0 = dumpAry([{a:"A"},{a:"Z"},{a:"a"},{a:"z"}]);
		str1 = dumpAry(ArrayUtil.sortOnLite(ary,["a"],ArrayUtil.SORT_UNIQUESORT));
		this.assertEquals(str0,str1);
		
		var p = str1;
		str0 = dumpAry([]);
		str1 = dumpAry(ArrayUtil.sortOn(ary,["a"],ArrayUtil.SORT_CASEINSENSITIVE|ArrayUtil.SORT_UNIQUESORT));
		this.assertEquals(str0,str1);
		
		this.assertEquals(p,dumpAry(ary));
		
		str0 = dumpAry([]);
		str1 = dumpAry(ArrayUtil.sortOnLite(ary,["a"],ArrayUtil.SORT_CASEINSENSITIVE|ArrayUtil.SORT_UNIQUESORT));
		this.assertEquals(str0,str1);
		
		this.assertEquals(p,dumpAry(ary));
		
		str0 = dumpAry([3,2,1,0]);
		str1 = dumpAry(ArrayUtil.sortOn(ary,["a"],ArrayUtil.SORT_DESCENDING|ArrayUtil.SORT_RETURNINDEXEDARRAY));
		this.assertEquals(str0,str1);
		
		str0 = dumpAry([3,2,1,0]);
		str1 = dumpAry(ArrayUtil.indicesOfSorted(ary,["a"],ArrayUtil.SORT_DESCENDING|ArrayUtil.SORT_RETURNINDEXEDARRAY));
		this.assertEquals(str0,str1);
		
		//below modified from AS3's doc
		var users:Array<Dynamic> = [];
		var rUser:Array<Dynamic>;
		users.push(new User("Bob", 3));
		users.push(new User("barb", 35));
		users.push(new User("abcd", 4));
		users.push(new User("catchy", 5));
		
		var dumpUsers = function (users:Array<Dynamic>):String {
			var ary:Array<String> = [];
			for (user in users) {
				ary.push(user.toString());
			}
			return ary.join(",");
		}

		this.assertEquals("Bob:3,abcd:4,barb:35,catchy:5",dumpUsers(ArrayUtil.sortOn(users,["name"])));
		
		this.assertEquals("Bob:3,abcd:4,barb:35,catchy:5",dumpUsers(ArrayUtil.sortOnLite(users,["name"])));
		
		this.assertEquals("abcd:4,barb:35,Bob:3,catchy:5",dumpUsers(ArrayUtil.sortOn(users,["name"],ArrayUtil.SORT_CASEINSENSITIVE)));
		
		this.assertEquals("abcd:4,barb:35,Bob:3,catchy:5",dumpUsers(ArrayUtil.sortOnLite(users,["name"],ArrayUtil.SORT_CASEINSENSITIVE)));
		
		this.assertEquals("catchy:5,Bob:3,barb:35,abcd:4",dumpUsers(ArrayUtil.sortOn(users,["name"],ArrayUtil.SORT_CASEINSENSITIVE|ArrayUtil.SORT_DESCENDING)));
		
		this.assertEquals("catchy:5,Bob:3,barb:35,abcd:4",dumpUsers(ArrayUtil.sortOnLite(users,["name"],ArrayUtil.SORT_CASEINSENSITIVE|ArrayUtil.SORT_DESCENDING)));
		
		
		rUser = ArrayUtil.sortOn(users,['age']);
		this.assertEquals("Bob:3,barb:35,abcd:4,catchy:5",dumpUsers(rUser));
		
		rUser = ArrayUtil.sortOnLite(users,['age']);
		this.assertEquals("Bob:3,barb:35,abcd:4,catchy:5",dumpUsers(rUser));
		
		rUser = ArrayUtil.sortOn(users,['age'],ArrayUtil.SORT_NUMERIC);
		this.assertEquals("Bob:3,abcd:4,catchy:5,barb:35",dumpUsers(rUser));
		
		rUser = ArrayUtil.sortOnLite(users,['age'],ArrayUtil.SORT_NUMERIC);
		this.assertEquals("Bob:3,abcd:4,catchy:5,barb:35",dumpUsers(rUser));
		
		rUser = ArrayUtil.sortOn(users,['age'],ArrayUtil.SORT_DESCENDING|ArrayUtil.SORT_NUMERIC);
		this.assertEquals("barb:35,catchy:5,abcd:4,Bob:3",dumpUsers(rUser));
		
		rUser = ArrayUtil.sortOnLite(users,['age'],ArrayUtil.SORT_DESCENDING|ArrayUtil.SORT_NUMERIC);
		this.assertEquals("barb:35,catchy:5,abcd:4,Bob:3",dumpUsers(rUser));
		
		rUser = ArrayUtil.sortOn(users,['age'],ArrayUtil.SORT_NUMERIC);
		this.assertEquals("Bob:3,abcd:4,catchy:5,barb:35",dumpUsers(rUser));
		
		rUser = ArrayUtil.sortOnLite(users,['age'],ArrayUtil.SORT_NUMERIC);
		this.assertEquals("Bob:3,abcd:4,catchy:5,barb:35",dumpUsers(rUser));

		var indices = ArrayUtil.sortOn(users,['age'],ArrayUtil.SORT_NUMERIC | ArrayUtil.SORT_RETURNINDEXEDARRAY);
		var index:UInt;
		var tempA:Array<String> = new Array<String>();
		for(i in indices) {
			tempA.push(users[i].name);
		}
		this.assertEquals("Bob,abcd,catchy,barb",tempA.join(','));
		
		var indices2 = ArrayUtil.indicesOfSorted(users,['age'],ArrayUtil.SORT_NUMERIC | ArrayUtil.SORT_RETURNINDEXEDARRAY);
		index = 0;
		tempA = new Array<String>();
		for(i in indices2) {
			tempA.push(users[i].name);
		}
		this.assertEquals("Bob,abcd,catchy,barb",tempA.join(','));
	}
	
	public function testClassUtil():Void {
		this.assertTrue(Std.is(ClassUtil.construct(Array),Array));
		this.assertTrue(new Rectangle(0,0,100,100).equals(ClassUtil.construct(Rectangle,[0,0,100,100])));
	}
	
	public function testColorUtil():Void {
		var myRGB = ColorUtil.getARGB(0xCCFF0011);
		this.assertEquals(0xCC,myRGB.a);
		this.assertEquals(0xFF,myRGB.r);
		this.assertEquals(0x00,myRGB.g);
		this.assertEquals(0x11,myRGB.b);
		
		this.assertEquals(0xCCFF0011,ColorUtil.getColor(myRGB.r,myRGB.g,myRGB.b,myRGB.a));
		
		this.assertEquals("CCFF0011",ColorUtil.getHexStringFromARGB(myRGB.a,myRGB.r,myRGB.g,myRGB.b));
		
		this.assertEquals("FF0011",ColorUtil.getHexStringFromRGB(myRGB.r,myRGB.g,myRGB.b));
		
		var ct0 = new flash.geom.ColorTransform(1,1,1,1,0x00,0x66,0x44,0xff);
		var ct1 = new flash.geom.ColorTransform(1,1,1,1,0,0,0,0xff);
		var ct05 = ColorUtil.interpolateColor(ct0,ct1,new Percent(0.5));
		this.assertEquals(1.0*0x00,ct05.redOffset);
		this.assertEquals(1.0*0x33,ct05.greenOffset);
		this.assertEquals(1.0*0x22,ct05.blueOffset);
		this.assertEquals(1.0*0xff,ct05.alphaOffset);
	}
	
	public function testConversionUtil():Void {
		this.assertTrue(1 == ConversionUtil.bitsToBytes(8));
		
		this.assertTrue(1 == ConversionUtil.bitsToKilobits(1024));
		
		this.assertTrue(1 == ConversionUtil.bitsToKilobytes(1024*8));
		
		this.assertTrue(1 == ConversionUtil.bytesToBits(1/8));
		
		this.assertTrue(1 == ConversionUtil.bytesToKilobytes(1024));
		
		this.assertTrue(1 == ConversionUtil.millisecondsToDays(ConversionUtil.daysToMilliseconds(1)));
		
		this.assertTrue(1 == ConversionUtil.minutesToDays(ConversionUtil.daysToMinutes(1)));
		
		this.assertTrue(1 == ConversionUtil.secondsToDays(ConversionUtil.daysToSeconds(1)));
		
		this.assertTrue(1 == ConversionUtil.radiansToDegrees(ConversionUtil.degreesToRadians(1)));
		
		this.assertTrue(1 == ConversionUtil.daysToHours(ConversionUtil.hoursToDays(1)));
		
		this.assertTrue(1 == ConversionUtil.millisecondsToHours(ConversionUtil.hoursToMilliseconds(1)));
		
		this.assertTrue(1 == ConversionUtil.minutesToHours(ConversionUtil.hoursToMinutes(1)));
		
		this.assertTrue(1 == ConversionUtil.secondsToHours(ConversionUtil.hoursToSeconds(1)));
		
		this.assertTrue(1 == ConversionUtil.bitsToKilobits(ConversionUtil.kilobitsToBits(1)));
		
		this.assertTrue(1024 == ConversionUtil.bytesToBits(ConversionUtil.kilobitsToBytes(1)));
		
		this.assertTrue(1 == ConversionUtil.kilobytesToKilobits(ConversionUtil.kilobitsToKilobytes(1)));
	}
	
	public function testDate():Void {
		var d0:Date = Date.fromString("1988-06-14 12:34:56");
		var d1:Date = Date.fromString("1988-06-14 12:34:56");
	
		this.assertTrue(DateUtil.equals(d0,d1));
		this.assertEquals("14",DateUtil.formatDate(d0, "d"));
		this.assertEquals("Tue",DateUtil.formatDate(d0, "D"));
		this.assertEquals("14",DateUtil.formatDate(d0, "j"));
		this.assertEquals("Tuesday",DateUtil.formatDate(d0, "l"));
		this.assertEquals("2",DateUtil.formatDate(d0, "N"));
		this.assertEquals("th",DateUtil.formatDate(d0, "S"));
		this.assertEquals("2",DateUtil.formatDate(d0, "w"));
		this.assertTrue(Std.string(DateUtil.getDayOfTheYear(d0))==DateUtil.formatDate(d0, "z"));
		this.assertTrue(Std.string(DateUtil.getWeekOfTheYear(d0))==DateUtil.formatDate(d0, "W"));
		this.assertEquals("June",DateUtil.formatDate(d0, "F"));
		this.assertEquals("06",DateUtil.formatDate(d0, "m"));
		this.assertEquals("Jun",DateUtil.formatDate(d0, "M"));
		this.assertEquals("6",DateUtil.formatDate(d0, "n"));
		this.assertEquals("30",DateUtil.formatDate(d0, "t"));
		this.assertEquals("1",DateUtil.formatDate(d0, "L"));
		this.assertEquals("1988",DateUtil.formatDate(d0, "o"));
		this.assertEquals("1988",DateUtil.formatDate(d0, "Y"));
		this.assertEquals("88",DateUtil.formatDate(d0, "y"));
		this.assertEquals("pm",DateUtil.formatDate(d0, "a"));
		this.assertEquals("PM",DateUtil.formatDate(d0, "A"));
		this.assertEquals("12",DateUtil.formatDate(d0, "g"));
		this.assertEquals("12",DateUtil.formatDate(d0, "G"));
		this.assertEquals("12",DateUtil.formatDate(d0, "h"));
		this.assertEquals("12",DateUtil.formatDate(d0, "H"));
		this.assertEquals("34",DateUtil.formatDate(d0, "i"));
		this.assertEquals("56",DateUtil.formatDate(d0, "s"));
		this.assertTrue(Std.string(d0.getTime()/1000)==DateUtil.formatDate(d0, "U"));
		
		this.assertEquals(31,DateUtil.getDaysInMonth(2010,12));
		
		d1 = DateTools.delta(d1,ConversionUtil.daysToMilliseconds(3));
		
		this.assertEquals(3,DateUtil.getCountdownUntil(d0,d1).days);
		
		//just to run it once... because I don't know your computer setting...
		DateUtil.getTimezoneOffset();
		
		var offset = DateUtil.getTimezoneOffset(d0);
		
		this.assertEquals(d0.getTime()-offset*60*1000,DateUtil.iso8601ToDate("1988-06-14T12:34:56-00:00").getTime());
		
		this.assertEquals(offset/60,DateUtil.getDifferenceFromUTCInHours(d0));
		
		this.assertEquals(offset*60,DateUtil.getDifferenceFromUTCInSeconds(d0));
		
		this.assertEquals(5,DateUtil.getFormattedDifferenceFromUTC(d0).length);
		
		//just to run it once... because I don't know your computer setting...
		DateUtil.isDaylightSavings(d0);
		
		this.assertTrue(DateUtil.getTimezone(d0).length>0);
		
		this.assertTrue(NumberUtil.isBetween(DateUtil.getInternetTime(Date.now()),0,1000));
		
		
	}
	
	#if !php
	public function testDisplayObjectUtil():Void {
		var d = new Sprite();
		var e = new Sprite();
		for (i in 0...10){
			d.addChild(new Sprite());
			e.addChild(new Sprite());
		}
		d.addChild(e);
		this.assertEquals(11,d.numChildren);
		this.assertEquals(10,e.numChildren);
		
		DisplayObjectUtil.removeChildren(d);
		this.assertEquals(0,d.numChildren);
		this.assertEquals(10,e.numChildren);
		
		d.addChild(e);
		this.assertEquals(1,d.numChildren);
		
		DisplayObjectUtil.removeChildren(d,false,true);
		this.assertEquals(0,d.numChildren);
		this.assertEquals(0,e.numChildren);
	}
	#end
	
	#if !php
	public function testDrawUtil():Void {
		var d = new Sprite();
		var e = new Sprite();
		flash.Lib.current.addChild(d);
		flash.Lib.current.addChild(e);
		d.graphics.beginFill(0,1);
		e.graphics.beginFill(0,1);
		
		DrawUtil.drawRoundRect(d.graphics,0,0,100,100,5,5);
		#if flash
		this.assertEquals(100.0,d.width);
		#end
		
		DrawUtil.drawWedge(e.graphics,new org.casalib.math.geom.Ellipse(0,0,100,100),0,180);
		#if flash
		this.assertEquals(50.0,e.width);
		this.assertEquals(100.0,e.height);
		#end
		
		DrawUtil.drawPath(d.graphics,[new Point(),new Point(34,66),new Point(10,124)]);
		
		DrawUtil.drawShape(e.graphics,[new Point(),new Point(34,66),new Point(10,124)]);
		
		this.assertTrue(true);
		
		flash.Lib.current.removeChild(d);
		flash.Lib.current.removeChild(e);
	}
	#end
	
	#if flash
	public function testFlashVarUtil():Void {
		StageReference.setStage(flash.Lib.current.stage);
		if (LocationUtil.isWeb(flash.Lib.current)){
			this.assertTrue(FlashVarUtil.hasKey("flashvar"));
			this.assertEquals("something",FlashVarUtil.getValue("flashvar"));
		} else {
			this.assertFalse(FlashVarUtil.hasKey("flashvar"));
		}		
	}
	#end
	
	#if flash
	public function testFrameUtil():Void {
		//TO-DO Test with a swf that really have some frames...
		
		var mc = new flash.display.MovieClip();
		var reach = false;
		this.assertTrue(FrameUtil.addFrameScript(mc,1,function(){trace("here");reach = true;}));
		FrameUtil.removeFrameScript(mc,1);
		this.assertEquals(-1,FrameUtil.getFrameNumberForLabel(mc,"test"));
	}
	#end
	
	public function testGeomUtil():Void {
		var pt = new Point(100,100);
		var pt0 = new Point();
		this.assertEquals(45.0,GeomUtil.angle(pt0,pt));
		
		this.assertTrue(300 == GeomUtil.getRectanglePerimeter(new Rectangle(0,0,100,50)));
		
		GeomUtil.rotatePoint(pt,pt0,90);
		GeomUtil.rotatePoint(pt,pt0,90);
		
		this.assertTrue(-100 == pt.x);
		this.assertTrue(-100 == pt.y);
		
		GeomUtil.rotatePoint(pt,pt0,90);
		GeomUtil.rotatePoint(pt,pt0,90);
		
		this.assertTrue(100 == pt.x);
		this.assertTrue(100 == pt.y);
	}
	
	public function testLoadUtil():Void {
		this.assertTrue(100 == LoadUtil.calculateBps(100,100,1100));
		
		//calculateMillisecondsUntilBuffered is also tested here...
		this.assertTrue(1 == LoadUtil.calculateBufferPercent(100,100,100,1100,1000).decimalPercentage);
		
		this.assertEquals(100/1024,LoadUtil.calculateKBps(100,100,1100));
	}
	
	#if !php
	public function testLocationUtil():Void {
		#if flash
			var domain = LocationUtil.getDomain(flash.Lib.current);
			LocationUtil.isAirApplication();
			this.assertTrue(LocationUtil.isDomain(flash.Lib.current,domain));
			LocationUtil.isIde();
			LocationUtil.isPlugin();
			LocationUtil.isStandAlone();
			LocationUtil.isWeb(flash.Lib.current);
		#elseif js
			var domain = LocationUtil.getDomain(flash.Lib.current);
			this.assertFalse(LocationUtil.isAirApplication());
			this.assertTrue(LocationUtil.isDomain(flash.Lib.current,domain));
			this.assertFalse(LocationUtil.isIde());
			this.assertFalse(LocationUtil.isPlugin());
			this.assertFalse(LocationUtil.isStandAlone());
			this.assertTrue(LocationUtil.isWeb(flash.Lib.current));
		#else
			var domain = LocationUtil.getDomain(flash.Lib.current);
			this.assertFalse(LocationUtil.isAirApplication());
			this.assertTrue(LocationUtil.isDomain(flash.Lib.current,domain));
			this.assertFalse(LocationUtil.isIde());
			this.assertFalse(LocationUtil.isPlugin());
			this.assertFalse(LocationUtil.isStandAlone());
			this.assertFalse(LocationUtil.isWeb(flash.Lib.current));
		#end
	}
	#end
	
	#if !php
	public function testNavigateUtil():Void {
		#if flash
		this.assertEquals(flash.external.ExternalInterface.available,NavigateUtil.openWindow("http://www.google.com/#swf"));
		#elseif js
		this.assertTrue(NavigateUtil.openWindow("http://www.google.com/#js"));
		#elseif neko
		this.assertTrue(NavigateUtil.openWindow("http://www.google.com/#neko"));
		#elseif cpp
		this.assertTrue(NavigateUtil.openWindow("http://www.google.com/#cpp"));
		#end
	}
	#end
	
	public function testNumberUtil():Void {
		this.assertEquals("00",NumberUtil.addLeadingZero(0));
		
		this.assertTrue(-1 == NumberUtil.constrain(-1,-1.001,100));
		this.assertTrue(0 == NumberUtil.constrain(-1,0,1));
		
		this.assertEquals("10 20 30 40",NumberUtil.createStepsBetween(0,50,4).join(' '));
		
		this.assertEquals("01,234,567",NumberUtil.format(1234567, 8, ","));
		
		this.assertEquals("32nd",32 + NumberUtil.getOrdinalSuffix(32));
		
		this.assertEquals(0.2,NumberUtil.getWeightedAverage(0,1,5));
		
		this.assertEquals(5.0,NumberUtil.interpolate(new Percent(0.5), 0, 10));
		
		this.assertTrue(NumberUtil.isBetween(3, 0, 5));
		this.assertFalse(NumberUtil.isBetween(7, 0, 5));
		
		this.assertFalse(NumberUtil.isEqual(3.042, 3, 0));
		this.assertTrue(NumberUtil.isEqual(3.042, 3, 0.5));
		
		this.assertFalse(NumberUtil.isEven(7));
		this.assertTrue(NumberUtil.isEven(12));
		
		this.assertTrue(NumberUtil.isInteger(13));
		this.assertFalse(NumberUtil.isInteger(1.2345));
		
		this.assertTrue(NumberUtil.isOdd(7));
		this.assertFalse(NumberUtil.isOdd(12));
		
		this.assertTrue(NumberUtil.isPrime(13));
		this.assertFalse(NumberUtil.isPrime(4));
		
		var colors:Array<String> = ["Red", "Green", "Blue"];
		this.assertEquals("Blue",colors[NumberUtil.loopIndex(2, colors.length)]);
		this.assertEquals("Green",colors[NumberUtil.loopIndex(4, colors.length)]);
		this.assertEquals("Red",colors[NumberUtil.loopIndex(-6, colors.length)]);
		
		this.assertEquals(75.0,NumberUtil.map(0.75, 0, 1, 0, 100));
		
		this.assertTrue(-5 == NumberUtil.max(-5, null));
		this.assertTrue(-5 == NumberUtil.max(-5, "CASA"));
		this.assertTrue(-5 == NumberUtil.max(-5, -13));
		
		this.assertTrue(5 == NumberUtil.min(5, null));
		this.assertTrue(5 == NumberUtil.min(5, "CASA"));
		this.assertTrue(5 == NumberUtil.min(5, 13));
		
		this.assertTrue(0.25 == NumberUtil.normalize(8, 4, 20).decimalPercentage);
		
		for (i in new IntIter(0,10)) {
			var randomI = NumberUtil.randomIntegerWithinRange(0,1);
			this.assertTrue(NumberUtil.isInteger(randomI));
			this.assertTrue(NumberUtil.isBetween(randomI,0,1));
		}
		
		for (i in new IntIter(0,10)) {
			var random = NumberUtil.randomWithinRange(0,1);
			this.assertTrue(NumberUtil.isBetween(random,0,1));
		}
		
		this.assertEquals(3.14,NumberUtil.roundDecimalToPlace(3.14159, 2));
		this.assertEquals(3.142,NumberUtil.roundDecimalToPlace(3.14159, 3));
	}
	
	public function testObjectUtil():Void {
		var rect = new Rectangle(1,2,3,4);
		
		this.assertTrue(rect.equals(ObjectUtil.clone(rect)));
		
		this.assertTrue(ObjectUtil.contains(rect,3.0));
		
		this.assertTrue(ObjectUtil.getKeys(rect).length >= 4);
		
		this.assertTrue(ObjectUtil.isEmpty([]));
		
		this.assertTrue(ObjectUtil.isEmpty({}));
		
		this.assertFalse(ObjectUtil.isEmpty(rect));
		
		this.assertFalse(ObjectUtil.isNull(12));
		this.assertFalse(ObjectUtil.isNull(rect));
		var that = this;
		var test = function (?n:Dynamic):Void{
			that.assertTrue(ObjectUtil.isNull(n));
		}
		test();
	}
	
	public function testPropertySetter():Void {
		var rect = new Rectangle(0,0,640,480);
		
		var ps = new PropertySetter(rect,"y");
		
		ps.defineProperty([10.0]);
		
		this.assertEquals(10.0,rect.y);
	}
	
	public function testQueryStringUtil():Void {
		#if (php||js)
			this.assertEquals("q=123",QueryStringUtil.queryString);
			this.assertTrue(QueryStringUtil.hasKey("q"));
			this.assertEquals("123",QueryStringUtil.getValue("q"));
			this.assertFalse(QueryStringUtil.hasKey("w"));
		#elseif flash
			if (LocationUtil.isWeb(flash.Lib.current)){
				this.assertEquals("q=123",QueryStringUtil.queryString);
				this.assertTrue(QueryStringUtil.hasKey("q"));
				this.assertEquals("123",QueryStringUtil.getValue("q"));
				this.assertFalse(QueryStringUtil.hasKey("w"));
			}else {
				this.assertEquals(null,QueryStringUtil.queryString);
			}
		#elseif (neko||cpp)
			this.assertEquals(null,QueryStringUtil.queryString);
		#end
	}
	
	public function testRatioUtil():Void {
		var rect = new Rectangle(0,0,640,480);
		this.assertEquals(3/4,RatioUtil.heightToWidth(rect));
		
		var rect2 = new Rectangle(0,0,640*0.33,480*0.33);
		this.assertTrue(RatioUtil.scale(rect,new Percent(0.33),false).equals(rect2));
		this.assertTrue(NumberUtil.isInteger(RatioUtil.scale(rect,new Percent(0.33),true).width));
		
		this.assertTrue(RatioUtil.scaleHeight(rect,rect2.width,false).equals(rect2));
		this.assertTrue(NumberUtil.isInteger(RatioUtil.scaleHeight(rect,rect2.width,true).width));
		
		this.assertTrue(RatioUtil.scaleToFill(rect2,rect,false).containsRect(rect2));
		
		this.assertTrue(RatioUtil.scaleToFit(rect2,rect,false).containsRect(rect2));
		
		this.assertTrue(RatioUtil.scaleWidth(rect,rect2.height,true).equals(RatioUtil.scale(rect2,new Percent(1))));
		
		this.assertEquals(4/3,RatioUtil.widthToHeight(rect));
	}
	
	public function testSingletonUtil():Void {
		this.assertEquals(SingletonUtil.singleton(haxe.Serializer),SingletonUtil.singleton(haxe.Serializer));
	}
	
	#if !php
	public function testStageReference():Void {
		var stage = flash.Lib.current.stage;
		StageReference.setStage(stage);
		this.assertEquals(stage,StageReference.getStage());
		this.assertEquals(StageReference.STAGE_DEFAULT,StageReference.getIds()[0]);
		this.assertEquals(StageReference.STAGE_DEFAULT,StageReference.getStageId(stage));
		StageReference.setStage(stage,"test");
		this.assertEquals(2,StageReference.getIds().length);
		StageReference.removeStage("test");
		this.assertEquals(1,StageReference.getIds().length);
		this.assertEquals(StageReference.STAGE_DEFAULT,StageReference.getStageId(stage));
	}
	#end
	
	public function testStringUtil():Void {
		this.assertEquals("123456", StringUtil.addAt("12456",2,"3"));
		
		this.assertEquals(2, StringUtil.contains("12345234","234"));
		this.assertEquals(0, StringUtil.contains("12345234","235"));
		this.assertEquals(0, StringUtil.contains("-14","."));
		
		this.assertEquals("ab",StringUtil.getLettersFromString("a123b456"));
		
		this.assertEquals("123456",StringUtil.getNumbersFromString("a123b456"));
		
		this.assertEquals("12345",StringUtil.getUniqueCharacters("12345234"));
		
		this.assertEquals(6,StringUtil.getWordCount("String in which to count words."));
		
		this.assertEquals("adf234qi^%&amp;%^@51trega&lt;&gt;",StringUtil.htmlEncode("adf234qi^%&%^@51trega<>"));
		
		this.assertEquals("adf234qi^%&%^@51trega<>",StringUtil.htmlDecode("adf234qi^%&amp;%^@51trega&lt;&gt;"));
		
		this.assertEquals(4,StringUtil.indexOfLowerCase("0123aAdf"));
		
		this.assertEquals(5,StringUtil.indexOfUpperCase("0123aAdf"));
		
		this.assertTrue(StringUtil.isLowerCase("asdg"));
		this.assertFalse(StringUtil.isLowerCase("asdGads"));
		
		this.assertFalse(StringUtil.isNumber("asd"));
		this.assertFalse(StringUtil.isNumber("f"));
		this.assertFalse(StringUtil.isNumber("0f0"));
		this.assertFalse(StringUtil.isNumber("0-0"));
		this.assertFalse(StringUtil.isNumber("0..0"));
		this.assertFalse(StringUtil.isNumber("."));
		this.assertFalse(StringUtil.isNumber("-."));
		this.assertTrue(StringUtil.isNumber("12.14"));
		this.assertTrue(StringUtil.isNumber("000"));
		this.assertTrue(StringUtil.isNumber("-1"));
		this.assertTrue(StringUtil.isNumber("-0"));
		this.assertTrue(StringUtil.isNumber("-00.000"));
		/*
		this.assertTrue(StringUtil.isNumber("-0xffffff"));
		this.assertTrue(StringUtil.isNumber("-0x0000"));
		this.assertTrue(StringUtil.isNumber("-0x0.000"));
		this.assertTrue(StringUtil.isNumber("-0xff.00"));
		this.assertTrue(StringUtil.isNumber("0.00f"));
		this.assertTrue(StringUtil.isNumber("0F"));
		this.assertTrue(StringUtil.isNumber("-0x0.0"));
		this.assertTrue(StringUtil.isNumber(".00"));
		this.assertTrue(StringUtil.isNumber("0X0f"));
		*/
		
		this.assertTrue(StringUtil.isPunctuation("!@#$%^&*()_+-=[]{}\\|;:'\",.<>/?"));
		this.assertFalse(StringUtil.isPunctuation("asdf!@34s<>"));
		
		this.assertTrue(StringUtil.isUpperCase("ASDF"));
		this.assertFalse(StringUtil.isUpperCase("ASsDF"));
		
		this.assertEquals("sno134531lns",StringUtil.remove("asno134531lnsa","a"));
		
		this.assertEquals("asno14531lnsa",StringUtil.removeAt("asno134531lnsa",5));
		
		this.assertEquals("1 2 3 4",StringUtil.removeExtraSpaces("1  2  3 4"));
		
		this.assertEquals("1234",StringUtil.removeWhitespace("1  2  3 4"));
		
		this.assertEquals("1234",StringUtil.replace("124564","456","3"));
		
		this.assertEquals("1234",StringUtil.replaceAt("1254",2,"3"));
		
		this.assertEquals("I Am Title", StringUtil.toTitleCase("i am title"));
		
		this.assertEquals("hel  lo",StringUtil.trim("  hel  lo  "));
		
		this.assertEquals("hel  lo  ",StringUtil.trimLeft("  hel  lo  "));
		
		this.assertEquals("  hel  lo",StringUtil.trimRight("  hel  lo  "));
	}
	
	#if !php
	public function testTextFieldUtil():Void {
		var title:flash.text.TextField = new flash.text.TextField();
		title.autoSize      = flash.text.TextFieldAutoSize.LEFT;
		
		#if flash
		var smallCapsStyle:flash.text.StyleSheet = new flash.text.StyleSheet();
		smallCapsStyle.parseCSS("p {font-size:15px;} .smallCaps {font-size:30px;}");
		
		title.styleSheet    = smallCapsStyle;
		#end
		
		title.htmlText      = "<p>This Text is Small Caps.</p>";

		TextFieldUtil.classSmallCaps(title, "smallCaps");
		
		this.assertEquals(('<P><SPAN CLASS="SMALLCAPS">T</SPAN>HIS <SPAN CLASS="SMALLCAPS">T</SPAN>EXT IS <SPAN CLASS="SMALLCAPS">S</SPAN>MALL <SPAN CLASS="SMALLCAPS">C</SPAN>APS.</P>').toLowerCase(),title.htmlText.toLowerCase());
		
		
		#if flash
		var small:flash.text.TextFormat = new flash.text.TextFormat();
		var large:flash.text.TextFormat = new flash.text.TextFormat();

		small.size = 15;
		large.size = 30;
		
		title = new flash.text.TextField();
		title.autoSize      = flash.text.TextFieldAutoSize.LEFT;
		title.text          = "This Text is Small Caps.";
		title.setTextFormat(small);

		TextFieldUtil.formatSmallCaps(title, large);
		
		title.width = 10;
		this.assertTrue(TextFieldUtil.hasOverFlow(title));
		TextFieldUtil.removeOverFlow(title);
		this.assertFalse(TextFieldUtil.hasOverFlow(title));
		#end
	}
	#end
	
	public function testValidationUtil():Void {
		//card numbers from https://www.paypal.com/en_US/vhelp/paypalmanager_help/credit_card_numbers.htm
		this.assertEquals("visa",ValidationUtil.getCreditCardProvider("4111111111111111"));
		this.assertEquals("mastercard",ValidationUtil.getCreditCardProvider("5555555555554444"));
		this.assertEquals("discover",ValidationUtil.getCreditCardProvider("6011000990139424"));
		this.assertEquals("amex",ValidationUtil.getCreditCardProvider("378282246310005"));
		this.assertEquals("diners",ValidationUtil.getCreditCardProvider("30569309025904"));
		this.assertEquals("other",ValidationUtil.getCreditCardProvider("3566002020360505"));
		this.assertEquals("invalid",ValidationUtil.getCreditCardProvider("123"));
		
		this.assertTrue(ValidationUtil.isCreditCard("378282246310005"));
		this.assertFalse(ValidationUtil.isCreditCard("345"));
		
		this.assertTrue(ValidationUtil.isEmail("andy@onthewings.net"));
		this.assertFalse(ValidationUtil.isEmail("12@3234"));
		
		this.assertTrue(ValidationUtil.isUsaStateAbbreviation("dC"));
		this.assertFalse(ValidationUtil.isUsaStateAbbreviation("hk"));
	}
}
