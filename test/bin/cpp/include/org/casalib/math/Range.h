#ifndef INCLUDED_org_casalib_math_Range
#define INCLUDED_org_casalib_math_Range

#include <hxcpp.h>

HX_DECLARE_CLASS3(org,casalib,math,Percent)
HX_DECLARE_CLASS3(org,casalib,math,Range)
namespace org{
namespace casalib{
namespace math{


class Range_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Range_obj OBJ_;
		Range_obj();
		Void __construct(double start,double end);

	public:
		static hx::ObjectPtr< Range_obj > __new(double start,double end);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Range_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Range",5); }

		double end; /* REM */ 
		double max; /* REM */ 
		double min; /* REM */ 
		double start; /* REM */ 
		double _end; /* REM */ 
		double _start; /* REM */ 
		virtual Void setRange( double start,double end);
		Dynamic setRange_dyn();

		virtual double getStart( );
		Dynamic getStart_dyn();

		virtual double setStart( double value);
		Dynamic setStart_dyn();

		virtual double getEnd( );
		Dynamic getEnd_dyn();

		virtual double setEnd( double value);
		Dynamic setEnd_dyn();

		virtual double getMin( );
		Dynamic getMin_dyn();

		virtual double getMax( );
		Dynamic getMax_dyn();

		virtual bool isWithinRange( double value);
		Dynamic isWithinRange_dyn();

		virtual double getValueOfPercent( ::org::casalib::math::Percent percent);
		Dynamic getValueOfPercent_dyn();

		virtual ::org::casalib::math::Percent getPercentOfValue( double value);
		Dynamic getPercentOfValue_dyn();

		virtual bool equals( ::org::casalib::math::Range range);
		Dynamic equals_dyn();

		virtual bool overlaps( ::org::casalib::math::Range range);
		Dynamic overlaps_dyn();

		virtual bool contains( ::org::casalib::math::Range range);
		Dynamic contains_dyn();

		virtual ::org::casalib::math::Range clone( );
		Dynamic clone_dyn();

};

} // end namespace org
} // end namespace casalib
} // end namespace math

#endif /* INCLUDED_org_casalib_math_Range */ 
