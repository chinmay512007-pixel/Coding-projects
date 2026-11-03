all: railcast

railcast:
	gcc -Wall -Wextra -Wpedantic main.c Trains.c ETA.c file_handler.c -o railcast -lm

test:
	gcc -Wall -Wextra -Wpedantic -c ETA.c -o ETA_test.o
	gcc -Wall -Wextra -Wpedantic -c Trains.c -o Trains_test.o
	g++ -Wall -Wextra -Wpedantic gtest.cpp ETA_test.o Trains_test.o -o test_railcast $$(pkg-config --cflags --libs gtest_main) -lm
	./test_railcast

run: railcast
	./railcast

clean:
	rm -f railcast test_railcast ETA_test.o Trains_test.o

.PHONY: all railcast test run clean