#include <hxcpp.h>

#ifndef INCLUDED_haxe_StackItem
#include <haxe/StackItem.h>
#endif
namespace haxe{

StackItem StackItem_obj::CFunction;

StackItem  StackItem_obj::FilePos(::haxe::StackItem s,::String file,int line)
	{ return hx::CreateEnum< StackItem_obj >(HX_STRING(L"FilePos",7),2,hx::DynamicArray(0,3).Add(s).Add(file).Add(line)); }

StackItem  StackItem_obj::Lambda(int v)
	{ return hx::CreateEnum< StackItem_obj >(HX_STRING(L"Lambda",6),4,hx::DynamicArray(0,1).Add(v)); }

StackItem  StackItem_obj::Method(::String classname,::String method)
	{ return hx::CreateEnum< StackItem_obj >(HX_STRING(L"Method",6),3,hx::DynamicArray(0,2).Add(classname).Add(method)); }

StackItem  StackItem_obj::Module(::String m)
	{ return hx::CreateEnum< StackItem_obj >(HX_STRING(L"Module",6),1,hx::DynamicArray(0,1).Add(m)); }

HX_DEFINE_CREATE_ENUM(StackItem_obj)

int StackItem_obj::__FindIndex(::String inName)
{
	if (inName==HX_STRING(L"CFunction",9)) return 0;
	if (inName==HX_STRING(L"FilePos",7)) return 2;
	if (inName==HX_STRING(L"Lambda",6)) return 4;
	if (inName==HX_STRING(L"Method",6)) return 3;
	if (inName==HX_STRING(L"Module",6)) return 1;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC3(StackItem_obj,FilePos,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(StackItem_obj,Lambda,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(StackItem_obj,Method,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(StackItem_obj,Module,return)

int StackItem_obj::__FindArgCount(::String inName)
{
	if (inName==HX_STRING(L"CFunction",9)) return 0;
	if (inName==HX_STRING(L"FilePos",7)) return 3;
	if (inName==HX_STRING(L"Lambda",6)) return 1;
	if (inName==HX_STRING(L"Method",6)) return 2;
	if (inName==HX_STRING(L"Module",6)) return 1;
	return super::__FindArgCount(inName);
}

Dynamic StackItem_obj::__Field(const ::String &inName)
{
	if (inName==HX_STRING(L"CFunction",9)) return CFunction;
	if (inName==HX_STRING(L"FilePos",7)) return FilePos_dyn();
	if (inName==HX_STRING(L"Lambda",6)) return Lambda_dyn();
	if (inName==HX_STRING(L"Method",6)) return Method_dyn();
	if (inName==HX_STRING(L"Module",6)) return Module_dyn();
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_STRING(L"CFunction",9),
	HX_STRING(L"FilePos",7),
	HX_STRING(L"Lambda",6),
	HX_STRING(L"Method",6),
	HX_STRING(L"Module",6),
	::String(null()) };

static void sMarkStatics() {
	hx::MarkMember(StackItem_obj::CFunction);
};

static ::String sMemberFields[] = { ::String(null()) };
Class StackItem_obj::__mClass;

Dynamic __Create_StackItem_obj() { return new StackItem_obj; }

void StackItem_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_STRING(L"haxe.StackItem",14), hx::TCanCast< StackItem_obj >,sStaticFields,sMemberFields,
	&__Create_StackItem_obj, &__Create,
	&super::__SGetClass(), &CreateStackItem_obj, sMarkStatics);
}

void StackItem_obj::__boot()
{
Static(CFunction) = hx::CreateEnum< StackItem_obj >(HX_STRING(L"CFunction",9),0);
}


} // end namespace haxe
