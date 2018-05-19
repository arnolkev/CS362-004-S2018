#include <stdio.h>
#include "assertTrue.h"

int assertTrue(int condition, char* message) {

    if (condition) {
        printf("TEST PASSED: %s\n", message);
    } else {
        printf("TEST FAILED: %s\n", message);
    }

    return 0;
}