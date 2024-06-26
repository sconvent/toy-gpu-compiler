default: run

%.ll: %.toy
	../build/tgc $< > $@

%.ptx: %.ll
	/usr/lib/llvm-15/bin/llc $< -o $@

nvptx: addition.ptx

main.app: main.cpp
	clang++ main.cpp -o main.app -g -I/usr/local/cuda/include -L/usr/lib/wsl/lib -lcuda

run: nvptx main.app
	./main.app
