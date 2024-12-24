CXX ?= g++
CXXFLAGS ?= -Wall -Werror -pedantic -g --std=c++11 -Wno-sign-compare -Wno-comment -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG

rocket-task-1.exe: rocket_task1.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

rocket-task-2.exe: rocket_task2.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

rocket-task-3.exe: rocket_task3.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

rocket-task-4.exe: rocket_task4.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm *.exe