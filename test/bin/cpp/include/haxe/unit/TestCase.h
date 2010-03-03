#ifndef INCLUDED_haxe_unit_TestCase
#define INCLUDED_haxe_unit_TestCase

#include <hxcpp.h>

#include <haxe/Public.h>
HX_DECLARE_CLASS1(haxe,Public)
HX_DECLARE_CLASS2(haxe,unit,TestCase)
HX_DECLARE_CLASS2(haxe,unit,TestStatus)
namespace haxe{
namespace unit{


class TestCase_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TestCase_obj OBJ_;
		TestCase_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TestCase_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TestCase_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		inline operator ::haxe::Public_obj *()
			{ return new ::haxe::Public_delegate_< TestCase_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_STRING(L"TestCase",8); }

		::haxe::unit::TestStatus currentTest; /* REM */ 
		virtual Void setup( );
		Dynamic setup_dyn();

		virtual Void tearDown( );
		Dynamic tearDown_dyn();

		virtual Void print( Dynamic v);
		Dynamic print_dyn();

		virtual Void assertTrue( bool b,Dynamic c);
		Dynamic assertTrue_dyn();

		virtual Void assertFalse( bool b,Dynamic c);
		Dynamic assertFalse_dyn();

		virtual Void assertEquals( Dynamic expected,Dynamic actual,Dynamic c);
		Dynamic assertEquals_dyn();

};

} // end namespace haxe
} // end namespace unit

#endif /* INCLUDED_haxe_unit_TestCase */ 
