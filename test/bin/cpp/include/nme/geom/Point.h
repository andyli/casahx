#ifndef INCLUDED_nme_geom_Point
#define INCLUDED_nme_geom_Point

#include <hxcpp.h>

HX_DECLARE_CLASS2(nme,geom,Point)
namespace nme{
namespace geom{


class Point_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Point_obj OBJ_;
		Point_obj();
		Void __construct(Dynamic inX,Dynamic inY);

	public:
		static hx::ObjectPtr< Point_obj > __new(Dynamic inX,Dynamic inY);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Point_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Point",5); }

		double x; /* REM */ 
		double y; /* REM */ 
		virtual ::nme::geom::Point add( ::nme::geom::Point v);
		Dynamic add_dyn();

		virtual ::nme::geom::Point clone( );
		Dynamic clone_dyn();

		virtual bool equals( ::nme::geom::Point toCompare);
		Dynamic equals_dyn();

		double length; /* REM */ 
		virtual double get_length( );
		Dynamic get_length_dyn();

		virtual Void normalize( double thickness);
		Dynamic normalize_dyn();

		virtual Void offset( double dx,double dy);
		Dynamic offset_dyn();

		virtual ::nme::geom::Point subtract( ::nme::geom::Point v);
		Dynamic subtract_dyn();

		static double distance( ::nme::geom::Point pt1,::nme::geom::Point pt2);
		static Dynamic distance_dyn();

		static ::nme::geom::Point interpolate( ::nme::geom::Point pt1,::nme::geom::Point pt2,double f);
		static Dynamic interpolate_dyn();

		static ::nme::geom::Point polar( double len,double angle);
		static Dynamic polar_dyn();

};

} // end namespace nme
} // end namespace geom

#endif /* INCLUDED_nme_geom_Point */ 
