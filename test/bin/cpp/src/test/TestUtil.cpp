#include <hxcpp.h>

#ifndef INCLUDED_IntIter
#include <IntIter.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Public
#include <haxe/Public.h>
#endif
#ifndef INCLUDED_haxe_unit_TestCase
#include <haxe/unit/TestCase.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
#ifndef INCLUDED_org_casalib_math_Percent
#include <org/casalib/math/Percent.h>
#endif
#ifndef INCLUDED_org_casalib_util_ArrayUtil
#include <org/casalib/util/ArrayUtil.h>
#endif
#ifndef INCLUDED_org_casalib_util_NumberUtil
#include <org/casalib/util/NumberUtil.h>
#endif
#ifndef INCLUDED_org_casalib_util_RatioUtil
#include <org/casalib/util/RatioUtil.h>
#endif
#ifndef INCLUDED_org_casalib_util_ValidationUtil
#include <org/casalib/util/ValidationUtil.h>
#endif
#ifndef INCLUDED_test_TestUtil
#include <test/TestUtil.h>
#endif
namespace test{

Void TestUtil_obj::__construct()
{
super::__construct();
	return null();
}

TestUtil_obj::~TestUtil_obj() { }

Dynamic TestUtil_obj::__CreateEmpty() { return  new TestUtil_obj; }
hx::ObjectPtr< TestUtil_obj > TestUtil_obj::__new()
{  hx::ObjectPtr< TestUtil_obj > result = new TestUtil_obj();
	result->__construct();
	return result;}

Dynamic TestUtil_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TestUtil_obj > result = new TestUtil_obj();
	result->__construct();
	return result;}

