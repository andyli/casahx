#include <hxcpp.h>

#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif

Void EReg_obj::__construct(::String r,::String opt)
{
{
	Array< ::String > a = opt.split(HX_STRING(L"g",1));
	this->global = (a->length > 1);
	if (this->global)
		opt = a->join(HX_STRING(L"",0));
	this->r = ::EReg_obj::regexp_new_options(r,opt);
}
;
	return null();
}

EReg_obj::~EReg_obj() { }

Dynamic EReg_obj::__CreateEmpty() { return  new EReg_obj; }
hx::ObjectPtr< EReg_obj > EReg_obj::__new(::String r,::String opt)
{  hx::ObjectPtr< EReg_obj > result = new EReg_obj();
	result->__construct(r,opt);
	return result;}

Dynamic EReg_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EReg_obj > result = new EReg_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

bool EReg_obj::match( ::String s){
	__SAFE_POINT
	bool p = ::EReg_obj::regexp_match(this->r,s,0,s.length);
	if (p){
		this->last = s;
	}
	else{
		this->last = null();
	}
	return p;
}


HX_DEFINE_DYNAMIC_FUNC1(EReg_obj,match,return )

::String EReg_obj::matched( int n){
	__SAFE_POINT
	::String m = ::EReg_obj::regexp_matched(this->r,n);
	return m;
}


HX_DEFINE_DYNAMIC_FUNC1(EReg_obj,matched,return )

::String EReg_obj::matchedLeft( ){
	__SAFE_POINT
	Dynamic p = ::EReg_obj::regexp_matched_pos(this->r,0);
	return this->last.substr(0,p->__Field(HX_STRING(L"pos",3)).Cast< int >());
}


HX_DEFINE_DYNAMIC_FUNC0(EReg_obj,matchedLeft,return )

::String EReg_obj::matchedRight( ){
	__SAFE_POINT
	Dynamic p = ::EReg_obj::regexp_matched_pos(this->r,0);
	int sz = (p->__Field(HX_STRING(L"pos",3)).Cast< int >() + p->__Field(HX_STRING(L"len",3)).Cast< int >());
	return this->last.substr(sz,(this->last.length - sz));
}


HX_DEFINE_DYNAMIC_FUNC0(EReg_obj,matchedRight,return )

Dynamic EReg_obj::matchedPos( ){
	__SAFE_POINT
	return ::EReg_obj::regexp_matched_pos(this->r,0);
}


HX_DEFINE_DYNAMIC_FUNC0(EReg_obj,matchedPos,return )

Array< ::String > EReg_obj::split( ::String s){
	__SAFE_POINT
	int pos = 0;
	int len = s.length;
	Array< ::String > a = Array_obj< ::String >::__new();
	bool first = true;
	do{
		if (!::EReg_obj::regexp_match(this->r,s,pos,len))
			break;
		Dynamic p = ::EReg_obj::regexp_matched_pos(this->r,0);
		if ((bool((p->__Field(HX_STRING(L"len",3)).Cast< int >() == 0)) && bool(!first))){
			if ((p->__Field(HX_STRING(L"pos",3)).Cast< int >() == s.length))
				break;
			hx::AddEq(p->__FieldRef(HX_STRING(L"pos",3)),1);
		}
		a->push(s.substr(pos,(p->__Field(HX_STRING(L"pos",3)).Cast< int >() - pos)));
		int tot = (((p->__Field(HX_STRING(L"pos",3)).Cast< int >() + p->__Field(HX_STRING(L"len",3)).Cast< int >())) - pos);
		hx::AddEq(pos,tot);
		hx::SubEq(len,tot);
		first = false;
	}
while(this->global);
	a->push(s.substr(pos,len));
	return a;
}


HX_DEFINE_DYNAMIC_FUNC1(EReg_obj,split,return )

