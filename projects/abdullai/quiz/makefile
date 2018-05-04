CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: quiz.out

quiz.out: testme.c
	echo "Running tests for testme.c" > quiz.out
	gcc -o random_tester  testme.c $(CFLAGS)
	# ./random_tester >> quiz.out
	./random_tester
	# gcov testme.c >> quiz.out -b


clean:
	rm quiz.out

cleanall: 
	rm quiz.out random_tester *.gcda *.gcno *.gcov
