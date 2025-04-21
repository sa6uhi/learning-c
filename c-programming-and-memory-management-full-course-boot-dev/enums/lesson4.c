#include <stdio.h>

typedef enum {
    BIG = 123412341234,
    BIGGER,
    BIGGEST,
} BigNumbers;

typedef enum {
    HTTP_BAD_REQUEST = 400,
    HTTP_UNAUTHORIZED = 401,
    HTTP_NOT_FOUND = 404,
    HTTP_I_AM_A_TEAPOT = 418,
    HTTP_INTERNAL_SERVER_ERROR = 500
} HttpErrorCode;

int main() {
    printf("The size of BigNumbers is %zu bytes\n", sizeof(BigNumbers));
    printf("The size of HttpErrorCode is %zu bytes\n", sizeof(HttpErrorCode));
    return 0;
}

// The size of the enum type is not the sum of all its values or members - it's the size needed to store any one of its possible values. Since all enum constants share the same type, the total size is just the size needed for the largest value.
