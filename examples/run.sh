#! /bin/bash

../build/tgc ./example1.toy > ./example1.ll
../build/tgc ./example2.toy > ./example2.ll
../build/tgc ./example3.toy > ./example3.ll
../build/tgc ./saxpy.toy > ./saxpy.ll

/usr/lib/llvm-15/bin/llc ./example1.ll -o ./example1.ptx
/usr/lib/llvm-15/bin/llc ./example2.ll -o ./example2.ptx
/usr/lib/llvm-15/bin/llc ./example3.ll -o ./example3.ptx
/usr/lib/llvm-15/bin/llc ./saxpy.ll -o ./saxpy.ptx
