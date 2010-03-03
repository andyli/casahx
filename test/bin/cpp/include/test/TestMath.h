#ifndef INCLUDED_test_TestMath
#define INCLUDED_test_TestMath

#include <hxcpp.h>

#include <haxe/unit/TestCase.h>
HX_DECLARE_CLASS1(haxe,Public)
HX_DECLARE_CLASS2(haxe,unit,TestCase)
HX_DECLARE_CLASS1(test,TestMath)
namespace test{


class TestMath_obj : public ::haxe::unit::TestCase_obj{
	public:
		typedef ::haxe::unit::TestCase_obj super;
		typedef TestMath_obj OBJ_;
		TestMath_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TestMath_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TestMath_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"TestMath",8); }

		virtual Void testPercent( );
		Dynamic testPercent_dyn();

		virtual Void testRange( );
		Dynamic testRange_dyn();

		virtual Void testEllipse( );
		Dynamic testEllipse_dyn();

		virtual Void testPoint3d( );
		Dynamic testPoint3d_dyn();

};

} // end namespace test

#endif /* INCLUDED_test_TestMath */ 
