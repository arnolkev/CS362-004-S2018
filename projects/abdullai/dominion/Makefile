CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: tests.out

tests.out: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.c rngs.c test_utils.c
	echo "Result for running Dominion tests:" > tests.out

	echo "unittest1.c:" >> tests.out
	gcc -o unittest1  dominion.c rngs.c test_utils.c unittest1.c $(CFLAGS)
	./unittest1 >> tests.out
	gcov dominion.c >> tests.out

	echo "unittest2.c:" >> tests.out
	gcc -o unittest2  dominion.c rngs.c test_utils.c unittest2.c $(CFLAGS)
	./unittest2 >> tests.out
	gcov dominion.c >> tests.out

	echo "unittest3.c:" >> tests.out
	gcc -o unittest3  dominion.c rngs.c test_utils.c unittest3.c $(CFLAGS)
	./unittest3 >> tests.out
	gcov dominion.c >> tests.out

	echo "unittest4.c:" >> tests.out
	gcc -o unittest4  dominion.c rngs.c test_utils.c unittest4.c $(CFLAGS)
	./unittest4 >> tests.out
	gcov dominion.c >> tests.out

	echo "cardtest1.c:" >> tests.out
	gcc -o cardtest1  dominion.c rngs.c test_utils.c cardtest1.c $(CFLAGS)
	./cardtest1 >> tests.out
	gcov dominion.c >> tests.out

	echo "cardtest2.c:" >> tests.out
	gcc -o cardtest2  dominion.c rngs.c test_utils.c cardtest2.c $(CFLAGS)
	./cardtest2 >> tests.out
	gcov dominion.c >> tests.out

	echo "cardtest3.c:" >> tests.out
	gcc -o cardtest3  dominion.c rngs.c test_utils.c cardtest3.c $(CFLAGS)
	./cardtest3 >> tests.out
	gcov dominion.c >> tests.out

	echo "cardtest4.c:" >> tests.out
	gcc -o cardtest4  dominion.c rngs.c test_utils.c cardtest4.c $(CFLAGS)
	./cardtest4 >> tests.out
	gcov dominion.c >> tests.out

clean:
	rm tests.out

cleanall: 
	rm tests.out unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4*.gcda *.gcno *.gcov
