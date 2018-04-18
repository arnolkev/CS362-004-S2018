CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: tests.out

tests.out: unittest1.c dominion.c rngs.c test_utils.c
	echo "Result for running Dominion tests:" > tests.out
	
	echo "unittest1.c:" >> tests.out
	gcc -o unittest1  dominion.c rngs.c test_utils.c unittest1.c $(CFLAGS)
	./unittest1 >> tests.out
	gcov dominion.c >> tests.out

clean:
	rm tests.out

cleanall: 
	rm tests.out unittest1 unittest2 unittest3 unittest4 *.gcda *.gcno *.gcov