::String EReg_obj::replace( ::String s,::String by){
	__SAFE_POINT
	::StringBuf b = ::StringBuf_obj::__new();
	int pos = 0;
	int len = s.length;
	Array< ::String > a = by.split(HX_STRING(L"$",1));
	bool first = true;
	do{
		if (!::EReg_obj::regexp_match(this->r,s.__s,pos,len))
			break;
		Dynamic p = ::EReg_obj::regexp_matched_pos(this->r,0);
		if ((bool((p->__Field(HX_STRING(L"len",3)).Cast< int >() == 0)) && bool(!first))){
			if ((p->__Field(HX_STRING(L"pos",3)).Cast< int >() == s.length))
				break;
			hx::AddEq(p->__FieldRef(HX_STRING(L"pos",3)),1);
		}
		b->b[b->b->length] = s.substr(pos,(p->__Field(HX_STRING(L"pos",3)).Cast< int >() - pos));
		if ((a->length > 0))
			b->b[b->b->length] = a->__get(0);
		int i = 1;
		while((i < a->length)){
			__SAFE_POINT
			::String k = a->__get(i);
			Dynamic c = k.charCodeAt(0);
			if ((bool((c >= 49)) && bool((c <= 57)))){
				struct _Function_4_1{
					inline static Dynamic Block( ::EReg_obj *__this,Dynamic &c)/* DEF (not block)(ret intern) */{
						try{
							return ::EReg_obj::regexp_matched_pos(__this->r,(::Std_obj::toInt(c) - 48));
						}
						catch(Dynamic __e){
							if (__e.IsClass< ::String >() ){
								::String e = __e;{
									return null();
								}
							}
							else throw(__e);
						}
					}
				};
				Dynamic p1 = _Function_4_1::Block(this,c);
				if ((p1 == null())){
					b->b[b->b->length] = HX_STRING(L"$",1);
					b->b[b->b->length] = k;
				}
				else{
					b->b[b->b->length] = s.substr(p1->__Field(HX_STRING(L"pos",3)).Cast< int >(),p1->__Field(HX_STRING(L"len",3)).Cast< int >());
					b->b[b->b->length] = k.substr(1,(k.length - 1));
				}
			}
			else{
				if ((c == null())){
					b->b[b->b->length] = HX_STRING(L"$",1);
					i++;
					::String k2 = a->__get(i);
					if ((bool((k2 != null())) && bool((k2.length > 0))))
						b->b[b->b->length] = k2;
				}
				else{
					b->b[b->b->length] = (HX_STRING(L"$",1) + k);
				}
			}
			i++;
		}
		int tot = (((p->__Field(HX_STRING(L"pos",3)).Cast< int >() + p->__Field(HX_STRING(L"len",3)).Cast< int >())) - pos);
		hx::AddEq(pos,tot);
		hx::SubEq(len,tot);
		first = false;
	}
while(this->global);
	b->b[b->b->length] = s.substr(pos,len);
	return b->b->join(HX_STRING(L"",0));
}


HX_DEFINE_DYNAMIC_FUNC2(EReg_obj,replace,return )

::String EReg_obj::customReplace( ::String s,Dynamic f){
	__SAFE_POINT
	::StringBuf buf = ::StringBuf_obj::__new();
	while(true){
		__SAFE_POINT
		if (!this->match(s))
			break;
		buf->b[buf->b->length] = this->matchedLeft();
		buf->b[buf->b->length] = f(this);
		s = this->matchedRight();
	}
	buf->b[buf->b->length] = s;
	return buf->b->join(HX_STRING(L"",0));
}


HX_DEFINE_DYNAMIC_FUNC2(EReg_obj,customReplace,return )

Dynamic EReg_obj::regexp_new_options;

Dynamic EReg_obj::regexp_match;

Dynamic EReg_obj::regexp_matched;

Dynamic EReg_obj::regexp_matched_pos;


EReg_obj::EReg_obj()
{
}