Void TestUtil_obj::testArrayUtil( ){
{
		__SAFE_POINT
		Array< int > a1 = Array_obj< int >::__new().Add(1).Add(6).Add(3).Add(3).Add(8);
		struct _Function_1_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 15);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertEquals(2,::org::casalib::util::ArrayUtil_obj::indexOf(a1,3,null()),_Function_1_1::Block());
		struct _Function_1_2{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 16);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertEquals(3,::org::casalib::util::ArrayUtil_obj::indexOf(a1,3,3),_Function_1_2::Block());
		struct _Function_1_3{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 18);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertEquals(3,::org::casalib::util::ArrayUtil_obj::lastIndexOf(a1,3,null()),_Function_1_3::Block());
		struct _Function_1_4{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 19);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertEquals(2,::org::casalib::util::ArrayUtil_obj::lastIndexOf(a1,3,2),_Function_1_4::Block());
		Array< ::String > alphabet = Array_obj< ::String >::__new().Add(HX_STRING(L"a",1)).Add(HX_STRING(L"d",1)).Add(HX_STRING(L"e",1));
		Array< ::String > parts = Array_obj< ::String >::__new().Add(HX_STRING(L"b",1)).Add(HX_STRING(L"c",1));
		struct _Function_1_5{
			inline static bool Block( Array< ::String > &parts,Array< ::String > &alphabet)/* DEF (ret block)(not intern) */{
				int index = 1;
				struct _Function_2_1{
					inline static bool Block( Array< ::String > &parts,int &index,Array< ::String > &alphabet)/* DEF (ret block)(not intern) */{
						int i = -1;
						while((++i < parts->length)){
							__SAFE_POINT
							alphabet->insert(index++,parts->__get(i));
						}
						return true;
					}
				};
				return (parts->length == 0) ? bool( false ) : bool( _Function_2_1::Block(parts,index,alphabet) );
			}
		};
		struct _Function_1_6{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 27);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertTrue(_Function_1_5::Block(parts,alphabet),_Function_1_6::Block());
		struct _Function_1_7{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 28);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertEquals(5,alphabet->length,_Function_1_7::Block());
		struct _Function_1_8{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 29);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertEquals(HX_STRING(L"a,b,c,d,e",9),alphabet->join(HX_STRING(L",",1)),_Function_1_8::Block());
		struct _Function_1_9{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 31);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertEquals(4.0,::org::casalib::util::ArrayUtil_obj::average(Array_obj< int >::__new().Add(2).Add(3).Add(8).Add(3)),_Function_1_9::Block());
		struct _Function_1_10{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 33);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertEquals(3,::org::casalib::util::ArrayUtil_obj::contains(Array_obj< int >::__new().Add(1).Add(2).Add(3).Add(7).Add(7).Add(7).Add(4).Add(5),7),_Function_1_10::Block());
		struct _Function_1_11{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 35);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertTrue(::org::casalib::util::ArrayUtil_obj::containsAll(Array_obj< int >::__new().Add(1).Add(2).Add(3).Add(4).Add(5),Array_obj< int >::__new().Add(1).Add(3).Add(5)),_Function_1_11::Block());
		struct _Function_1_12{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 36);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertFalse(::org::casalib::util::ArrayUtil_obj::containsAll(Array_obj< int >::__new().Add(1).Add(2).Add(3).Add(4).Add(5),Array_obj< int >::__new().Add(1).Add(3).Add(6)),_Function_1_12::Block());
		struct _Function_1_13{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 38);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertTrue(::org::casalib::util::ArrayUtil_obj::containsAny(Array_obj< int >::__new().Add(1).Add(2).Add(3).Add(4).Add(5),Array_obj< int >::__new().Add(1).Add(6).Add(5)),_Function_1_13::Block());
		struct _Function_1_14{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 39);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertFalse(::org::casalib::util::ArrayUtil_obj::containsAny(Array_obj< int >::__new().Add(1).Add(2).Add(3).Add(4).Add(5),Array_obj< double >::__new().Add(-1).Add(0).Add(6.1)),_Function_1_14::Block());
		struct _Function_1_15{
			inline static bool Block( )/* DEF (ret block)(not intern) */{
				Array< Dynamic > first = Array_obj< int >::__new().Add(1).Add(2).Add(-1);
				Array< Dynamic > second = Array_obj< int >::__new().Add(1).Add(2).Add(-1);
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
		};
		struct _Function_1_16{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 41);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertTrue(_Function_1_15::Block(),_Function_1_16::Block());
		struct _Function_1_17{
			inline static bool Block( )/* DEF (ret block)(not intern) */{
				Array< Dynamic > first = Array_obj< int >::__new().Add(1).Add(2).Add(-1);
				Array< Dynamic > second = Array_obj< int >::__new().Add(1).Add(2).Add(1);
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
		};
		struct _Function_1_18{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 42);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertFalse(_Function_1_17::Block(),_Function_1_18::Block());
		struct _Function_1_19{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 44);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertEquals(10.0,::org::casalib::util::ArrayUtil_obj::getHighestValue(Array_obj< double >::__new().Add(-123).Add(2).Add(5).Add(6).Add(2).Add(10).Add(-0.11)),_Function_1_19::Block());
		struct _Function_1_20{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 46);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertEquals(3,::org::casalib::util::ArrayUtil_obj::getIndexOfDifference(Array_obj< ::String >::__new().Add(HX_STRING(L"Red",3)).Add(HX_STRING(L"Blue",4)).Add(HX_STRING(L"Green",5)).Add(HX_STRING(L"Indigo",6)).Add(HX_STRING(L"Violet",6)),Array_obj< ::String >::__new().Add(HX_STRING(L"Red",3)).Add(HX_STRING(L"Blue",4)).Add(HX_STRING(L"Green",5)).Add(HX_STRING(L"Violet",6)),null()),_Function_1_20::Block());
		struct _Function_1_21{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"a",1) , 123);
				__result->Add(HX_STRING(L"b",1) , 456);
				return __result;
			}
		};
		Dynamic item = _Function_1_21::Block();
		struct _Function_1_22{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"b",1) , 12);
				return __result;
			}
		};
		struct _Function_1_23{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"b",1) , 15);
				return __result;
			}
		};
		struct _Function_1_24{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 49);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertEquals(item,::org::casalib::util::ArrayUtil_obj::getItemByKey(Array_obj< Dynamic >::__new().Add(_Function_1_22::Block()).Add(_Function_1_23::Block()).Add(item),HX_STRING(L"b",1),456),_Function_1_24::Block());
		Array< int > array = Array_obj< int >::__new().Add(1).Add(2).Add(3).Add(4).Add(5).Add(5).Add(7).Add(5).Add(9).Add(0).Add(11).Add(12).Add(13);
		struct _Function_1_25{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 52);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertEquals(array,::org::casalib::util::ArrayUtil_obj::getItemByType(Array_obj< Dynamic >::__new().Add(14).Add(array).Add(HX_STRING(L"",0)).Add(HX_STRING(L"asdfn",5)),hx::ClassOf< Array<int> >()),_Function_1_25::Block());
		struct _Function_1_26{
			inline static Array< Dynamic > Block( Dynamic &item)/* DEF (ret block)(not intern) */{
				struct _Function_2_1{
					inline static Dynamic Block( ){
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_STRING(L"b",1) , 12);
						return __result;
					}
				};
				struct _Function_2_2{
					inline static Dynamic Block( ){
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_STRING(L"b",1) , 15);
						return __result;
					}
				};
				struct _Function_2_3{
					inline static Dynamic Block( ){
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_STRING(L"b",1) , 15);
						return __result;
					}
				};
				struct _Function_2_4{
					inline static Dynamic Block( ){
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_STRING(L"b",1) , 15);
						return __result;
					}
				};
				Dynamic _g = hx::ClassOf< ::org::casalib::util::ArrayUtil >();
				Array< Dynamic > inArray = Array_obj< Dynamic >::__new().Add(_Function_2_1::Block()).Add(_Function_2_2::Block()).Add(item).Add(_Function_2_3::Block()).Add(_Function_2_4::Block());
				Array< Dynamic > t = Array_obj< Dynamic >::__new();
				{
					int _g1 = 0;
					while((_g1 < inArray->length)){
						__SAFE_POINT
						Dynamic item1 = inArray->__get(_g1);
						++_g1;
						Dynamic value = ((item1 == null())) ? Dynamic( null() ) : Dynamic( item1->__Field(HX_STRING(L"b",1)) );
						if ((value == 15))
							t->push(item1);
					}
				}
				return t;
			}
		};
		struct _Function_1_27{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 54);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertEquals(3,_Function_1_26::Block(item)->length,_Function_1_27::Block());
		struct _Function_1_28{
			inline static Array< Dynamic > Block( Array< int > &array)/* DEF (ret block)(not intern) */{
				Dynamic _g = hx::ClassOf< ::org::casalib::util::ArrayUtil >();
				Array< Dynamic > inArray = Array_obj< Dynamic >::__new().Add(14).Add(array).Add(HX_STRING(L"",0)).Add(HX_STRING(L"asdfn",5));
				Array< Dynamic > t = Array_obj< Dynamic >::__new();
				{
					int _g1 = 0;
					while((_g1 < inArray->length)){
						__SAFE_POINT
						Dynamic item1 = inArray->__get(_g1);
						++_g1;
						if (::Std_obj::is(item1,hx::ClassOf< ::String >()))
							t->push(item1);
					}
				}
				return t;
			}
		};
		struct _Function_1_29{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 56);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertEquals(2,_Function_1_28::Block(array)->length,_Function_1_29::Block());
		struct _Function_1_30{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 58);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertEquals(1.0,::org::casalib::util::ArrayUtil_obj::getLowestValue(Array_obj< int >::__new().Add(2).Add(1).Add(5).Add(4).Add(3)),_Function_1_30::Block());
		struct _Function_1_31{
			inline static bool Block( Array< int > &array)/* DEF (ret block)(not intern) */{
				Array< Dynamic > first = ::org::casalib::util::ArrayUtil_obj::randomize(array);
				int i = first->length;
				bool result = true;
				if ((i != array->length)){
					result = false;
				}
				else{
					while((i-- > 0)){
						__SAFE_POINT
						if ((first->__get(i) != array->__get(i))){
							result = false;
							break;
						}
					}
				}
				return result;
			}
		};
		struct _Function_1_32{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 60);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertFalse(_Function_1_31::Block(array),_Function_1_32::Block());
		struct _Function_1_33{
			inline static Array< Dynamic > Block( Array< int > &a1)/* DEF (ret block)(not intern) */{
				Array< Dynamic > newArray = Array_obj< Dynamic >::__new();
				::IntIter iter = ::IntIter_obj::__new(0,a1->length);
				for(Dynamic __it = iter;  __it->__Field(HX_STRING(L"hasNext",7))(); ){
int i = __it->__Field(HX_STRING(L"next",4))();
					{
						if (::org::casalib::util::ArrayUtil_obj::_removeDuplicatesFilter(a1->__get(i),i,a1)){
							newArray->push(a1->__get(i));
						}
					}
;
					__SAFE_POINT
				}
				return newArray;
			}
		};
		struct _Function_1_34{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 62);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertEquals(4,_Function_1_33::Block(a1)->length,_Function_1_34::Block());
		struct _Function_1_35{
			inline static int Block( Array< int > &array)/* DEF (ret block)(not intern) */{
				int i = ::org::casalib::util::ArrayUtil_obj::indexOf(array,5,null());
				int f = 0;
				while((i != -1)){
					__SAFE_POINT
					array->splice(i,1);
					i = ::org::casalib::util::ArrayUtil_obj::indexOf(array,5,i);
					f++;
				}
				return f;
			}
		};
		struct _Function_1_36{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 64);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertEquals(3,_Function_1_35::Block(array),_Function_1_36::Block());
		{
			bool removed = false;
			int l = array->length;
			while((l-- > 0)){
				__SAFE_POINT
				if ((::org::casalib::util::ArrayUtil_obj::indexOf(Array_obj< int >::__new().Add(1).Add(11),array->__get(l),null()) > -1)){
					array->splice(l,1);
					removed = true;
				}
			}
			removed;
		}
		struct _Function_1_37{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 67);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertEquals(8,array->length,_Function_1_37::Block());
		{
			bool removed = false;
			int l = array->length;
			while((l-- > 0)){
				__SAFE_POINT
				if ((::org::casalib::util::ArrayUtil_obj::indexOf(Array_obj< int >::__new().Add(0),array->__get(l),null()) == -1)){
					array->splice(l,1);
					removed = true;
				}
			}
			removed;
		}
		struct _Function_1_38{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 70);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertEquals(0,array->__get(0),_Function_1_38::Block());
		struct _Function_1_39{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 72);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testArrayUtil",13));
				return __result;
			}
		};
		this->assertEquals(5.0,::org::casalib::util::ArrayUtil_obj::sum(Array_obj< double >::__new().Add(1).Add(1).Add(1).Add(0.25).Add(1.75)),_Function_1_39::Block());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TestUtil_obj,testArrayUtil,(void))

