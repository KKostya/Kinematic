GTESTPATH=$(HOME)/Physics/googletest

%.o: %.cpp ../kinematic.hpp
	g++ --std=c++11 -g -c $^ -I$(GTESTPATH)/include/ -I.. 

test: test_single.o test_vector.o 
	g++ --std=c++11 -o $@ $^ -L$(GTESTPATH)/lib/ -pthread -lgtest -lgtest_main

clean:
	rm -rf *.o 
	rm test