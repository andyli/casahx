#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_org_casalib_math_Percent
#include <org/casalib/math/Percent.h>
#endif
#ifndef INCLUDED_org_casalib_util_NumberUtil
#include <org/casalib/util/NumberUtil.h>
#endif
namespace org{
namespace casalib{
namespace util{

Void NumberUtil_obj::__construct()
{
	return null();
}

NumberUtil_obj::~NumberUtil_obj() { }

Dynamic NumberUtil_obj::__CreateEmpty() { return  new NumberUtil_obj; }
hx::ObjectPtr< NumberUtil_obj > NumberUtil_obj::__new()
{  hx::ObjectPtr< NumberUtil_obj > result = new NumberUtil_obj();
	result->__construct();
	return result;}

Dynamic NumberUtil_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NumberUtil_obj > result = new NumberUtil_obj();
	result->__construct();
	return result;}

bool NumberUtil_obj::isEqual( double val1,double val2,Dynamic __o_precision){
double precision = __o_precision.Default(0);
{
		__SAFE_POINT
		return (::Math_obj::abs((val1 - val2)) <= ::Math_obj::abs(precision));
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(NumberUtil_obj,isEqual,return )

double NumberUtil_obj::min( Dynamic val1,Dynamic val2){
	__SAFE_POINT
	if ((bool((bool((val1 == ::Math_obj::NaN)) && bool((val2 == ::Math_obj::NaN)))) || bool((bool((val1 == null())) && bool((val2 == null()))))))
		return ::Math_obj::NaN;
	if ((bool((val1 == null())) || bool((val2 == null()))))
		return ((val2 == null())) ? Dynamic( val1 ) : Dynamic( val2 );
	if ((bool((val1 == ::Math_obj::NaN)) || bool((val2 == ::Math_obj::NaN))))
		return (val2 == ::Math_obj::NaN) ? Dynamic( val1 ) : Dynamic( val2 );
	if ((bool(!::Std_obj::is(val1,hx::ClassOf< ::Float >())) || bool(!::Std_obj::is(val2,hx::ClassOf< ::Float >()))))
		return ::Std_obj::is(val1,hx::ClassOf< ::Float >()) ? Dynamic( val1 ) : Dynamic( val2 );
	return ::Math_obj::min(val1,val2);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(NumberUtil_obj,min,return )

double NumberUtil_obj::max( Dynamic val1,Dynamic val2){
	__SAFE_POINT
	if ((bool((bool((val1 == ::Math_obj::NaN)) && bool((val2 == ::Math_obj::NaN)))) || bool((bool((val1 == null())) && bool((val2 == null()))))))
		return ::Math_obj::NaN;
	if ((bool((val1 == null())) || bool((val2 == null()))))
		return ((val2 == null())) ? Dynamic( val1 ) : Dynamic( val2 );
	if ((bool((val1 == ::Math_obj::NaN)) || bool((val2 == ::Math_obj::NaN))))
		return ((val2 == ::Math_obj::NaN)) ? Dynamic( val1 ) : Dynamic( val2 );
	if ((bool(!::Std_obj::is(val1,hx::ClassOf< ::Float >())) || bool(!::Std_obj::is(val2,hx::ClassOf< ::Float >()))))
		return ::Std_obj::is(val1,hx::ClassOf< ::Float >()) ? Dynamic( val1 ) : Dynamic( val2 );
	return ::Math_obj::max(val1,val2);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(NumberUtil_obj,max,return )

double NumberUtil_obj::randomWithinRange( double min,double max){
	__SAFE_POINT
	return (min + ((::Math_obj::random() * ((max - min)))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(NumberUtil_obj,randomWithinRange,return )

int NumberUtil_obj::randomIntegerWithinRange( int min,int max){
	__SAFE_POINT
	return ::Math_obj::round(::org::casalib::util::NumberUtil_obj::randomWithinRange(min,max));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(NumberUtil_obj,randomIntegerWithinRange,return )

bool NumberUtil_obj::isEven( int value){
	return (((int(value) & int(1))) == 0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(NumberUtil_obj,isEven,return )

bool NumberUtil_obj::isOdd( int value){
	__SAFE_POINT
	return !::org::casalib::util::NumberUtil_obj::isEven(value);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(NumberUtil_obj,isOdd,return )

bool NumberUtil_obj::isInteger( double value){
	return ((hx::Mod(value,1)) == 0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(NumberUtil_obj,isInteger,return )

bool NumberUtil_obj::isPrime( int value){
	__SAFE_POINT
	if ((bool((value == 1)) || bool((value == 2))))
		return true;
	if (::org::casalib::util::NumberUtil_obj::isEven(value))
		return false;
	double s = ::Math_obj::sqrt(value);
	{
		int _g1 = 3;
		int _g = ::Std_obj::toInt(s);
		while((_g1 < _g)){
			__SAFE_POINT
			int i = _g1++;
			if ((hx::Mod(value,i) == 0))
				return false;
		}
	}
	return true;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(NumberUtil_obj,isPrime,return )

double NumberUtil_obj::roundDecimalToPlace( double value,double place){
	__SAFE_POINT
	double p = ::Math_obj::pow(10,place);
	return (double(::Math_obj::round((value * p))) / double(p));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(NumberUtil_obj,roundDecimalToPlace,return )

int NumberUtil_obj::loopIndex( int index,int length){
	if ((index < 0))
		index = (length + hx::Mod(index,length));
	if ((index >= length))
		return hx::Mod(index,length);
	return index;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(NumberUtil_obj,loopIndex,return )

bool NumberUtil_obj::isBetween( double value,double firstValue,double secondValue){
	__SAFE_POINT
	return !((bool((value < ::Math_obj::min(firstValue,secondValue))) || bool((value > ::Math_obj::max(firstValue,secondValue)))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(NumberUtil_obj,isBetween,return )

double NumberUtil_obj::constrain( double value,double firstValue,double secondValue){
	__SAFE_POINT
	return ::Math_obj::min(::Math_obj::max(value,::Math_obj::min(firstValue,secondValue)),::Math_obj::max(firstValue,secondValue));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(NumberUtil_obj,constrain,return )

Array< Dynamic > NumberUtil_obj::createStepsBetween( double begin,double end,double steps){
	__SAFE_POINT
	steps++;
	int i = 0;
	Array< Dynamic > stepsBetween = Array_obj< Dynamic >::__new();
	double increment = (double(((end - begin))) / double(steps));
	while((++i < steps))stepsBetween->push((((i * increment)) + begin));
	return stepsBetween;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(NumberUtil_obj,createStepsBetween,return )

double NumberUtil_obj::interpolate( ::org::casalib::math::Percent amount,double minimum,double maximum){
	__SAFE_POINT
	return (minimum + (((maximum - minimum)) * amount->getDecimalPercentage()));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(NumberUtil_obj,interpolate,return )

::org::casalib::math::Percent NumberUtil_obj::normalize( double value,double minimum,double maximum){
	return ::org::casalib::math::Percent_obj::__new((double(((value - minimum))) / double(((maximum - minimum)))),null());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(NumberUtil_obj,normalize,return )

double NumberUtil_obj::map( double value,double min1,double max1,double min2,double max2){
	return (min2 + (((max2 - min2)) * ((double(((value - min1))) / double(((max1 - min1)))))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(NumberUtil_obj,map,return )

double NumberUtil_obj::getWeightedAverage( double value,double dest,double n){
	return (value + (double(((dest - value))) / double(n)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(NumberUtil_obj,getWeightedAverage,return )

::String NumberUtil_obj::format( double value,int minLength,::String thouDelim,::String fillChar){
	__SAFE_POINT
	::String num = ::Std_obj::string(value);
	int len = num.length;
	if ((thouDelim != null())){
		Array< Dynamic > numSplit = num.split(HX_STRING(L"",0));
		int counter = 3;
		int i = numSplit->length;
		while((--i > 0)){
			__SAFE_POINT
			counter--;
			if ((counter == 0)){
				counter = 3;
				numSplit->insert(i,thouDelim);
			}
		}
		num = numSplit->join(HX_STRING(L"",0));
	}
	if ((minLength != 0)){
		if ((len < minLength)){
			hx::SubEq(minLength,len);
			::String addChar = ((fillChar == null())) ? ::String( HX_STRING(L"0",1) ) : ::String( fillChar );
			while((minLength-- > 0))num = (addChar + num);
		}
	}
	return num;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(NumberUtil_obj,format,return )

::String NumberUtil_obj::getOrdinalSuffix( int value){
	if ((bool((value >= 10)) && bool((value <= 20))))
		return HX_STRING(L"th",2);
	switch( (int)(hx::Mod(value,10))){
		case 0: case 4: case 5: case 6: case 7: case 8: case 9: {
			return HX_STRING(L"th",2);
		}
		;break;
		case 3: {
			return HX_STRING(L"rd",2);
		}
		;break;
		case 2: {
			return HX_STRING(L"nd",2);
		}
		;break;
		case 1: {
			return HX_STRING(L"st",2);
		}
		;break;
		default: {
			return HX_STRING(L"",0);
		}
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(NumberUtil_obj,getOrdinalSuffix,return )

::String NumberUtil_obj::addLeadingZero( double value){
	__SAFE_POINT
	return ((value < 10)) ? ::String( (HX_STRING(L"0",1) + value) ) : ::String( ::Std_obj::string(value) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(NumberUtil_obj,addLeadingZero,return )


NumberUtil_obj::NumberUtil_obj()
{
}

void NumberUtil_obj::__Mark()
{
}

Dynamic NumberUtil_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"min",sizeof(wchar_t)*3) ) { return min_dyn(); }
		if (!memcmp(inName.__s,L"max",sizeof(wchar_t)*3) ) { return max_dyn(); }
		if (!memcmp(inName.__s,L"map",sizeof(wchar_t)*3) ) { return map_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"isOdd",sizeof(wchar_t)*5) ) { return isOdd_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"isEven",sizeof(wchar_t)*6) ) { return isEven_dyn(); }
		if (!memcmp(inName.__s,L"format",sizeof(wchar_t)*6) ) { return format_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"isEqual",sizeof(wchar_t)*7) ) { return isEqual_dyn(); }
		if (!memcmp(inName.__s,L"isPrime",sizeof(wchar_t)*7) ) { return isPrime_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"isInteger",sizeof(wchar_t)*9) ) { return isInteger_dyn(); }
		if (!memcmp(inName.__s,L"loopIndex",sizeof(wchar_t)*9) ) { return loopIndex_dyn(); }
		if (!memcmp(inName.__s,L"isBetween",sizeof(wchar_t)*9) ) { return isBetween_dyn(); }
		if (!memcmp(inName.__s,L"constrain",sizeof(wchar_t)*9) ) { return constrain_dyn(); }
		if (!memcmp(inName.__s,L"normalize",sizeof(wchar_t)*9) ) { return normalize_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"interpolate",sizeof(wchar_t)*11) ) { return interpolate_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"addLeadingZero",sizeof(wchar_t)*14) ) { return addLeadingZero_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"getOrdinalSuffix",sizeof(wchar_t)*16) ) { return getOrdinalSuffix_dyn(); }
		break;
	case 17:
		if (!memcmp(inName.__s,L"randomWithinRange",sizeof(wchar_t)*17) ) { return randomWithinRange_dyn(); }
		break;
	case 18:
		if (!memcmp(inName.__s,L"createStepsBetween",sizeof(wchar_t)*18) ) { return createStepsBetween_dyn(); }
		if (!memcmp(inName.__s,L"getWeightedAverage",sizeof(wchar_t)*18) ) { return getWeightedAverage_dyn(); }
		break;
	case 19:
		if (!memcmp(inName.__s,L"roundDecimalToPlace",sizeof(wchar_t)*19) ) { return roundDecimalToPlace_dyn(); }
		break;
	case 24:
		if (!memcmp(inName.__s,L"randomIntegerWithinRange",sizeof(wchar_t)*24) ) { return randomIntegerWithinRange_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic NumberUtil_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void NumberUtil_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"isEqual",7),
	HX_STRING(L"min",3),
	HX_STRING(L"max",3),
	HX_STRING(L"randomWithinRange",17),
	HX_STRING(L"randomIntegerWithinRange",24),
	HX_STRING(L"isEven",6),
	HX_STRING(L"isOdd",5),
	HX_STRING(L"isInteger",9),
	HX_STRING(L"isPrime",7),
	HX_STRING(L"roundDecimalToPlace",19),
	HX_STRING(L"loopIndex",9),
	HX_STRING(L"isBetween",9),
	HX_STRING(L"constrain",9),
	HX_STRING(L"createStepsBetween",18),
	HX_STRING(L"interpolate",11),
	HX_STRING(L"normalize",9),
	HX_STRING(L"map",3),
	HX_STRING(L"getWeightedAverage",18),
	HX_STRING(L"format",6),
	HX_STRING(L"getOrdinalSuffix",16),
	HX_STRING(L"addLeadingZero",14),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
};

Class NumberUtil_obj::__mClass;

void NumberUtil_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"org.casalib.util.NumberUtil",27), hx::TCanCast< NumberUtil_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void NumberUtil_obj::__boot()
{
}

} // end namespace org
} // end namespace casalib
} // end namespace util
