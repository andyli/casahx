#ifndef INCLUDED_org_casalib_math_geom_Point3d
#define INCLUDED_org_casalib_math_geom_Point3d

#include <hxcpp.h>

HX_DECLARE_CLASS3(org,casalib,math,Percent)
HX_DECLARE_CLASS4(org,casalib,math,geom,Point3d)
namespace org{
namespace casalib{
namespace math{
namespace geom{


class Point3d_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Point3d_obj OBJ_;
		Point3d_obj();
		Void __construct(Dynamic __o_x,Dynamic __o_y,Dynamic __o_z);

	public:
		static hx::ObjectPtr< Point3d_obj > __new(Dynamic __o_x,Dynamic __o_y,Dynamic __o_z);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Point3d_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"Point3d",7); }

		double x; /* REM */ 
		double y; /* REM */ 
		double z; /* REM */ 
		double _x; /* REM */ 
		double _y; /* REM */ 
		double _z; /* REM */ 
		virtual double getX( );
		Dynamic getX_dyn();

		virtual double setX( double position);
		Dynamic setX_dyn();

		virtual double getY( );
		Dynamic getY_dyn();

		virtual double setY( double position);
		Dynamic setY_dyn();

		virtual double getZ( );
		Dynamic getZ_dyn();

		virtual double setZ( double position);
		Dynamic setZ_dyn();

		virtual ::org::casalib::math::geom::Point3d add( ::org::casalib::math::geom::Point3d point);
		Dynamic add_dyn();

		virtual ::org::casalib::math::geom::Point3d subtract( ::org::casalib::math::geom::Point3d point);
		Dynamic subtract_dyn();

		virtual Void offset( double xOffset,double yOffset,double zOffset);
		Dynamic offset_dyn();

		virtual bool equals( ::org::casalib::math::geom::Point3d point);
		Dynamic equals_dyn();

		virtual ::org::casalib::math::geom::Point3d clone( );
		Dynamic clone_dyn();

		static double distance( ::org::casalib::math::geom::Point3d firstPoint,::org::casalib::math::geom::Point3d secondPoint);
		static Dynamic distance_dyn();

		static ::org::casalib::math::geom::Point3d interpolate( ::org::casalib::math::geom::Point3d firstPoint,::org::casalib::math::geom::Point3d secondPoint,::org::casalib::math::Percent amount);
		static Dynamic interpolate_dyn();

};

} // end namespace org
} // end namespace casalib
} // end namespace math
} // end namespace geom

#endif /* INCLUDED_org_casalib_math_geom_Point3d */ 
