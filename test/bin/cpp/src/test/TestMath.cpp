#include <hxcpp.h>

#ifndef INCLUDED_haxe_Public
#include <haxe/Public.h>
#endif
#ifndef INCLUDED_haxe_unit_TestCase
#include <haxe/unit/TestCase.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
#ifndef INCLUDED_org_casalib_math_Percent
#include <org/casalib/math/Percent.h>
#endif
#ifndef INCLUDED_org_casalib_math_Range
#include <org/casalib/math/Range.h>
#endif
#ifndef INCLUDED_org_casalib_math_geom_Ellipse
#include <org/casalib/math/geom/Ellipse.h>
#endif
#ifndef INCLUDED_org_casalib_math_geom_Point3d
#include <org/casalib/math/geom/Point3d.h>
#endif
#ifndef INCLUDED_test_TestMath
#include <test/TestMath.h>
#endif
namespace test{

Void TestMath_obj::__construct()
{
super::__construct();
	return null();
}

TestMath_obj::~TestMath_obj() { }

Dynamic TestMath_obj::__CreateEmpty() { return  new TestMath_obj; }
hx::ObjectPtr< TestMath_obj > TestMath_obj::__new()
{  hx::ObjectPtr< TestMath_obj > result = new TestMath_obj();
	result->__construct();
	return result;}

Dynamic TestMath_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TestMath_obj > result = new TestMath_obj();
	result->__construct();
	return result;}

Void TestMath_obj::testPercent( ){
{
		__SAFE_POINT
		::org::casalib::math::Percent p1 = ::org::casalib::math::Percent_obj::__new(1.5,true);
		::org::casalib::math::Percent p2 = ::org::casalib::math::Percent_obj::__new(150,false);
		::org::casalib::math::Percent p3 = p1->clone();
		::org::casalib::math::Percent p4 = ::org::casalib::math::Percent_obj::__new(-1,null());
		struct _Function_1_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestMath.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 16);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestMath",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testPercent",11));
				return __result;
			}
		};
		this->assertTrue(p1->equals(p2),_Function_1_1::Block());
		struct _Function_1_2{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestMath.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 17);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestMath",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testPercent",11));
				return __result;
			}
		};
		this->assertTrue(p2->equals(p3),_Function_1_2::Block());
		struct _Function_1_3{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestMath.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 18);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestMath",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testPercent",11));
				return __result;
			}
		};
		this->assertFalse(p4->equals(p1),_Function_1_3::Block());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TestMath_obj,testPercent,(void))

Void TestMath_obj::testRange( ){
{
		__SAFE_POINT
		::org::casalib::math::Range r1 = ::org::casalib::math::Range_obj::__new(0,100);
		::org::casalib::math::Range r2 = r1->clone();
		::org::casalib::math::Range r3 = ::org::casalib::math::Range_obj::__new(-100,100);
		struct _Function_1_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestMath.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 25);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestMath",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testRange",9));
				return __result;
			}
		};
		this->assertTrue(r1->equals(r2),_Function_1_1::Block());
		struct _Function_1_2{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestMath.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 26);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestMath",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testRange",9));
				return __result;
			}
		};
		this->assertFalse(r2->equals(r3),_Function_1_2::Block());
		struct _Function_1_3{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestMath.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 27);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestMath",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testRange",9));
				return __result;
			}
		};
		this->assertEquals(0.2,r1->getPercentOfValue(20)->getDecimalPercentage(),_Function_1_3::Block());
		struct _Function_1_4{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestMath.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 28);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestMath",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testRange",9));
				return __result;
			}
		};
		this->assertEquals(-30.,r2->getValueOfPercent(::org::casalib::math::Percent_obj::__new(-0.3,null())),_Function_1_4::Block());
		struct _Function_1_5{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestMath.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 29);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestMath",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testRange",9));
				return __result;
			}
		};
		this->assertTrue(r3->isWithinRange(-99.99),_Function_1_5::Block());
		struct _Function_1_6{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestMath.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 30);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestMath",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testRange",9));
				return __result;
			}
		};
		this->assertTrue(r1->overlaps(r3),_Function_1_6::Block());
		struct _Function_1_7{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestMath.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 31);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestMath",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testRange",9));
				return __result;
			}
		};
		this->assertFalse(r1->contains(r3),_Function_1_7::Block());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TestMath_obj,testRange,(void))

