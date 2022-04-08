# original
# emcc lerp.cpp \
#   -lembind \
#   -o lerp.js \
#   -s MODULARIZE=1

emcc lerp.cpp \
  -lembind \
  -o lerp.mjs \
  -s MODULARIZE=1