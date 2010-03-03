#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif

Void Reflect_obj::__construct()
{
	return null();
}

Reflect_obj::~Reflect_obj() { }

Dynamic Reflect_obj::__CreateEmpty() { return  new Reflect_obj; }
hx::ObjectPtr< Reflect_obj > Reflect_obj::__new()
{  hx::ObjectPtr< Reflect_obj > result = new Reflect_obj();
	result->__construct();
	return result;}

Dynamic Reflect_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Reflect_obj > result = new Reflect_obj();
	result->__construct();
	return result;}

bool Reflect_obj::hasField( Dynamic o,::String field){
	__SAFE_POINT
	return (bool((o != null())) && bool(o->__HasField(field)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Reflect_obj,hasField,return )

Dynamic Reflect_obj::field( Dynamic o,::String field){
	__SAFE_POINT
	return ((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(field) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Reflect_obj,field,return )

Void Reflect_obj::setField( Dynamic o,::String field,Dynamic value){
{
		__SAFE_POINT
		if ((o != null())){
			o->__SetField(field,value);
		}
		else{
			{};
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Reflect_obj,setField,(void))

Dynamic Reflect_obj::callMethod( Dynamic o,Dynamic func,Array< Dynamic > args){
	__SAFE_POINT
	if ((bool((func != null())) && bool((func->__GetType() == ::vtString))))
		func = o->__Field(func);
	func->__SetThis(o);
	return func->__Run(args);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Reflect_obj,callMethod,return )

Array< ::String > Reflect_obj::fields( Dynamic o){
	__SAFE_POINT
	if ((o == null()))
		return Array_obj< ::String >::__new();
	Array< ::String > a = Array_obj< ::String >::__new();
	o->__GetFields(a);
	return a;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Reflect_obj,fields,return )

bool Reflect_obj::isFunction( Dynamic f){
	__SAFE_POINT
	return (bool((f != null())) && bool((f->__GetType() == ::vtFunction)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Reflect_obj,isFunction,return )

int Reflect_obj::compare( Dynamic a,Dynamic b){
	return ((a == b)) ? int( 0 ) : int( ((((a) > (b))) ? int( 1 ) : int( -1 )) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Reflect_obj,compare,return )

bool Reflect_obj::compareMethods( Dynamic f1,Dynamic f2){
	__SAFE_POINT
	if ((f1 == f2))
		return true;
	if ((bool(!::Reflect_obj::isFunction(f1)) || bool(!::Reflect_obj::isFunction(f2))))
		return false;
	return ::__hxcpp_same_closure(f1,f2);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Reflect_obj,compareMethods,return )

bool Reflect_obj::isObject( Dynamic v){
	__SAFE_POINT
	if ((v == null()))
		return false;
	int t = v->__GetType();
	return (bool((t == ::vtObject)) || bool((bool((t == ::vtClass)) || bool((bool((t == ::vtString)) || bool((t == ::vtArray)))))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Reflect_obj,isObject,return )

bool Reflect_obj::deleteField( Dynamic o,::String f){
	__SAFE_POINT
	if ((o == null()))
		return false;
	return __hxcpp_anon_remove(o,f);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Reflect_obj,deleteField,return )

Dynamic Reflect_obj::copy( Dynamic o){
	__SAFE_POINT
	if ((o == null()))
		return null();
	if ((o->__GetType() == ::vtString))
		return o;
	if ((o->__GetType() == ::vtArray))
		return o->__Field(HX_STRING(L"copy",4))();
	struct _Function_1_1{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			return __result;
		}
	};
	Dynamic o2 = _Function_1_1::Block();
	{
		int _g = 0;
		Array< ::String > _g1 = ::Reflect_obj::fields(o);
		while((_g < _g1->length)){
			__SAFE_POINT
			::String f = _g1->__get(_g);
			++_g;
			if ((o2 != null())){
				o2->__SetField(f,((o == null())) ? Dynamic( null() ) : Dynamic( o->__Field(f) ));
			}
			else{
				{};
			}
		}
	}
	return o2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Reflect_obj,copy,return )

Dynamic Reflect_obj::makeVarArgs( Dynamic f){
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Reflect_obj,makeVarArgs,return )


Reflect_obj::Reflect_obj()
{
}

void Reflect_obj::__Mark()
{
}

Dynamic Reflect_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"copy",sizeof(wchar_t)*4) ) { return copy_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"field",sizeof(wchar_t)*5) ) { return field_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"fields",sizeof(wchar_t)*6) ) { return fields_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"compare",sizeof(wchar_t)*7) ) { return compare_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"hasField",sizeof(wchar_t)*8) ) { return hasField_dyn(); }
		if (!memcmp(inName.__s,L"setField",sizeof(wchar_t)*8) ) { return setField_dyn(); }
		if (!memcmp(inName.__s,L"isObject",sizeof(wchar_t)*8) ) { return isObject_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"callMethod",sizeof(wchar_t)*10) ) { return callMethod_dyn(); }
		if (!memcmp(inName.__s,L"isFunction",sizeof(wchar_t)*10) ) { return isFunction_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"deleteField",sizeof(wchar_t)*11) ) { return deleteField_dyn(); }
		if (!memcmp(inName.__s,L"makeVarArgs",sizeof(wchar_t)*11) ) { return makeVarArgs_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"compareMethods",sizeof(wchar_t)*14) ) { return compareMethods_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Reflect_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Reflect_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"hasField",8),
	HX_STRING(L"field",5),
	HX_STRING(L"setField",8),
	HX_STRING(L"callMethod",10),
	HX_STRING(L"fields",6),
	HX_STRING(L"isFunction",10),
	HX_STRING(L"compare",7),
	HX_STRING(L"compareMethods",14),
	HX_STRING(L"isObject",8),
	HX_STRING(L"deleteField",11),
	HX_STRING(L"copy",4),
	HX_STRING(L"makeVarArgs",11),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
};

Class Reflect_obj::__mClass;

void Reflect_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"Reflect",7), hx::TCanCast< Reflect_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Reflect_obj::__boot()
{
}

