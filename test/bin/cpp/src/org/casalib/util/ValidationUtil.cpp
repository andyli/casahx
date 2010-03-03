#include <hxcpp.h>

#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_org_casalib_util_ArrayUtil
#include <org/casalib/util/ArrayUtil.h>
#endif
#ifndef INCLUDED_org_casalib_util_ValidationUtil
#include <org/casalib/util/ValidationUtil.h>
#endif
namespace org{
namespace casalib{
namespace util{

Void ValidationUtil_obj::__construct()
{
	return null();
}

ValidationUtil_obj::~ValidationUtil_obj() { }

Dynamic ValidationUtil_obj::__CreateEmpty() { return  new ValidationUtil_obj; }
hx::ObjectPtr< ValidationUtil_obj > ValidationUtil_obj::__new()
{  hx::ObjectPtr< ValidationUtil_obj > result = new ValidationUtil_obj();
	result->__construct();
	return result;}

Dynamic ValidationUtil_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ValidationUtil_obj > result = new ValidationUtil_obj();
	result->__construct();
	return result;}

bool ValidationUtil_obj::isEmail( ::String email){
	__SAFE_POINT
	::EReg pattern = ::EReg_obj::__new(HX_STRING(L"^[\\w-\\.]{2,}@[\xC5"L"\xC4"L"\xD6"L"\xE5"L"\xE4"L"\xF6"L"\\w-\\.]{2,}\\.[a-z]{2,6}$",43),HX_STRING(L"i",1));
	return pattern->match(email);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ValidationUtil_obj,isEmail,return )

bool ValidationUtil_obj::isUsaStateAbbreviation( ::String state){
	__SAFE_POINT
	Array< Dynamic > states = Array_obj< ::String >::__new().Add(HX_STRING(L"ak",2)).Add(HX_STRING(L"al",2)).Add(HX_STRING(L"ar",2)).Add(HX_STRING(L"az",2)).Add(HX_STRING(L"ca",2)).Add(HX_STRING(L"co",2)).Add(HX_STRING(L"ct",2)).Add(HX_STRING(L"dc",2)).Add(HX_STRING(L"de",2)).Add(HX_STRING(L"fl",2)).Add(HX_STRING(L"ga",2)).Add(HX_STRING(L"hi",2)).Add(HX_STRING(L"ia",2)).Add(HX_STRING(L"id",2)).Add(HX_STRING(L"il",2)).Add(HX_STRING(L"in",2)).Add(HX_STRING(L"ks",2)).Add(HX_STRING(L"ky",2)).Add(HX_STRING(L"la",2)).Add(HX_STRING(L"ma",2)).Add(HX_STRING(L"md",2)).Add(HX_STRING(L"me",2)).Add(HX_STRING(L"mi",2)).Add(HX_STRING(L"mn",2)).Add(HX_STRING(L"mo",2)).Add(HX_STRING(L"ms",2)).Add(HX_STRING(L"mt",2)).Add(HX_STRING(L"nb",2)).Add(HX_STRING(L"nc",2)).Add(HX_STRING(L"nd",2)).Add(HX_STRING(L"nh",2)).Add(HX_STRING(L"nj",2)).Add(HX_STRING(L"nm",2)).Add(HX_STRING(L"nv",2)).Add(HX_STRING(L"ny",2)).Add(HX_STRING(L"oh",2)).Add(HX_STRING(L"ok",2)).Add(HX_STRING(L"or",2)).Add(HX_STRING(L"pa",2)).Add(HX_STRING(L"ri",2)).Add(HX_STRING(L"sc",2)).Add(HX_STRING(L"sd",2)).Add(HX_STRING(L"tn",2)).Add(HX_STRING(L"tx",2)).Add(HX_STRING(L"ut",2)).Add(HX_STRING(L"va",2)).Add(HX_STRING(L"vt",2)).Add(HX_STRING(L"wa",2)).Add(HX_STRING(L"wi",2)).Add(HX_STRING(L"wv",2)).Add(HX_STRING(L"wy",2));
	return (::org::casalib::util::ArrayUtil_obj::contains(states,state.toLowerCase()) == 1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ValidationUtil_obj,isUsaStateAbbreviation,return )

bool ValidationUtil_obj::isCreditCard( ::String cardNumber){
	__SAFE_POINT
	if ((bool((cardNumber.length < 7)) || bool((bool((cardNumber.length > 19)) || bool((::Std_obj::parseFloat(cardNumber) < 1000000))))))
		return false;
	double pre;
	double sum = 0;
	bool alt = true;
	int i = cardNumber.length;
	while((--i > -1)){
		__SAFE_POINT
		if (alt){
			hx::AddEq(sum,::Std_obj::parseFloat(cardNumber.substr(i,1)));
		}
		else{
			pre = (::Std_obj::parseFloat(cardNumber.substr(i,1)) * 2);
			hx::AddEq(sum,((pre > 8)) ? double( hx::SubEq(pre,9) ) : double( pre ));
		}
		alt = !alt;
	}
	return (hx::Mod(sum,10) == 0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ValidationUtil_obj,isCreditCard,return )

::String ValidationUtil_obj::getCreditCardProvider( ::String cardNumber){
	__SAFE_POINT
	if (!::org::casalib::util::ValidationUtil_obj::isCreditCard(cardNumber))
		return HX_STRING(L"invalid",7);
	if ((bool((cardNumber.length == 13)) || bool((bool((cardNumber.length == 16)) && bool((cardNumber.indexOf(HX_STRING(L"4",1),null()) == 0)))))){
		return HX_STRING(L"visa",4);
	}
	else{
		if ((bool((cardNumber.indexOf(HX_STRING(L"51",2),null()) == 0)) || bool((bool((cardNumber.indexOf(HX_STRING(L"52",2),null()) == 0)) || bool((bool((cardNumber.indexOf(HX_STRING(L"53",2),null()) == 0)) || bool((bool((cardNumber.indexOf(HX_STRING(L"54",2),null()) == 0)) || bool((bool((cardNumber.indexOf(HX_STRING(L"55",2),null()) == 0)) && bool((cardNumber.length == 16)))))))))))){
			return HX_STRING(L"mastercard",10);
		}
		else{
			if ((bool((cardNumber.length == 16)) && bool((cardNumber.indexOf(HX_STRING(L"6011",4),null()) == 0)))){
				return HX_STRING(L"discover",8);
			}
			else{
				if ((bool((cardNumber.indexOf(HX_STRING(L"34",2),null()) == 0)) || bool((bool((cardNumber.indexOf(HX_STRING(L"37",2),null()) == 0)) && bool((cardNumber.length == 15)))))){
					return HX_STRING(L"amex",4);
				}
				else{
					if ((bool((cardNumber.indexOf(HX_STRING(L"300",3),null()) == 0)) || bool((bool((cardNumber.indexOf(HX_STRING(L"301",3),null()) == 0)) || bool((bool((cardNumber.indexOf(HX_STRING(L"302",3),null()) == 0)) || bool((bool((cardNumber.indexOf(HX_STRING(L"303",3),null()) == 0)) || bool((bool((cardNumber.indexOf(HX_STRING(L"304",3),null()) == 0)) || bool((bool((cardNumber.indexOf(HX_STRING(L"305",3),null()) == 0)) || bool((bool((cardNumber.indexOf(HX_STRING(L"36",2),null()) == 0)) || bool((bool((cardNumber.indexOf(HX_STRING(L"38",2),null()) == 0)) && bool((cardNumber.length == 14)))))))))))))))))){
						return HX_STRING(L"diners",6);
					}
					else{
						return HX_STRING(L"other",5);
					}
				}
			}
		}
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ValidationUtil_obj,getCreditCardProvider,return )


ValidationUtil_obj::ValidationUtil_obj()
{
}

void ValidationUtil_obj::__Mark()
{
}

Dynamic ValidationUtil_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (!memcmp(inName.__s,L"isEmail",sizeof(wchar_t)*7) ) { return isEmail_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"isCreditCard",sizeof(wchar_t)*12) ) { return isCreditCard_dyn(); }
		break;
	case 21:
		if (!memcmp(inName.__s,L"getCreditCardProvider",sizeof(wchar_t)*21) ) { return getCreditCardProvider_dyn(); }
		break;
	case 22:
		if (!memcmp(inName.__s,L"isUsaStateAbbreviation",sizeof(wchar_t)*22) ) { return isUsaStateAbbreviation_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic ValidationUtil_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void ValidationUtil_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"isEmail",7),
	HX_STRING(L"isUsaStateAbbreviation",22),
	HX_STRING(L"isCreditCard",12),
	HX_STRING(L"getCreditCardProvider",21),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
};

Class ValidationUtil_obj::__mClass;

void ValidationUtil_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"org.casalib.util.ValidationUtil",31), hx::TCanCast< ValidationUtil_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ValidationUtil_obj::__boot()
{
}

} // end namespace org
} // end namespace casalib
} // end namespace util
