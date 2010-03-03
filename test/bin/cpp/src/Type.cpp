#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_ValueType
#include <ValueType.h>
#endif

Void Type_obj::__construct()
{
	return null();
}

Type_obj::~Type_obj() { }

Dynamic Type_obj::__CreateEmpty() { return  new Type_obj; }
hx::ObjectPtr< Type_obj > Type_obj::__new()
{  hx::ObjectPtr< Type_obj > result = new Type_obj();
	result->__construct();
	return result;}

Dynamic Type_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Type_obj > result = new Type_obj();
	result->__construct();
	return result;}

::Class Type_obj::getClass( Dynamic o){
	__SAFE_POINT
	if ((bool((o == null())) || bool(!::Reflect_obj::isObject(o))))
		return null();
	Dynamic c = o->__GetClass();
	::String _switch_1 = (c->toString());
	if (  ( _switch_1==HX_STRING(L"__Anon",6))){
		return null();
	}
	else if (  ( _switch_1==HX_STRING(L"Class",5))){
		return null();
	}
	return c;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getClass,return )

::Enum Type_obj::getEnum( Dynamic o){
	__SAFE_POINT
	if ((o->__GetClass() != hx::ClassOf< ::Enum >()))
		return null();
	return o;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getEnum,return )

::Class Type_obj::getSuperClass( ::Class c){
	__SAFE_POINT
	return c->GetSuper();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getSuperClass,return )

::String Type_obj::getClassName( ::Class c){
	if ((c == null()))
		return null();
	return c->mName;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getClassName,return )

::String Type_obj::getEnumName( ::Enum e){
	__SAFE_POINT
	return e->__ToString();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getEnumName,return )

::Class Type_obj::resolveClass( ::String name){
	__SAFE_POINT
	return ::Class_obj::Resolve(name);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,resolveClass,return )

::Enum Type_obj::resolveEnum( ::String name){
	__SAFE_POINT
	return ::Class_obj::Resolve(name);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,resolveEnum,return )

Dynamic Type_obj::createInstance( ::Class cl,Array< Dynamic > args){
	__SAFE_POINT
	if ((cl != null()))
		return cl->mConstructArgs(args);
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Type_obj,createInstance,return )

Dynamic Type_obj::createEmptyInstance( ::Class cl){
	__SAFE_POINT
	return cl->mConstructEmpty();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,createEmptyInstance,return )

Dynamic Type_obj::createEnum( ::Enum e,::String constr,Array< Dynamic > params){
	__SAFE_POINT
	if ((e->mConstructEnum != null()))
		return e->mConstructEnum(constr,params);
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Type_obj,createEnum,return )

Dynamic Type_obj::createEnumIndex( ::Enum e,int index,Array< Dynamic > params){
	__SAFE_POINT
	::String c = ::Type_obj::getEnumConstructs(e)->__get(index);
	if ((c == null()))
		hx::Throw ((index + HX_STRING(L" is not a valid enum constructor index",38)));
	return ::Type_obj::createEnum(e,c,params);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Type_obj,createEnumIndex,return )

Array< ::String > Type_obj::getInstanceFields( ::Class c){
	__SAFE_POINT
	return c->GetInstanceFields();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getInstanceFields,return )

Array< ::String > Type_obj::getClassFields( ::Class c){
	__SAFE_POINT
	return c->GetClassFields();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getClassFields,return )

Array< ::String > Type_obj::getEnumConstructs( ::Enum e){
	__SAFE_POINT
	return e->GetClassFields();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,getEnumConstructs,return )

::ValueType Type_obj::_typeof( Dynamic v){
	__SAFE_POINT
	if ((v == null()))
		return ::ValueType_obj::TNull;
	int t = v->__GetType();
	int _switch_2 = (t);
	if (  ( _switch_2==::vtBool)){
		return ::ValueType_obj::TBool;
	}
	else if (  ( _switch_2==::vtInt)){
		return ::ValueType_obj::TInt;
	}
	else if (  ( _switch_2==::vtFloat)){
		return ::ValueType_obj::TFloat;
	}
	else if (  ( _switch_2==::vtFunction)){
		return ::ValueType_obj::TFunction;
	}
	else if (  ( _switch_2==::vtObject)){
		return ::ValueType_obj::TObject;
	}
	else if (  ( _switch_2==::vtEnum)){
		return ::ValueType_obj::TEnum(v->__GetClass());
	}
	else  {
		return ::ValueType_obj::TClass(v->__GetClass());
	}
;
;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,_typeof,return )

