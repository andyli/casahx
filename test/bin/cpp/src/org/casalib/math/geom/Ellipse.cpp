#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
#ifndef INCLUDED_org_casalib_math_geom_Ellipse
#include <org/casalib/math/geom/Ellipse.h>
#endif
namespace org{
namespace casalib{
namespace math{
namespace geom{

Void Ellipse_obj::__construct(double x,double y,double width,double height)
{
{
	this->setX(x);
	this->setY(y);
	this->setWidth(width);
	this->setHeight(height);
}
;
	return null();
}

Ellipse_obj::~Ellipse_obj() { }

Dynamic Ellipse_obj::__CreateEmpty() { return  new Ellipse_obj; }
hx::ObjectPtr< Ellipse_obj > Ellipse_obj::__new(double x,double y,double width,double height)
{  hx::ObjectPtr< Ellipse_obj > result = new Ellipse_obj();
	result->__construct(x,y,width,height);
	return result;}

Dynamic Ellipse_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Ellipse_obj > result = new Ellipse_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

double Ellipse_obj::getX( ){
	return this->_x;
}


HX_DEFINE_DYNAMIC_FUNC0(Ellipse_obj,getX,return )

double Ellipse_obj::setX( double xPos){
	this->_x = xPos;
	return xPos;
}


HX_DEFINE_DYNAMIC_FUNC1(Ellipse_obj,setX,return )

double Ellipse_obj::getY( ){
	return this->_y;
}


HX_DEFINE_DYNAMIC_FUNC0(Ellipse_obj,getY,return )

double Ellipse_obj::setY( double yPos){
	this->_y = yPos;
	return yPos;
}


HX_DEFINE_DYNAMIC_FUNC1(Ellipse_obj,setY,return )

double Ellipse_obj::getWidth( ){
	return this->_width;
}


HX_DEFINE_DYNAMIC_FUNC0(Ellipse_obj,getWidth,return )

double Ellipse_obj::setWidth( double width){
	this->_width = width;
	return width;
}


HX_DEFINE_DYNAMIC_FUNC1(Ellipse_obj,setWidth,return )

double Ellipse_obj::getHeight( ){
	return this->_height;
}


HX_DEFINE_DYNAMIC_FUNC0(Ellipse_obj,getHeight,return )

double Ellipse_obj::setHeight( double height){
	this->_height = height;
	return height;
}


HX_DEFINE_DYNAMIC_FUNC1(Ellipse_obj,setHeight,return )

::nme::geom::Point Ellipse_obj::getCenter( ){
	__SAFE_POINT
	return ::nme::geom::Point_obj::__new((this->getX() + (this->getWidth() * 0.5)),(this->getY() + (this->getHeight() * 0.5)));
}


HX_DEFINE_DYNAMIC_FUNC0(Ellipse_obj,getCenter,return )

::nme::geom::Point Ellipse_obj::setCenter( ::nme::geom::Point c){
	__SAFE_POINT
	this->setX((c->x - (this->getWidth() * 0.5)));
	this->setY((c->y - (this->getHeight() * 0.5)));
	return c;
}


HX_DEFINE_DYNAMIC_FUNC1(Ellipse_obj,setCenter,return )

::nme::geom::Point Ellipse_obj::getSize( ){
	__SAFE_POINT
	return ::nme::geom::Point_obj::__new(this->getWidth(),this->getHeight());
}


HX_DEFINE_DYNAMIC_FUNC0(Ellipse_obj,getSize,return )

double Ellipse_obj::getPerimeter( ){
	__SAFE_POINT
	return (((((::Math_obj::sqrt((.5 * ((::Math_obj::pow(this->getWidth(),2) + ::Math_obj::pow(this->getHeight(),2))))) * ::Math_obj::PI)) * 2)) * 0.5);
}


HX_DEFINE_DYNAMIC_FUNC0(Ellipse_obj,getPerimeter,return )

double Ellipse_obj::getArea( ){
	__SAFE_POINT
	return (((::Math_obj::PI * ((this->getWidth() * 0.5)))) * ((this->getHeight() * 0.5)));
}


HX_DEFINE_DYNAMIC_FUNC0(Ellipse_obj,getArea,return )

::nme::geom::Point Ellipse_obj::getPointOfDegree( double degree){
	__SAFE_POINT
	double radian = (((degree - 90)) * ((double(::Math_obj::PI) / double(180))));
	double xRadius = (this->getWidth() * 0.5);
	double yRadius = (this->getHeight() * 0.5);
	return ::nme::geom::Point_obj::__new((((this->getX() + xRadius)) + (::Math_obj::cos(radian) * xRadius)),(((this->getY() + yRadius)) + (::Math_obj::sin(radian) * yRadius)));
}


HX_DEFINE_DYNAMIC_FUNC1(Ellipse_obj,getPointOfDegree,return )

bool Ellipse_obj::containsPoint( ::nme::geom::Point point){
	__SAFE_POINT
	double xRadius = (this->getWidth() * 0.5);
	double yRadius = (this->getHeight() * 0.5);
	double xTar = (((point->x - this->getX())) - xRadius);
	double yTar = (((point->y - this->getY())) - yRadius);
	return ((::Math_obj::pow((double(xTar) / double(xRadius)),2) + ::Math_obj::pow((double(yTar) / double(yRadius)),2)) <= 1);
}


HX_DEFINE_DYNAMIC_FUNC1(Ellipse_obj,containsPoint,return )

bool Ellipse_obj::equals( ::org::casalib::math::geom::Ellipse ellipse){
	__SAFE_POINT
	return (bool((this->getX() == ellipse->getX())) && bool((bool((this->getY() == ellipse->getY())) && bool((bool((this->getWidth() == ellipse->getWidth())) && bool((this->getHeight() == ellipse->getHeight())))))));
}


HX_DEFINE_DYNAMIC_FUNC1(Ellipse_obj,equals,return )

::org::casalib::math::geom::Ellipse Ellipse_obj::clone( ){
	__SAFE_POINT
	return ::org::casalib::math::geom::Ellipse_obj::__new(this->getX(),this->getY(),this->getWidth(),this->getHeight());
}


HX_DEFINE_DYNAMIC_FUNC0(Ellipse_obj,clone,return )


Ellipse_obj::Ellipse_obj()
{
}

void Ellipse_obj::__Mark()
{
	hx::MarkMember(area);
	hx::MarkMember(center);
	hx::MarkMember(height);
	hx::MarkMember(perimeter);
	hx::MarkMember(size);
	hx::MarkMember(width);
	hx::MarkMember(x);
	hx::MarkMember(y);
	hx::MarkMember(_x);
	hx::MarkMember(_y);
	hx::MarkMember(_width);
	hx::MarkMember(_height);
}

Dynamic Ellipse_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { return getX(); }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { return getY(); }
		break;
	case 2:
		if (!memcmp(inName.__s,L"_x",sizeof(wchar_t)*2) ) { return _x; }
		if (!memcmp(inName.__s,L"_y",sizeof(wchar_t)*2) ) { return _y; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"area",sizeof(wchar_t)*4) ) { return getArea(); }
		if (!memcmp(inName.__s,L"size",sizeof(wchar_t)*4) ) { return getSize(); }
		if (!memcmp(inName.__s,L"getX",sizeof(wchar_t)*4) ) { return getX_dyn(); }
		if (!memcmp(inName.__s,L"setX",sizeof(wchar_t)*4) ) { return setX_dyn(); }
		if (!memcmp(inName.__s,L"getY",sizeof(wchar_t)*4) ) { return getY_dyn(); }
		if (!memcmp(inName.__s,L"setY",sizeof(wchar_t)*4) ) { return setY_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"width",sizeof(wchar_t)*5) ) { return getWidth(); }
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"center",sizeof(wchar_t)*6) ) { return getCenter(); }
		if (!memcmp(inName.__s,L"height",sizeof(wchar_t)*6) ) { return getHeight(); }
		if (!memcmp(inName.__s,L"_width",sizeof(wchar_t)*6) ) { return _width; }
		if (!memcmp(inName.__s,L"equals",sizeof(wchar_t)*6) ) { return equals_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"_height",sizeof(wchar_t)*7) ) { return _height; }
		if (!memcmp(inName.__s,L"getSize",sizeof(wchar_t)*7) ) { return getSize_dyn(); }
		if (!memcmp(inName.__s,L"getArea",sizeof(wchar_t)*7) ) { return getArea_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"getWidth",sizeof(wchar_t)*8) ) { return getWidth_dyn(); }
		if (!memcmp(inName.__s,L"setWidth",sizeof(wchar_t)*8) ) { return setWidth_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"perimeter",sizeof(wchar_t)*9) ) { return getPerimeter(); }
		if (!memcmp(inName.__s,L"getHeight",sizeof(wchar_t)*9) ) { return getHeight_dyn(); }
		if (!memcmp(inName.__s,L"setHeight",sizeof(wchar_t)*9) ) { return setHeight_dyn(); }
		if (!memcmp(inName.__s,L"getCenter",sizeof(wchar_t)*9) ) { return getCenter_dyn(); }
		if (!memcmp(inName.__s,L"setCenter",sizeof(wchar_t)*9) ) { return setCenter_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"getPerimeter",sizeof(wchar_t)*12) ) { return getPerimeter_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"containsPoint",sizeof(wchar_t)*13) ) { return containsPoint_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"getPointOfDegree",sizeof(wchar_t)*16) ) { return getPointOfDegree_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Ellipse_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { return setX(inValue); }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { return setY(inValue); }
		break;
	case 2:
		if (!memcmp(inName.__s,L"_x",sizeof(wchar_t)*2) ) { _x=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"_y",sizeof(wchar_t)*2) ) { _y=inValue.Cast< double >(); return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"area",sizeof(wchar_t)*4) ) { area=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"size",sizeof(wchar_t)*4) ) { size=inValue.Cast< ::nme::geom::Point >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"width",sizeof(wchar_t)*5) ) { return setWidth(inValue); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"center",sizeof(wchar_t)*6) ) { return setCenter(inValue); }
		if (!memcmp(inName.__s,L"height",sizeof(wchar_t)*6) ) { return setHeight(inValue); }
		if (!memcmp(inName.__s,L"_width",sizeof(wchar_t)*6) ) { _width=inValue.Cast< double >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"_height",sizeof(wchar_t)*7) ) { _height=inValue.Cast< double >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"perimeter",sizeof(wchar_t)*9) ) { perimeter=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Ellipse_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"area",4));
	outFields->push(HX_STRING(L"center",6));
	outFields->push(HX_STRING(L"height",6));
	outFields->push(HX_STRING(L"perimeter",9));
	outFields->push(HX_STRING(L"size",4));
	outFields->push(HX_STRING(L"width",5));
	outFields->push(HX_STRING(L"x",1));
	outFields->push(HX_STRING(L"y",1));
	outFields->push(HX_STRING(L"_x",2));
	outFields->push(HX_STRING(L"_y",2));
	outFields->push(HX_STRING(L"_width",6));
	outFields->push(HX_STRING(L"_height",7));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"area",4),
	HX_STRING(L"center",6),
	HX_STRING(L"height",6),
	HX_STRING(L"perimeter",9),
	HX_STRING(L"size",4),
	HX_STRING(L"width",5),
	HX_STRING(L"x",1),
	HX_STRING(L"y",1),
	HX_STRING(L"_x",2),
	HX_STRING(L"_y",2),
	HX_STRING(L"_width",6),
	HX_STRING(L"_height",7),
	HX_STRING(L"getX",4),
	HX_STRING(L"setX",4),
	HX_STRING(L"getY",4),
	HX_STRING(L"setY",4),
	HX_STRING(L"getWidth",8),
	HX_STRING(L"setWidth",8),
	HX_STRING(L"getHeight",9),
	HX_STRING(L"setHeight",9),
	HX_STRING(L"getCenter",9),
	HX_STRING(L"setCenter",9),
	HX_STRING(L"getSize",7),
	HX_STRING(L"getPerimeter",12),
	HX_STRING(L"getArea",7),
	HX_STRING(L"getPointOfDegree",16),
	HX_STRING(L"containsPoint",13),
	HX_STRING(L"equals",6),
	HX_STRING(L"clone",5),
	String(null()) };

static void sMarkStatics() {
};

Class Ellipse_obj::__mClass;

void Ellipse_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"org.casalib.math.geom.Ellipse",29), hx::TCanCast< Ellipse_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Ellipse_obj::__boot()
{
}

} // end namespace org
} // end namespace casalib
} // end namespace math
} // end namespace geom
