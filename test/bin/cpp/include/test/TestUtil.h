#ifndef INCLUDED_test_TestUtil
#define INCLUDED_test_TestUtil

#include <hxcpp.h>

#include <haxe/unit/TestCase.h>
HX_DECLARE_CLASS1(haxe,Public)
HX_DECLARE_CLASS2(haxe,unit,TestCase)
HX_DECLARE_CLASS1(test,TestUtil)
namespace test{


class TestUtil_obj : public ::haxe::unit::TestCase_obj{
	public:
		typedef ::haxe::unit::TestCase_obj super;
		typedef TestUtil_obj OBJ_;
		TestUtil_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TestUtil_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TestUtil_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"TestUtil",8); }

		virtual Void testArrayUtil( );
		Dynamic testArrayUtil_dyn();

		virtual Void testNumberUtil( );
		Dynamic testNumberUtil_dyn();

		virtual Void testRatioUtil( );
		Dynamic testRatioUtil_dyn();

		virtual Void testValidationUtil( );
		Dynamic testValidationUtil_dyn();

};

} // end namespace test

#endif /* INCLUDED_test_TestUtil */ 
