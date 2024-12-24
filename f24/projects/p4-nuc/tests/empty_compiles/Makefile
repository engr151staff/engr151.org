CXX ?= g++
CXXFLAGS ?= -Wall -Werror -pedantic -g --std=c++11 -Wno-sign-compare -Wno-comment -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG

tcgen.exe: tcGenerator.cpp radionuc.hpp molybdenum.hpp technetium.hpp
	$(CXX) $(CXXFLAGS) tcGenerator.cpp -o $@

testradionuc.exe: testRadionuc.cpp radionuc.hpp
	$(CXX) $(CXXFLAGS) testRadionuc.cpp -o $@

clean:
	rm -f *.exe *.o *.out