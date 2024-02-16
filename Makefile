PYTHON ?= python3

.PHONY: build

.PHONY: graphviz

graphviz: rtps.ksy
	kaitai-struct-compiler -t graphviz rtps.ksy

build: rtps.ksy decoder.ksy
	kaitai-struct-compiler -t python --outdir build --python-package build decoder.ksy
	kaitai-struct-compiler --target cpp_stl rtps.ksy

decoder: decoder.cpp
	clang++ -o decoder -std=c++11 -I /opt/homebrew/opt/libpcap/include decoder.cpp rtps.cpp /opt/homebrew/opt/libpcap/lib/libpcap.a /usr/local/lib/libkaitai_struct_cpp_stl_runtime.dylib