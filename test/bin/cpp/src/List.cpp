#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif

Void List_obj::__construct()
{
{
	this->length = 0;
}
;
	return null();
}

List_obj::~List_obj() { }

Dynamic List_obj::__CreateEmpty() { return  new List_obj; }
hx::ObjectPtr< List_obj > List_obj::__new()
{  hx::ObjectPtr< List_obj > result = new List_obj();
	result->__construct();
	return result;}

Dynamic List_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< List_obj > result = new List_obj();
	result->__construct();
	return result;}

Void List_obj::add( Dynamic item){
{
		Array< Dynamic > x = Array_obj< Dynamic >::__new().Add(item);
		if ((this->h == null())){
			this->h = x;
		}
		else{
			this->q[1] = x;
		}
		this->q = x;
		this->length++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(List_obj,add,(void))

Void List_obj::push( Dynamic item){
{
		Array< Dynamic > x = Array_obj< Dynamic >::__new().Add(item).Add(this->h);
		this->h = x;
		if ((this->q == null()))
			this->q = x;
		this->length++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(List_obj,push,(void))

Dynamic List_obj::first( ){
	return (this->h == null()) ? Dynamic( null() ) : Dynamic( this->h->__get(0) );
}


HX_DEFINE_DYNAMIC_FUNC0(List_obj,first,return )

Dynamic List_obj::last( ){
	return (this->q == null()) ? Dynamic( null() ) : Dynamic( this->q->__get(0) );
}


HX_DEFINE_DYNAMIC_FUNC0(List_obj,last,return )

Dynamic List_obj::pop( ){
	if ((this->h == null()))
		return null();
	Dynamic x = this->h->__get(0);
	this->h = this->h->__get(1);
	if ((this->h == null()))
		this->q = null();
	this->length--;
	return x;
}


HX_DEFINE_DYNAMIC_FUNC0(List_obj,pop,return )

bool List_obj::isEmpty( ){
	return ((this->h == null()));
}


HX_DEFINE_DYNAMIC_FUNC0(List_obj,isEmpty,return )

Void List_obj::clear( ){
{
		this->h = null();
		this->q = null();
		this->length = 0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(List_obj,clear,(void))

bool List_obj::remove( Dynamic v){
	Array< Dynamic > prev = null();
	Array< Dynamic > l = this->h;
	while((l != null())){
		__SAFE_POINT
		if ((l->__get(0) == v)){
			if ((prev == null())){
				this->h = l->__get(1);
			}
			else{
				prev[1] = l->__get(1);
			}
			if ((this->q == l))
				this->q = prev;
			this->length--;
			return true;
		}
		prev = l;
		l = l->__get(1);
	}
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(List_obj,remove,return )

Dynamic List_obj::iterator( ){
	struct _Function_1_1{
		inline static Dynamic Block( ::List_obj *__this){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_STRING(L"h",1) , __this->h);

			HX_BEGIN_LOCAL_FUNC0(_Function_2_1)
			Dynamic run(){
{
					return ((__this->__Field(HX_STRING(L"h",1)).Cast< Array< Dynamic > >() != null()));
				}
				return null();
			}
			Dynamic __this;
			void __SetThis(Dynamic inThis) { __this = inThis; }
			HX_END_LOCAL_FUNC0(return)

			__result->Add(HX_STRING(L"hasNext",7) ,  Dynamic(new _Function_2_1()));

			HX_BEGIN_LOCAL_FUNC0(_Function_2_2)
			Dynamic run(){
{
					{
						if ((__this->__Field(HX_STRING(L"h",1)).Cast< Array< Dynamic > >() == null()))
							return null();
						Dynamic x = __this->__Field(HX_STRING(L"h",1)).Cast< Array< Dynamic > >()->__get(0);
						__this->__FieldRef(HX_STRING(L"h",1)) = __this->__Field(HX_STRING(L"h",1)).Cast< Array< Dynamic > >()->__get(1);
						return x;
					}
				}
				return null();
			}
			Dynamic __this;
			void __SetThis(Dynamic inThis) { __this = inThis; }
			HX_END_LOCAL_FUNC0(return)

			__result->Add(HX_STRING(L"next",4) ,  Dynamic(new _Function_2_2()));
			return __result;
		}
	};
	return _Function_1_1::Block(this);
}


HX_DEFINE_DYNAMIC_FUNC0(List_obj,iterator,return )

::String List_obj::toString( ){
	__SAFE_POINT
	::StringBuf s = ::StringBuf_obj::__new();
	bool first = true;
	Array< Dynamic > l = this->h;
	s->b[s->b->length] = HX_STRING(L"{",1);
	while((l != null())){
		__SAFE_POINT
		if (first){
			first = false;
		}
		else{
			s->b[s->b->length] = HX_STRING(L", ",2);
		}
		s->b[s->b->length] = ::Std_obj::string(l->__get(0));
		l = l->__get(1);
	}
	s->b[s->b->length] = HX_STRING(L"}",1);
	return s->b->join(HX_STRING(L"",0));
}


HX_DEFINE_DYNAMIC_FUNC0(List_obj,toString,return )

::String List_obj::join( ::String sep){
	__SAFE_POINT
	::StringBuf s = ::StringBuf_obj::__new();
	bool first = true;
	Array< Dynamic > l = this->h;
	while((l != null())){
		__SAFE_POINT
		if (first){
			first = false;
		}
		else{
			s->b[s->b->length] = sep;
		}
		s->b[s->b->length] = l->__get(0);
		l = l->__get(1);
	}
	return s->b->join(HX_STRING(L"",0));
}


HX_DEFINE_DYNAMIC_FUNC1(List_obj,join,return )

::List List_obj::filter( Dynamic f){
	__SAFE_POINT
	::List l2 = ::List_obj::__new();
	Array< Dynamic > l = this->h;
	while((l != null())){
		__SAFE_POINT
		Dynamic v = l->__get(0);
		l = l->__get(1);
		if (f(v))
			l2->add(v);
	}
	return l2;
}


HX_DEFINE_DYNAMIC_FUNC1(List_obj,filter,return )

::List List_obj::map( Dynamic f){
	__SAFE_POINT
	::List b = ::List_obj::__new();
	Array< Dynamic > l = this->h;
	while((l != null())){
		__SAFE_POINT
		Dynamic v = l->__get(0);
		l = l->__get(1);
		b->add(f(v));
	}
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(List_obj,map,return )


List_obj::List_obj()
{
}

void List_obj::__Mark()
{
	hx::MarkMember(h);
	hx::MarkMember(q);
	hx::MarkMember(length);
}

Dynamic List_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"h",sizeof(wchar_t)*1) ) { return h; }
		if (!memcmp(inName.__s,L"q",sizeof(wchar_t)*1) ) { return q; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"add",sizeof(wchar_t)*3) ) { return add_dyn(); }
		if (!memcmp(inName.__s,L"pop",sizeof(wchar_t)*3) ) { return pop_dyn(); }
		if (!memcmp(inName.__s,L"map",sizeof(wchar_t)*3) ) { return map_dyn(); }
		break;
	case 4:
		if (!memcmp(inName.__s,L"push",sizeof(wchar_t)*4) ) { return push_dyn(); }
		if (!memcmp(inName.__s,L"last",sizeof(wchar_t)*4) ) { return last_dyn(); }
		if (!memcmp(inName.__s,L"join",sizeof(wchar_t)*4) ) { return join_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"first",sizeof(wchar_t)*5) ) { return first_dyn(); }
		if (!memcmp(inName.__s,L"clear",sizeof(wchar_t)*5) ) { return clear_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"length",sizeof(wchar_t)*6) ) { return length; }
		if (!memcmp(inName.__s,L"remove",sizeof(wchar_t)*6) ) { return remove_dyn(); }
		if (!memcmp(inName.__s,L"filter",sizeof(wchar_t)*6) ) { return filter_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"isEmpty",sizeof(wchar_t)*7) ) { return isEmpty_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"iterator",sizeof(wchar_t)*8) ) { return iterator_dyn(); }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic List_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"h",sizeof(wchar_t)*1) ) { h=inValue.Cast< Array< Dynamic > >(); return inValue; }
		if (!memcmp(inName.__s,L"q",sizeof(wchar_t)*1) ) { q=inValue.Cast< Array< Dynamic > >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"length",sizeof(wchar_t)*6) ) { length=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void List_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"h",1));
	outFields->push(HX_STRING(L"q",1));
	outFields->push(HX_STRING(L"length",6));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"h",1),
	HX_STRING(L"q",1),
	HX_STRING(L"length",6),
	HX_STRING(L"add",3),
	HX_STRING(L"push",4),
	HX_STRING(L"first",5),
	HX_STRING(L"last",4),
	HX_STRING(L"pop",3),
	HX_STRING(L"isEmpty",7),
	HX_STRING(L"clear",5),
	HX_STRING(L"remove",6),
	HX_STRING(L"iterator",8),
	HX_STRING(L"toString",8),
	HX_STRING(L"join",4),
	HX_STRING(L"filter",6),
	HX_STRING(L"map",3),
	String(null()) };

static void sMarkStatics() {
};

Class List_obj::__mClass;

void List_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"List",4), hx::TCanCast< List_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void List_obj::__boot()
{
}

