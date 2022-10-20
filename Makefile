CXX = g++

# compiler flags:
# -g adds debugging information to the executeable file.
#  -wall turns on most, but not all, compiler warnings.

CXXFLAGS = -g -Wall

OBJECTS = SimulationRunner.o

TESTS = GraphTest

main: main.cpp $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

GraphTest: Tests/GraphTest.cpp CityGraph.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf *.dSYM
		$(RM) *.o *.gc main $(TESTS)
