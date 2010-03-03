#ifndef INCLUDED_org_casalib_util_ValidationUtil
#define INCLUDED_org_casalib_util_ValidationUtil

#include <hxcpp.h>

HX_DECLARE_CLASS3(org,casalib,util,ValidationUtil)
namespace org{
namespace casalib{
namespace util{


class ValidationUtil_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ValidationUtil_obj OBJ_;
		ValidationUtil_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ValidationUtil_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ValidationUtil_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"ValidationUtil",14); }

		static bool isEmail( ::String email);
		static Dynamic isEmail_dyn();

		static bool isUsaStateAbbreviation( ::String state);
		static Dynamic isUsaStateAbbreviation_dyn();

		static bool isCreditCard( ::String cardNumber);
		static Dynamic isCreditCard_dyn();

		static ::String getCreditCardProvider( ::String cardNumber);
		static Dynamic getCreditCardProvider_dyn();

};

} // end namespace org
} // end namespace casalib
} // end namespace util

#endif /* INCLUDED_org_casalib_util_ValidationUtil */ 
