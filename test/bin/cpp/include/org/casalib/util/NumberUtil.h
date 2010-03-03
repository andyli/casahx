#ifndef INCLUDED_org_casalib_util_NumberUtil
#define INCLUDED_org_casalib_util_NumberUtil

#include <hxcpp.h>

HX_DECLARE_CLASS3(org,casalib,math,Percent)
HX_DECLARE_CLASS3(org,casalib,util,NumberUtil)
namespace org{
namespace casalib{
namespace util{


class NumberUtil_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef NumberUtil_obj OBJ_;
		NumberUtil_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< NumberUtil_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NumberUtil_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"NumberUtil",10); }

		static bool isEqual( double val1,double val2,Dynamic precision);
		static Dynamic isEqual_dyn();

		static double min( Dynamic val1,Dynamic val2);
		static Dynamic min_dyn();

		static double max( Dynamic val1,Dynamic val2);
		static Dynamic max_dyn();

		static double randomWithinRange( double min,double max);
		static Dynamic randomWithinRange_dyn();

		static int randomIntegerWithinRange( int min,int max);
		static Dynamic randomIntegerWithinRange_dyn();

		static bool isEven( int value);
		static Dynamic isEven_dyn();

		static bool isOdd( int value);
		static Dynamic isOdd_dyn();

		static bool isInteger( double value);
		static Dynamic isInteger_dyn();

		static bool isPrime( int value);
		static Dynamic isPrime_dyn();

		static double roundDecimalToPlace( double value,double place);
		static Dynamic roundDecimalToPlace_dyn();

		static int loopIndex( int index,int length);
		static Dynamic loopIndex_dyn();

		static bool isBetween( double value,double firstValue,double secondValue);
		static Dynamic isBetween_dyn();

		static double constrain( double value,double firstValue,double secondValue);
		static Dynamic constrain_dyn();

		static Array< Dynamic > createStepsBetween( double begin,double end,double steps);
		static Dynamic createStepsBetween_dyn();

		static double interpolate( ::org::casalib::math::Percent amount,double minimum,double maximum);
		static Dynamic interpolate_dyn();

		static ::org::casalib::math::Percent normalize( double value,double minimum,double maximum);
		static Dynamic normalize_dyn();

		static double map( double value,double min1,double max1,double min2,double max2);
		static Dynamic map_dyn();

		static double getWeightedAverage( double value,double dest,double n);
		static Dynamic getWeightedAverage_dyn();

		static ::String format( double value,int minLength,::String thouDelim,::String fillChar);
		static Dynamic format_dyn();

		static ::String getOrdinalSuffix( int value);
		static Dynamic getOrdinalSuffix_dyn();

		static ::String addLeadingZero( double value);
		static Dynamic addLeadingZero_dyn();

};

} // end namespace org
} // end namespace casalib
} // end namespace util

#endif /* INCLUDED_org_casalib_util_NumberUtil */ 
