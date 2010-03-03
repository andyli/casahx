#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
namespace nme{
namespace geom{

Void Matrix_obj::__construct(Dynamic in_a,Dynamic in_b,Dynamic in_c,Dynamic in_d,Dynamic in_tx,Dynamic in_ty)
{
{
	this->a = (in_a == null()) ? Dynamic( 1.0 ) : Dynamic( in_a );
	this->b = (in_b == null()) ? Dynamic( 0.0 ) : Dynamic( in_b );
	this->c = (in_c == null()) ? Dynamic( 0.0 ) : Dynamic( in_c );
	this->d = (in_d == null()) ? Dynamic( 1.0 ) : Dynamic( in_d );
	this->tx = (in_tx == null()) ? Dynamic( 0.0 ) : Dynamic( in_tx );
	this->ty = (in_ty == null()) ? Dynamic( 0.0 ) : Dynamic( in_ty );
}
;
	return null();
}

Matrix_obj::~Matrix_obj() { }

Dynamic Matrix_obj::__CreateEmpty() { return  new Matrix_obj; }
hx::ObjectPtr< Matrix_obj > Matrix_obj::__new(Dynamic in_a,Dynamic in_b,Dynamic in_c,Dynamic in_d,Dynamic in_tx,Dynamic in_ty)
{  hx::ObjectPtr< Matrix_obj > result = new Matrix_obj();
	result->__construct(in_a,in_b,in_c,in_d,in_tx,in_ty);
	return result;}

Dynamic Matrix_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Matrix_obj > result = new Matrix_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

::nme::geom::Matrix Matrix_obj::clone( ){
	return ::nme::geom::Matrix_obj::__new(this->a,this->b,this->c,this->d,this->tx,this->ty);
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix_obj,clone,return )

Void Matrix_obj::createGradientBox( double in_width,double in_height,Dynamic rotation,Dynamic in_tx,Dynamic in_ty){
{
		__SAFE_POINT
		this->a = (double(in_width) / double(1638.4));
		this->d = (double(in_height) / double(1638.4));
		if ((bool((rotation != null())) && bool((rotation != 0.0)))){
			double cos = ::Math_obj::cos(rotation);
			double sin = ::Math_obj::sin(rotation);
			this->b = (sin * this->d);
			this->c = (-sin * this->a);
			hx::MultEq(this->a,cos);
			hx::MultEq(this->d,cos);
		}
		else{
			this->b = this->c = 0;
		}
		this->tx = (in_tx != null()) ? double( (in_tx + (double(in_width) / double(2))) ) : double( (double(in_width) / double(2)) );
		this->ty = (in_ty != null()) ? double( (in_ty + (double(in_height) / double(2))) ) : double( (double(in_height) / double(2)) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(Matrix_obj,createGradientBox,(void))

Void Matrix_obj::setRotation( double inTheta,Dynamic inScale){
{
		__SAFE_POINT
		double scale = (inScale == null()) ? Dynamic( 1.0 ) : Dynamic( inScale );
		this->a = (::Math_obj::cos(inTheta) * scale);
		this->c = (::Math_obj::sin(inTheta) * scale);
		this->b = -this->c;
		this->d = this->a;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix_obj,setRotation,(void))

Void Matrix_obj::identity( ){
{
		this->a = 1;
		this->b = 0;
		this->c = 0;
		this->d = 1;
		this->tx = 0;
		this->ty = 0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix_obj,identity,(void))

::nme::geom::Matrix Matrix_obj::invert( ){
	double norm = ((this->a * this->d) - (this->b * this->c));
	if ((norm == 0)){
		this->a = this->b = this->c = this->d = 0;
		this->tx = -this->tx;
		this->ty = -this->ty;
	}
	else{
		norm = (double(1.0) / double(norm));
		double a1 = (this->d * norm);
		this->d = (this->a * norm);
		this->a = a1;
		hx::MultEq(this->b,-norm);
		hx::MultEq(this->c,-norm);
		double tx1 = ((-this->a * this->tx) - (this->c * this->ty));
		this->ty = ((-this->b * this->tx) - (this->d * this->ty));
		this->tx = tx1;
	}
	return this;
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix_obj,invert,return )

::nme::geom::Point Matrix_obj::transformPoint( ::nme::geom::Point inPos){
	return ::nme::geom::Point_obj::__new(((((inPos->x * this->a) + (inPos->y * this->c))) + this->tx),((((inPos->x * this->b) + (inPos->y * this->d))) + this->ty));
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix_obj,transformPoint,return )

Void Matrix_obj::translate( double inDX,double inDY){
{
		hx::AddEq(this->tx,inDX);
		hx::AddEq(this->ty,inDY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix_obj,translate,(void))

Void Matrix_obj::rotate( double inTheta){
{
		__SAFE_POINT
		double cos = ::Math_obj::cos(inTheta);
		double sin = ::Math_obj::sin(inTheta);
		double a1 = ((this->a * cos) - (this->b * sin));
		this->b = ((this->a * sin) + (this->b * cos));
		this->a = a1;
		double c1 = ((this->c * cos) - (this->d * sin));
		this->d = ((this->c * sin) + (this->d * cos));
		this->c = c1;
		double tx1 = ((this->tx * cos) - (this->ty * sin));
		this->ty = ((this->tx * sin) + (this->ty * cos));
		this->tx = tx1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix_obj,rotate,(void))

Void Matrix_obj::scale( double inSX,double inSY){
{
		hx::MultEq(this->a,inSX);
		hx::MultEq(this->b,inSY);
		hx::MultEq(this->c,inSX);
		hx::MultEq(this->d,inSY);
		hx::MultEq(this->tx,inSX);
		hx::MultEq(this->ty,inSY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix_obj,scale,(void))

Void Matrix_obj::concat( ::nme::geom::Matrix m){
{
		double a1 = ((this->a * m->a) + (this->b * m->c));
		this->b = ((this->a * m->b) + (this->b * m->d));
		this->a = a1;
		double c1 = ((this->c * m->a) + (this->d * m->c));
		this->d = ((this->c * m->b) + (this->d * m->d));
		this->c = c1;
		double tx1 = ((((this->tx * m->a) + (this->ty * m->c))) + m->tx);
		this->ty = ((((this->tx * m->b) + (this->ty * m->d))) + m->ty);
		this->tx = tx1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix_obj,concat,(void))

::nme::geom::Matrix Matrix_obj::mult( ::nme::geom::Matrix m){
	::nme::geom::Matrix result = ::nme::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	result->a = ((this->a * m->a) + (this->b * m->c));
	result->b = ((this->a * m->b) + (this->b * m->d));
	result->c = ((this->c * m->a) + (this->d * m->c));
	result->d = ((this->c * m->b) + (this->d * m->d));
	result->tx = ((((this->tx * m->a) + (this->ty * m->c))) + m->tx);
	result->ty = ((((this->tx * m->b) + (this->ty * m->d))) + m->ty);
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix_obj,mult,return )


Matrix_obj::Matrix_obj()
{
}

void Matrix_obj::__Mark()
{
	hx::MarkMember(a);
	hx::MarkMember(b);
	hx::MarkMember(c);
	hx::MarkMember(d);
	hx::MarkMember(tx);
	hx::MarkMember(ty);
}

Dynamic Matrix_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"a",sizeof(wchar_t)*1) ) { return a; }
		if (!memcmp(inName.__s,L"b",sizeof(wchar_t)*1) ) { return b; }
		if (!memcmp(inName.__s,L"c",sizeof(wchar_t)*1) ) { return c; }
		if (!memcmp(inName.__s,L"d",sizeof(wchar_t)*1) ) { return d; }
		break;
	case 2:
		if (!memcmp(inName.__s,L"tx",sizeof(wchar_t)*2) ) { return tx; }
		if (!memcmp(inName.__s,L"ty",sizeof(wchar_t)*2) ) { return ty; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"mult",sizeof(wchar_t)*4) ) { return mult_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		if (!memcmp(inName.__s,L"scale",sizeof(wchar_t)*5) ) { return scale_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"invert",sizeof(wchar_t)*6) ) { return invert_dyn(); }
		if (!memcmp(inName.__s,L"rotate",sizeof(wchar_t)*6) ) { return rotate_dyn(); }
		if (!memcmp(inName.__s,L"concat",sizeof(wchar_t)*6) ) { return concat_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"identity",sizeof(wchar_t)*8) ) { return identity_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"translate",sizeof(wchar_t)*9) ) { return translate_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"setRotation",sizeof(wchar_t)*11) ) { return setRotation_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"transformPoint",sizeof(wchar_t)*14) ) { return transformPoint_dyn(); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"createGradientBox",sizeof(wchar_t)*17) ) { return createGradientBox_dyn(); }
	}
	return super::__Field(inName);
}

static int __id_a = __hxcpp_field_to_id("a");
static int __id_b = __hxcpp_field_to_id("b");
static int __id_c = __hxcpp_field_to_id("c");
static int __id_d = __hxcpp_field_to_id("d");
static int __id_tx = __hxcpp_field_to_id("tx");
static int __id_ty = __hxcpp_field_to_id("ty");
static int __id_clone = __hxcpp_field_to_id("clone");
static int __id_createGradientBox = __hxcpp_field_to_id("createGradientBox");
static int __id_setRotation = __hxcpp_field_to_id("setRotation");
static int __id_identity = __hxcpp_field_to_id("identity");
static int __id_invert = __hxcpp_field_to_id("invert");
static int __id_transformPoint = __hxcpp_field_to_id("transformPoint");
static int __id_translate = __hxcpp_field_to_id("translate");
static int __id_rotate = __hxcpp_field_to_id("rotate");
static int __id_scale = __hxcpp_field_to_id("scale");
static int __id_concat = __hxcpp_field_to_id("concat");
static int __id_mult = __hxcpp_field_to_id("mult");


double Matrix_obj::__INumField(int inFieldID)
{
	if (inFieldID==__id_a) return hx::ToDouble( a ) ;
	if (inFieldID==__id_b) return hx::ToDouble( b ) ;
	if (inFieldID==__id_c) return hx::ToDouble( c ) ;
	if (inFieldID==__id_d) return hx::ToDouble( d ) ;
	if (inFieldID==__id_tx) return hx::ToDouble( tx ) ;
	if (inFieldID==__id_ty) return hx::ToDouble( ty ) ;
	if (inFieldID==__id_clone) return hx::ToDouble( clone_dyn() ) ;
	if (inFieldID==__id_createGradientBox) return hx::ToDouble( createGradientBox_dyn() ) ;
	if (inFieldID==__id_setRotation) return hx::ToDouble( setRotation_dyn() ) ;
	if (inFieldID==__id_identity) return hx::ToDouble( identity_dyn() ) ;
	if (inFieldID==__id_invert) return hx::ToDouble( invert_dyn() ) ;
	if (inFieldID==__id_transformPoint) return hx::ToDouble( transformPoint_dyn() ) ;
	if (inFieldID==__id_translate) return hx::ToDouble( translate_dyn() ) ;
	if (inFieldID==__id_rotate) return hx::ToDouble( rotate_dyn() ) ;
	if (inFieldID==__id_scale) return hx::ToDouble( scale_dyn() ) ;
	if (inFieldID==__id_concat) return hx::ToDouble( concat_dyn() ) ;
	if (inFieldID==__id_mult) return hx::ToDouble( mult_dyn() ) ;
	return super::__INumField(inFieldID);
}

Dynamic Matrix_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"a",sizeof(wchar_t)*1) ) { a=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"b",sizeof(wchar_t)*1) ) { b=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"c",sizeof(wchar_t)*1) ) { c=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"d",sizeof(wchar_t)*1) ) { d=inValue.Cast< double >(); return inValue; }
		break;
	case 2:
		if (!memcmp(inName.__s,L"tx",sizeof(wchar_t)*2) ) { tx=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"ty",sizeof(wchar_t)*2) ) { ty=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Matrix_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"a",1));
	outFields->push(HX_STRING(L"b",1));
	outFields->push(HX_STRING(L"c",1));
	outFields->push(HX_STRING(L"d",1));
	outFields->push(HX_STRING(L"tx",2));
	outFields->push(HX_STRING(L"ty",2));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"a",1),
	HX_STRING(L"b",1),
	HX_STRING(L"c",1),
	HX_STRING(L"d",1),
	HX_STRING(L"tx",2),
	HX_STRING(L"ty",2),
	HX_STRING(L"clone",5),
	HX_STRING(L"createGradientBox",17),
	HX_STRING(L"setRotation",11),
	HX_STRING(L"identity",8),
	HX_STRING(L"invert",6),
	HX_STRING(L"transformPoint",14),
	HX_STRING(L"translate",9),
	HX_STRING(L"rotate",6),
	HX_STRING(L"scale",5),
	HX_STRING(L"concat",6),
	HX_STRING(L"mult",4),
	String(null()) };

static void sMarkStatics() {
};

Class Matrix_obj::__mClass;

void Matrix_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.geom.Matrix",15), hx::TCanCast< Matrix_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Matrix_obj::__boot()
{
}

} // end namespace nme
} // end namespace geom
