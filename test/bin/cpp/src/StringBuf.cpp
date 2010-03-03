#include <hxcpp.h>

#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif

Void StringBuf_obj::__construct()
{
{
	this->b = Array_obj< Dynamic >::__new();
}
;
	return null();
}

StringBuf_obj::~StringBuf_obj() { }

Dynamic StringBuf_obj::__CreateEmpty() { return  new StringBuf_obj; }
hx::ObjectPtr< StringBuf_obj > StringBuf_obj::__new()
{  hx::ObjectPtr< StringBuf_obj > result = new StringBuf_obj();
	result->__construct();
	return result;}

Dynamic StringBuf_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< StringBuf_obj > result = new StringBuf_obj();
	result->__construct();
	return result;}

Void StringBuf_obj::add( Dynamic x){
{
		this->b[this->b->length] = x;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(StringBuf_obj,add,(void))

Void StringBuf_obj::addSub( ::String s,int pos,Dynamic len){
{
		__SAFE_POINT
		this->b[this->b->length] = s.substr(pos,len);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(StringBuf_obj,addSub,(void))

Void StringBuf_obj::addChar( int c){
{
		__SAFE_POINT
		this->b[this->b->length] = ::String::fromCharCode(c);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(StringBuf_obj,addChar,(void))

::String StringBuf_obj::toString( ){
	__SAFE_POINT
	return this->b->join(HX_STRING(L"",0));
}


HX_DEFINE_DYNAMIC_FUNC0(StringBuf_obj,toString,return )


StringBuf_obj::StringBuf_obj()
{
}

void StringBuf_obj::__Mark()
{
	hx::MarkMember(b);
}

Dynamic StringBuf_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"b",sizeof(wchar_t)*1) ) { return b; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"add",sizeof(wchar_t)*3) ) { return add_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"addSub",sizeof(wchar_t)*6) ) { return addSub_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"addChar",sizeof(wchar_t)*7) ) { return addChar_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic StringBuf_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"b",sizeof(wchar_t)*1) ) { b=inValue.Cast< Array< Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void StringBuf_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"b",1));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"add",3),
	HX_STRING(L"addSub",6),
	HX_STRING(L"addChar",7),
	HX_STRING(L"toString",8),
	HX_STRING(L"b",1),
	String(null()) };

static void sMarkStatics() {
};

Class StringBuf_obj::__mClass;

void StringBuf_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"StringBuf",9), hx::TCanCast< StringBuf_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void StringBuf_obj::__boot()
{
}