bool Type_obj::enumEq( Dynamic a,Dynamic b){
	if ((a == b))
		return true;
	return (a == b);
	return true;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Type_obj,enumEq,return )

::String Type_obj::enumConstructor( Dynamic e){
	__SAFE_POINT
	return e->__Tag();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,enumConstructor,return )

Array< Dynamic > Type_obj::enumParameters( Dynamic e){
	__SAFE_POINT
	return e->__EnumParams();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,enumParameters,return )

int Type_obj::enumIndex( Dynamic e){
	__SAFE_POINT
	return e->__Index();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Type_obj,enumIndex,return )


Type_obj::Type_obj()
{
}

void Type_obj::__Mark()
{
}

Dynamic Type_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (!memcmp(inName.__s,L"typeof",sizeof(wchar_t)*6) ) { return _typeof_dyn(); }
		if (!memcmp(inName.__s,L"enumEq",sizeof(wchar_t)*6) ) { return enumEq_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"getEnum",sizeof(wchar_t)*7) ) { return getEnum_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"getClass",sizeof(wchar_t)*8) ) { return getClass_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"enumIndex",sizeof(wchar_t)*9) ) { return enumIndex_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"createEnum",sizeof(wchar_t)*10) ) { return createEnum_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"getEnumName",sizeof(wchar_t)*11) ) { return getEnumName_dyn(); }
		if (!memcmp(inName.__s,L"resolveEnum",sizeof(wchar_t)*11) ) { return resolveEnum_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"getClassName",sizeof(wchar_t)*12) ) { return getClassName_dyn(); }
		if (!memcmp(inName.__s,L"resolveClass",sizeof(wchar_t)*12) ) { return resolveClass_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"getSuperClass",sizeof(wchar_t)*13) ) { return getSuperClass_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"createInstance",sizeof(wchar_t)*14) ) { return createInstance_dyn(); }
		if (!memcmp(inName.__s,L"getClassFields",sizeof(wchar_t)*14) ) { return getClassFields_dyn(); }
		if (!memcmp(inName.__s,L"enumParameters",sizeof(wchar_t)*14) ) { return enumParameters_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"createEnumIndex",sizeof(wchar_t)*15) ) { return createEnumIndex_dyn(); }
		if (!memcmp(inName.__s,L"enumConstructor",sizeof(wchar_t)*15) ) { return enumConstructor_dyn(); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"getInstanceFields",sizeof(wchar_t)*17) ) { return getInstanceFields_dyn(); }
		if (!memcmp(inName.__s,L"getEnumConstructs",sizeof(wchar_t)*17) ) { return getEnumConstructs_dyn(); }
		break;
	case 19:
		if (!memcmp(inName.__s,L"createEmptyInstance",sizeof(wchar_t)*19) ) { return createEmptyInstance_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Type_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Type_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"getClass",8),
	HX_STRING(L"getEnum",7),
	HX_STRING(L"getSuperClass",13),
	HX_STRING(L"getClassName",12),
	HX_STRING(L"getEnumName",11),
	HX_STRING(L"resolveClass",12),
	HX_STRING(L"resolveEnum",11),
	HX_STRING(L"createInstance",14),
	HX_STRING(L"createEmptyInstance",19),
	HX_STRING(L"createEnum",10),
	HX_STRING(L"createEnumIndex",15),
	HX_STRING(L"getInstanceFields",17),
	HX_STRING(L"getClassFields",14),
	HX_STRING(L"getEnumConstructs",17),
	HX_STRING(L"typeof",6),
	HX_STRING(L"enumEq",6),
	HX_STRING(L"enumConstructor",15),
	HX_STRING(L"enumParameters",14),
	HX_STRING(L"enumIndex",9),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
};

Class Type_obj::__mClass;

void Type_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"Type",4), hx::TCanCast< Type_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Type_obj::__boot()
{
}

