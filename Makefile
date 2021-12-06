EXE = main
TEST = test

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

OBJS = data.o graph.o algorithms.o

EXE_OBJS = $(OBJS) main.o

all: $(EXE)

$(EXE): $(EXE_OBJS)
	$(LD) $(EXE_OBJS) $(LDFLAGS) -o $(EXE)

main.o : main.cpp
	$(CXX) $(CXXFLAGS) main.cpp