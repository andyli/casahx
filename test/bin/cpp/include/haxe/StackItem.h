#ifndef INCLUDED_haxe_StackItem
#define INCLUDED_haxe_StackItem

#include <hxcpp.h>

HX_DECLARE_CLASS1(haxe,StackItem)
namespace haxe{


class StackItem_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef StackItem_obj OBJ_;

	public:
		StackItem_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_STRING(L"haxe.StackItem",14); }
		::String __ToString() const { return HX_STRING(L"StackItem.",10) + tag; }

		static StackItem CFunction;
		static StackItem FilePos(::haxe::StackItem s,::String file,int line);
		static Dynamic FilePos_dyn();
		static StackItem Lambda(int v);
		static Dynamic Lambda_dyn();
		static StackItem Method(::String classname,::String method);
		static Dynamic Method_dyn();
		static StackItem Module(::String m);
		static Dynamic Module_dyn();
};

} // end namespace haxe

#endif /* INCLUDED_haxe_StackItem */ 
