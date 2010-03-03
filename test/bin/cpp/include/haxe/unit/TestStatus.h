#ifndef INCLUDED_haxe_unit_TestStatus
#define INCLUDED_haxe_unit_TestStatus

#include <hxcpp.h>

HX_DECLARE_CLASS2(haxe,unit,TestStatus)
namespace haxe{
namespace unit{


class TestStatus_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TestStatus_obj OBJ_;
		TestStatus_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TestStatus_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TestStatus_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"TestStatus",10); }

		bool done; /* REM */ 
		bool success; /* REM */ 
		::String error; /* REM */ 
		::String method; /* REM */ 
		::String classname; /* REM */ 
		Dynamic posInfos; /* REM */ 
		::String backtrace; /* REM */ 
};

} // end namespace haxe
} // end namespace unit

#endif /* INCLUDED_haxe_unit_TestStatus */ 
