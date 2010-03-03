#ifndef INCLUDED_Std
#define INCLUDED_Std

#include <hxcpp.h>

HX_DECLARE_CLASS0(Std)


class Std_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Std_obj OBJ_;
		Std_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Std_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Std_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		static void __init__();

		::String __ToString() const { return HX_STRING(L"Std",3); }

		static bool is( Dynamic v,Dynamic t);
		static Dynamic is_dyn();

		static ::String string( Dynamic s);
		static Dynamic string_dyn();

		static int toInt( double x);
		static Dynamic toInt_dyn();

		static Dynamic parseInt( ::String x);
		static Dynamic parseInt_dyn();

		static double parseFloat( ::String x);
		static Dynamic parseFloat_dyn();

		static int random( int x);
		static Dynamic random_dyn();

};


#endif /* INCLUDED_Std */ 
