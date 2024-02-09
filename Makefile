PYTHON ?= python3

.PHONY: build
build:
	kaitai-struct-compiler -t python --outdir build --python-package build decoder.ksy

.PHONY: graphviz
	kaitai-struct-compiler -t graphviz rtps.ksy

