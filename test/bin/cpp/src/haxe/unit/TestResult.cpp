#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_haxe_unit_TestResult
#include <haxe/unit/TestResult.h>
#endif
#ifndef INCLUDED_haxe_unit_TestStatus
#include <haxe/unit/TestStatus.h>
#endif
namespace haxe{
namespace unit{

Void TestResult_obj::__construct()
{
{
	this->m_tests = ::List_obj::__new();
	this->success = true;
}
;
	return null();
}

TestResult_obj::~TestResult_obj() { }

Dynamic TestResult_obj::__CreateEmpty() { return  new TestResult_obj; }
hx::ObjectPtr< TestResult_obj > TestResult_obj::__new()
{  hx::ObjectPtr< TestResult_obj > result = new TestResult_obj();
	result->__construct();
	return result;}

Dynamic TestResult_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TestResult_obj > result = new TestResult_obj();
	result->__construct();
	return result;}

Void TestResult_obj::add( ::haxe::unit::TestStatus t){
{
		__SAFE_POINT
		this->m_tests->add(t);
		if (!t->success)
			this->success = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TestResult_obj,add,(void))

::String TestResult_obj::toString( ){
	__SAFE_POINT
	::StringBuf buf = ::StringBuf_obj::__new();
	int failures = 0;
	for(Dynamic __it = this->m_tests->iterator();  __it->__Field(HX_STRING(L"hasNext",7))(); ){
::haxe::unit::TestStatus test = __it->__Field(HX_STRING(L"next",4))();
		{
			if ((test->success == false)){
				buf->b[buf->b->length] = HX_STRING(L"* ",2);
				buf->b[buf->b->length] = test->classname;
				buf->b[buf->b->length] = HX_STRING(L"::",2);
				buf->b[buf->b->length] = test->method;
				buf->b[buf->b->length] = HX_STRING(L"()",2);
				buf->b[buf->b->length] = HX_STRING(L"\n",1);
				buf->b[buf->b->length] = HX_STRING(L"ERR: ",5);
				if ((test->posInfos != null())){
					buf->b[buf->b->length] = test->posInfos->__Field(HX_STRING(L"fileName",8)).Cast< ::String >();
					buf->b[buf->b->length] = HX_STRING(L":",1);
					buf->b[buf->b->length] = test->posInfos->__Field(HX_STRING(L"lineNumber",10)).Cast< int >();
					buf->b[buf->b->length] = HX_STRING(L"(",1);
					buf->b[buf->b->length] = test->posInfos->__Field(HX_STRING(L"className",9)).Cast< ::String >();
					buf->b[buf->b->length] = HX_STRING(L".",1);
					buf->b[buf->b->length] = test->posInfos->__Field(HX_STRING(L"methodName",10)).Cast< ::String >();
					buf->b[buf->b->length] = HX_STRING(L") - ",4);
				}
				buf->b[buf->b->length] = test->error;
				buf->b[buf->b->length] = HX_STRING(L"\n",1);
				if ((test->backtrace != null())){
					buf->b[buf->b->length] = test->backtrace;
					buf->b[buf->b->length] = HX_STRING(L"\n",1);
				}
				buf->b[buf->b->length] = HX_STRING(L"\n",1);
				failures++;
			}
		}
;
		__SAFE_POINT
	}
	buf->b[buf->b->length] = HX_STRING(L"\n",1);
	if ((failures == 0)){
		buf->b[buf->b->length] = HX_STRING(L"OK ",3);
	}
	else{
		buf->b[buf->b->length] = HX_STRING(L"FAILED ",7);
	}
	buf->b[buf->b->length] = this->m_tests->length;
	buf->b[buf->b->length] = HX_STRING(L" tests, ",8);
	buf->b[buf->b->length] = failures;
	buf->b[buf->b->length] = HX_STRING(L" failed, ",9);
	buf->b[buf->b->length] = ((this->m_tests->length - failures));
	buf->b[buf->b->length] = HX_STRING(L" success",8);
	buf->b[buf->b->length] = HX_STRING(L"\n",1);
	return buf->b->join(HX_STRING(L"",0));
}


HX_DEFINE_DYNAMIC_FUNC0(TestResult_obj,toString,return )


TestResult_obj::TestResult_obj()
{
}

void TestResult_obj::__Mark()
{
	hx::MarkMember(m_tests);
	hx::MarkMember(success);
}

Dynamic TestResult_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"add",sizeof(wchar_t)*3) ) { return add_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"m_tests",sizeof(wchar_t)*7) ) { return m_tests; }
		if (!memcmp(inName.__s,L"success",sizeof(wchar_t)*7) ) { return success; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic TestResult_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (!memcmp(inName.__s,L"m_tests",sizeof(wchar_t)*7) ) { m_tests=inValue.Cast< ::List >(); return inValue; }
		if (!memcmp(inName.__s,L"success",sizeof(wchar_t)*7) ) { success=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void TestResult_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"m_tests",7));
	outFields->push(HX_STRING(L"success",7));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"m_tests",7),
	HX_STRING(L"success",7),
	HX_STRING(L"add",3),
	HX_STRING(L"toString",8),
	String(null()) };

static void sMarkStatics() {
};

Class TestResult_obj::__mClass;

void TestResult_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"haxe.unit.TestResult",20), hx::TCanCast< TestResult_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void TestResult_obj::__boot()
{
}

} // end namespace haxe
} // end namespace unit
