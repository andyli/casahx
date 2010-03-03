#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_org_casalib_math_Percent
#include <org/casalib/math/Percent.h>
#endif
#ifndef INCLUDED_org_casalib_math_Range
#include <org/casalib/math/Range.h>
#endif
namespace org{
namespace casalib{
namespace math{

Void Range_obj::__construct(double start,double end)
{
{
	this->setRange(start,end);
}
;
	return null();
}

Range_obj::~Range_obj() { }

Dynamic Range_obj::__CreateEmpty() { return  new Range_obj; }
hx::ObjectPtr< Range_obj > Range_obj::__new(double start,double end)
{  hx::ObjectPtr< Range_obj > result = new Range_obj();
	result->__construct(start,end);
	return result;}

Dynamic Range_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Range_obj > result = new Range_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Range_obj::setRange( double start,double end){
{
		__SAFE_POINT
		this->setStart(start);
		this->setEnd(end);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Range_obj,setRange,(void))

double Range_obj::getStart( ){
	return this->_start;
}


HX_DEFINE_DYNAMIC_FUNC0(Range_obj,getStart,return )

double Range_obj::setStart( double value){
	this->_start = value;
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Range_obj,setStart,return )

double Range_obj::getEnd( ){
	return this->_end;
}


HX_DEFINE_DYNAMIC_FUNC0(Range_obj,getEnd,return )

double Range_obj::setEnd( double value){
	this->_end = value;
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Range_obj,setEnd,return )

double Range_obj::getMin( ){
	__SAFE_POINT
	return ::Math_obj::min(this->getStart(),this->getEnd());
}


HX_DEFINE_DYNAMIC_FUNC0(Range_obj,getMin,return )

double Range_obj::getMax( ){
	__SAFE_POINT
	return ::Math_obj::max(this->getStart(),this->getEnd());
}


HX_DEFINE_DYNAMIC_FUNC0(Range_obj,getMax,return )

bool Range_obj::isWithinRange( double value){
	__SAFE_POINT
	return ((bool((value <= this->getMax())) && bool((value >= this->getMin()))));
}


HX_DEFINE_DYNAMIC_FUNC1(Range_obj,isWithinRange,return )

double Range_obj::getValueOfPercent( ::org::casalib::math::Percent percent){
	__SAFE_POINT
	double min;
	double max;
	double val;
	::org::casalib::math::Percent per = percent->clone();
	if ((this->getStart() <= this->getEnd())){
		min = this->getStart();
		max = this->getEnd();
	}
	else{
		per->setDecimalPercentage((1 - per->getDecimalPercentage()));
		min = this->getEnd();
		max = this->getStart();
	}
	val = ((::Math_obj::abs((max - min)) * per->getDecimalPercentage()) + min);
	return val;
}


HX_DEFINE_DYNAMIC_FUNC1(Range_obj,getValueOfPercent,return )

::org::casalib::math::Percent Range_obj::getPercentOfValue( double value){
	__SAFE_POINT
	return ::org::casalib::math::Percent_obj::__new((double(((value - this->getMin()))) / double(((this->getMax() - this->getMin())))),null());
}


HX_DEFINE_DYNAMIC_FUNC1(Range_obj,getPercentOfValue,return )

bool Range_obj::equals( ::org::casalib::math::Range range){
	__SAFE_POINT
	return (bool((this->getStart() == range->getStart())) && bool((this->getEnd() == range->getEnd())));
}


HX_DEFINE_DYNAMIC_FUNC1(Range_obj,equals,return )

bool Range_obj::overlaps( ::org::casalib::math::Range range){
	__SAFE_POINT
	if ((bool(this->equals(range)) || bool((bool(this->contains(range)) || bool((bool(range->contains(this)) || bool((bool(this->isWithinRange(range->getStart())) || bool(this->isWithinRange(range->getEnd()))))))))))
		return true;
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(Range_obj,overlaps,return )

bool Range_obj::contains( ::org::casalib::math::Range range){
	__SAFE_POINT
	return (bool((this->getStart() <= range->getStart())) && bool((this->getEnd() >= range->getEnd())));
}


HX_DEFINE_DYNAMIC_FUNC1(Range_obj,contains,return )

::org::casalib::math::Range Range_obj::clone( ){
	__SAFE_POINT
	return ::org::casalib::math::Range_obj::__new(this->getStart(),this->getEnd());
}


HX_DEFINE_DYNAMIC_FUNC0(Range_obj,clone,return )


Range_obj::Range_obj()
{
}

void Range_obj::__Mark()
{
	hx::MarkMember(end);
	hx::MarkMember(max);
	hx::MarkMember(min);
	hx::MarkMember(start);
	hx::MarkMember(_end);
	hx::MarkMember(_start);
}

Dynamic Range_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"end",sizeof(wchar_t)*3) ) { return getEnd(); }
		if (!memcmp(inName.__s,L"max",sizeof(wchar_t)*3) ) { return getMax(); }
		if (!memcmp(inName.__s,L"min",sizeof(wchar_t)*3) ) { return getMin(); }
		break;
	case 4:
		if (!memcmp(inName.__s,L"_end",sizeof(wchar_t)*4) ) { return _end; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"start",sizeof(wchar_t)*5) ) { return getStart(); }
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"_start",sizeof(wchar_t)*6) ) { return _start; }
		if (!memcmp(inName.__s,L"getEnd",sizeof(wchar_t)*6) ) { return getEnd_dyn(); }
		if (!memcmp(inName.__s,L"setEnd",sizeof(wchar_t)*6) ) { return setEnd_dyn(); }
		if (!memcmp(inName.__s,L"getMin",sizeof(wchar_t)*6) ) { return getMin_dyn(); }
		if (!memcmp(inName.__s,L"getMax",sizeof(wchar_t)*6) ) { return getMax_dyn(); }
		if (!memcmp(inName.__s,L"equals",sizeof(wchar_t)*6) ) { return equals_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"setRange",sizeof(wchar_t)*8) ) { return setRange_dyn(); }
		if (!memcmp(inName.__s,L"getStart",sizeof(wchar_t)*8) ) { return getStart_dyn(); }
		if (!memcmp(inName.__s,L"setStart",sizeof(wchar_t)*8) ) { return setStart_dyn(); }
		if (!memcmp(inName.__s,L"overlaps",sizeof(wchar_t)*8) ) { return overlaps_dyn(); }
		if (!memcmp(inName.__s,L"contains",sizeof(wchar_t)*8) ) { return contains_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"isWithinRange",sizeof(wchar_t)*13) ) { return isWithinRange_dyn(); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"getValueOfPercent",sizeof(wchar_t)*17) ) { return getValueOfPercent_dyn(); }
		if (!memcmp(inName.__s,L"getPercentOfValue",sizeof(wchar_t)*17) ) { return getPercentOfValue_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Range_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"end",sizeof(wchar_t)*3) ) { return setEnd(inValue); }
		if (!memcmp(inName.__s,L"max",sizeof(wchar_t)*3) ) { max=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"min",sizeof(wchar_t)*3) ) { min=inValue.Cast< double >(); return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"_end",sizeof(wchar_t)*4) ) { _end=inValue.Cast< double >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"start",sizeof(wchar_t)*5) ) { return setStart(inValue); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"_start",sizeof(wchar_t)*6) ) { _start=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Range_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"end",3));
	outFields->push(HX_STRING(L"max",3));
	outFields->push(HX_STRING(L"min",3));
	outFields->push(HX_STRING(L"start",5));
	outFields->push(HX_STRING(L"_end",4));
	outFields->push(HX_STRING(L"_start",6));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"end",3),
	HX_STRING(L"max",3),
	HX_STRING(L"min",3),
	HX_STRING(L"start",5),
	HX_STRING(L"_end",4),
	HX_STRING(L"_start",6),
	HX_STRING(L"setRange",8),
	HX_STRING(L"getStart",8),
	HX_STRING(L"setStart",8),
	HX_STRING(L"getEnd",6),
	HX_STRING(L"setEnd",6),
	HX_STRING(L"getMin",6),
	HX_STRING(L"getMax",6),
	HX_STRING(L"isWithinRange",13),
	HX_STRING(L"getValueOfPercent",17),
	HX_STRING(L"getPercentOfValue",17),
	HX_STRING(L"equals",6),
	HX_STRING(L"overlaps",8),
	HX_STRING(L"contains",8),
	HX_STRING(L"clone",5),
	String(null()) };

static void sMarkStatics() {
};

Class Range_obj::__mClass;

void Range_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"org.casalib.math.Range",22), hx::TCanCast< Range_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Range_obj::__boot()
{
}

} // end namespace org
} // end namespace casalib
} // end namespace math
