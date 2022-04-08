
// CGAL. NOTE: we include cartesian, since exact predicates rely on features of boost which are difficult to translate to wasm

// Based on: https://doc.cgal.org/latest/Manual/tuto_gis.html
#include <CGAL/Cartesian.h>
// #include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Projection_traits_xy_3.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/Point_set_3.h>

#include <CGAL/IO/read_xyz_points.h>
#include <CGAL/IO/write_xyz_points.h>

#include <CGAL/property_map.h>

// PROBLEMS: because this means compiling lastools
// #include <CGAL/IO/read_las_points.h>

#include <emscripten/bind.h>
#include <emscripten/val.h>

#include <string>



using Kernel = CGAL::Cartesian<double>;
// using Kernel = CGAL::Exact_predicates_inexact_constructions_kernel;

using Projection_traits = CGAL::Projection_traits_xy_3<Kernel>;
using Point_2 = Kernel::Point_2;
using Point_3 = Kernel::Point_3;
using Segment_3 = Kernel::Segment_3;
using TIN = CGAL::Delaunay_triangulation_2<Projection_traits>;
using Mesh = CGAL::Surface_mesh<Point_3>;
using Point_set_3 = CGAL::Point_set_3<Point_3>;

using Color = std::array<unsigned short, 4>;
using PointWithColor = std::pair<Point_3, Color>;

using namespace emscripten;

// Mesh dsm_from_points(Point_set_3 points) {
//     // Create DSM
//     TIN dsm (points.points().begin(), points.points().end());
//     Mesh dsm_mesh;
//     CGAL::copy_face_graph(dsm, dsm_mesh);
//     return dsm_mesh;
// }

// https://emscripten.org/docs/porting/connecting_cpp_and_javascript/embind.html#memory-views
// emscripten::val getInt8Array() {
//     return emscripten::val(
//         emscripten::typed_memory_view(
//             buffer->size(),
//             buffer->data()
//         )
//     );
// }

// int read_laz(std::string laz) {   
//     std::stringstream stream(laz);
//     std::vector<Point_3> points;
//     bool success = CGAL::read_las_points(stream, std::back_inserter(points));
//     if (!success) {
//         std::cout << "could not read xyz" << std::endl; 
//     }
//     return points.size(); // return the number of points
// }

// int read_laz(std::string laz) {

//     std::stringstream stream(laz);  
//   const char* fname = (argc>1) ? argv[1] : "data/pig_points.las";
//   // Reads a .las point set file with normal vectors and colors
//   std::ifstream in(fname, std::ios_base::binary);
//   std::vector<PointWithColor> points; // store points
//   if(!CGAL::IO::read_LAS_with_properties(in, std::back_inserter (points),
//                                          CGAL::IO::make_las_point_reader(CGAL::First_of_pair_property_map<PointWithColor>()),
//                                          std::make_tuple(CGAL::Second_of_pair_property_map<PointWithColor>(),
//                                                          CGAL::Construct_array(),
//                                                          CGAL::IO::LAS_property::R(),
//                                                          CGAL::IO::LAS_property::G(),
//                                                          CGAL::IO::LAS_property::B(),
//                                                          CGAL::IO::LAS_property::I())))
//   {
//     std::cerr << "Error: cannot read file " << fname << std::endl;
//     return EXIT_FAILURE;
//   }
//   for(std::size_t i = 0; i < points.size(); ++ i)
//     std::cout << points[i].first << std::endl;
//   return EXIT_SUCCESS;
// }


std::vector<Point_3> get_some_points() {
    std::vector<Point_3> points; // store points
    for (int i = 0; i < 10; ++ i) {
        points.push_back(Point_3 (i, 1.0 - i, 1.0 / (i + 1.0)));
    }
    return points;
}

// empty if failure to read
std::vector<Point_3> read_points(std::string xyz) {
    
    std::stringstream stream(xyz);
    std::vector<Point_3> points;
    bool success = CGAL::read_xyz_points(stream, std::back_inserter(points));
    if (!success) {
        std::cout << "could not read xyz" << std::endl; 
    }
    return points;
}

std::string write_points(std::vector<Point_3> points) {
    std::stringstream stream;
    CGAL::write_xyz_points(stream, points);
    // CGAL::IO::write_XYZ(stream, &points, nullptr); // GRRRRRRRR.... OUTDATED DOCS....
    return stream.str();
}

std::string dsm_from_points(std::string xyz) {
    // in
    // Point_set_3 points = read_points(xyz);

    // Create DSM
    // TIN dsm (points.points().begin(), points.points().end());
    // Mesh dsm_mesh;
    // CGAL::copy_face_graph(dsm, dsm_mesh);
    
    // out
    // std::ofstream dsm_ofile("dsm.ply", std::ios_base::binary);
    // CGAL::IO::set_binary_mode dsm_ofile);
    // CGAL::IO::write_PLY(dsm_ofile, dsm_mesh);
    // dsm_ofile.close();  
    return "";
}

std::string demo() {

    auto points = get_some_points();
    auto str = write_points(points);
    auto copy = read_points(str);
    auto copy_str= write_points(copy);
    return str;
}

EMSCRIPTEN_BINDINGS(embind_demo) {
    function("demo", &demo);
    function("readPoints", &read_points);
    function("writePoints", &write_points);
    // function("getInt8Array", &getInt8Array);
    // function("readLaz", &read_laz);
}