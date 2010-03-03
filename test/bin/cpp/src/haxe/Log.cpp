#include <hxcpp.h>

#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
namespace haxe{

Void Log_obj::__construct()
{
	return null();
}

Log_obj::~Log_obj() { }

Dynamic Log_obj::__CreateEmpty() { return  new Log_obj; }
hx::ObjectPtr< Log_obj > Log_obj::__new()
{  hx::ObjectPtr< Log_obj > result = new Log_obj();
	result->__construct();
	return result;}

Dynamic Log_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Log_obj > result = new Log_obj();
	result->__construct();
	return result;}

HX_BEGIN_DEFAULT_FUNC(__default_trace,Log_obj)
Void run(Dynamic v,Dynamic infos){
{
		__trace(v,infos);
	}
return null();
}
HX_END_LOCAL_FUNC2((void))
HX_END_DEFAULT_FUNC

Dynamic Log_obj::trace;

HX_BEGIN_DEFAULT_FUNC(__default_clear,Log_obj)
Void run(){
{
	}
return null();
}
HX_END_LOCAL_FUNC0((void))
HX_END_DEFAULT_FUNC

Dynamic Log_obj::clear;


Log_obj::Log_obj()
{
}

void Log_obj::__Mark()
{
}

Dynamic Log_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"trace",sizeof(wchar_t)*5) ) { return trace; }
		if (!memcmp(inName.__s,L"clear",sizeof(wchar_t)*5) ) { return clear; }
	}
	return super::__Field(inName);
}

Dynamic Log_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"trace",sizeof(wchar_t)*5) ) { trace=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"clear",sizeof(wchar_t)*5) ) { clear=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Log_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"trace",5),
	HX_STRING(L"clear",5),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Log_obj::trace);
	hx::MarkMember(Log_obj::clear);
};

Class Log_obj::__mClass;

void Log_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"haxe.Log",8), hx::TCanCast< Log_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Log_obj::__boot()
{
	hx::Static(trace) = new __default_trace;

	hx::Static(clear) = new __default_clear;

}

} // end namespace haxe
