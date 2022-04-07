// quick_example.cpp
#include <string>
#include <vector>

#include <math.h>

#include <CGAL/Cartesian.h>
#include <CGAL/squared_distance_2.h> 

#include <emscripten/bind.h>

typedef CGAL::Cartesian<double> K;
typedef K::Point_2 Point_2;
typedef K::Vector_2 Vector_2;


bool something(double x, double y) {
    Point_2 p(x, y), q;
    Vector_2 v = p - CGAL::ORIGIN;
    q = CGAL::ORIGIN + v;
    
    return (p == q);
}

double distance(double x1, double y1, double x2, double y2) {
    Point_2 p(x1, y1), q(x2, y2);
    double dis_squared = CGAL::squared_distance(p, q);
    return std::pow(dis_squared, 0.5);
}

typedef double N;

N lerp(N a, N b, N t) {
    return (1.0 - t) * a + t * b;
}

std::vector<N> multiLerp(N a, N b, std::vector<N> vector) {
    
    std::vector<N> result(vector.size());

    for (int i = 0; i < vector.size(); i++) {  
        result[i] = lerp(a, b, vector[i]);
    }   

    return result;
}

std::vector<N> returnVectorData () {
  std::vector<N> v{1000.0, 4039.0, 834.0, 2.0};
  return v;
}


using namespace emscripten;

EMSCRIPTEN_BINDINGS(embind_demo) {
    // types
    register_vector<N>("DoubleVector");

    // functions
    function("returnVectorData", &returnVectorData);
    function("multiLerp", &multiLerp);
    function("lerp", &lerp);
    function("something", &something);
    function("distance", &distance);
}

int main() {
    return 0;
}