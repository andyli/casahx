#include <hxcpp.h>

#include <test/TestUtil.h>
#include <haxe/unit/TestStatus.h>
#include <nme/geom/Point.h>
#include <org/casalib/math/geom/Ellipse.h>
#include <EReg.h>
#include <org/casalib/math/Range.h>
#include <org/casalib/util/RatioUtil.h>
#include <Type.h>
#include <ValueType.h>
#include <org/casalib/util/ArrayUtil.h>
#include <List.h>
#include <org/casalib/math/Percent.h>
#include <Std.h>
#include <nme/geom/Rectangle.h>
#include <nme/geom/Matrix.h>
#include <IntIter.h>
#include <org/casalib/util/ValidationUtil.h>
#include <org/casalib/math/geom/Point3d.h>
#include <StringBuf.h>
#include <haxe/Log.h>
#include <cpp/Lib.h>
#include <org/casalib/util/NumberUtil.h>
#include <haxe/unit/TestResult.h>
#include <Reflect.h>
#include <test/Test.h>
#include <haxe/unit/TestRunner.h>
#include <StringTools.h>
#include <haxe/Stack.h>
#include <haxe/StackItem.h>
#include <test/TestMath.h>
#include <haxe/unit/TestCase.h>

void __boot_all()
{
hx::RegisterResources( hx::GetResources() );
::test::TestUtil_obj::__register();
::haxe::unit::TestStatus_obj::__register();
::nme::geom::Point_obj::__register();
::org::casalib::math::geom::Ellipse_obj::__register();
::EReg_obj::__register();
::org::casalib::math::Range_obj::__register();
::org::casalib::util::RatioUtil_obj::__register();
::Type_obj::__register();
::ValueType_obj::__register();
::org::casalib::util::ArrayUtil_obj::__register();
::List_obj::__register();
::org::casalib::math::Percent_obj::__register();
::Std_obj::__register();
::nme::geom::Rectangle_obj::__register();
::nme::geom::Matrix_obj::__register();
::IntIter_obj::__register();
::org::casalib::util::ValidationUtil_obj::__register();
::org::casalib::math::geom::Point3d_obj::__register();
::StringBuf_obj::__register();
::haxe::Log_obj::__register();
::cpp::Lib_obj::__register();
::org::casalib::util::NumberUtil_obj::__register();
::haxe::unit::TestResult_obj::__register();
::Reflect_obj::__register();
::test::Test_obj::__register();
::haxe::unit::TestRunner_obj::__register();
::StringTools_obj::__register();
::haxe::Stack_obj::__register();
::haxe::StackItem_obj::__register();
::test::TestMath_obj::__register();
::haxe::unit::TestCase_obj::__register();
::Std_obj::__init__();
::haxe::unit::TestCase_obj::__boot();
::test::TestMath_obj::__boot();
::haxe::StackItem_obj::__boot();
::haxe::Stack_obj::__boot();
::StringTools_obj::__boot();
::haxe::unit::TestRunner_obj::__boot();
::test::Test_obj::__boot();
::Reflect_obj::__boot();
::haxe::unit::TestResult_obj::__boot();
::org::casalib::util::NumberUtil_obj::__boot();
::cpp::Lib_obj::__boot();
::haxe::Log_obj::__boot();
::StringBuf_obj::__boot();
::org::casalib::math::geom::Point3d_obj::__boot();
::org::casalib::util::ValidationUtil_obj::__boot();
::IntIter_obj::__boot();
::nme::geom::Matrix_obj::__boot();
::nme::geom::Rectangle_obj::__boot();
::Std_obj::__boot();
::org::casalib::math::Percent_obj::__boot();
::List_obj::__boot();
::org::casalib::util::ArrayUtil_obj::__boot();
::ValueType_obj::__boot();
::Type_obj::__boot();
::org::casalib::util::RatioUtil_obj::__boot();
::org::casalib::math::Range_obj::__boot();
::EReg_obj::__boot();
::org::casalib::math::geom::Ellipse_obj::__boot();
::nme::geom::Point_obj::__boot();
::haxe::unit::TestStatus_obj::__boot();
::test::TestUtil_obj::__boot();
}

