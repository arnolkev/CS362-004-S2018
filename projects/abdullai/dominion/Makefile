CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: unittestresults.out

unittestresults.out: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.c rngs.c test_utils.c
	echo "Result for running Dominion tests:" > unittestresults.out

	echo "unittest1.c:" >> unittestresults.out
	gcc -o unittest1  dominion.c rngs.c test_utils.c unittest1.c $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out -b

	echo "unittest2.c:" >> unittestresults.out
	gcc -o unittest2  dominion.c rngs.c test_utils.c unittest2.c $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out -b

	echo "unittest3.c:" >> unittestresults.out
	gcc -o unittest3  dominion.c rngs.c test_utils.c unittest3.c $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out -b

	echo "unittest4.c:" >> unittestresults.out
	gcc -o unittest4  dominion.c rngs.c test_utils.c unittest4.c $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out -b

	echo "cardtest1.c:" >> unittestresults.out
	gcc -o cardtest1  dominion.c rngs.c test_utils.c cardtest1.c $(CFLAGS)
	./cardtest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out -b

	echo "cardtest2.c:" >> unittestresults.out
	gcc -o cardtest2  dominion.c rngs.c test_utils.c cardtest2.c $(CFLAGS)
	./cardtest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out -b

	echo "cardtest3.c:" >> unittestresults.out
	gcc -o cardtest3  dominion.c rngs.c test_utils.c cardtest3.c $(CFLAGS)
	./cardtest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out -b

	echo "cardtest4.c:" >> unittestresults.out
	gcc -o cardtest4  dominion.c rngs.c test_utils.c cardtest4.c $(CFLAGS)
	./cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out -b

clean:
	rm unittestresults.out

cleanall: 
	rm unittestresults.out unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4*.gcda *.gcno *.gcov
