#ifndef INCLUDED_org_casalib_util_ArrayUtil
#define INCLUDED_org_casalib_util_ArrayUtil

#include <hxcpp.h>

HX_DECLARE_CLASS3(org,casalib,util,ArrayUtil)
namespace org{
namespace casalib{
namespace util{


class ArrayUtil_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ArrayUtil_obj OBJ_;
		ArrayUtil_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ArrayUtil_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ArrayUtil_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"ArrayUtil",9); }

		static int indexOf( Array< Dynamic > inArray,Dynamic match,Dynamic fromIndex);
		static Dynamic indexOf_dyn();

		static int lastIndexOf( Array< Dynamic > inArray,Dynamic match,Dynamic fromIndex);
		static Dynamic lastIndexOf_dyn();

		static Array< Dynamic > filter( Array< Dynamic > inArray,Dynamic callBack);
		static Dynamic filter_dyn();

		static Dynamic getItemByKey( Array< Dynamic > inArray,::String key,Dynamic match);
		static Dynamic getItemByKey_dyn();

		static Array< Dynamic > getItemsByKey( Array< Dynamic > inArray,::String key,Dynamic match);
		static Dynamic getItemsByKey_dyn();

		static Dynamic getItemByType( Array< Dynamic > inArray,::Class type);
		static Dynamic getItemByType_dyn();

		static Array< Dynamic > getItemsByType( Array< Dynamic > inArray,::Class type);
		static Dynamic getItemsByType_dyn();

		static bool equals( Array< Dynamic > first,Array< Dynamic > second);
		static Dynamic equals_dyn();

		static bool addItemsAt( Array< Dynamic > tarArray,Array< Dynamic > items,Dynamic index);
		static Dynamic addItemsAt_dyn();

		static Array< Dynamic > removeDuplicates( Array< Dynamic > inArray);
		static Dynamic removeDuplicates_dyn();

		static bool _removeDuplicatesFilter( Dynamic e,int i,Array< Dynamic > inArray);
		static Dynamic _removeDuplicatesFilter_dyn();

		static int removeItem( Array< Dynamic > tarArray,Dynamic item);
		static Dynamic removeItem_dyn();

		static bool removeItems( Array< Dynamic > tarArray,Array< Dynamic > items);
		static Dynamic removeItems_dyn();

		static bool retainItems( Array< Dynamic > tarArray,Array< Dynamic > items);
		static Dynamic retainItems_dyn();

		static int contains( Array< Dynamic > inArray,Dynamic item);
		static Dynamic contains_dyn();

		static bool containsAll( Array< Dynamic > inArray,Array< Dynamic > items);
		static Dynamic containsAll_dyn();

		static bool containsAny( Array< Dynamic > inArray,Array< Dynamic > items);
		static Dynamic containsAny_dyn();

		static int getIndexOfDifference( Array< Dynamic > first,Array< Dynamic > second,Dynamic fromIndex);
		static Dynamic getIndexOfDifference_dyn();

		static Array< Dynamic > randomize( Array< Dynamic > inArray);
		static Dynamic randomize_dyn();

		static double sum( Array< Dynamic > inArray);
		static Dynamic sum_dyn();

		static double average( Array< Dynamic > inArray);
		static Dynamic average_dyn();

		static double getLowestValue( Array< Dynamic > inArray);
		static Dynamic getLowestValue_dyn();

		static double getHighestValue( Array< Dynamic > inArray);
		static Dynamic getHighestValue_dyn();

};

} // end namespace org
} // end namespace casalib
} // end namespace util

#endif /* INCLUDED_org_casalib_util_ArrayUtil */ 
