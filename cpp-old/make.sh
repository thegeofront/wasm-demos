emcc -O2 \
  -s EXPORTED_FUNCTIONS="['_add', '_substract']" \
  -s EXTRA_EXPORTED_RUNTIME_METHODS="['ccall']" \
  -o public/demo.js \
  test/lib.cpp


# emcc -o2 -s EXPORTED_FUNCTIONS="['_add', '_substract']" -s EXTRA_EXPORTED_RUNTIME_METHODS="['ccall']" -s MODULARIZE=1 -o public/demo.js test/lib.cpp

# emcc test/quick_example.cpp -O2 -lembind -o public/quick_example.js 
  