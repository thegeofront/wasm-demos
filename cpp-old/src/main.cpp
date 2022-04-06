#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polygon_2.h>
#include <iostream>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point;
typedef CGAL::Polygon_2<K> Polygon_2;

Polygon_2 polygon_from_list(std::vector<double> values) {
    assert(values.size() % 2 == 0);
    Polygon_2 p;
    for (auto i = 0 ; i < values.size(); i += 2) {
        p.push_back(Point(values[i], values[i+1]));
    }
    return p;
}

double get_area(std::vector<double> values) {
    return polygon_from_list(values).area();
}

int main()
{
    Point points[] = { Point(0,0), Point(5.1,0), Point(1, 1), Point(0.5, 6), Point(0.6, 9) };
    
    double values[] = { 0.0, 0.0, 5.1, 0.0, 1.0, 1.0, 0.5, 6 };
    Polygon_2 lin_pgn();
    Polygon_2 pgn(points, points+5);
    std::cout << "The polygon is " <<
        (pgn.is_simple() ? "" : "not ") << "simple." << std::endl;
    std::cout << "The polygon is " <<
        (pgn.is_convex() ? "" : "not ") << "convex." << std::endl;    
    std::cout << "The area of polygon is " <<
        (pgn.area()) << "." << std::endl;

    auto p = get_area({5,6, 8,9, 3,2, 6,0});

    std::cout << p << std::endl;

    return 0;
}

