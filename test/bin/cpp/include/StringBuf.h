#ifndef INCLUDED_StringBuf
#define INCLUDED_StringBuf

#include <hxcpp.h>

HX_DECLARE_CLASS0(StringBuf)


class StringBuf_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef StringBuf_obj OBJ_;
		StringBuf_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< StringBuf_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~StringBuf_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"StringBuf",9); }

		virtual Void add( Dynamic x);
		Dynamic add_dyn();

		virtual Void addSub( ::String s,int pos,Dynamic len);
		Dynamic addSub_dyn();

		virtual Void addChar( int c);
		Dynamic addChar_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		Array< Dynamic > b; /* REM */ 
};


#endif /* INCLUDED_StringBuf */ 
