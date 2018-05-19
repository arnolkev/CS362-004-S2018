CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: cleanall tests

tests: alltests.c randomtestadventurer.c randomtestcard1.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.c rngs.c test_utils.c
	echo "cardtest1.c:" >> cardtests.out
	gcc -o cardtest1  dominion.c rngs.c test_utils.c cardtest1.c $(CFLAGS)
	./cardtest1 >> cardtests.out

	echo "cardtest2.c:" >> cardtests.out
	gcc -o cardtest2  dominion.c rngs.c test_utils.c cardtest2.c $(CFLAGS)
	./cardtest2 >> cardtests.out

	echo "cardtest3.c:" >> cardtests.out
	gcc -o cardtest3  dominion.c rngs.c test_utils.c cardtest3.c $(CFLAGS)
	./cardtest3 >> cardtests.out

	echo "cardtest4.c:" >> cardtests.out
	gcc -o cardtest4  dominion.c rngs.c test_utils.c cardtest4.c $(CFLAGS)
	./cardtest4 >> cardtests.out

	gcc -o randomtestadventurer dominion.c rngs.c test_utils.c randomtestadventurer.c $(CFLAGS)
	./randomtestadventurer >> randomtestadventurer.out

	gcc -o randomtestcard1 dominion.c rngs.c test_utils.c randomtestcard1.c $(CFLAGS)
	./randomtestcard1 >> randomtestcard1.out

	gcc -o randomtestcard2 dominion.c rngs.c test_utils.c randomtestcard2.c $(CFLAGS)
	./randomtestcard2 >> randomtestcard2.out

	gcc -o alltests dominion.c rngs.c test_utils.c alltests.c $(CFLAGS)
	./alltests >> alltestsresults.out
	gcov dominion.c >> alltestscoverage.out -b

clean:
	rm -f cardtests.out randomtestadventurer.out randomtestcard1.out randomtestcard2.out

cleanall:
	rm -f cardtests.out cardtest1 cardtest2 cardtest3 cardtest4 randomtestadventurer.out randomtestadventurer randomtestcard1 randomtestcard1.out randomtestcard2 randomtestcard2.out *.gcda *.gcno *.gcov
