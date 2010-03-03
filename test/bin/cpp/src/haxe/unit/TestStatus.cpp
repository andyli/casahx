#include <hxcpp.h>

#ifndef INCLUDED_haxe_unit_TestStatus
#include <haxe/unit/TestStatus.h>
#endif
namespace haxe{
namespace unit{

Void TestStatus_obj::__construct()
{
{
	this->done = false;
	this->success = false;
}
;
	return null();
}

TestStatus_obj::~TestStatus_obj() { }

Dynamic TestStatus_obj::__CreateEmpty() { return  new TestStatus_obj; }
hx::ObjectPtr< TestStatus_obj > TestStatus_obj::__new()
{  hx::ObjectPtr< TestStatus_obj > result = new TestStatus_obj();
	result->__construct();
	return result;}

Dynamic TestStatus_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TestStatus_obj > result = new TestStatus_obj();
	result->__construct();
	return result;}


TestStatus_obj::TestStatus_obj()
{
}

void TestStatus_obj::__Mark()
{
	hx::MarkMember(done);
	hx::MarkMember(success);
	hx::MarkMember(error);
	hx::MarkMember(method);
	hx::MarkMember(classname);
	hx::MarkMember(posInfos);
	hx::MarkMember(backtrace);
}

Dynamic TestStatus_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"done",sizeof(wchar_t)*4) ) { return done; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"error",sizeof(wchar_t)*5) ) { return error; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"method",sizeof(wchar_t)*6) ) { return method; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"success",sizeof(wchar_t)*7) ) { return success; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"posInfos",sizeof(wchar_t)*8) ) { return posInfos; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"classname",sizeof(wchar_t)*9) ) { return classname; }
		if (!memcmp(inName.__s,L"backtrace",sizeof(wchar_t)*9) ) { return backtrace; }
	}
	return super::__Field(inName);
}

Dynamic TestStatus_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"done",sizeof(wchar_t)*4) ) { done=inValue.Cast< bool >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"error",sizeof(wchar_t)*5) ) { error=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"method",sizeof(wchar_t)*6) ) { method=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"success",sizeof(wchar_t)*7) ) { success=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"posInfos",sizeof(wchar_t)*8) ) { posInfos=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"classname",sizeof(wchar_t)*9) ) { classname=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"backtrace",sizeof(wchar_t)*9) ) { backtrace=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void TestStatus_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"done",4));
	outFields->push(HX_STRING(L"success",7));
	outFields->push(HX_STRING(L"error",5));
	outFields->push(HX_STRING(L"method",6));
	outFields->push(HX_STRING(L"classname",9));
	outFields->push(HX_STRING(L"posInfos",8));
	outFields->push(HX_STRING(L"backtrace",9));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"done",4),
	HX_STRING(L"success",7),
	HX_STRING(L"error",5),
	HX_STRING(L"method",6),
	HX_STRING(L"classname",9),
	HX_STRING(L"posInfos",8),
	HX_STRING(L"backtrace",9),
	String(null()) };

static void sMarkStatics() {
};

Class TestStatus_obj::__mClass;

void TestStatus_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"haxe.unit.TestStatus",20), hx::TCanCast< TestStatus_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void TestStatus_obj::__boot()
{
}

} // end namespace haxe
} // end namespace unit
