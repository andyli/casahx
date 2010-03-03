#include <hxcpp.h>

#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
namespace nme{
namespace geom{

Void Rectangle_obj::__construct(Dynamic inX,Dynamic inY,Dynamic inWidth,Dynamic inHeight)
{
{
	this->x = (inX == null()) ? Dynamic( 0 ) : Dynamic( inX );
	this->y = (inY == null()) ? Dynamic( 0 ) : Dynamic( inY );
	this->width = (inWidth == null()) ? Dynamic( 0 ) : Dynamic( inWidth );
	this->height = (inHeight == null()) ? Dynamic( 0 ) : Dynamic( inHeight );
}
;
	return null();
}

Rectangle_obj::~Rectangle_obj() { }

Dynamic Rectangle_obj::__CreateEmpty() { return  new Rectangle_obj; }
hx::ObjectPtr< Rectangle_obj > Rectangle_obj::__new(Dynamic inX,Dynamic inY,Dynamic inWidth,Dynamic inHeight)
{  hx::ObjectPtr< Rectangle_obj > result = new Rectangle_obj();
	result->__construct(inX,inY,inWidth,inHeight);
	return result;}

Dynamic Rectangle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Rectangle_obj > result = new Rectangle_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

double Rectangle_obj::get_left( ){
	return this->x;
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_left,return )

double Rectangle_obj::set_left( double l){
	this->x = l;
	return l;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_left,return )

double Rectangle_obj::get_right( ){
	return (this->x + this->width);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_right,return )

double Rectangle_obj::set_right( double r){
	this->width = (r - this->x);
	return r;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_right,return )

double Rectangle_obj::get_top( ){
	return this->y;
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_top,return )

double Rectangle_obj::set_top( double t){
	this->y = t;
	return t;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_top,return )

double Rectangle_obj::get_bottom( ){
	return (this->y + this->height);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_bottom,return )

double Rectangle_obj::set_bottom( double b){
	this->height = (b - this->y);
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_bottom,return )

::nme::geom::Point Rectangle_obj::get_topLeft( ){
	return ::nme::geom::Point_obj::__new(this->x,this->y);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_topLeft,return )

::nme::geom::Point Rectangle_obj::set_topLeft( ::nme::geom::Point p){
	__SAFE_POINT
	this->x = p->x;
	this->y = p->y;
	return p->clone();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_topLeft,return )

::nme::geom::Point Rectangle_obj::get_size( ){
	return ::nme::geom::Point_obj::__new(this->width,this->height);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_size,return )

::nme::geom::Point Rectangle_obj::set_size( ::nme::geom::Point p){
	__SAFE_POINT
	this->width = p->x;
	this->height = p->y;
	return p->clone();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_size,return )

::nme::geom::Point Rectangle_obj::get_bottomRight( ){
	return ::nme::geom::Point_obj::__new((this->x + this->width),(this->y + this->height));
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_bottomRight,return )

::nme::geom::Point Rectangle_obj::set_bottomRight( ::nme::geom::Point p){
	__SAFE_POINT
	this->width = (p->x - this->x);
	this->height = (p->y - this->y);
	return p->clone();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_bottomRight,return )

::nme::geom::Rectangle Rectangle_obj::clone( ){
	return ::nme::geom::Rectangle_obj::__new(this->x,this->y,this->width,this->height);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,clone,return )

bool Rectangle_obj::contains( double inX,double inY){
	__SAFE_POINT
	return (bool((inX >= this->x)) && bool((bool((inY >= this->y)) && bool((bool((inX < this->get_right())) && bool((inY < this->get_bottom())))))));
}


HX_DEFINE_DYNAMIC_FUNC2(Rectangle_obj,contains,return )

bool Rectangle_obj::containsPoint( ::nme::geom::Point point){
	__SAFE_POINT
	return this->contains(point->x,point->y);
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,containsPoint,return )

bool Rectangle_obj::containsRect( ::nme::geom::Rectangle rect){
	__SAFE_POINT
	return (bool(this->contains(rect->x,rect->y)) && bool(this->containsPoint(rect->get_bottomRight())));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,containsRect,return )

bool Rectangle_obj::equals( ::nme::geom::Rectangle toCompare){
	return (bool((this->x == toCompare->x)) && bool((bool((this->y == toCompare->y)) && bool((bool((this->width == toCompare->width)) && bool((this->height == toCompare->height)))))));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,equals,return )

Void Rectangle_obj::inflate( double dx,double dy){
{
		hx::SubEq(this->x,dx);
		hx::AddEq(this->width,(dx * 2));
		hx::SubEq(this->y,dy);
		hx::AddEq(this->height,(dy * 2));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Rectangle_obj,inflate,(void))

Void Rectangle_obj::inflatePoint( ::nme::geom::Point point){
{
		__SAFE_POINT
		this->inflate(point->x,point->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,inflatePoint,(void))

::nme::geom::Rectangle Rectangle_obj::intersection( ::nme::geom::Rectangle toIntersect){
	__SAFE_POINT
	double x0 = (this->x < toIntersect->x) ? double( toIntersect->x ) : double( this->x );
	double x1 = (this->get_right() > toIntersect->get_right()) ? double( toIntersect->get_right() ) : double( this->get_right() );
	if ((x1 <= x0))
		return ::nme::geom::Rectangle_obj::__new(null(),null(),null(),null());
	double y0 = (this->y < toIntersect->y) ? double( toIntersect->x ) : double( this->y );
	double y1 = (this->get_bottom() > toIntersect->get_bottom()) ? double( toIntersect->get_bottom() ) : double( this->get_bottom() );
	if ((y1 <= y0))
		return ::nme::geom::Rectangle_obj::__new(null(),null(),null(),null());
	return ::nme::geom::Rectangle_obj::__new(x0,y0,(x1 - x0),(y1 - y0));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,intersection,return )

bool Rectangle_obj::intersects( ::nme::geom::Rectangle toIntersect){
	__SAFE_POINT
	double x0 = (this->x < toIntersect->x) ? double( toIntersect->x ) : double( this->x );
	double x1 = (this->get_right() > toIntersect->get_right()) ? double( toIntersect->get_right() ) : double( this->get_right() );
	if ((x1 <= x0))
		return false;
	double y0 = (this->y < toIntersect->y) ? double( toIntersect->x ) : double( this->y );
	double y1 = (this->get_bottom() > toIntersect->get_bottom()) ? double( toIntersect->get_bottom() ) : double( this->get_bottom() );
	return (y1 > y0);
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,intersects,return )

::nme::geom::Rectangle Rectangle_obj::_union( ::nme::geom::Rectangle toUnion){
	__SAFE_POINT
	double x0 = (this->x > toUnion->x) ? double( toUnion->x ) : double( this->x );
	double x1 = (this->get_right() < toUnion->get_right()) ? double( toUnion->get_right() ) : double( this->get_right() );
	double y0 = (this->y > toUnion->y) ? double( toUnion->x ) : double( this->y );
	double y1 = (this->get_bottom() < toUnion->get_bottom()) ? double( toUnion->get_bottom() ) : double( this->get_bottom() );
	return ::nme::geom::Rectangle_obj::__new(x0,y0,(x1 - x0),(y1 - y0));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,_union,return )

bool Rectangle_obj::isEmpty( ){
	return (bool((this->width == 0)) && bool((this->height == 0)));
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,isEmpty,return )

Void Rectangle_obj::offset( double dx,double dy){
{
		hx::AddEq(this->x,dx);
		hx::AddEq(this->y,dy);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Rectangle_obj,offset,(void))

Void Rectangle_obj::offsetPoint( ::nme::geom::Point point){
{
		hx::AddEq(this->x,point->x);
		hx::AddEq(this->y,point->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,offsetPoint,(void))

Void Rectangle_obj::setEmpty( ){
{
		this->x = this->y = this->width = this->height = 0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,setEmpty,(void))

::nme::geom::Rectangle Rectangle_obj::transform( ::nme::geom::Matrix m){
	double tx0 = ((m->a * this->x) + (m->c * this->y));
	double tx1 = tx0;
	double ty0 = ((m->b * this->x) + (m->d * this->y));
	double ty1 = tx0;
	double tx = ((m->a * ((this->x + this->width))) + (m->c * this->y));
	double ty = ((m->b * ((this->x + this->width))) + (m->d * this->y));
	if ((tx < tx0))
		tx0 = tx;
	if ((ty < ty0))
		ty0 = ty;
	if ((tx > tx1))
		tx1 = tx;
	if ((ty > ty1))
		ty1 = ty;
	tx = ((m->a * ((this->x + this->width))) + (m->c * ((this->y + this->height))));
	ty = ((m->b * ((this->x + this->width))) + (m->d * ((this->y + this->height))));
	if ((tx < tx0))
		tx0 = tx;
	if ((ty < ty0))
		ty0 = ty;
	if ((tx > tx1))
		tx1 = tx;
	if ((ty > ty1))
		ty1 = ty;
	tx = ((m->a * this->x) + (m->c * ((this->y + this->height))));
	ty = ((m->b * this->x) + (m->d * ((this->y + this->height))));
	if ((tx < tx0))
		tx0 = tx;
	if ((ty < ty0))
		ty0 = ty;
	if ((tx > tx1))
		tx1 = tx;
	if ((ty > ty1))
		ty1 = ty;
	return ::nme::geom::Rectangle_obj::__new((tx0 + m->tx),(ty0 + m->ty),(tx1 - tx0),(ty1 - ty0));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,transform,return )

Void Rectangle_obj::extendBounds( ::nme::geom::Rectangle r){
{
		__SAFE_POINT
		double dx = (this->x - r->x);
		if ((dx > 0)){
			hx::SubEq(this->x,dx);
			hx::AddEq(this->width,dx);
		}
		double dy = (this->y - r->y);
		if ((dy > 0)){
			hx::SubEq(this->y,dy);
			hx::AddEq(this->height,dy);
		}
		if ((r->get_right() > this->get_right()))
			this->set_right(r->get_right());
		if ((r->get_bottom() > this->get_bottom()))
			this->set_bottom(r->get_bottom());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,extendBounds,(void))


Rectangle_obj::Rectangle_obj()
{
}

void Rectangle_obj::__Mark()
{
	hx::MarkMember(x);
	hx::MarkMember(y);
	hx::MarkMember(width);
	hx::MarkMember(height);
	hx::MarkMember(left);
	hx::MarkMember(right);
	hx::MarkMember(top);
	hx::MarkMember(bottom);
	hx::MarkMember(topLeft);
	hx::MarkMember(size);
	hx::MarkMember(bottomRight);
}

Dynamic Rectangle_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { return x; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { return y; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"top",sizeof(wchar_t)*3) ) { return get_top(); }
		break;
	case 4:
		if (!memcmp(inName.__s,L"left",sizeof(wchar_t)*4) ) { return get_left(); }
		if (!memcmp(inName.__s,L"size",sizeof(wchar_t)*4) ) { return get_topLeft(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"width",sizeof(wchar_t)*5) ) { return width; }
		if (!memcmp(inName.__s,L"right",sizeof(wchar_t)*5) ) { return get_right(); }
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		if (!memcmp(inName.__s,L"union",sizeof(wchar_t)*5) ) { return _union_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"height",sizeof(wchar_t)*6) ) { return height; }
		if (!memcmp(inName.__s,L"bottom",sizeof(wchar_t)*6) ) { return get_bottom(); }
		if (!memcmp(inName.__s,L"equals",sizeof(wchar_t)*6) ) { return equals_dyn(); }
		if (!memcmp(inName.__s,L"offset",sizeof(wchar_t)*6) ) { return offset_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"get_top",sizeof(wchar_t)*7) ) { return get_top_dyn(); }
		if (!memcmp(inName.__s,L"set_top",sizeof(wchar_t)*7) ) { return set_top_dyn(); }
		if (!memcmp(inName.__s,L"topLeft",sizeof(wchar_t)*7) ) { return get_topLeft(); }
		if (!memcmp(inName.__s,L"inflate",sizeof(wchar_t)*7) ) { return inflate_dyn(); }
		if (!memcmp(inName.__s,L"isEmpty",sizeof(wchar_t)*7) ) { return isEmpty_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"get_left",sizeof(wchar_t)*8) ) { return get_left_dyn(); }
		if (!memcmp(inName.__s,L"set_left",sizeof(wchar_t)*8) ) { return set_left_dyn(); }
		if (!memcmp(inName.__s,L"get_size",sizeof(wchar_t)*8) ) { return get_size_dyn(); }
		if (!memcmp(inName.__s,L"set_size",sizeof(wchar_t)*8) ) { return set_size_dyn(); }
		if (!memcmp(inName.__s,L"contains",sizeof(wchar_t)*8) ) { return contains_dyn(); }
		if (!memcmp(inName.__s,L"setEmpty",sizeof(wchar_t)*8) ) { return setEmpty_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"get_right",sizeof(wchar_t)*9) ) { return get_right_dyn(); }
		if (!memcmp(inName.__s,L"set_right",sizeof(wchar_t)*9) ) { return set_right_dyn(); }
		if (!memcmp(inName.__s,L"transform",sizeof(wchar_t)*9) ) { return transform_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"get_bottom",sizeof(wchar_t)*10) ) { return get_bottom_dyn(); }
		if (!memcmp(inName.__s,L"set_bottom",sizeof(wchar_t)*10) ) { return set_bottom_dyn(); }
		if (!memcmp(inName.__s,L"intersects",sizeof(wchar_t)*10) ) { return intersects_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"get_topLeft",sizeof(wchar_t)*11) ) { return get_topLeft_dyn(); }
		if (!memcmp(inName.__s,L"set_topLeft",sizeof(wchar_t)*11) ) { return set_topLeft_dyn(); }
		if (!memcmp(inName.__s,L"bottomRight",sizeof(wchar_t)*11) ) { return get_bottomRight(); }
		if (!memcmp(inName.__s,L"offsetPoint",sizeof(wchar_t)*11) ) { return offsetPoint_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"containsRect",sizeof(wchar_t)*12) ) { return containsRect_dyn(); }
		if (!memcmp(inName.__s,L"inflatePoint",sizeof(wchar_t)*12) ) { return inflatePoint_dyn(); }
		if (!memcmp(inName.__s,L"intersection",sizeof(wchar_t)*12) ) { return intersection_dyn(); }
		if (!memcmp(inName.__s,L"extendBounds",sizeof(wchar_t)*12) ) { return extendBounds_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"containsPoint",sizeof(wchar_t)*13) ) { return containsPoint_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"get_bottomRight",sizeof(wchar_t)*15) ) { return get_bottomRight_dyn(); }
		if (!memcmp(inName.__s,L"set_bottomRight",sizeof(wchar_t)*15) ) { return set_bottomRight_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Rectangle_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { x=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { y=inValue.Cast< double >(); return inValue; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"top",sizeof(wchar_t)*3) ) { return set_top(inValue); }
		break;
	case 4:
		if (!memcmp(inName.__s,L"left",sizeof(wchar_t)*4) ) { return set_left(inValue); }
		if (!memcmp(inName.__s,L"size",sizeof(wchar_t)*4) ) { return set_topLeft(inValue); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"width",sizeof(wchar_t)*5) ) { width=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"right",sizeof(wchar_t)*5) ) { return set_right(inValue); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"height",sizeof(wchar_t)*6) ) { height=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"bottom",sizeof(wchar_t)*6) ) { return set_bottom(inValue); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"topLeft",sizeof(wchar_t)*7) ) { return set_topLeft(inValue); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"bottomRight",sizeof(wchar_t)*11) ) { return set_bottomRight(inValue); }
	}
	return super::__SetField(inName,inValue);
}

