#ifndef INCLUDED_haxe_unit_TestResult
#define INCLUDED_haxe_unit_TestResult

#include <hxcpp.h>

HX_DECLARE_CLASS0(List)
HX_DECLARE_CLASS2(haxe,unit,TestResult)
HX_DECLARE_CLASS2(haxe,unit,TestStatus)
namespace haxe{
namespace unit{


class TestResult_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TestResult_obj OBJ_;
		TestResult_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TestResult_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TestResult_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"TestResult",10); }

		::List m_tests; /* REM */ 
		bool success; /* REM */ 
		virtual Void add( ::haxe::unit::TestStatus t);
		Dynamic add_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace haxe
} // end namespace unit

#endif /* INCLUDED_haxe_unit_TestResult */ 
