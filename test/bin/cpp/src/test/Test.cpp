#include <hxcpp.h>

#ifndef INCLUDED_haxe_Public
#include <haxe/Public.h>
#endif
#ifndef INCLUDED_haxe_unit_TestCase
#include <haxe/unit/TestCase.h>
#endif
#ifndef INCLUDED_haxe_unit_TestRunner
#include <haxe/unit/TestRunner.h>
#endif
#ifndef INCLUDED_test_Test
#include <test/Test.h>
#endif
#ifndef INCLUDED_test_TestMath
#include <test/TestMath.h>
#endif
#ifndef INCLUDED_test_TestUtil
#include <test/TestUtil.h>
#endif
namespace test{

Void Test_obj::__construct()
{
super::__construct();
	return null();
}

Test_obj::~Test_obj() { }

Dynamic Test_obj::__CreateEmpty() { return  new Test_obj; }
hx::ObjectPtr< Test_obj > Test_obj::__new()
{  hx::ObjectPtr< Test_obj > result = new Test_obj();
	result->__construct();
	return result;}

Dynamic Test_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Test_obj > result = new Test_obj();
	result->__construct();
	return result;}

Void Test_obj::main( ){
{
		__SAFE_POINT
		::test::Test runner = ::test::Test_obj::__new();
		runner->add(::test::TestMath_obj::__new());
		runner->add(::test::TestUtil_obj::__new());
		runner->run();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Test_obj,main,(void))


Test_obj::Test_obj()
{
}

void Test_obj::__Mark()
{
	super::__Mark();
}

Dynamic Test_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"main",sizeof(wchar_t)*4) ) { return main_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Test_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Test_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"main",4),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
};

Class Test_obj::__mClass;

void Test_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"test.Test",9), hx::TCanCast< Test_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Test_obj::__boot()
{
}

} // end namespace test
