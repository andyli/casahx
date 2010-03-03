#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
namespace nme{
namespace geom{

Void Point_obj::__construct(Dynamic inX,Dynamic inY)
{
{
	this->x = (inX == null()) ? Dynamic( 0.0 ) : Dynamic( inX );
	this->y = (inY == null()) ? Dynamic( 0.0 ) : Dynamic( inY );
}
;
	return null();
}

Point_obj::~Point_obj() { }

Dynamic Point_obj::__CreateEmpty() { return  new Point_obj; }
hx::ObjectPtr< Point_obj > Point_obj::__new(Dynamic inX,Dynamic inY)
{  hx::ObjectPtr< Point_obj > result = new Point_obj();
	result->__construct(inX,inY);
	return result;}

Dynamic Point_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Point_obj > result = new Point_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::nme::geom::Point Point_obj::add( ::nme::geom::Point v){
	return ::nme::geom::Point_obj::__new((v->x + this->x),(v->y + this->y));
}


HX_DEFINE_DYNAMIC_FUNC1(Point_obj,add,return )

::nme::geom::Point Point_obj::clone( ){
	return ::nme::geom::Point_obj::__new(this->x,this->y);
}


HX_DEFINE_DYNAMIC_FUNC0(Point_obj,clone,return )

bool Point_obj::equals( ::nme::geom::Point toCompare){
	return (bool((toCompare->x == this->x)) && bool((toCompare->y == this->y)));
}


HX_DEFINE_DYNAMIC_FUNC1(Point_obj,equals,return )

double Point_obj::get_length( ){
	__SAFE_POINT
	return ::Math_obj::sqrt(((this->x * this->x) + (this->y * this->y)));
}


HX_DEFINE_DYNAMIC_FUNC0(Point_obj,get_length,return )

Void Point_obj::normalize( double thickness){
{
		__SAFE_POINT
		if ((bool((this->x == 0)) && bool((this->y == 0)))){
			this->x = thickness;
		}
		else{
			double norm = (double(thickness) / double(::Math_obj::sqrt(((this->x * this->x) + (this->y * this->y)))));
			hx::MultEq(this->x,norm);
			hx::MultEq(this->y,norm);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Point_obj,normalize,(void))

Void Point_obj::offset( double dx,double dy){
{
		hx::AddEq(this->x,dx);
		hx::AddEq(this->y,dy);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Point_obj,offset,(void))

::nme::geom::Point Point_obj::subtract( ::nme::geom::Point v){
	return ::nme::geom::Point_obj::__new((this->x - v->x),(this->y - v->y));
}


HX_DEFINE_DYNAMIC_FUNC1(Point_obj,subtract,return )

double Point_obj::distance( ::nme::geom::Point pt1,::nme::geom::Point pt2){
	__SAFE_POINT
	double dx = (pt1->x - pt2->x);
	double dy = (pt1->y - pt2->y);
	return ::Math_obj::sqrt(((dx * dy) + (dy * dy)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Point_obj,distance,return )

::nme::geom::Point Point_obj::interpolate( ::nme::geom::Point pt1,::nme::geom::Point pt2,double f){
	return ::nme::geom::Point_obj::__new((pt2->x + (f * ((pt1->x - pt2->x)))),(pt2->y + (f * ((pt1->y - pt2->y)))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Point_obj,interpolate,return )

::nme::geom::Point Point_obj::polar( double len,double angle){
	__SAFE_POINT
	return ::nme::geom::Point_obj::__new((len * ::Math_obj::cos(angle)),(len * ::Math_obj::sin(angle)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Point_obj,polar,return )


Point_obj::Point_obj()
{
}

void Point_obj::__Mark()
{
	hx::MarkMember(x);
	hx::MarkMember(y);
	hx::MarkMember(length);
}

Dynamic Point_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { return x; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { return y; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"add",sizeof(wchar_t)*3) ) { return add_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"polar",sizeof(wchar_t)*5) ) { return polar_dyn(); }
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"equals",sizeof(wchar_t)*6) ) { return equals_dyn(); }
		if (!memcmp(inName.__s,L"length",sizeof(wchar_t)*6) ) { return get_length(); }
		if (!memcmp(inName.__s,L"offset",sizeof(wchar_t)*6) ) { return offset_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"distance",sizeof(wchar_t)*8) ) { return distance_dyn(); }
		if (!memcmp(inName.__s,L"subtract",sizeof(wchar_t)*8) ) { return subtract_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"normalize",sizeof(wchar_t)*9) ) { return normalize_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"get_length",sizeof(wchar_t)*10) ) { return get_length_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"interpolate",sizeof(wchar_t)*11) ) { return interpolate_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Point_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { x=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { y=inValue.Cast< double >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"length",sizeof(wchar_t)*6) ) { length=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Point_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"x",1));
	outFields->push(HX_STRING(L"y",1));
	outFields->push(HX_STRING(L"length",6));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"distance",8),
	HX_STRING(L"interpolate",11),
	HX_STRING(L"polar",5),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"x",1),
	HX_STRING(L"y",1),
	HX_STRING(L"add",3),
	HX_STRING(L"clone",5),
	HX_STRING(L"equals",6),
	HX_STRING(L"length",6),
	HX_STRING(L"get_length",10),
	HX_STRING(L"normalize",9),
	HX_STRING(L"offset",6),
	HX_STRING(L"subtract",8),
	String(null()) };

static void sMarkStatics() {
};

Class Point_obj::__mClass;

void Point_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.geom.Point",14), hx::TCanCast< Point_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Point_obj::__boot()
{
}

} // end namespace nme
} // end namespace geom
