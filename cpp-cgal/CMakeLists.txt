cmake_minimum_required(VERSION 3.0.0)

project(cgal-wasm-demo VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

# CGAL.
set(CGAL_DIR $ENV{CGAL_DIR})
find_package( CGAL )
message(STATUS "CGAL_LIBRARIES=${CGAL_LIBRARIES}")

if(CGAL_Qt5_FOUND)
    add_definitions(-DCGAL_USE_BASIC_VIEWER -DQT_NO_KEYWORDS)
endif()

include_directories( includes )

set( MY_EXE cgal-demo )
add_executable( ${MY_EXE} cgal.cpp )
target_link_libraries( ${MY_EXE} ${CGAL_LIBRARIES} )

# # CGAL
# set(CGAL_DIR $ENV{CGAL_DIR})
# find_package(CGAL REQUIRED COMPONENTS Qt5 OPTIONAL_COMPONENTS Core )
# message(STATUS "CGAL_LIBRARIES=${CGAL_LIBRARIES}")

# if(CGAL_Qt5_FOUND)
#     add_definitions(-DCGAL_USE_BASIC_VIEWER -DQT_NO_KEYWORDS)
# endif()

# # find_package( CGAL )
# # find_package( GDAL)
# # find_package( CGAL::Qt )

# include(CTest)
# enable_testing()

# add_executable(cpp-demo main.cpp)
# target_link_libraries(cpp-demo CGAL)
# # target_link_libraries(cpp-demo CGAL::CGAL_Basic_viewer )
# # target_link_libraries(cpp-demo GDAL)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)