Void TestUtil_obj::testNumberUtil( ){
{
		__SAFE_POINT
		struct _Function_1_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 76);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertEquals(HX_STRING(L"00",2),::org::casalib::util::NumberUtil_obj::addLeadingZero(0),_Function_1_1::Block());
		struct _Function_1_2{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 78);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertEquals(-1.,::org::casalib::util::NumberUtil_obj::constrain(-1,-1.001,100),_Function_1_2::Block());
		struct _Function_1_3{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 79);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertEquals(0.0,::org::casalib::util::NumberUtil_obj::constrain(-1,0,1),_Function_1_3::Block());
		struct _Function_1_4{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 81);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertEquals(HX_STRING(L"10 20 30 40",11),::org::casalib::util::NumberUtil_obj::createStepsBetween(0,50,4)->join(HX_STRING(L" ",1)),_Function_1_4::Block());
		struct _Function_1_5{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 83);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertEquals(HX_STRING(L"01,234,567",10),::org::casalib::util::NumberUtil_obj::format(1234567,8,HX_STRING(L",",1),null()),_Function_1_5::Block());
		struct _Function_1_6{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 85);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertEquals(HX_STRING(L"32nd",4),(32 + ::org::casalib::util::NumberUtil_obj::getOrdinalSuffix(32)),_Function_1_6::Block());
		struct _Function_1_7{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 87);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertEquals(0.2,::org::casalib::util::NumberUtil_obj::getWeightedAverage(0,1,5),_Function_1_7::Block());
		struct _Function_1_8{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 89);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertEquals(5.0,::org::casalib::util::NumberUtil_obj::interpolate(::org::casalib::math::Percent_obj::__new(0.5,null()),0,10),_Function_1_8::Block());
		struct _Function_1_9{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 91);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertTrue(::org::casalib::util::NumberUtil_obj::isBetween(3,0,5),_Function_1_9::Block());
		struct _Function_1_10{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 92);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertFalse(::org::casalib::util::NumberUtil_obj::isBetween(7,0,5),_Function_1_10::Block());
		struct _Function_1_11{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 94);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertFalse(::org::casalib::util::NumberUtil_obj::isEqual(3.042,3,0),_Function_1_11::Block());
		struct _Function_1_12{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 95);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertTrue(::org::casalib::util::NumberUtil_obj::isEqual(3.042,3,0.5),_Function_1_12::Block());
		struct _Function_1_13{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 97);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertFalse(::org::casalib::util::NumberUtil_obj::isEven(7),_Function_1_13::Block());
		struct _Function_1_14{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 98);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertTrue(::org::casalib::util::NumberUtil_obj::isEven(12),_Function_1_14::Block());
		struct _Function_1_15{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 100);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertTrue(::org::casalib::util::NumberUtil_obj::isInteger(13),_Function_1_15::Block());
		struct _Function_1_16{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 101);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertFalse(::org::casalib::util::NumberUtil_obj::isInteger(1.2345),_Function_1_16::Block());
		struct _Function_1_17{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 103);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertTrue(::org::casalib::util::NumberUtil_obj::isOdd(7),_Function_1_17::Block());
		struct _Function_1_18{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 104);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertFalse(::org::casalib::util::NumberUtil_obj::isOdd(12),_Function_1_18::Block());
		struct _Function_1_19{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 106);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertTrue(::org::casalib::util::NumberUtil_obj::isPrime(13),_Function_1_19::Block());
		struct _Function_1_20{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 107);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertFalse(::org::casalib::util::NumberUtil_obj::isPrime(4),_Function_1_20::Block());
		Array< ::String > colors = Array_obj< ::String >::__new().Add(HX_STRING(L"Red",3)).Add(HX_STRING(L"Green",5)).Add(HX_STRING(L"Blue",4));
		struct _Function_1_21{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 110);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertEquals(HX_STRING(L"Blue",4),colors->__get(::org::casalib::util::NumberUtil_obj::loopIndex(2,colors->length)),_Function_1_21::Block());
		struct _Function_1_22{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 111);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertEquals(HX_STRING(L"Green",5),colors->__get(::org::casalib::util::NumberUtil_obj::loopIndex(4,colors->length)),_Function_1_22::Block());
		struct _Function_1_23{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 112);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertEquals(HX_STRING(L"Red",3),colors->__get(::org::casalib::util::NumberUtil_obj::loopIndex(-6,colors->length)),_Function_1_23::Block());
		struct _Function_1_24{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 114);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertEquals(75.0,::org::casalib::util::NumberUtil_obj::map(0.75,0,1,0,100),_Function_1_24::Block());
		struct _Function_1_25{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 116);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertEquals(-5.,::org::casalib::util::NumberUtil_obj::max(-5,null()),_Function_1_25::Block());
		struct _Function_1_26{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 117);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertEquals(-5.,::org::casalib::util::NumberUtil_obj::max(-5,HX_STRING(L"CASA",4)),_Function_1_26::Block());
		struct _Function_1_27{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 118);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertEquals(-5.,::org::casalib::util::NumberUtil_obj::max(-5,-13),_Function_1_27::Block());
		struct _Function_1_28{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 120);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertEquals(5.0,::org::casalib::util::NumberUtil_obj::min(5,null()),_Function_1_28::Block());
		struct _Function_1_29{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 121);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertEquals(5.0,::org::casalib::util::NumberUtil_obj::min(5,HX_STRING(L"CASA",4)),_Function_1_29::Block());
		struct _Function_1_30{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 122);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertEquals(5.0,::org::casalib::util::NumberUtil_obj::min(5,13),_Function_1_30::Block());
		struct _Function_1_31{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 124);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertEquals(0.25,::org::casalib::util::NumberUtil_obj::normalize(8,4,20)->getDecimalPercentage(),_Function_1_31::Block());
		{
			int _g = 0;
			while((_g < 10)){
				__SAFE_POINT
				int i = _g++;
				int randomI = ::org::casalib::util::NumberUtil_obj::randomIntegerWithinRange(0,1);
				struct _Function_3_1{
					inline static Dynamic Block( ){
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
						__result->Add(HX_STRING(L"lineNumber",10) , 128);
						__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
						__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
						return __result;
					}
				};
				this->assertTrue(::org::casalib::util::NumberUtil_obj::isInteger(randomI),_Function_3_1::Block());
				struct _Function_3_2{
					inline static Dynamic Block( ){
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
						__result->Add(HX_STRING(L"lineNumber",10) , 129);
						__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
						__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
						return __result;
					}
				};
				this->assertTrue(::org::casalib::util::NumberUtil_obj::isBetween(randomI,0,1),_Function_3_2::Block());
			}
		}
		{
			int _g = 0;
			while((_g < 10)){
				__SAFE_POINT
				int i = _g++;
				double random = ::org::casalib::util::NumberUtil_obj::randomWithinRange(0,1);
				struct _Function_3_1{
					inline static Dynamic Block( ){
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
						__result->Add(HX_STRING(L"lineNumber",10) , 134);
						__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
						__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
						return __result;
					}
				};
				this->assertTrue(::org::casalib::util::NumberUtil_obj::isBetween(random,0,1),_Function_3_1::Block());
			}
		}
		struct _Function_1_32{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 137);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertEquals(3.14,::org::casalib::util::NumberUtil_obj::roundDecimalToPlace(3.14159,2),_Function_1_32::Block());
		struct _Function_1_33{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 138);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testNumberUtil",14));
				return __result;
			}
		};
		this->assertEquals(3.142,::org::casalib::util::NumberUtil_obj::roundDecimalToPlace(3.14159,3),_Function_1_33::Block());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TestUtil_obj,testNumberUtil,(void))

