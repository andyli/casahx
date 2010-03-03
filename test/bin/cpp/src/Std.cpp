#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif

Void Std_obj::__construct()
{
	return null();
}

Std_obj::~Std_obj() { }

Dynamic Std_obj::__CreateEmpty() { return  new Std_obj; }
hx::ObjectPtr< Std_obj > Std_obj::__new()
{  hx::ObjectPtr< Std_obj > result = new Std_obj();
	result->__construct();
	return result;}

Dynamic Std_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Std_obj > result = new Std_obj();
	result->__construct();
	return result;}

void Std_obj::__init__(){}

bool Std_obj::is( Dynamic v,Dynamic t){
	__SAFE_POINT
	return ::__instanceof(v,t);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Std_obj,is,return )

::String Std_obj::string( Dynamic s){
	__SAFE_POINT
	return (s == null()) ? ::String( HX_STRING(L"null",4) ) : ::String( s->toString() );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Std_obj,string,return )

int Std_obj::toInt( double x){
	__SAFE_POINT
	return ::__int__(x);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Std_obj,toInt,return )

Dynamic Std_obj::parseInt( ::String x){
	__SAFE_POINT
	{
		if ((x == null()))
			return null();
		return ::__hxcpp_parse_int(x);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Std_obj,parseInt,return )

double Std_obj::parseFloat( ::String x){
	__SAFE_POINT
	return ::__hxcpp_parse_float(x.__s);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Std_obj,parseFloat,return )

int Std_obj::random( int x){
	__SAFE_POINT
	return hx::Mod(::rand(),x);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Std_obj,random,return )


Std_obj::Std_obj()
{
}

void Std_obj::__Mark()
{
}

Dynamic Std_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"is",sizeof(wchar_t)*2) ) { return is_dyn(); }
		break;
	case 3:
		if (!memcmp(inName.__s,L"int",sizeof(wchar_t)*3) ) { return toInt_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"string",sizeof(wchar_t)*6) ) { return string_dyn(); }
		if (!memcmp(inName.__s,L"random",sizeof(wchar_t)*6) ) { return random_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"parseInt",sizeof(wchar_t)*8) ) { return parseInt_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"parseFloat",sizeof(wchar_t)*10) ) { return parseFloat_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Std_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Std_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"is",2),
	HX_STRING(L"string",6),
	HX_STRING(L"int",3),
	HX_STRING(L"parseInt",8),
	HX_STRING(L"parseFloat",10),
	HX_STRING(L"random",6),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
};

Class Std_obj::__mClass;

void Std_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"Std",3), hx::TCanCast< Std_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Std_obj::__boot()
{
}

