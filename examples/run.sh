#! /bin/bash

../build/tgc ./addition.toy > ./addition.ll
#../build/tgc ./saxpy.toy > ./saxpy.ll

/usr/lib/llvm-15/bin/llc ./addition.ll -o ./addition.ptx
#/usr/lib/llvm-15/bin/llc ./saxpy.ll -o ./saxpy.ptx