Void TestMath_obj::testEllipse( ){
{
		__SAFE_POINT
		::org::casalib::math::geom::Ellipse e1 = ::org::casalib::math::geom::Ellipse_obj::__new(10,20,20,30);
		::org::casalib::math::geom::Ellipse e2 = e1->clone();
		::org::casalib::math::geom::Ellipse e3 = ::org::casalib::math::geom::Ellipse_obj::__new(20,-1,60,40);
		struct _Function_1_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestMath.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 38);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestMath",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testEllipse",11));
				return __result;
			}
		};
		this->assertTrue(e1->equals(e2),_Function_1_1::Block());
		struct _Function_1_2{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestMath.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 39);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestMath",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testEllipse",11));
				return __result;
			}
		};
		this->assertFalse(e3->equals(e1),_Function_1_2::Block());
		struct _Function_1_3{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestMath.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 40);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestMath",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testEllipse",11));
				return __result;
			}
		};
		this->assertTrue(e1->containsPoint(e1->getCenter()),_Function_1_3::Block());
		struct _Function_1_4{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestMath.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 41);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestMath",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testEllipse",11));
				return __result;
			}
		};
		this->assertEquals(e3->getArea(),(e1->getArea() * 4),_Function_1_4::Block());
		struct _Function_1_5{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestMath.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 42);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestMath",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testEllipse",11));
				return __result;
			}
		};
		this->assertEquals(e3->getPerimeter(),(e1->getPerimeter() * 2),_Function_1_5::Block());
		e1->setHeight(20);
		struct _Function_1_6{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestMath.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 44);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestMath",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testEllipse",11));
				return __result;
			}
		};
		this->assertTrue(e1->getPointOfDegree(45)->equals(e1->getPointOfDegree(405)),_Function_1_6::Block());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TestMath_obj,testEllipse,(void))

Void TestMath_obj::testPoint3d( ){
{
		__SAFE_POINT
		::org::casalib::math::geom::Point3d p1 = ::org::casalib::math::geom::Point3d_obj::__new(-1,0,1);
		::org::casalib::math::geom::Point3d p2 = p1->clone();
		::org::casalib::math::geom::Point3d p3 = ::org::casalib::math::geom::Point3d_obj::__new(12,54,-123);
		::org::casalib::math::geom::Point3d p4 = ::org::casalib::math::geom::Point3d_obj::interpolate(p1,p3,::org::casalib::math::Percent_obj::__new(0.2,null()));
		struct _Function_1_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestMath.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 52);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestMath",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testPoint3d",11));
				return __result;
			}
		};
		this->assertTrue(p1->equals(p2),_Function_1_1::Block());
		struct _Function_1_2{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestMath.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 53);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestMath",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testPoint3d",11));
				return __result;
			}
		};
		this->assertEquals(::org::casalib::math::geom::Point3d_obj::distance(p1,p3),(::org::casalib::math::geom::Point3d_obj::distance(p1,p4) * 5),_Function_1_2::Block());
		struct _Function_1_3{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestMath.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 54);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestMath",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testPoint3d",11));
				return __result;
			}
		};
		this->assertTrue(p1->subtract(p2)->equals(::org::casalib::math::geom::Point3d_obj::__new(null(),null(),null())),_Function_1_3::Block());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TestMath_obj,testPoint3d,(void))


TestMath_obj::TestMath_obj()
{
}

void TestMath_obj::__Mark()
{
	super::__Mark();
}

Dynamic TestMath_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 9:
		if (!memcmp(inName.__s,L"testRange",sizeof(wchar_t)*9) ) { return testRange_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"testPercent",sizeof(wchar_t)*11) ) { return testPercent_dyn(); }
		if (!memcmp(inName.__s,L"testEllipse",sizeof(wchar_t)*11) ) { return testEllipse_dyn(); }
		if (!memcmp(inName.__s,L"testPoint3d",sizeof(wchar_t)*11) ) { return testPoint3d_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic TestMath_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void TestMath_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"testPercent",11),
	HX_STRING(L"testRange",9),
	HX_STRING(L"testEllipse",11),
	HX_STRING(L"testPoint3d",11),
	String(null()) };

static void sMarkStatics() {
};

Class TestMath_obj::__mClass;

void TestMath_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"test.TestMath",13), hx::TCanCast< TestMath_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void TestMath_obj::__boot()
{
}

} // end namespace test