Void TestUtil_obj::testRatioUtil( ){
{
		__SAFE_POINT
		::nme::geom::Rectangle rect = ::nme::geom::Rectangle_obj::__new(0,0,640,480);
		struct _Function_1_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 143);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testRatioUtil",13));
				return __result;
			}
		};
		this->assertEquals((double(3) / double(4)),::org::casalib::util::RatioUtil_obj::heightToWidth(rect),_Function_1_1::Block());
		::nme::geom::Rectangle rect2 = ::nme::geom::Rectangle_obj::__new(0,0,(640 * 0.33),(480 * 0.33));
		struct _Function_1_2{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 146);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testRatioUtil",13));
				return __result;
			}
		};
		this->assertTrue(::org::casalib::util::RatioUtil_obj::scale(rect,::org::casalib::math::Percent_obj::__new(0.33,null()),false)->equals(rect2),_Function_1_2::Block());
		struct _Function_1_3{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 147);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testRatioUtil",13));
				return __result;
			}
		};
		this->assertTrue(::org::casalib::util::NumberUtil_obj::isInteger(::org::casalib::util::RatioUtil_obj::scale(rect,::org::casalib::math::Percent_obj::__new(0.33,null()),true)->width),_Function_1_3::Block());
		struct _Function_1_4{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 149);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testRatioUtil",13));
				return __result;
			}
		};
		this->assertTrue(::org::casalib::util::RatioUtil_obj::scaleHeight(rect,rect2->width,false)->equals(rect2),_Function_1_4::Block());
		struct _Function_1_5{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 150);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testRatioUtil",13));
				return __result;
			}
		};
		this->assertTrue(::org::casalib::util::NumberUtil_obj::isInteger(::org::casalib::util::RatioUtil_obj::scaleHeight(rect,rect2->width,true)->width),_Function_1_5::Block());
		struct _Function_1_6{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 152);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testRatioUtil",13));
				return __result;
			}
		};
		this->assertTrue(::org::casalib::util::RatioUtil_obj::scaleToFill(rect2,rect,false)->containsRect(rect2),_Function_1_6::Block());
		struct _Function_1_7{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 154);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testRatioUtil",13));
				return __result;
			}
		};
		this->assertTrue(::org::casalib::util::RatioUtil_obj::scaleToFit(rect2,rect,false)->containsRect(rect2),_Function_1_7::Block());
		struct _Function_1_8{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 156);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testRatioUtil",13));
				return __result;
			}
		};
		this->assertTrue(::org::casalib::util::RatioUtil_obj::scaleWidth(rect,rect2->height,true)->equals(::org::casalib::util::RatioUtil_obj::scale(rect2,::org::casalib::math::Percent_obj::__new(1,null()),null())),_Function_1_8::Block());
		struct _Function_1_9{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 158);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testRatioUtil",13));
				return __result;
			}
		};
		this->assertEquals((double(4) / double(3)),::org::casalib::util::RatioUtil_obj::widthToHeight(rect),_Function_1_9::Block());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TestUtil_obj,testRatioUtil,(void))

