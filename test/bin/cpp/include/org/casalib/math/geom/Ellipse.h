#ifndef INCLUDED_org_casalib_math_geom_Ellipse
#define INCLUDED_org_casalib_math_geom_Ellipse

#include <hxcpp.h>

HX_DECLARE_CLASS2(nme,geom,Point)
HX_DECLARE_CLASS4(org,casalib,math,geom,Ellipse)
namespace org{
namespace casalib{
namespace math{
namespace geom{


class Ellipse_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Ellipse_obj OBJ_;
		Ellipse_obj();
		Void __construct(double x,double y,double width,double height);

	public:
		static hx::ObjectPtr< Ellipse_obj > __new(double x,double y,double width,double height);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Ellipse_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Ellipse",7); }

		double area; /* REM */ 
		::nme::geom::Point center; /* REM */ 
		double height; /* REM */ 
		double perimeter; /* REM */ 
		::nme::geom::Point size; /* REM */ 
		double width; /* REM */ 
		double x; /* REM */ 
		double y; /* REM */ 
		double _x; /* REM */ 
		double _y; /* REM */ 
		double _width; /* REM */ 
		double _height; /* REM */ 
		virtual double getX( );
		Dynamic getX_dyn();

		virtual double setX( double xPos);
		Dynamic setX_dyn();

		virtual double getY( );
		Dynamic getY_dyn();

		virtual double setY( double yPos);
		Dynamic setY_dyn();

		virtual double getWidth( );
		Dynamic getWidth_dyn();

		virtual double setWidth( double width);
		Dynamic setWidth_dyn();

		virtual double getHeight( );
		Dynamic getHeight_dyn();

		virtual double setHeight( double height);
		Dynamic setHeight_dyn();

		virtual ::nme::geom::Point getCenter( );
		Dynamic getCenter_dyn();

		virtual ::nme::geom::Point setCenter( ::nme::geom::Point c);
		Dynamic setCenter_dyn();

		virtual ::nme::geom::Point getSize( );
		Dynamic getSize_dyn();

		virtual double getPerimeter( );
		Dynamic getPerimeter_dyn();

		virtual double getArea( );
		Dynamic getArea_dyn();

		virtual ::nme::geom::Point getPointOfDegree( double degree);
		Dynamic getPointOfDegree_dyn();

		virtual bool containsPoint( ::nme::geom::Point point);
		Dynamic containsPoint_dyn();

		virtual bool equals( ::org::casalib::math::geom::Ellipse ellipse);
		Dynamic equals_dyn();

		virtual ::org::casalib::math::geom::Ellipse clone( );
		Dynamic clone_dyn();

};

} // end namespace org
} // end namespace casalib
} // end namespace math
} // end namespace geom

#endif /* INCLUDED_org_casalib_math_geom_Ellipse */ 
