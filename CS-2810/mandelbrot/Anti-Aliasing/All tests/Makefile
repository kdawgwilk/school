.SUFFIXES:
.SUFFIXES: .asm .o .cpp
ASMSOURCE=$(wildcard *.asm)
ASMTARGET=$(ASMSOURCE:.asm=.o)
CPPSOURCE=$(wildcard tests/*.cpp)

all: grade

grade: a.out
	./a.out

debug: a.out
	gdb ./a.out

.asm.o:
	nasm -f elf64 -g -F dwarf $<

a.out: $(ASMTARGET) $(CPPSOURCE)
	g++ -std=c++11 -Wpedantic -g -Wall -Wextra -Werror -I. -pthread $(ASMTARGET) $(CPPSOURCE) -lgtest -lpthread

setup:
	# install nasm, etc., and the sources for gtest
	sudo apt-get install build-essential gdb nasm libgtest-dev
	# build the gtest unit test library
	g++ -std=c++11 -Wpedantic -g -Wall -Wextra -Werror -I/usr/src/gtest -pthread -c /usr/src/gtest/src/gtest-all.cc
	g++ -std=c++11 -Wpedantic -g -Wall -Wextra -Werror -I/usr/src/gtest -pthread -c /usr/src/gtest/src/gtest_main.cc
	ar rv gtest_main.a gtest-all.o gtest_main.o
	rm -f gtest-all.o gtest_main.o
	sudo mv gtest_main.a /usr/local/lib/libgtest.a
	sudo chmod 644 /usr/local/lib/libgtest.a
	sudo chown root:root /usr/local/lib/libgtest.a

clean:
	rm -f a.out *.o
