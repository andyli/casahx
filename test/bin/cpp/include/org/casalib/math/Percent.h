#ifndef INCLUDED_org_casalib_math_Percent
#define INCLUDED_org_casalib_math_Percent

#include <hxcpp.h>

HX_DECLARE_CLASS3(org,casalib,math,Percent)
namespace org{
namespace casalib{
namespace math{


class Percent_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Percent_obj OBJ_;
		Percent_obj();
		Void __construct(Dynamic __o_percentage,Dynamic __o_isDecimalPercentage);

	public:
		static hx::ObjectPtr< Percent_obj > __new(Dynamic __o_percentage,Dynamic __o_isDecimalPercentage);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Percent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Percent",7); }

		double decimalPercentage; /* REM */ 
		double percentage; /* REM */ 
		double _percent; /* REM */ 
		virtual double getPercentage( );
		Dynamic getPercentage_dyn();

		virtual double setPercentage( double percent);
		Dynamic setPercentage_dyn();

		virtual double getDecimalPercentage( );
		Dynamic getDecimalPercentage_dyn();

		virtual double setDecimalPercentage( double percent);
		Dynamic setDecimalPercentage_dyn();

		virtual bool equals( ::org::casalib::math::Percent percent);
		Dynamic equals_dyn();

		virtual ::org::casalib::math::Percent clone( );
		Dynamic clone_dyn();

		virtual double valueOf( );
		Dynamic valueOf_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace org
} // end namespace casalib
} // end namespace math

#endif /* INCLUDED_org_casalib_math_Percent */ 
