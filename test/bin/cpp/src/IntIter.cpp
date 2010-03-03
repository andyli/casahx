#include <hxcpp.h>

#ifndef INCLUDED_IntIter
#include <IntIter.h>
#endif

Void IntIter_obj::__construct(int min,int max)
{
{
	this->min = min;
	this->max = max;
}
;
	return null();
}

IntIter_obj::~IntIter_obj() { }

Dynamic IntIter_obj::__CreateEmpty() { return  new IntIter_obj; }
hx::ObjectPtr< IntIter_obj > IntIter_obj::__new(int min,int max)
{  hx::ObjectPtr< IntIter_obj > result = new IntIter_obj();
	result->__construct(min,max);
	return result;}

Dynamic IntIter_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< IntIter_obj > result = new IntIter_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

bool IntIter_obj::hasNext( ){
	return (this->min < this->max);
}


HX_DEFINE_DYNAMIC_FUNC0(IntIter_obj,hasNext,return )

int IntIter_obj::next( ){
	return this->min++;
}


HX_DEFINE_DYNAMIC_FUNC0(IntIter_obj,next,return )


IntIter_obj::IntIter_obj()
{
}

void IntIter_obj::__Mark()
{
	hx::MarkMember(min);
	hx::MarkMember(max);
}

Dynamic IntIter_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"min",sizeof(wchar_t)*3) ) { return min; }
		if (!memcmp(inName.__s,L"max",sizeof(wchar_t)*3) ) { return max; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"next",sizeof(wchar_t)*4) ) { return next_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"hasNext",sizeof(wchar_t)*7) ) { return hasNext_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic IntIter_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"min",sizeof(wchar_t)*3) ) { min=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"max",sizeof(wchar_t)*3) ) { max=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void IntIter_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"min",3));
	outFields->push(HX_STRING(L"max",3));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"min",3),
	HX_STRING(L"max",3),
	HX_STRING(L"hasNext",7),
	HX_STRING(L"next",4),
	String(null()) };

static void sMarkStatics() {
};

Class IntIter_obj::__mClass;

void IntIter_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"IntIter",7), hx::TCanCast< IntIter_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void IntIter_obj::__boot()
{
}

