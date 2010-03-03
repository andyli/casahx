#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
#ifndef INCLUDED_org_casalib_math_Percent
#include <org/casalib/math/Percent.h>
#endif
#ifndef INCLUDED_org_casalib_util_RatioUtil
#include <org/casalib/util/RatioUtil.h>
#endif
namespace org{
namespace casalib{
namespace util{

Void RatioUtil_obj::__construct()
{
	return null();
}

RatioUtil_obj::~RatioUtil_obj() { }

Dynamic RatioUtil_obj::__CreateEmpty() { return  new RatioUtil_obj; }
hx::ObjectPtr< RatioUtil_obj > RatioUtil_obj::__new()
{  hx::ObjectPtr< RatioUtil_obj > result = new RatioUtil_obj();
	result->__construct();
	return result;}

Dynamic RatioUtil_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< RatioUtil_obj > result = new RatioUtil_obj();
	result->__construct();
	return result;}

double RatioUtil_obj::widthToHeight( ::nme::geom::Rectangle size){
	return (double(size->width) / double(size->height));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(RatioUtil_obj,widthToHeight,return )

double RatioUtil_obj::heightToWidth( ::nme::geom::Rectangle size){
	return (double(size->height) / double(size->width));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(RatioUtil_obj,heightToWidth,return )

::nme::geom::Rectangle RatioUtil_obj::scale( ::nme::geom::Rectangle size,::org::casalib::math::Percent amount,Dynamic __o_snapToPixel){
bool snapToPixel = __o_snapToPixel.Default(true);
{
		__SAFE_POINT
		return ::org::casalib::util::RatioUtil_obj::_defineRect(size,(size->width * amount->getDecimalPercentage()),(size->height * amount->getDecimalPercentage()),snapToPixel);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(RatioUtil_obj,scale,return )

::nme::geom::Rectangle RatioUtil_obj::scaleWidth( ::nme::geom::Rectangle size,double height,Dynamic __o_snapToPixel){
bool snapToPixel = __o_snapToPixel.Default(true);
{
		__SAFE_POINT
		return ::org::casalib::util::RatioUtil_obj::_defineRect(size,(height * ::org::casalib::util::RatioUtil_obj::widthToHeight(size)),height,snapToPixel);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(RatioUtil_obj,scaleWidth,return )

::nme::geom::Rectangle RatioUtil_obj::scaleHeight( ::nme::geom::Rectangle size,double width,Dynamic __o_snapToPixel){
bool snapToPixel = __o_snapToPixel.Default(true);
{
		__SAFE_POINT
		return ::org::casalib::util::RatioUtil_obj::_defineRect(size,width,(width * ::org::casalib::util::RatioUtil_obj::heightToWidth(size)),snapToPixel);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(RatioUtil_obj,scaleHeight,return )

::nme::geom::Rectangle RatioUtil_obj::scaleToFill( ::nme::geom::Rectangle size,::nme::geom::Rectangle bounds,Dynamic __o_snapToPixel){
bool snapToPixel = __o_snapToPixel.Default(true);
{
		__SAFE_POINT
		::nme::geom::Rectangle scaled = ::org::casalib::util::RatioUtil_obj::scaleHeight(size,bounds->width,snapToPixel);
		if ((scaled->height < bounds->height))
			scaled = ::org::casalib::util::RatioUtil_obj::scaleWidth(size,bounds->height,snapToPixel);
		return scaled;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(RatioUtil_obj,scaleToFill,return )

::nme::geom::Rectangle RatioUtil_obj::scaleToFit( ::nme::geom::Rectangle size,::nme::geom::Rectangle bounds,Dynamic __o_snapToPixel){
bool snapToPixel = __o_snapToPixel.Default(true);
{
		__SAFE_POINT
		::nme::geom::Rectangle scaled = ::org::casalib::util::RatioUtil_obj::scaleHeight(size,bounds->width,snapToPixel);
		if ((scaled->height > bounds->height))
			scaled = ::org::casalib::util::RatioUtil_obj::scaleWidth(size,bounds->height,snapToPixel);
		return scaled;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(RatioUtil_obj,scaleToFit,return )

::nme::geom::Rectangle RatioUtil_obj::_defineRect( ::nme::geom::Rectangle size,double width,double height,bool snapToPixel){
	__SAFE_POINT
	::nme::geom::Rectangle scaled = size->clone();
	scaled->width = snapToPixel ? double( ::Math_obj::round(width) ) : double( width );
	scaled->height = snapToPixel ? double( ::Math_obj::round(height) ) : double( height );
	return scaled;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(RatioUtil_obj,_defineRect,return )


RatioUtil_obj::RatioUtil_obj()
{
}

void RatioUtil_obj::__Mark()
{
}

Dynamic RatioUtil_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"scale",sizeof(wchar_t)*5) ) { return scale_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"scaleWidth",sizeof(wchar_t)*10) ) { return scaleWidth_dyn(); }
		if (!memcmp(inName.__s,L"scaleToFit",sizeof(wchar_t)*10) ) { return scaleToFit_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"scaleHeight",sizeof(wchar_t)*11) ) { return scaleHeight_dyn(); }
		if (!memcmp(inName.__s,L"scaleToFill",sizeof(wchar_t)*11) ) { return scaleToFill_dyn(); }
		if (!memcmp(inName.__s,L"_defineRect",sizeof(wchar_t)*11) ) { return _defineRect_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"widthToHeight",sizeof(wchar_t)*13) ) { return widthToHeight_dyn(); }
		if (!memcmp(inName.__s,L"heightToWidth",sizeof(wchar_t)*13) ) { return heightToWidth_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic RatioUtil_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void RatioUtil_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"widthToHeight",13),
	HX_STRING(L"heightToWidth",13),
	HX_STRING(L"scale",5),
	HX_STRING(L"scaleWidth",10),
	HX_STRING(L"scaleHeight",11),
	HX_STRING(L"scaleToFill",11),
	HX_STRING(L"scaleToFit",10),
	HX_STRING(L"_defineRect",11),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
};

Class RatioUtil_obj::__mClass;

void RatioUtil_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"org.casalib.util.RatioUtil",26), hx::TCanCast< RatioUtil_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void RatioUtil_obj::__boot()
{
}

} // end namespace org
} // end namespace casalib
} // end namespace util
