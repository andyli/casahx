#ifndef INCLUDED_test_Test
#define INCLUDED_test_Test

#include <hxcpp.h>

#include <haxe/unit/TestRunner.h>
HX_DECLARE_CLASS2(haxe,unit,TestRunner)
HX_DECLARE_CLASS1(test,Test)
namespace test{


class Test_obj : public ::haxe::unit::TestRunner_obj{
	public:
		typedef ::haxe::unit::TestRunner_obj super;
		typedef Test_obj OBJ_;
		Test_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Test_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Test_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Test",4); }

		static Void main( );
		static Dynamic main_dyn();

};

} // end namespace test

#endif /* INCLUDED_test_Test */ 
