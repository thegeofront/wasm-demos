# NOTE : im still a noob. keep this close: https://makefiletutorial.com/

main: build-using-local-includes

install: 
	@echo "-------------------------------------------------------------------"
	@echo " TODO: install CGAL & boost, and put them in the ./includes folder "
	@echo "-------------------------------------------------------------------"

build-using-local-includes: 
	@echo "building cgal.cpp..."
	@emcc cgal.cpp \
	-I/home/feenster/dev/geofront/wasm-demos/cpp-cgal/includes/ \
	-O3 \
	-lembind \
	-o cgal.js \
	-s MODULARIZE=1 \
	-DCGAL_NO_GMP=1 \
	-DCGAL_DISABLE_ROUNDING_MATH_CHECK
	@echo "done!"