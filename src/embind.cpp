#include <emscripten/bind.h>

using namespace emscripten;

float lerp(float a, float b, float t) {
    return (1 - t) * a + t * b;
}

EMSCRIPTEN_BINDINGS(my_module) {
    function("lerp", &lerp);
}

//  emcc --bind -g src/embind.cpp -o embind.js  --source-map-base http://localhost:8888/src/