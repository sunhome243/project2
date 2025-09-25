test: test_minqueue.cpp minqueue.h minqueue.cpp
	make clean
	g++ -o test test_minqueue.cpp
	./test
#TODO: needs to be fixed. this is just for a test.
clean:
	rm -f test