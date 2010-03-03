#ifndef INCLUDED_haxe_Log
#define INCLUDED_haxe_Log

#include <hxcpp.h>

HX_DECLARE_CLASS1(haxe,Log)
namespace haxe{


class Log_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Log_obj OBJ_;
		Log_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Log_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Log_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Log",3); }

		static Dynamic trace;
		static inline Dynamic &trace_dyn() {return trace; }

		static Dynamic clear;
		static inline Dynamic &clear_dyn() {return clear; }

};

} // end namespace haxe

#endif /* INCLUDED_haxe_Log */ 
