# https://stackoverflow.com/questions/55869531/how-to-use-emscripten-with-cmake-for-project-dependencies
# This example worked for someone
# emcc  
#    latuile.cpp \
#    binpack.cpp \
#    compact_frame.cpp \
#    compact_rectangles.cpp \
#    fit_together.cpp \
#    KMeansRexCore.cpp \
#    MPD_Arc.cpp \
#    MyRect.cpp \
#    optimize_rectangle_positions.cpp \
#    permutation.cpp \
#    stair_steps.cpp \
#    swap_rectangles.cpp \
#    WidgetContext.cpp \
#    FunctionTimer.cpp \
#    -o latuile.js \
#    -I/usr/include/eigen3 \
#    -Wno-c++11-narrowing \
#    -s EXPORTED_FUNCTIONS='["_latuile"]' \
#    -s EXPORTED_RUNTIME_METHODS='["ccall","cwrap"]' \
#    -s ALLOW_MEMORY_GROWTH=1 \

# try 0
# emcc \
#    -l embind \
#    -o cgal.js \
#    cgal.cpp 

# try 1
# -> emcc: error: CGAL/Cartesian.h: No such file or directory ("CGAL/Cartesian.h" was expected to be an input file, based on the commandline arguments provided)
# emcc \
#    -I usr/include/CGAL \
#    -l embind \
#    -o cgal.js \
#    cgal.cpp \
#    CGAL/Cartesian.h
# 

# try 2
# -> cgal.cpp:4:10: fatal error: 'CGAL/Cartesian.h' file not found
# emcc \
#    -I usr/include/CGAL/Cartesian.h \
#    -l embind \
#    -o cgal.js \
#    cgal.cpp \
#

# try 3
# `-> emcc: error: cannot mix precompiled headers with non-header inputs: ['cgal.cpp', '/usr/include/CGAL/Cartesian.h'] : cgal.cpp`
# emcc \
#    -l embind \
#    -o cgal.js \
#    cgal.cpp \
#    /usr/include/CGAL/Cartesian.h
# 

# try 4
# https://github.com/emscripten-core/emscripten/issues/7716
# 
# LOG: I now copy-pasted everything in /usr/include/CGAL to /CGAL in this directory
#
# RESULT IS PROMISING: 
# 
# cgal.cpp:4:10: error: 'CGAL/Cartesian.h' file not found with <angled> include; use "quotes" instead
# #include <CGAL/Cartesian.h>
#          ^~~~~~~~~~~~~~~~~~
#          "CGAL/Cartesian.h"
# In file included from cgal.cpp:4:
# ./CGAL/Cartesian.h:20:10: fatal error: 'CGAL/Cartesian/Cartesian_base.h' file not found
# #include <CGAL/Cartesian/Cartesian_base.h>
# 
# So something is getting included
#
# emcc \
#    -I /CGAL \
#    -l embind \
#    -o cgal.js \
#    cgal.cpp \


# try 5 
# emcc \
#    -I CGAL \
#    -l embind \
#    -o cgal.js \
#    cgal.cpp \
# CGAL/stddef.h:10:2: error: You have added .../path/to/CGAL-x.y/include/CGAL to the INCLUDE path. You should use .../path/to/CGAL-x.y/include instead.

# try 6 
# CGAL_DIR 
# emcc \
#    -s DCGAL_DIR=CGAL
#    -l embind \
#    -o cgal.js \
#    cgal.cpp \
# NOPE....

# THIS WORKS: only the console still gives us some errors
# emcc cgal.cpp \
# -I/home/feenster/dev/geofront/wasm-demos/cpp-cgal/includes/ \
#   -lembind \
#   -o cgal.js \
#   -s MODULARIZE=1 \
#   -DCGAL_NO_GMP=1 \

# WARNING WHEN BUILDING
# warning: overriding currently unsupported rounding mode on this target [-Wunsupported-floating-point-opt]

# CONSOLE.LOG: 
# CGAL error: assertion violation! cgal.js:3910:16
# Expression : -CGAL_IA_MUL(-1.1, 10.1) != CGAL_IA_MUL(1.1, 10.1) cgal.js:3910:16
# File       : /home/feenster/dev/geofront/wasm-demos/cpp-cgal/includes/CGAL/Interval_nt.h cgal.js:3910:16
# Line       : 280 cgal.js:3910:16
# Explanation: Wrong rounding: did you forget the  -frounding-math  option if you use GCC (or  -fp-model strict  for Intel)? cgal.js:3910:16
# Refer to the bug-reporting instructions at https://www.cgal.org/bug_report.html cgal.js:3910:16
# Uncaught (in promise) 5268472 - Exception catching is disabled, this exception cannot be caught. Compile with -s NO_DISABLE_EXCEPTION_CATCHING or -s EXCEPTION_CATCHING_ALLOWED=[..] to catch.

# TALKING ABOUT ROUNDING ERROR WHEN PORTING OPENSCAD (WHICH USES CGAL)
# https://github.com/openscad/openscad/issues/259

# OPENSCAD JUST DISABLES ROUNDING MATH CHECKS, SO I THINK IT IS SAVE TO DO THE SAME
# if(WASM)
#   set(NULLGL ON)
#   set(ENV{PKG_CONFIG_PATH} "/emsdk/upstream/emscripten/cache/sysroot/lib/pkgconfig")
#   target_compile_definitions(OpenSCAD PRIVATE CGAL_DISABLE_ROUNDING_MATH_CHECK)
# endif()

# FOUND WEBASSEMBLY IN OPENSCAD https://openscad.org/downloads.html
# THIS IS HOW THEY DID IT https://github.com/DSchroer/openscad-wasm/blob/master/Makefile

# THIS IS ALSO REALLY IMPORTANT https://github.com/marcosscriven/cgaljs/tree/master/examples/cgal
# PROBLEM IS : its old. 5 years since last commit. CGAL has since then been converted to a header only library

# THIS FINALLY WORKS!!!
# emcc cgal.cpp \
# -I/home/feenster/dev/geofront/wasm-demos/cpp-cgal/includes/ \
#   -O3 \
#   -lembind \
#   -o cgal.js \
#   -s MODULARIZE=1 \
#   -DCGAL_NO_GMP=1 \
#   -DCGAL_DISABLE_ROUNDING_MATH_CHECK

# now moving over to regular makefile