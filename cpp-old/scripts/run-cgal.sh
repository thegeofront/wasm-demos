emcc src/main.cpp \
    -s LINKABLE=1 \
    -s EXPORT_ALL=1 \
    -s EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' \
    -s WASM=1 -o build-emcc/lib.js -O2