CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: random_tester

random_tester: testme.c
	echo "Running tests for testme.c" > quiz.out
	gcc -o random_tester  testme.c $(CFLAGS)
	./random_tester

clean:
	rm random_tester

cleanall: 
	rm random_tester
