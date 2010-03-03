#include <hxcpp.h>

#ifndef INCLUDED_ValueType
#include <ValueType.h>
#endif

ValueType ValueType_obj::TBool;

ValueType  ValueType_obj::TClass(::Class c)
	{ return hx::CreateEnum< ValueType_obj >(HX_STRING(L"TClass",6),6,hx::DynamicArray(0,1).Add(c)); }

ValueType  ValueType_obj::TEnum(::Enum e)
	{ return hx::CreateEnum< ValueType_obj >(HX_STRING(L"TEnum",5),7,hx::DynamicArray(0,1).Add(e)); }

ValueType ValueType_obj::TFloat;

ValueType ValueType_obj::TFunction;

ValueType ValueType_obj::TInt;

ValueType ValueType_obj::TNull;

ValueType ValueType_obj::TObject;

ValueType ValueType_obj::TUnknown;

HX_DEFINE_CREATE_ENUM(ValueType_obj)

int ValueType_obj::__FindIndex(::String inName)
{
	if (inName==HX_STRING(L"TBool",5)) return 3;
	if (inName==HX_STRING(L"TClass",6)) return 6;
	if (inName==HX_STRING(L"TEnum",5)) return 7;
	if (inName==HX_STRING(L"TFloat",6)) return 2;
	if (inName==HX_STRING(L"TFunction",9)) return 5;
	if (inName==HX_STRING(L"TInt",4)) return 1;
	if (inName==HX_STRING(L"TNull",5)) return 0;
	if (inName==HX_STRING(L"TObject",7)) return 4;
	if (inName==HX_STRING(L"TUnknown",8)) return 8;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(ValueType_obj,TClass,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(ValueType_obj,TEnum,return)

int ValueType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_STRING(L"TBool",5)) return 0;
	if (inName==HX_STRING(L"TClass",6)) return 1;
	if (inName==HX_STRING(L"TEnum",5)) return 1;
	if (inName==HX_STRING(L"TFloat",6)) return 0;
	if (inName==HX_STRING(L"TFunction",9)) return 0;
	if (inName==HX_STRING(L"TInt",4)) return 0;
	if (inName==HX_STRING(L"TNull",5)) return 0;
	if (inName==HX_STRING(L"TObject",7)) return 0;
	if (inName==HX_STRING(L"TUnknown",8)) return 0;
	return super::__FindArgCount(inName);
}

Dynamic ValueType_obj::__Field(const ::String &inName)
{
	if (inName==HX_STRING(L"TBool",5)) return TBool;
	if (inName==HX_STRING(L"TClass",6)) return TClass_dyn();
	if (inName==HX_STRING(L"TEnum",5)) return TEnum_dyn();
	if (inName==HX_STRING(L"TFloat",6)) return TFloat;
	if (inName==HX_STRING(L"TFunction",9)) return TFunction;
	if (inName==HX_STRING(L"TInt",4)) return TInt;
	if (inName==HX_STRING(L"TNull",5)) return TNull;
	if (inName==HX_STRING(L"TObject",7)) return TObject;
	if (inName==HX_STRING(L"TUnknown",8)) return TUnknown;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_STRING(L"TBool",5),
	HX_STRING(L"TClass",6),
	HX_STRING(L"TEnum",5),
	HX_STRING(L"TFloat",6),
	HX_STRING(L"TFunction",9),
	HX_STRING(L"TInt",4),
	HX_STRING(L"TNull",5),
	HX_STRING(L"TObject",7),
	HX_STRING(L"TUnknown",8),
	::String(null()) };

static void sMarkStatics() {
	hx::MarkMember(ValueType_obj::TBool);
	hx::MarkMember(ValueType_obj::TFloat);
	hx::MarkMember(ValueType_obj::TFunction);
	hx::MarkMember(ValueType_obj::TInt);
	hx::MarkMember(ValueType_obj::TNull);
	hx::MarkMember(ValueType_obj::TObject);
	hx::MarkMember(ValueType_obj::TUnknown);
};

static ::String sMemberFields[] = { ::String(null()) };
Class ValueType_obj::__mClass;

Dynamic __Create_ValueType_obj() { return new ValueType_obj; }

void ValueType_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_STRING(L"ValueType",9), hx::TCanCast< ValueType_obj >,sStaticFields,sMemberFields,
	&__Create_ValueType_obj, &__Create,
	&super::__SGetClass(), &CreateValueType_obj, sMarkStatics);
}

void ValueType_obj::__boot()
{
Static(TBool) = hx::CreateEnum< ValueType_obj >(HX_STRING(L"TBool",5),3);
Static(TFloat) = hx::CreateEnum< ValueType_obj >(HX_STRING(L"TFloat",6),2);
Static(TFunction) = hx::CreateEnum< ValueType_obj >(HX_STRING(L"TFunction",9),5);
Static(TInt) = hx::CreateEnum< ValueType_obj >(HX_STRING(L"TInt",4),1);
Static(TNull) = hx::CreateEnum< ValueType_obj >(HX_STRING(L"TNull",5),0);
Static(TObject) = hx::CreateEnum< ValueType_obj >(HX_STRING(L"TObject",7),4);
Static(TUnknown) = hx::CreateEnum< ValueType_obj >(HX_STRING(L"TUnknown",8),8);
}


