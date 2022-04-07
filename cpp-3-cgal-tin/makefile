# NOTE : im still a noob. keep this close: https://makefiletutorial.com/

main: build-using-local-includes

install: 
	@echo "-------------------------------------------------------------------"
	@echo " please download CGAL & boost, and put them in the wasm-demos/includes folder: "
	@echo "-------------------------------------------------------------------"
	@echo "$ cp -R /usr/include/cgal ../include"
	@echo "$ cp -R /usr/include/boost ../include"

build-using-local-includes: 
	@echo "building tin.cpp..."
	@emcc tin.cpp \
	-I/home/feenster/dev/geofront/wasm-demos/_includes/ \
	-O3 \
	-lembind \
	-o tin.js \
	-s MODULARIZE=1 \
	-DCGAL_NO_GMP=1 \
	-DCGAL_DISABLE_ROUNDING_MATH_CHECK
	@echo "done!"