void Rectangle_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"x",1));
	outFields->push(HX_STRING(L"y",1));
	outFields->push(HX_STRING(L"width",5));
	outFields->push(HX_STRING(L"height",6));
	outFields->push(HX_STRING(L"left",4));
	outFields->push(HX_STRING(L"right",5));
	outFields->push(HX_STRING(L"top",3));
	outFields->push(HX_STRING(L"bottom",6));
	outFields->push(HX_STRING(L"topLeft",7));
	outFields->push(HX_STRING(L"size",4));
	outFields->push(HX_STRING(L"bottomRight",11));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"x",1),
	HX_STRING(L"y",1),
	HX_STRING(L"width",5),
	HX_STRING(L"height",6),
	HX_STRING(L"left",4),
	HX_STRING(L"get_left",8),
	HX_STRING(L"set_left",8),
	HX_STRING(L"right",5),
	HX_STRING(L"get_right",9),
	HX_STRING(L"set_right",9),
	HX_STRING(L"top",3),
	HX_STRING(L"get_top",7),
	HX_STRING(L"set_top",7),
	HX_STRING(L"bottom",6),
	HX_STRING(L"get_bottom",10),
	HX_STRING(L"set_bottom",10),
	HX_STRING(L"topLeft",7),
	HX_STRING(L"get_topLeft",11),
	HX_STRING(L"set_topLeft",11),
	HX_STRING(L"size",4),
	HX_STRING(L"get_size",8),
	HX_STRING(L"set_size",8),
	HX_STRING(L"bottomRight",11),
	HX_STRING(L"get_bottomRight",15),
	HX_STRING(L"set_bottomRight",15),
	HX_STRING(L"clone",5),
	HX_STRING(L"contains",8),
	HX_STRING(L"containsPoint",13),
	HX_STRING(L"containsRect",12),
	HX_STRING(L"equals",6),
	HX_STRING(L"inflate",7),
	HX_STRING(L"inflatePoint",12),
	HX_STRING(L"intersection",12),
	HX_STRING(L"intersects",10),
	HX_STRING(L"union",5),
	HX_STRING(L"isEmpty",7),
	HX_STRING(L"offset",6),
	HX_STRING(L"offsetPoint",11),
	HX_STRING(L"setEmpty",8),
	HX_STRING(L"transform",9),
	HX_STRING(L"extendBounds",12),
	String(null()) };

static void sMarkStatics() {
};

Class Rectangle_obj::__mClass;

void Rectangle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.geom.Rectangle",18), hx::TCanCast< Rectangle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Rectangle_obj::__boot()
{
}

} // end namespace nme
} // end namespace geom
