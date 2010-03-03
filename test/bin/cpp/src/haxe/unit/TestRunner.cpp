#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_Public
#include <haxe/Public.h>
#endif
#ifndef INCLUDED_haxe_Stack
#include <haxe/Stack.h>
#endif
#ifndef INCLUDED_haxe_StackItem
#include <haxe/StackItem.h>
#endif
#ifndef INCLUDED_haxe_unit_TestCase
#include <haxe/unit/TestCase.h>
#endif
#ifndef INCLUDED_haxe_unit_TestResult
#include <haxe/unit/TestResult.h>
#endif
#ifndef INCLUDED_haxe_unit_TestRunner
#include <haxe/unit/TestRunner.h>
#endif
#ifndef INCLUDED_haxe_unit_TestStatus
#include <haxe/unit/TestStatus.h>
#endif
namespace haxe{
namespace unit{

Void TestRunner_obj::__construct()
{
{
	this->result = ::haxe::unit::TestResult_obj::__new();
	this->cases = ::List_obj::__new();
}
;
	return null();
}

TestRunner_obj::~TestRunner_obj() { }

Dynamic TestRunner_obj::__CreateEmpty() { return  new TestRunner_obj; }
hx::ObjectPtr< TestRunner_obj > TestRunner_obj::__new()
{  hx::ObjectPtr< TestRunner_obj > result = new TestRunner_obj();
	result->__construct();
	return result;}

Dynamic TestRunner_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TestRunner_obj > result = new TestRunner_obj();
	result->__construct();
	return result;}

Void TestRunner_obj::add( ::haxe::unit::TestCase c){
{
		__SAFE_POINT
		this->cases->add(c);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TestRunner_obj,add,(void))

bool TestRunner_obj::run( ){
	__SAFE_POINT
	this->result = ::haxe::unit::TestResult_obj::__new();
	for(Dynamic __it = this->cases->iterator();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
::haxe::unit::TestCase c = __it->__Field(HX_STRING(L"next",4))();
		{
			this->runCase(c);
		}
;
		__SAFE_POINT
	}
	::haxe::unit::TestRunner_obj::print(this->result->toString());
	return this->result->success;
}


HX_DEFINE_DYNAMIC_FUNC0(TestRunner_obj,run,return )

Void TestRunner_obj::runCase( ::haxe::unit::TestCase t){
{
		__SAFE_POINT
		Dynamic old = ::haxe::Log_obj::trace_dyn();
		::haxe::Log_obj::trace = ::haxe::unit::TestRunner_obj::customTrace_dyn();
		::Class cl = ::Type_obj::getClass(t);
		Array< ::String > fields = ::Type_obj::getInstanceFields(cl);
		::haxe::unit::TestRunner_obj::print((((HX_STRING(L"Class: ",7) + ::Type_obj::getClassName(cl))) + HX_STRING(L" ",1)));
		{
			int _g = 0;
			while((_g < fields->length)){
				__SAFE_POINT
				::String f = fields->__get(_g);
				++_g;
				::String fname = f;
				Dynamic field = ((t == null())) ? Dynamic( null() ) : Dynamic( t->__Field(f) );
				if ((bool(::StringTools_obj::startsWith(fname,HX_STRING(L"test",4))) && bool(::Reflect_obj::isFunction(field)))){
					t->currentTest = ::haxe::unit::TestStatus_obj::__new();
					t->currentTest->classname = ::Type_obj::getClassName(cl);
					t->currentTest->method = fname;
					t->setup();
					try{
						::Reflect_obj::callMethod(t,field,Array_obj< Dynamic >::__new());
						if (t->currentTest->done){
							t->currentTest->success = true;
							::haxe::unit::TestRunner_obj::print(HX_STRING(L".",1));
						}
						else{
							t->currentTest->success = false;
							t->currentTest->error = HX_STRING(L"(warning) no assert",19);
							::haxe::unit::TestRunner_obj::print(HX_STRING(L"W",1));
						}
					}
					catch(Dynamic __e){
						if (__e.IsClass< ::haxe::unit::TestStatus >() ){
							::haxe::unit::TestStatus e = __e;{
								::haxe::unit::TestRunner_obj::print(HX_STRING(L"F",1));
								t->currentTest->backtrace = ::haxe::Stack_obj::toString(::haxe::Stack_obj::exceptionStack());
							}
						}
						else {
							Dynamic e = __e;{
								::haxe::unit::TestRunner_obj::print(HX_STRING(L"E",1));
								t->currentTest->error = (HX_STRING(L"exception thrown : ",19) + e);
								t->currentTest->backtrace = ::haxe::Stack_obj::toString(::haxe::Stack_obj::exceptionStack());
							}
						}
					}
					this->result->add(t->currentTest);
					t->tearDown();
				}
			}
		}
		::haxe::unit::TestRunner_obj::print(HX_STRING(L"\n",1));
		::haxe::Log_obj::trace = old;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TestRunner_obj,runCase,(void))

HX_BEGIN_DEFAULT_FUNC(__default_print,TestRunner_obj)
Void run(Dynamic v){
{
		::cpp::Lib_obj::print(v);
	}
return null();
}
HX_END_LOCAL_FUNC1((void))
HX_END_DEFAULT_FUNC

Dynamic TestRunner_obj::print;

Void TestRunner_obj::customTrace( Dynamic v,Dynamic p){
{
		__SAFE_POINT
		::haxe::unit::TestRunner_obj::print((((((((((p->__Field(HX_STRING(L"fileName",8)).Cast< ::String >() + HX_STRING(L":",1))) + p->__Field(HX_STRING(L"lineNumber",10)).Cast< int >())) + HX_STRING(L": ",2))) + ::Std_obj::string(v))) + HX_STRING(L"\n",1)));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(TestRunner_obj,customTrace,(void))


TestRunner_obj::TestRunner_obj()
{
}

void TestRunner_obj::__Mark()
{
	hx::MarkMember(result);
	hx::MarkMember(cases);
}

Dynamic TestRunner_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"add",sizeof(wchar_t)*3) ) { return add_dyn(); }
		if (!memcmp(inName.__s,L"run",sizeof(wchar_t)*3) ) { return run_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"print",sizeof(wchar_t)*5) ) { return print; }
		if (!memcmp(inName.__s,L"cases",sizeof(wchar_t)*5) ) { return cases; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"result",sizeof(wchar_t)*6) ) { return result; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"runCase",sizeof(wchar_t)*7) ) { return runCase_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"customTrace",sizeof(wchar_t)*11) ) { return customTrace_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic TestRunner_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"print",sizeof(wchar_t)*5) ) { print=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"cases",sizeof(wchar_t)*5) ) { cases=inValue.Cast< ::List >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"result",sizeof(wchar_t)*6) ) { result=inValue.Cast< ::haxe::unit::TestResult >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void TestRunner_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"result",6));
	outFields->push(HX_STRING(L"cases",5));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"print",5),
	HX_STRING(L"customTrace",11),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"result",6),
	HX_STRING(L"cases",5),
	HX_STRING(L"add",3),
	HX_STRING(L"run",3),
	HX_STRING(L"runCase",7),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(TestRunner_obj::print);
};

Class TestRunner_obj::__mClass;

void TestRunner_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"haxe.unit.TestRunner",20), hx::TCanCast< TestRunner_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void TestRunner_obj::__boot()
{
	hx::Static(print) = new __default_print;

}

} // end namespace haxe
} // end namespace unit