Void TestUtil_obj::testValidationUtil( ){
{
		__SAFE_POINT
		struct _Function_1_1{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 163);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testValidationUtil",18));
				return __result;
			}
		};
		this->assertEquals(HX_STRING(L"visa",4),::org::casalib::util::ValidationUtil_obj::getCreditCardProvider(HX_STRING(L"4111111111111111",16)),_Function_1_1::Block());
		struct _Function_1_2{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 164);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testValidationUtil",18));
				return __result;
			}
		};
		this->assertEquals(HX_STRING(L"mastercard",10),::org::casalib::util::ValidationUtil_obj::getCreditCardProvider(HX_STRING(L"5555555555554444",16)),_Function_1_2::Block());
		struct _Function_1_3{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 165);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testValidationUtil",18));
				return __result;
			}
		};
		this->assertEquals(HX_STRING(L"discover",8),::org::casalib::util::ValidationUtil_obj::getCreditCardProvider(HX_STRING(L"6011000990139424",16)),_Function_1_3::Block());
		struct _Function_1_4{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 166);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testValidationUtil",18));
				return __result;
			}
		};
		this->assertEquals(HX_STRING(L"amex",4),::org::casalib::util::ValidationUtil_obj::getCreditCardProvider(HX_STRING(L"378282246310005",15)),_Function_1_4::Block());
		struct _Function_1_5{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 167);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testValidationUtil",18));
				return __result;
			}
		};
		this->assertEquals(HX_STRING(L"diners",6),::org::casalib::util::ValidationUtil_obj::getCreditCardProvider(HX_STRING(L"30569309025904",14)),_Function_1_5::Block());
		struct _Function_1_6{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 168);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testValidationUtil",18));
				return __result;
			}
		};
		this->assertEquals(HX_STRING(L"other",5),::org::casalib::util::ValidationUtil_obj::getCreditCardProvider(HX_STRING(L"3566002020360505",16)),_Function_1_6::Block());
		struct _Function_1_7{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 169);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testValidationUtil",18));
				return __result;
			}
		};
		this->assertEquals(HX_STRING(L"invalid",7),::org::casalib::util::ValidationUtil_obj::getCreditCardProvider(HX_STRING(L"123",3)),_Function_1_7::Block());
		struct _Function_1_8{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 171);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testValidationUtil",18));
				return __result;
			}
		};
		this->assertTrue(::org::casalib::util::ValidationUtil_obj::isCreditCard(HX_STRING(L"378282246310005",15)),_Function_1_8::Block());
		struct _Function_1_9{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 172);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testValidationUtil",18));
				return __result;
			}
		};
		this->assertFalse(::org::casalib::util::ValidationUtil_obj::isCreditCard(HX_STRING(L"345",3)),_Function_1_9::Block());
		struct _Function_1_10{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 174);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testValidationUtil",18));
				return __result;
			}
		};
		this->assertTrue(::org::casalib::util::ValidationUtil_obj::isEmail(HX_STRING(L"andy@onthewings.net",19)),_Function_1_10::Block());
		struct _Function_1_11{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 175);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testValidationUtil",18));
				return __result;
			}
		};
		this->assertFalse(::org::casalib::util::ValidationUtil_obj::isEmail(HX_STRING(L"12@3234",7)),_Function_1_11::Block());
		struct _Function_1_12{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 177);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testValidationUtil",18));
				return __result;
			}
		};
		this->assertTrue(::org::casalib::util::ValidationUtil_obj::isUsaStateAbbreviation(HX_STRING(L"dC",2)),_Function_1_12::Block());
		struct _Function_1_13{
			inline static Dynamic Block( ){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_STRING(L"fileName",8) , HX_STRING(L"TestUtil.hx",11));
				__result->Add(HX_STRING(L"lineNumber",10) , 178);
				__result->Add(HX_STRING(L"className",9) , HX_STRING(L"test.TestUtil",13));
				__result->Add(HX_STRING(L"methodName",10) , HX_STRING(L"testValidationUtil",18));
				return __result;
			}
		};
		this->assertFalse(::org::casalib::util::ValidationUtil_obj::isUsaStateAbbreviation(HX_STRING(L"hk",2)),_Function_1_13::Block());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TestUtil_obj,testValidationUtil,(void))


TestUtil_obj::TestUtil_obj()
{
}

void TestUtil_obj::__Mark()
{
	super::__Mark();
}

Dynamic TestUtil_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 13:
		if (!memcmp(inName.__s,L"testArrayUtil",sizeof(wchar_t)*13) ) { return testArrayUtil_dyn(); }
		if (!memcmp(inName.__s,L"testRatioUtil",sizeof(wchar_t)*13) ) { return testRatioUtil_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"testNumberUtil",sizeof(wchar_t)*14) ) { return testNumberUtil_dyn(); }
		break;
	case 18:
		if (!memcmp(inName.__s,L"testValidationUtil",sizeof(wchar_t)*18) ) { return testValidationUtil_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic TestUtil_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void TestUtil_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"testArrayUtil",13),
	HX_STRING(L"testNumberUtil",14),
	HX_STRING(L"testRatioUtil",13),
	HX_STRING(L"testValidationUtil",18),
	String(null()) };

static void sMarkStatics() {
};

Class TestUtil_obj::__mClass;

void TestUtil_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"test.TestUtil",13), hx::TCanCast< TestUtil_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void TestUtil_obj::__boot()
{
}

} // end namespace test
