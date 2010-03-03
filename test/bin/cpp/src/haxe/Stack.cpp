#include <hxcpp.h>

#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_haxe_Stack
#include <haxe/Stack.h>
#endif
#ifndef INCLUDED_haxe_StackItem
#include <haxe/StackItem.h>
#endif
namespace haxe{

Void Stack_obj::__construct()
{
	return null();
}

Stack_obj::~Stack_obj() { }

Dynamic Stack_obj::__CreateEmpty() { return  new Stack_obj; }
hx::ObjectPtr< Stack_obj > Stack_obj::__new()
{  hx::ObjectPtr< Stack_obj > result = new Stack_obj();
	result->__construct();
	return result;}

Dynamic Stack_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Stack_obj > result = new Stack_obj();
	result->__construct();
	return result;}

Array< ::haxe::StackItem > Stack_obj::callStack( ){
	return Array_obj< ::haxe::StackItem >::__new();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Stack_obj,callStack,return )

Array< ::haxe::StackItem > Stack_obj::exceptionStack( ){
	return Array_obj< ::haxe::StackItem >::__new();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Stack_obj,exceptionStack,return )

::String Stack_obj::toString( Array< ::haxe::StackItem > stack){
	__SAFE_POINT
	::StringBuf b = ::StringBuf_obj::__new();
	{
		int _g = 0;
		while((_g < stack->length)){
			__SAFE_POINT
			::haxe::StackItem s = stack->__get(_g);
			++_g;
			b->b[b->b->length] = HX_STRING(L"\nCalled from ",13);
			::haxe::Stack_obj::itemToString(b,s);
		}
	}
	return b->b->join(HX_STRING(L"",0));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Stack_obj,toString,return )

Void Stack_obj::itemToString( ::StringBuf b,::haxe::StackItem s){
{
		__SAFE_POINT
		::haxe::StackItem _switch_1 = (s);
		switch((_switch_1)->GetIndex()){
			case 0: {
				b->b[b->b->length] = HX_STRING(L"a C function",12);
			}
			;break;
			case 1: {
				::String m = _switch_1->__Param(0);
{
					b->b[b->b->length] = HX_STRING(L"module ",7);
					b->b[b->b->length] = m;
				}
			}
			;break;
			case 2: {
				int line = _switch_1->__Param(2);
				::String file = _switch_1->__Param(1);
				::haxe::StackItem s1 = _switch_1->__Param(0);
{
					if ((s1 != null())){
						::haxe::Stack_obj::itemToString(b,s1);
						b->b[b->b->length] = HX_STRING(L" (",2);
					}
					b->b[b->b->length] = file;
					b->b[b->b->length] = HX_STRING(L" line ",6);
					b->b[b->b->length] = line;
					if ((s1 != null()))
						b->b[b->b->length] = HX_STRING(L")",1);
				}
			}
			;break;
			case 3: {
				::String meth = _switch_1->__Param(1);
				::String cname = _switch_1->__Param(0);
{
					b->b[b->b->length] = cname;
					b->b[b->b->length] = HX_STRING(L".",1);
					b->b[b->b->length] = meth;
				}
			}
			;break;
			case 4: {
				int n = _switch_1->__Param(0);
{
					b->b[b->b->length] = HX_STRING(L"local function #",16);
					b->b[b->b->length] = n;
				}
			}
			;break;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Stack_obj,itemToString,(void))

Dynamic Stack_obj::makeStack( Dynamic s){
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Stack_obj,makeStack,return )


Stack_obj::Stack_obj()
{
}

void Stack_obj::__Mark()
{
}

Dynamic Stack_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 8:
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"callStack",sizeof(wchar_t)*9) ) { return callStack_dyn(); }
		if (!memcmp(inName.__s,L"makeStack",sizeof(wchar_t)*9) ) { return makeStack_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"itemToString",sizeof(wchar_t)*12) ) { return itemToString_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"exceptionStack",sizeof(wchar_t)*14) ) { return exceptionStack_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Stack_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Stack_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"callStack",9),
	HX_STRING(L"exceptionStack",14),
	HX_STRING(L"toString",8),
	HX_STRING(L"itemToString",12),
	HX_STRING(L"makeStack",9),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
};

Class Stack_obj::__mClass;

void Stack_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"haxe.Stack",10), hx::TCanCast< Stack_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Stack_obj::__boot()
{
}

} // end namespace haxe
