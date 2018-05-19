#include "container.h"

//Check that removeAll works as expected. E.g., it removes all instance of a number
void test1() {
    container* cont = newContainer();
    add(1, cont);
    add(2, cont);
    add(1, cont);
    add(4, cont);
    add(1, cont);
    removeAll(1, cont);

    //check that the size decreased by three
    assert(size(cont) == 2);

    //check that container does not have 1 anymore
    assert(get(1, cont) == 0);

    //check that container still has 2 and 4
    assert(get(2, cont) == 1);
    assert(get(4, cont) == 1);
}

//Check that calling removeAll does not remove other numbers from container if there are no matches
void test2() {
    container* cont = newContainer();
    add(1, cont);
    add(2, cont);
    removeAll(3, cont);

    //check that the size decreased by three
    assert(size() == 2);
    assert(get(1, cont) == 1);
    assert(get(2, cont) == 1);
}

//Stress test: try running removeAll for many numbers in a container
void test3() {
    container* cont = newContainer();
    for (int i = 0; i < 10000; i++) {
        add(12345, cont);
    }
    removeAll(12345, cont);
    assert(size(cont) == 0);
    assert(get(12345, cont) == 0);
}


int main() {
    test1();
    test2();
    test3();
    return 0;
}