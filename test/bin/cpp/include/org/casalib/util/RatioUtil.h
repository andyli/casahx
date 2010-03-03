#ifndef INCLUDED_org_casalib_util_RatioUtil
#define INCLUDED_org_casalib_util_RatioUtil

#include <hxcpp.h>

HX_DECLARE_CLASS2(nme,geom,Rectangle)
HX_DECLARE_CLASS3(org,casalib,math,Percent)
HX_DECLARE_CLASS3(org,casalib,util,RatioUtil)
namespace org{
namespace casalib{
namespace util{


class RatioUtil_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef RatioUtil_obj OBJ_;
		RatioUtil_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< RatioUtil_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~RatioUtil_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"RatioUtil",9); }

		static double widthToHeight( ::nme::geom::Rectangle size);
		static Dynamic widthToHeight_dyn();

		static double heightToWidth( ::nme::geom::Rectangle size);
		static Dynamic heightToWidth_dyn();

		static ::nme::geom::Rectangle scale( ::nme::geom::Rectangle size,::org::casalib::math::Percent amount,Dynamic snapToPixel);
		static Dynamic scale_dyn();

		static ::nme::geom::Rectangle scaleWidth( ::nme::geom::Rectangle size,double height,Dynamic snapToPixel);
		static Dynamic scaleWidth_dyn();

		static ::nme::geom::Rectangle scaleHeight( ::nme::geom::Rectangle size,double width,Dynamic snapToPixel);
		static Dynamic scaleHeight_dyn();

		static ::nme::geom::Rectangle scaleToFill( ::nme::geom::Rectangle size,::nme::geom::Rectangle bounds,Dynamic snapToPixel);
		static Dynamic scaleToFill_dyn();

		static ::nme::geom::Rectangle scaleToFit( ::nme::geom::Rectangle size,::nme::geom::Rectangle bounds,Dynamic snapToPixel);
		static Dynamic scaleToFit_dyn();

		static ::nme::geom::Rectangle _defineRect( ::nme::geom::Rectangle size,double width,double height,bool snapToPixel);
		static Dynamic _defineRect_dyn();

};

} // end namespace org
} // end namespace casalib
} // end namespace util

#endif /* INCLUDED_org_casalib_util_RatioUtil */ 
