// quick_example.cpp
#include <emscripten/bind.h>
#include <string>
#include <vector>

using namespace emscripten;

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

EMSCRIPTEN_BINDINGS(embind_demo) {
    // types
    register_vector<N>("DoubleVector");

    // functions
    function("returnVectorData", &returnVectorData);
    function("multiLerp", &multiLerp);
    function("lerp", &lerp);
}