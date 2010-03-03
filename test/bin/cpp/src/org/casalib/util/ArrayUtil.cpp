#include <hxcpp.h>

#ifndef INCLUDED_IntIter
#include <IntIter.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_org_casalib_util_ArrayUtil
#include <org/casalib/util/ArrayUtil.h>
#endif
#ifndef INCLUDED_org_casalib_util_NumberUtil
#include <org/casalib/util/NumberUtil.h>
#endif
namespace org{
namespace casalib{
namespace util{

Void ArrayUtil_obj::__construct()
{
	return null();
}

ArrayUtil_obj::~ArrayUtil_obj() { }

Dynamic ArrayUtil_obj::__CreateEmpty() { return  new ArrayUtil_obj; }
hx::ObjectPtr< ArrayUtil_obj > ArrayUtil_obj::__new()
{  hx::ObjectPtr< ArrayUtil_obj > result = new ArrayUtil_obj();
	result->__construct();
	return result;}

Dynamic ArrayUtil_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ArrayUtil_obj > result = new ArrayUtil_obj();
	result->__construct();
	return result;}

int ArrayUtil_obj::indexOf( Array< Dynamic > inArray,Dynamic match,Dynamic __o_fromIndex){
int fromIndex = __o_fromIndex.Default(0);
{
		int i = (fromIndex - 1);
		while((++i < inArray->length)){
			__SAFE_POINT
			if ((inArray->__get(i) == match))
				return i;
		}
		return -1;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ArrayUtil_obj,indexOf,return )

int ArrayUtil_obj::lastIndexOf( Array< Dynamic > inArray,Dynamic match,Dynamic fromIndex){
	__SAFE_POINT
	int i;
	if ((fromIndex == null())){
		i = inArray->length;
	}
	else{
		i = ::Math_obj::round(::Math_obj::min(inArray->length,(fromIndex + 1)));
	}
	while((--i > 0)){
		__SAFE_POINT
		if ((inArray->__get(i) == match))
			return i;
	}
	return -1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ArrayUtil_obj,lastIndexOf,return )

Array< Dynamic > ArrayUtil_obj::filter( Array< Dynamic > inArray,Dynamic callBack){
	__SAFE_POINT
	Array< Dynamic > newArray = Array_obj< Dynamic >::__new();
	::IntIter iter = ::IntIter_obj::__new(0,inArray->length);
	for(Dynamic __it = iter;  __it->__Field(HX_STRING(L"hasNext",7))(); ){
int i = __it->__Field(HX_STRING(L"next",4))();
		{
			if (callBack(inArray->__get(i),i,inArray)){
				newArray->push(inArray->__get(i));
			}
		}
;
		__SAFE_POINT
	}
	return newArray;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,filter,return )

Dynamic ArrayUtil_obj::getItemByKey( Array< Dynamic > inArray,::String key,Dynamic match){
	__SAFE_POINT
	{
		int _g = 0;
		while((_g < inArray->length)){
			__SAFE_POINT
			Dynamic item = inArray->__get(_g);
			++_g;
			Dynamic value = ((item == null())) ? Dynamic( null() ) : Dynamic( item->__Field(key) );
			if ((value == match))
				return item;
		}
	}
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ArrayUtil_obj,getItemByKey,return )

Array< Dynamic > ArrayUtil_obj::getItemsByKey( Array< Dynamic > inArray,::String key,Dynamic match){
	__SAFE_POINT
	Array< Dynamic > t = Array_obj< Dynamic >::__new();
	{
		int _g = 0;
		while((_g < inArray->length)){
			__SAFE_POINT
			Dynamic item = inArray->__get(_g);
			++_g;
			Dynamic value = ((item == null())) ? Dynamic( null() ) : Dynamic( item->__Field(key) );
			if ((value == match))
				t->push(item);
		}
	}
	return t;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ArrayUtil_obj,getItemsByKey,return )

Dynamic ArrayUtil_obj::getItemByType( Array< Dynamic > inArray,::Class type){
	__SAFE_POINT
	{
		int _g = 0;
		while((_g < inArray->length)){
			__SAFE_POINT
			Dynamic item = inArray->__get(_g);
			++_g;
			if (::Std_obj::is(item,type))
				return item;
		}
	}
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,getItemByType,return )

Array< Dynamic > ArrayUtil_obj::getItemsByType( Array< Dynamic > inArray,::Class type){
	__SAFE_POINT
	Array< Dynamic > t = Array_obj< Dynamic >::__new();
	{
		int _g = 0;
		while((_g < inArray->length)){
			__SAFE_POINT
			Dynamic item = inArray->__get(_g);
			++_g;
			if (::Std_obj::is(item,type))
				t->push(item);
		}
	}
	return t;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,getItemsByType,return )

bool ArrayUtil_obj::equals( Array< Dynamic > first,Array< Dynamic > second){
	int i = first->length;
	bool result = true;
	if ((i != second->length)){
		result = false;
	}
	else{
		while((i-- > 0)){
			__SAFE_POINT
			if ((first->__get(i) != second->__get(i))){
				result = false;
				break;
			}
		}
	}
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,equals,return )

bool ArrayUtil_obj::addItemsAt( Array< Dynamic > tarArray,Array< Dynamic > items,Dynamic __o_index){
int index = __o_index.Default(2147483647);
{
		__SAFE_POINT
		if ((items->length == 0)){
			return false;
		}
		else{
			int i = -1;
			while((++i < items->length)){
				__SAFE_POINT
				tarArray->insert(index++,items->__get(i));
			}
			return true;
		}
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ArrayUtil_obj,addItemsAt,return )

Array< Dynamic > ArrayUtil_obj::removeDuplicates( Array< Dynamic > inArray){
	__SAFE_POINT
	struct _Function_1_1{
		inline static Array< Dynamic > Block( Array< Dynamic > &inArray)/* DEF (ret block)(not intern) */{
			Array< Dynamic > newArray = Array_obj< Dynamic >::__new();
			::IntIter iter = ::IntIter_obj::__new(0,inArray->length);
			for(Dynamic __it = iter;  __it->__Field(HX_STRING(L"hasNext",7))(); ){
int i = __it->__Field(HX_STRING(L"next",4))();
				{
					if (::org::casalib::util::ArrayUtil_obj::_removeDuplicatesFilter(inArray->__get(i),i,inArray)){
						newArray->push(inArray->__get(i));
					}
				}
;
				__SAFE_POINT
			}
			return newArray;
		}
	};
	return _Function_1_1::Block(inArray);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ArrayUtil_obj,removeDuplicates,return )

bool ArrayUtil_obj::_removeDuplicatesFilter( Dynamic e,int i,Array< Dynamic > inArray){
	__SAFE_POINT
	return ((i == 0)) ? bool( true ) : bool( (::org::casalib::util::ArrayUtil_obj::lastIndexOf(inArray,e,(i - 1)) == -1) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ArrayUtil_obj,_removeDuplicatesFilter,return )

int ArrayUtil_obj::removeItem( Array< Dynamic > tarArray,Dynamic item){
	__SAFE_POINT
	int i = ::org::casalib::util::ArrayUtil_obj::indexOf(tarArray,item,null());
	int f = 0;
	while((i != -1)){
		__SAFE_POINT
		tarArray->splice(i,1);
		i = ::org::casalib::util::ArrayUtil_obj::indexOf(tarArray,item,i);
		f++;
	}
	return f;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,removeItem,return )

bool ArrayUtil_obj::removeItems( Array< Dynamic > tarArray,Array< Dynamic > items){
	__SAFE_POINT
	bool removed = false;
	int l = tarArray->length;
	while((l-- > 0)){
		__SAFE_POINT
		if ((::org::casalib::util::ArrayUtil_obj::indexOf(items,tarArray->__get(l),null()) > -1)){
			tarArray->splice(l,1);
			removed = true;
		}
	}
	return removed;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,removeItems,return )

bool ArrayUtil_obj::retainItems( Array< Dynamic > tarArray,Array< Dynamic > items){
	__SAFE_POINT
	bool removed = false;
	int l = tarArray->length;
	while((l-- > 0)){
		__SAFE_POINT
		if ((::org::casalib::util::ArrayUtil_obj::indexOf(items,tarArray->__get(l),null()) == -1)){
			tarArray->splice(l,1);
			removed = true;
		}
	}
	return removed;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,retainItems,return )

int ArrayUtil_obj::contains( Array< Dynamic > inArray,Dynamic item){
	__SAFE_POINT
	int i = ::org::casalib::util::ArrayUtil_obj::indexOf(inArray,item,0);
	int t = 0;
	while((i != -1)){
		__SAFE_POINT
		i = ::org::casalib::util::ArrayUtil_obj::indexOf(inArray,item,(i + 1));
		t++;
	}
	return t;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,contains,return )

bool ArrayUtil_obj::containsAll( Array< Dynamic > inArray,Array< Dynamic > items){
	__SAFE_POINT
	int l = items->length;
	while((l-- > 0))if ((::org::casalib::util::ArrayUtil_obj::indexOf(inArray,items->__get(l),null()) == -1))
		return false;
	return true;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,containsAll,return )

bool ArrayUtil_obj::containsAny( Array< Dynamic > inArray,Array< Dynamic > items){
	__SAFE_POINT
	int l = items->length;
	while((l-- > 0))if ((::org::casalib::util::ArrayUtil_obj::indexOf(inArray,items->__get(l),null()) > -1))
		return true;
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(ArrayUtil_obj,containsAny,return )

int ArrayUtil_obj::getIndexOfDifference( Array< Dynamic > first,Array< Dynamic > second,Dynamic __o_fromIndex){
int fromIndex = __o_fromIndex.Default(0);
{
		int i = (fromIndex - 1);
		while((++i < first->length))if ((first->__get(i) != second->__get(i)))
			return i;
		return -1;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(ArrayUtil_obj,getIndexOfDifference,return )

Array< Dynamic > ArrayUtil_obj::randomize( Array< Dynamic > inArray){
	__SAFE_POINT
	Array< Dynamic > t = Array_obj< Dynamic >::__new();
	Array< Dynamic > c = inArray->copy();
	while((c->length > 0))t->push(c->splice(::org::casalib::util::NumberUtil_obj::randomIntegerWithinRange(0,(c->length - 1)),1));
	return t;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ArrayUtil_obj,randomize,return )

double ArrayUtil_obj::sum( Array< Dynamic > inArray){
	double t = 0;
	int l = inArray->length;
	while((l-- > 0))hx::AddEq(t,inArray->__get(l));
	return t;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ArrayUtil_obj,sum,return )

double ArrayUtil_obj::average( Array< Dynamic > inArray){
	__SAFE_POINT
	if ((inArray->length == 0))
		return 0;
	return (double(::org::casalib::util::ArrayUtil_obj::sum(inArray)) / double(inArray->length));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ArrayUtil_obj,average,return )

double ArrayUtil_obj::getLowestValue( Array< Dynamic > inArray){
	__SAFE_POINT
	double lowest = inArray->__get(0);
	{
		int _g = 0;
		while((_g < inArray->length)){
			__SAFE_POINT
			Dynamic i = inArray->__get(_g);
			++_g;
			lowest = ::org::casalib::util::NumberUtil_obj::min(i,lowest);
		}
	}
	return lowest;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ArrayUtil_obj,getLowestValue,return )

double ArrayUtil_obj::getHighestValue( Array< Dynamic > inArray){
	__SAFE_POINT
	double lowest = inArray->__get(0);
	{
		int _g = 0;
		while((_g < inArray->length)){
			__SAFE_POINT
			Dynamic i = inArray->__get(_g);
			++_g;
			lowest = ::org::casalib::util::NumberUtil_obj::max(i,lowest);
		}
	}
	return lowest;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ArrayUtil_obj,getHighestValue,return )


ArrayUtil_obj::ArrayUtil_obj()
{
}

void ArrayUtil_obj::__Mark()
{
}

Dynamic ArrayUtil_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"sum",sizeof(wchar_t)*3) ) { return sum_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"filter",sizeof(wchar_t)*6) ) { return filter_dyn(); }
		if (!memcmp(inName.__s,L"equals",sizeof(wchar_t)*6) ) { return equals_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"indexOf",sizeof(wchar_t)*7) ) { return indexOf_dyn(); }
		if (!memcmp(inName.__s,L"average",sizeof(wchar_t)*7) ) { return average_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"contains",sizeof(wchar_t)*8) ) { return contains_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"randomize",sizeof(wchar_t)*9) ) { return randomize_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"addItemsAt",sizeof(wchar_t)*10) ) { return addItemsAt_dyn(); }
		if (!memcmp(inName.__s,L"removeItem",sizeof(wchar_t)*10) ) { return removeItem_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"lastIndexOf",sizeof(wchar_t)*11) ) { return lastIndexOf_dyn(); }
		if (!memcmp(inName.__s,L"removeItems",sizeof(wchar_t)*11) ) { return removeItems_dyn(); }
		if (!memcmp(inName.__s,L"retainItems",sizeof(wchar_t)*11) ) { return retainItems_dyn(); }
		if (!memcmp(inName.__s,L"containsAll",sizeof(wchar_t)*11) ) { return containsAll_dyn(); }
		if (!memcmp(inName.__s,L"containsAny",sizeof(wchar_t)*11) ) { return containsAny_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"getItemByKey",sizeof(wchar_t)*12) ) { return getItemByKey_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"getItemsByKey",sizeof(wchar_t)*13) ) { return getItemsByKey_dyn(); }
		if (!memcmp(inName.__s,L"getItemByType",sizeof(wchar_t)*13) ) { return getItemByType_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"getItemsByType",sizeof(wchar_t)*14) ) { return getItemsByType_dyn(); }
		if (!memcmp(inName.__s,L"getLowestValue",sizeof(wchar_t)*14) ) { return getLowestValue_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"getHighestValue",sizeof(wchar_t)*15) ) { return getHighestValue_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"removeDuplicates",sizeof(wchar_t)*16) ) { return removeDuplicates_dyn(); }
		break;
	case 20:
		if (!memcmp(inName.__s,L"getIndexOfDifference",sizeof(wchar_t)*20) ) { return getIndexOfDifference_dyn(); }
		break;
	case 23:
		if (!memcmp(inName.__s,L"_removeDuplicatesFilter",sizeof(wchar_t)*23) ) { return _removeDuplicatesFilter_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic ArrayUtil_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void ArrayUtil_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"indexOf",7),
	HX_STRING(L"lastIndexOf",11),
	HX_STRING(L"filter",6),
	HX_STRING(L"getItemByKey",12),
	HX_STRING(L"getItemsByKey",13),
	HX_STRING(L"getItemByType",13),
	HX_STRING(L"getItemsByType",14),
	HX_STRING(L"equals",6),
	HX_STRING(L"addItemsAt",10),
	HX_STRING(L"removeDuplicates",16),
	HX_STRING(L"_removeDuplicatesFilter",23),
	HX_STRING(L"removeItem",10),
	HX_STRING(L"removeItems",11),
	HX_STRING(L"retainItems",11),
	HX_STRING(L"contains",8),
	HX_STRING(L"containsAll",11),
	HX_STRING(L"containsAny",11),
	HX_STRING(L"getIndexOfDifference",20),
	HX_STRING(L"randomize",9),
	HX_STRING(L"sum",3),
	HX_STRING(L"average",7),
	HX_STRING(L"getLowestValue",14),
	HX_STRING(L"getHighestValue",15),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
};

Class ArrayUtil_obj::__mClass;

void ArrayUtil_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"org.casalib.util.ArrayUtil",26), hx::TCanCast< ArrayUtil_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ArrayUtil_obj::__boot()
{
}

} // end namespace org
} // end namespace casalib
} // end namespace util
