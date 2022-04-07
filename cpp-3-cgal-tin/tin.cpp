
// CGAL. NOTE: we include cartesian, since exact predicates rely on features of boost which are difficult to translate to wasm

#include <CGAL/Cartesian.h>
// #include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Projection_traits_xy_3.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/Point_set_3.h>

#include <CGAL/IO/read_xyz_points.h>
#include <CGAL/IO/write_xyz_points.h>

#include <emscripten/bind.h>
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

using namespace emscripten;

// Mesh dsm_from_points(Point_set_3 points) {
//     // Create DSM
//     TIN dsm (points.points().begin(), points.points().end());
//     Mesh dsm_mesh;
//     CGAL::copy_face_graph(dsm, dsm_mesh);
//     return dsm_mesh;
// }

// std::string dsm_from_points_str(std::string points) {
//     // in
//     Point_set_3 points;
//     // DO MAGIC

//     // pros
//     auto mesh = dsm_from_points(points);

//     // out
//     std::ofstream dsm_ofile ("dsm.ply", std::ios_base::binary);
//     CGAL::IO::set_binary_mode (dsm_ofile);
//     CGAL::IO::write_PLY (dsm_ofile, dsm_mesh);
//     dsm_ofile.close();  
// }

int read_points(std::string points) {

    // bool CGAL::IO::read_PLY(points,
	// 	PointOutputIterator  	output,
	// 	const NamedParameters &  	np 
	// ) 	
    // return 10;
    return 0;
}

std::string write_points() {
    std::vector<Point_3> points; // store points
    for (int i = 0; i < 10; ++ i) {
        points.push_back(Point_3 (i, 1.0 - i, 1.0 / (i + 1.0)));
    }
    std::stringstream stream;
    CGAL::write_xyz_points(stream, points);
    // CGAL::IO::write_XYZ(stream, &points, nullptr); // GRRRRRRRR.... OUTDATED DOCS....
    return stream.str();
}


std::string get_some_string() {
    return "henkenkaasmoeder";
}

EMSCRIPTEN_BINDINGS(embind_demo) {
    function("getSomeString", &get_some_string);
    function("readPoints", &read_points);
    function("writePoints", &write_points);
}