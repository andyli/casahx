#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_org_casalib_math_Percent
#include <org/casalib/math/Percent.h>
#endif
namespace org{
namespace casalib{
namespace math{

Void Percent_obj::__construct(Dynamic __o_percentage,Dynamic __o_isDecimalPercentage)
{
double percentage = __o_percentage.Default(0);
bool isDecimalPercentage = __o_isDecimalPercentage.Default(true);
{
	if (isDecimalPercentage){
		this->setDecimalPercentage(percentage);
	}
	else{
		this->setPercentage(percentage);
	}
}
;
	return null();
}

Percent_obj::~Percent_obj() { }

Dynamic Percent_obj::__CreateEmpty() { return  new Percent_obj; }
hx::ObjectPtr< Percent_obj > Percent_obj::__new(Dynamic __o_percentage,Dynamic __o_isDecimalPercentage)
{  hx::ObjectPtr< Percent_obj > result = new Percent_obj();
	result->__construct(__o_percentage,__o_isDecimalPercentage);
	return result;}

Dynamic Percent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Percent_obj > result = new Percent_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

double Percent_obj::getPercentage( ){
	return (100 * this->_percent);
}


HX_DEFINE_DYNAMIC_FUNC0(Percent_obj,getPercentage,return )

double Percent_obj::setPercentage( double percent){
	this->_percent = (percent * .01);
	return percent;
}


HX_DEFINE_DYNAMIC_FUNC1(Percent_obj,setPercentage,return )

double Percent_obj::getDecimalPercentage( ){
	return this->_percent;
}


HX_DEFINE_DYNAMIC_FUNC0(Percent_obj,getDecimalPercentage,return )

double Percent_obj::setDecimalPercentage( double percent){
	this->_percent = percent;
	return percent;
}


HX_DEFINE_DYNAMIC_FUNC1(Percent_obj,setDecimalPercentage,return )

bool Percent_obj::equals( ::org::casalib::math::Percent percent){
	__SAFE_POINT
	return (this->getDecimalPercentage() == percent->getDecimalPercentage());
}


HX_DEFINE_DYNAMIC_FUNC1(Percent_obj,equals,return )

::org::casalib::math::Percent Percent_obj::clone( ){
	__SAFE_POINT
	return ::org::casalib::math::Percent_obj::__new(this->getDecimalPercentage(),null());
}


HX_DEFINE_DYNAMIC_FUNC0(Percent_obj,clone,return )

double Percent_obj::valueOf( ){
	__SAFE_POINT
	return this->getDecimalPercentage();
}


HX_DEFINE_DYNAMIC_FUNC0(Percent_obj,valueOf,return )

::String Percent_obj::toString( ){
	__SAFE_POINT
	return ::Std_obj::string(this->getDecimalPercentage());
}


HX_DEFINE_DYNAMIC_FUNC0(Percent_obj,toString,return )


Percent_obj::Percent_obj()
{
}

void Percent_obj::__Mark()
{
	hx::MarkMember(decimalPercentage);
	hx::MarkMember(percentage);
	hx::MarkMember(_percent);
}

Dynamic Percent_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"equals",sizeof(wchar_t)*6) ) { return equals_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"valueOf",sizeof(wchar_t)*7) ) { return valueOf_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"_percent",sizeof(wchar_t)*8) ) { return _percent; }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"percentage",sizeof(wchar_t)*10) ) { return getPercentage(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"getPercentage",sizeof(wchar_t)*13) ) { return getPercentage_dyn(); }
		if (!memcmp(inName.__s,L"setPercentage",sizeof(wchar_t)*13) ) { return setPercentage_dyn(); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"decimalPercentage",sizeof(wchar_t)*17) ) { return getDecimalPercentage(); }
		break;
	case 20:
		if (!memcmp(inName.__s,L"getDecimalPercentage",sizeof(wchar_t)*20) ) { return getDecimalPercentage_dyn(); }
		if (!memcmp(inName.__s,L"setDecimalPercentage",sizeof(wchar_t)*20) ) { return setDecimalPercentage_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Percent_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (!memcmp(inName.__s,L"_percent",sizeof(wchar_t)*8) ) { _percent=inValue.Cast< double >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"percentage",sizeof(wchar_t)*10) ) { return setPercentage(inValue); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"decimalPercentage",sizeof(wchar_t)*17) ) { return setDecimalPercentage(inValue); }
	}
	return super::__SetField(inName,inValue);
}

void Percent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"decimalPercentage",17));
	outFields->push(HX_STRING(L"percentage",10));
	outFields->push(HX_STRING(L"_percent",8));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"decimalPercentage",17),
	HX_STRING(L"percentage",10),
	HX_STRING(L"_percent",8),
	HX_STRING(L"getPercentage",13),
	HX_STRING(L"setPercentage",13),
	HX_STRING(L"getDecimalPercentage",20),
	HX_STRING(L"setDecimalPercentage",20),
	HX_STRING(L"equals",6),
	HX_STRING(L"clone",5),
	HX_STRING(L"valueOf",7),
	HX_STRING(L"toString",8),
	String(null()) };

static void sMarkStatics() {
};

Class Percent_obj::__mClass;

void Percent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"org.casalib.math.Percent",24), hx::TCanCast< Percent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Percent_obj::__boot()
{
}

} // end namespace org
} // end namespace casalib
} // end namespace math