void EReg_obj::__Mark()
{
	hx::MarkMember(r);
	hx::MarkMember(last);
	hx::MarkMember(global);
}

Dynamic EReg_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"r",sizeof(wchar_t)*1) ) { return r; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"last",sizeof(wchar_t)*4) ) { return last; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"match",sizeof(wchar_t)*5) ) { return match_dyn(); }
		if (!memcmp(inName.__s,L"split",sizeof(wchar_t)*5) ) { return split_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"global",sizeof(wchar_t)*6) ) { return global; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"matched",sizeof(wchar_t)*7) ) { return matched_dyn(); }
		if (!memcmp(inName.__s,L"replace",sizeof(wchar_t)*7) ) { return replace_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"matchedPos",sizeof(wchar_t)*10) ) { return matchedPos_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"matchedLeft",sizeof(wchar_t)*11) ) { return matchedLeft_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"regexp_match",sizeof(wchar_t)*12) ) { return regexp_match; }
		if (!memcmp(inName.__s,L"matchedRight",sizeof(wchar_t)*12) ) { return matchedRight_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"customReplace",sizeof(wchar_t)*13) ) { return customReplace_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"regexp_matched",sizeof(wchar_t)*14) ) { return regexp_matched; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"regexp_new_options",sizeof(wchar_t)*18) ) { return regexp_new_options; }
		if (!memcmp(inName.__s,L"regexp_matched_pos",sizeof(wchar_t)*18) ) { return regexp_matched_pos; }
	}
	return super::__Field(inName);
}

Dynamic EReg_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"r",sizeof(wchar_t)*1) ) { r=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"last",sizeof(wchar_t)*4) ) { last=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"global",sizeof(wchar_t)*6) ) { global=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"regexp_match",sizeof(wchar_t)*12) ) { regexp_match=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"regexp_matched",sizeof(wchar_t)*14) ) { regexp_matched=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"regexp_new_options",sizeof(wchar_t)*18) ) { regexp_new_options=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"regexp_matched_pos",sizeof(wchar_t)*18) ) { regexp_matched_pos=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void EReg_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"r",1));
	outFields->push(HX_STRING(L"last",4));
	outFields->push(HX_STRING(L"global",6));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"regexp_new_options",18),
	HX_STRING(L"regexp_match",12),
	HX_STRING(L"regexp_matched",14),
	HX_STRING(L"regexp_matched_pos",18),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"r",1),
	HX_STRING(L"last",4),
	HX_STRING(L"global",6),
	HX_STRING(L"match",5),
	HX_STRING(L"matched",7),
	HX_STRING(L"matchedLeft",11),
	HX_STRING(L"matchedRight",12),
	HX_STRING(L"matchedPos",10),
	HX_STRING(L"split",5),
	HX_STRING(L"replace",7),
	HX_STRING(L"customReplace",13),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(EReg_obj::regexp_new_options);
	hx::MarkMember(EReg_obj::regexp_match);
	hx::MarkMember(EReg_obj::regexp_matched);
	hx::MarkMember(EReg_obj::regexp_matched_pos);
};

Class EReg_obj::__mClass;

void EReg_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"EReg",4), hx::TCanCast< EReg_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void EReg_obj::__boot()
{
	hx::Static(regexp_new_options) = ::cpp::Lib_obj::load(HX_STRING(L"regexp",6),HX_STRING(L"regexp_new_options",18),2);
	hx::Static(regexp_match) = ::cpp::Lib_obj::load(HX_STRING(L"regexp",6),HX_STRING(L"regexp_match",12),4);
	hx::Static(regexp_matched) = ::cpp::Lib_obj::load(HX_STRING(L"regexp",6),HX_STRING(L"regexp_matched",14),2);
	hx::Static(regexp_matched_pos) = ::cpp::Lib_obj::load(HX_STRING(L"regexp",6),HX_STRING(L"regexp_matched_pos",18),2);
}

