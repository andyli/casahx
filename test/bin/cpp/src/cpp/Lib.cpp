#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
namespace cpp{

Void Lib_obj::__construct()
{
	return null();
}

Lib_obj::~Lib_obj() { }

Dynamic Lib_obj::__CreateEmpty() { return  new Lib_obj; }
hx::ObjectPtr< Lib_obj > Lib_obj::__new()
{  hx::ObjectPtr< Lib_obj > result = new Lib_obj();
	result->__construct();
	return result;}

Dynamic Lib_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Lib_obj > result = new Lib_obj();
	result->__construct();
	return result;}

Dynamic Lib_obj::load( ::String lib,::String prim,int nargs){
	__SAFE_POINT
	return ::__loadprim(lib,prim,nargs);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Lib_obj,load,return )

Dynamic Lib_obj::loadLazy( Dynamic lib,Dynamic prim,int nargs){
	__SAFE_POINT
	try{
		return ::__loadprim(lib,prim,nargs);
	}
	catch(Dynamic __e){
		{
			Dynamic $t1 = __e;{
				Array< Dynamic > e = Array_obj< Dynamic >::__new().Add($t1);
				switch( (int)(nargs)){
					case 0: {

						HX_BEGIN_LOCAL_FUNC1(_Function_3_1,Array< Dynamic >,e)
						Void run(){
{
								hx::Throw (e->__get(0));
							}
							return null();
						}
						HX_END_LOCAL_FUNC0((void))

						return  Dynamic(new _Function_3_1(e));
					}
					;break;
					case 2: {

						HX_BEGIN_LOCAL_FUNC1(_Function_3_1,Array< Dynamic >,e)
						Void run(Dynamic _1,Dynamic _2){
{
								hx::Throw (e->__get(0));
							}
							return null();
						}
						HX_END_LOCAL_FUNC2((void))

						return  Dynamic(new _Function_3_1(e));
					}
					;break;
					case 3: {

						HX_BEGIN_LOCAL_FUNC1(_Function_3_1,Array< Dynamic >,e)
						Void run(Dynamic _1,Dynamic _2,Dynamic _3){
{
								hx::Throw (e->__get(0));
							}
							return null();
						}
						HX_END_LOCAL_FUNC3((void))

						return  Dynamic(new _Function_3_1(e));
					}
					;break;
					case 4: {

						HX_BEGIN_LOCAL_FUNC1(_Function_3_1,Array< Dynamic >,e)
						Void run(Dynamic _1,Dynamic _2,Dynamic _3,Dynamic _4){
{
								hx::Throw (e->__get(0));
							}
							return null();
						}
						HX_END_LOCAL_FUNC4((void))

						return  Dynamic(new _Function_3_1(e));
					}
					;break;
					case 5: {

						HX_BEGIN_LOCAL_FUNC1(_Function_3_1,Array< Dynamic >,e)
						Void run(Dynamic _1,Dynamic _2,Dynamic _3,Dynamic _4,Dynamic _5){
{
								hx::Throw (e->__get(0));
							}
							return null();
						}
						HX_END_LOCAL_FUNC5((void))

						return  Dynamic(new _Function_3_1(e));
					}
					;break;
					default: {

						HX_BEGIN_LOCAL_FUNC1(_Function_3_1,Array< Dynamic >,e)
						Void run(Dynamic _1){
{
								hx::Throw (e->__get(0));
							}
							return null();
						}
						HX_END_LOCAL_FUNC1((void))

						return  Dynamic(new _Function_3_1(e));
					}
				}
			}
		}
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Lib_obj,loadLazy,return )

Void Lib_obj::rethrow( Dynamic inExp){
{
		hx::Throw (inExp);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,rethrow,(void))

Void Lib_obj::stringReference( Dynamic inExp){
{
		hx::Throw (inExp);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,stringReference,(void))

Void Lib_obj::print( Dynamic v){
{
		__SAFE_POINT
		::__hxcpp_print(v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,print,(void))

Dynamic Lib_obj::haxeToNeko( Dynamic v){
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,haxeToNeko,return )

Dynamic Lib_obj::nekoToHaxe( Dynamic v){
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,nekoToHaxe,return )

Void Lib_obj::println( Dynamic v){
{
		__SAFE_POINT
		::__hxcpp_println(v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,println,(void))


Lib_obj::Lib_obj()
{
}

void Lib_obj::__Mark()
{
}

Dynamic Lib_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"load",sizeof(wchar_t)*4) ) { return load_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"print",sizeof(wchar_t)*5) ) { return print_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"rethrow",sizeof(wchar_t)*7) ) { return rethrow_dyn(); }
		if (!memcmp(inName.__s,L"println",sizeof(wchar_t)*7) ) { return println_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"loadLazy",sizeof(wchar_t)*8) ) { return loadLazy_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"haxeToNeko",sizeof(wchar_t)*10) ) { return haxeToNeko_dyn(); }
		if (!memcmp(inName.__s,L"nekoToHaxe",sizeof(wchar_t)*10) ) { return nekoToHaxe_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"stringReference",sizeof(wchar_t)*15) ) { return stringReference_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Lib_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Lib_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"load",4),
	HX_STRING(L"loadLazy",8),
	HX_STRING(L"rethrow",7),
	HX_STRING(L"stringReference",15),
	HX_STRING(L"print",5),
	HX_STRING(L"haxeToNeko",10),
	HX_STRING(L"nekoToHaxe",10),
	HX_STRING(L"println",7),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
};

Class Lib_obj::__mClass;

void Lib_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"cpp.Lib",7), hx::TCanCast< Lib_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Lib_obj::__boot()
{
}

} // end namespace cpp
