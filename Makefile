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

CPP_TEST = $(wildcard tests/*.cpp)
CPP_TEST += catch/catchmain.cpp
TEST_OBJS = $(OBJS) $(CPP_TEST:.cpp=.o)

# Full Test
#test: catch/catchmain.cpp tests/test_parsing.cpp tests/test_graph.cpp tests/test_algorithms.cpp data/data.cpp graph/graph.cpp graph/algorithms.cpp
#	$(LD) catch/catchmain.cpp tests/test_parsing.cpp tests/test_graph.cpp tests/test_algorithms.cpp data/data.cpp graph/graph.cpp graph/algorithms.cpp $(LDFLAGS) -o test

# Graph Unit Test
#test: catch/catchmain.cpp tests/test_graph.cpp data/data.cpp graph/graph.cpp
#	$(LD) catch/catchmain.cpp tests/test_graph.cpp data/data.cpp graph/graph.cpp $(LDFLAGS) -o test

# Algorithm Unit Test
test: catch/catchmain.cpp tests/test_graph.cpp tests/test_algorithms.cpp data/data.cpp graph/graph.cpp graph/algorithms.cpp
	$(LD) catch/catchmain.cpp tests/test_graph.cpp tests/test_algorithms.cpp data/data.cpp graph/graph.cpp graph/algorithms.cpp $(LDFLAGS) -o test

catchmain.o: catch/catchmain.cpp
	$(CXX) $(CXXFLAGS) catch/catchmain.cpp

data.o : data/data.cpp
	$(CXX) $(CXXFLAGS) data/data.cpp

graph.o : graph/graph.cpp
	$(CXX) $(CXXFLAGS) graph/graph.cpp

algorithms.o : graph/algorithms.cpp
	$(CXX) $(CXXFLAGS) graph/algorithms.cpp

clean:
	$(RM) $(EXE) .o tests/.o