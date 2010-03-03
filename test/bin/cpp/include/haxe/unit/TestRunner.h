#ifndef INCLUDED_haxe_unit_TestRunner
#define INCLUDED_haxe_unit_TestRunner

#include <hxcpp.h>

HX_DECLARE_CLASS0(List)
HX_DECLARE_CLASS1(haxe,Public)
HX_DECLARE_CLASS2(haxe,unit,TestCase)
HX_DECLARE_CLASS2(haxe,unit,TestResult)
HX_DECLARE_CLASS2(haxe,unit,TestRunner)
namespace haxe{
namespace unit{


class TestRunner_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TestRunner_obj OBJ_;
		TestRunner_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TestRunner_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TestRunner_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"TestRunner",10); }

		::haxe::unit::TestResult result; /* REM */ 
		::List cases; /* REM */ 
		virtual Void add( ::haxe::unit::TestCase c);
		Dynamic add_dyn();

		virtual bool run( );
		Dynamic run_dyn();

		virtual Void runCase( ::haxe::unit::TestCase t);
		Dynamic runCase_dyn();

		static Dynamic print;
		static inline Dynamic &print_dyn() {return print; }

		static Void customTrace( Dynamic v,Dynamic p);
		static Dynamic customTrace_dyn();

};

} // end namespace haxe
} // end namespace unit

#endif /* INCLUDED_haxe_unit_TestRunner */ 
