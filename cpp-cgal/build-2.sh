emcmake cmake .
emcc \
  -I usr/include/CGAL/Cartesian.h \
  -l embind \
  -o cgal.js \
  -s MODULARIZE=1 \
  cgal.cpp

