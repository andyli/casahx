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
#ifndef INCLUDED_haxe_unit_TestStatus
#include <haxe/unit/TestStatus.h>
#endif
namespace haxe{
namespace unit{

Void TestCase_obj::__construct()
{
{
}
;
	return null();
}

TestCase_obj::~TestCase_obj() { }

Dynamic TestCase_obj::__CreateEmpty() { return  new TestCase_obj; }
hx::ObjectPtr< TestCase_obj > TestCase_obj::__new()
{  hx::ObjectPtr< TestCase_obj > result = new TestCase_obj();
	result->__construct();
	return result;}

Dynamic TestCase_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TestCase_obj > result = new TestCase_obj();
	result->__construct();
	return result;}

hx::Object *TestCase_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::haxe::Public_obj)) return operator ::haxe::Public_obj *();
	return super::__ToInterface(inType);
}

Void TestCase_obj::setup( ){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TestCase_obj,setup,(void))

Void TestCase_obj::tearDown( ){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TestCase_obj,tearDown,(void))

Void TestCase_obj::print( Dynamic v){
{
		__SAFE_POINT
		::haxe::unit::TestRunner_obj::print(v);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TestCase_obj,print,(void))

Void TestCase_obj::assertTrue( bool b,Dynamic c){
{
		this->currentTest->done = true;
		if ((b == false)){
			this->currentTest->success = false;
			this->currentTest->error = HX_STRING(L"expected true but was false",27);
			this->currentTest->posInfos = c;
			hx::Throw (this->currentTest);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(TestCase_obj,assertTrue,(void))

Void TestCase_obj::assertFalse( bool b,Dynamic c){
{
		this->currentTest->done = true;
		if ((b == true)){
			this->currentTest->success = false;
			this->currentTest->error = HX_STRING(L"expected false but was true",27);
			this->currentTest->posInfos = c;
			hx::Throw (this->currentTest);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(TestCase_obj,assertFalse,(void))

Void TestCase_obj::assertEquals( Dynamic expected,Dynamic actual,Dynamic c){
{
		this->currentTest->done = true;
		if ((actual != expected)){
			this->currentTest->success = false;
			this->currentTest->error = (((((((HX_STRING(L"expected '",10) + expected)) + HX_STRING(L"' but was '",11))) + actual)) + HX_STRING(L"'",1));
			this->currentTest->posInfos = c;
			hx::Throw (this->currentTest);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(TestCase_obj,assertEquals,(void))


TestCase_obj::TestCase_obj()
{
}

void TestCase_obj::__Mark()
{
	hx::MarkMember(currentTest);
}

Dynamic TestCase_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"setup",sizeof(wchar_t)*5) ) { return setup_dyn(); }
		if (!memcmp(inName.__s,L"print",sizeof(wchar_t)*5) ) { return print_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"tearDown",sizeof(wchar_t)*8) ) { return tearDown_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"assertTrue",sizeof(wchar_t)*10) ) { return assertTrue_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"currentTest",sizeof(wchar_t)*11) ) { return currentTest; }
		if (!memcmp(inName.__s,L"assertFalse",sizeof(wchar_t)*11) ) { return assertFalse_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"assertEquals",sizeof(wchar_t)*12) ) { return assertEquals_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic TestCase_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 11:
		if (!memcmp(inName.__s,L"currentTest",sizeof(wchar_t)*11) ) { currentTest=inValue.Cast< ::haxe::unit::TestStatus >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void TestCase_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"currentTest",11));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"currentTest",11),
	HX_STRING(L"setup",5),
	HX_STRING(L"tearDown",8),
	HX_STRING(L"print",5),
	HX_STRING(L"assertTrue",10),
	HX_STRING(L"assertFalse",11),
	HX_STRING(L"assertEquals",12),
	String(null()) };

static void sMarkStatics() {
};

Class TestCase_obj::__mClass;

void TestCase_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"haxe.unit.TestCase",18), hx::TCanCast< TestCase_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void TestCase_obj::__boot()
{
}

} // end namespace haxe
} // end namespace unit
