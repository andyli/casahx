#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif

Void StringTools_obj::__construct()
{
	return null();
}

StringTools_obj::~StringTools_obj() { }

Dynamic StringTools_obj::__CreateEmpty() { return  new StringTools_obj; }
hx::ObjectPtr< StringTools_obj > StringTools_obj::__new()
{  hx::ObjectPtr< StringTools_obj > result = new StringTools_obj();
	result->__construct();
	return result;}

Dynamic StringTools_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< StringTools_obj > result = new StringTools_obj();
	result->__construct();
	return result;}

::String StringTools_obj::urlEncode( ::String s){
	__SAFE_POINT
	return s.__URLEncode();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,urlEncode,return )

::String StringTools_obj::urlDecode( ::String s){
	__SAFE_POINT
	return s.__URLDecode();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,urlDecode,return )

::String StringTools_obj::htmlEscape( ::String s){
	__SAFE_POINT
	return s.split(HX_STRING(L"&",1))->join(HX_STRING(L"&amp;",5)).split(HX_STRING(L"<",1))->join(HX_STRING(L"&lt;",4)).split(HX_STRING(L">",1))->join(HX_STRING(L"&gt;",4));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,htmlEscape,return )

::String StringTools_obj::htmlUnescape( ::String s){
	__SAFE_POINT
	return s.split(HX_STRING(L"&gt;",4))->join(HX_STRING(L">",1)).split(HX_STRING(L"&lt;",4))->join(HX_STRING(L"<",1)).split(HX_STRING(L"&amp;",5))->join(HX_STRING(L"&",1));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,htmlUnescape,return )

bool StringTools_obj::startsWith( ::String s,::String start){
	__SAFE_POINT
	return ((bool((s.length >= start.length)) && bool((s.substr(0,start.length) == start))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(StringTools_obj,startsWith,return )

bool StringTools_obj::endsWith( ::String s,::String end){
	__SAFE_POINT
	int elen = end.length;
	int slen = s.length;
	return ((bool((slen >= elen)) && bool((s.substr((slen - elen),elen) == end))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(StringTools_obj,endsWith,return )

bool StringTools_obj::isSpace( ::String s,int pos){
	__SAFE_POINT
	Dynamic c = s.charCodeAt(pos);
	return (bool(((bool((c >= 9)) && bool((c <= 13))))) || bool((c == 32)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(StringTools_obj,isSpace,return )

::String StringTools_obj::ltrim( ::String s){
	__SAFE_POINT
	int l = s.length;
	int r = 0;
	while((bool((r < l)) && bool(::StringTools_obj::isSpace(s,r)))){
		__SAFE_POINT
		r++;
	}
	if ((r > 0)){
		return s.substr(r,(l - r));
	}
	else{
		return s;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,ltrim,return )

::String StringTools_obj::rtrim( ::String s){
	__SAFE_POINT
	int l = s.length;
	int r = 0;
	while((bool((r < l)) && bool(::StringTools_obj::isSpace(s,(((l - r)) - 1))))){
		__SAFE_POINT
		r++;
	}
	if ((r > 0)){
		return s.substr(0,(l - r));
	}
	else{
		return s;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,rtrim,return )

::String StringTools_obj::trim( ::String s){
	__SAFE_POINT
	return ::StringTools_obj::ltrim(::StringTools_obj::rtrim(s));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,trim,return )

::String StringTools_obj::rpad( ::String s,::String c,int l){
	__SAFE_POINT
	int sl = s.length;
	int cl = c.length;
	while((sl < l)){
		__SAFE_POINT
		if (((l - sl) < cl)){
			hx::AddEq(s,c.substr(0,(l - sl)));
			sl = l;
		}
		else{
			hx::AddEq(s,c);
			hx::AddEq(sl,cl);
		}
	}
	return s;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(StringTools_obj,rpad,return )

::String StringTools_obj::lpad( ::String s,::String c,int l){
	__SAFE_POINT
	::String ns = HX_STRING(L"",0);
	int sl = s.length;
	if ((sl >= l))
		return s;
	int cl = c.length;
	while((sl < l)){
		__SAFE_POINT
		if (((l - sl) < cl)){
			hx::AddEq(ns,c.substr(0,(l - sl)));
			sl = l;
		}
		else{
			hx::AddEq(ns,c);
			hx::AddEq(sl,cl);
		}
	}
	return (ns + s);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(StringTools_obj,lpad,return )

::String StringTools_obj::replace( ::String s,::String sub,::String by){
	__SAFE_POINT
	return s.split(sub)->join(by);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(StringTools_obj,replace,return )

::String StringTools_obj::hex( int n,Dynamic digits){
	__SAFE_POINT
	bool neg = false;
	if ((n < 0)){
		neg = true;
		n = -n;
	}
	::String s = HX_STRING(L"",0);
	::String hexChars = HX_STRING(L"0123456789ABCDEF",16);
	do{
		s = (hexChars.charAt(hx::Mod(n,16)) + s);
		n = ::Std_obj::toInt((double(n) / double(16)));
	}
while((n > 0));
	if ((digits != null()))
		while((s.length < digits))s = (HX_STRING(L"0",1) + s);
	if (neg)
		s = (HX_STRING(L"-",1) + s);
	return s;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(StringTools_obj,hex,return )


StringTools_obj::StringTools_obj()
{
}

void StringTools_obj::__Mark()
{
}

Dynamic StringTools_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"hex",sizeof(wchar_t)*3) ) { return hex_dyn(); }
		break;
	case 4:
		if (!memcmp(inName.__s,L"trim",sizeof(wchar_t)*4) ) { return trim_dyn(); }
		if (!memcmp(inName.__s,L"rpad",sizeof(wchar_t)*4) ) { return rpad_dyn(); }
		if (!memcmp(inName.__s,L"lpad",sizeof(wchar_t)*4) ) { return lpad_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"ltrim",sizeof(wchar_t)*5) ) { return ltrim_dyn(); }
		if (!memcmp(inName.__s,L"rtrim",sizeof(wchar_t)*5) ) { return rtrim_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"isSpace",sizeof(wchar_t)*7) ) { return isSpace_dyn(); }
		if (!memcmp(inName.__s,L"replace",sizeof(wchar_t)*7) ) { return replace_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"endsWith",sizeof(wchar_t)*8) ) { return endsWith_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"urlEncode",sizeof(wchar_t)*9) ) { return urlEncode_dyn(); }
		if (!memcmp(inName.__s,L"urlDecode",sizeof(wchar_t)*9) ) { return urlDecode_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"htmlEscape",sizeof(wchar_t)*10) ) { return htmlEscape_dyn(); }
		if (!memcmp(inName.__s,L"startsWith",sizeof(wchar_t)*10) ) { return startsWith_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"htmlUnescape",sizeof(wchar_t)*12) ) { return htmlUnescape_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic StringTools_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void StringTools_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"urlEncode",9),
	HX_STRING(L"urlDecode",9),
	HX_STRING(L"htmlEscape",10),
	HX_STRING(L"htmlUnescape",12),
	HX_STRING(L"startsWith",10),
	HX_STRING(L"endsWith",8),
	HX_STRING(L"isSpace",7),
	HX_STRING(L"ltrim",5),
	HX_STRING(L"rtrim",5),
	HX_STRING(L"trim",4),
	HX_STRING(L"rpad",4),
	HX_STRING(L"lpad",4),
	HX_STRING(L"replace",7),
	HX_STRING(L"hex",3),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
};

Class StringTools_obj::__mClass;

void StringTools_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"StringTools",11), hx::TCanCast< StringTools_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void StringTools_obj::__boot()
{
}

