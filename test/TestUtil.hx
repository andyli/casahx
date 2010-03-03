package test;

import haxe.unit.TestCase;
import flash.geom.Rectangle;
import org.casalib.math.Percent;
import org.casalib.util.ArrayUtil;
import org.casalib.util.NumberUtil;
import org.casalib.util.RatioUtil;
import org.casalib.util.ValidationUtil;

class TestUtil extends TestCase {
	public function testArrayUtil():Void {
		var a1:Array<Int> = [1,6,3,3,8];
		
		this.assertEquals(2,ArrayUtil.indexOf(a1,3));
		this.assertEquals(3,ArrayUtil.indexOf(a1,3,3));
		
		this.assertEquals(3,ArrayUtil.lastIndexOf(a1,3));
		this.assertEquals(2,ArrayUtil.lastIndexOf(a1,3,2));
		
		var alphabet:Array<String> = ["a", "d", "e"];
		var parts:Array<String>    = ["b", "c"];
		
		//alphabet.insert(2,"c");
		//this.assertEquals(4,alphabet.length);
		
		this.assertTrue(ArrayUtil.addItemsAt(alphabet, parts, 1));
		this.assertEquals(5,alphabet.length);
		this.assertEquals("a,b,c,d,e",alphabet.join(','));
		
		this.assertEquals(4.0,ArrayUtil.average([2, 3, 8, 3]));
		
		this.assertEquals(3, ArrayUtil.contains([1, 2, 3, 7, 7, 7, 4, 5],7));
		
		this.assertTrue(ArrayUtil.containsAll([1,2,3,4,5],[1,3,5]));
		this.assertFalse(ArrayUtil.containsAll([1,2,3,4,5],[1,3,6]));
		
		this.assertTrue(ArrayUtil.containsAny([1,2,3,4,5],[1,6,5]));
		this.assertFalse(ArrayUtil.containsAny([1,2,3,4,5],[-1,0,6.1]));
		
		this.assertTrue(ArrayUtil.equals([1,2,-1],[1,2,-1]));
		this.assertFalse(ArrayUtil.equals([1,2,-1],[1,2,1]));
		
		this.assertEquals(10.0,ArrayUtil.getHighestValue([-123,2,5,6,2,10,-0.11]));
		
		this.assertEquals(3,ArrayUtil.getIndexOfDifference(["Red", "Blue", "Green", "Indigo", "Violet"],["Red", "Blue", "Green", "Violet"]));
		
		var item = {a:123, b:456};
		this.assertEquals(item, ArrayUtil.getItemByKey([{b:12},{b:15},item],"b",456));
		
		var array = [1,2,3,4,5,5,7,5,9,0,11,12,13];
		this.assertEquals(array, ArrayUtil.getItemByType([14,array,"","asdfn"],Array));
		
		this.assertEquals(3, ArrayUtil.getItemsByKey([{b:12},{b:15},item,{b:15},{b:15}],"b",15).length);
		
		this.assertEquals(2, ArrayUtil.getItemsByType([14,array,"","asdfn"],String).length);
		
		this.assertEquals(1.0, ArrayUtil.getLowestValue([2, 1, 5, 4, 3]));
		
		this.assertFalse(ArrayUtil.equals(ArrayUtil.randomize(array),array));
		
		this.assertEquals(4,ArrayUtil.removeDuplicates(a1).length);
		
		this.assertEquals(3,ArrayUtil.removeItem(array,5));
		
		ArrayUtil.removeItems(array,[1,11]);
		this.assertEquals(8,array.length);
		
		ArrayUtil.retainItems(array,[0]);
		this.assertEquals(0,array[0]);
		
		this.assertEquals(5.0,ArrayUtil.sum([1,1,1,0.25,1.75]));
	}
	
	public function testNumberUtil():Void {
		this.assertEquals("00",NumberUtil.addLeadingZero(0));
		
		this.assertEquals(-1.0,NumberUtil.constrain(-1,-1.001,100));
		this.assertEquals(0.0,NumberUtil.constrain(-1,0,1));
		
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
		
		this.assertEquals(-5.0,NumberUtil.max(-5, null));
		this.assertEquals(-5.0,NumberUtil.max(-5, "CASA"));
		this.assertEquals(-5.0,NumberUtil.max(-5, -13));
		
		this.assertEquals(5.0,NumberUtil.min(5, null));
		this.assertEquals(5.0,NumberUtil.min(5, "CASA"));
		this.assertEquals(5.0,NumberUtil.min(5, 13));
		
		this.assertEquals(0.25,NumberUtil.normalize(8, 4, 20).decimalPercentage);
		
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
