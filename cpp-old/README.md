# CPP

Demo project to toy with CGAL & GDAL

# Currently working on: 

This is probably what we are looking for : https://emscripten.org/docs/porting/connecting_cpp_and_javascript/WebIDL-Binder.html?highlight=modularize

Taken from there: 
## Binding using the WebIDL Binder is a three-stage process:

Create a WebIDL file that describes the C++ interface.

Use the binder to generate C++ and JavaScript “glue” code.

Compile this glue code with the Emscripten project.







# shellscripts


```
cmake --build ./build --config Debug --target all && ./build/cpp-demo
```

A simple hello world
```
emcc test/hello.cpp -o build-emcc/app.js
emcc -o2 test/hello.cpp -o build-emcc/app.js
```

A demo containing graphics
```

emcc test/hello.cpp -o build-emcc/app.js --cache ./.cache

```

testing a library
```
emcc -O2
    test/lib.cpp -o build-emcc/lib.js -s LINKABLE=1 -s EXPORT_ALL=1
```

# Tutorial notes: 

https://3d.bk.tudelft.nl/courses/geo1004//hw/0/

long story short : this is how you install gdal & cgal
```terminal
sudo add-apt-repository ppa:ubuntugis/ppa
sudo apt-get update
sudo apt-get install gdal-bin
sudo apt-get install libgdal-dev
sudo apt-get install libcgal-dev
```

this is how to get cmake working 
```
sudo apt-get install build-essential libssl-dev
cd /tmp
wget https://github.com/Kitware/CMake/releases/download/v3.20.0/cmake-3.20.0.tar.gz
tar -zxvf cmake-3.20.0.tar.gz
cd cmake-3.20.0
./bootstrap
make
sudo make install
```

check if this worked by using:
```
cmake --version 
```




Some other links: 
https://docs.microsoft.com/en-us/windows/wsl/setup/environment#file-storage
https://code.visualstudio.com/docs/cpp/config-wsl


# more tuts 
found a nice emscripten tutorial from 2018


https://www.youtube.com/watch?v=CLuhogat6aY
https://www.youtube.com/watch?v=t_R-nxHMWEg



NOTE: emscripten seems MUCH more convoluted than wasm-pack. It just does so many things, and makes so many assumptions about everyhting
example: it tries to be the full runtime. 


https://www.dynamsoft.com/codepool/webassembly-standalone-dynamic-linking-wasm.html