#include <stdio.h>

typedef union {
  int value;
  unsigned int err;
} val_or_err_t;

int main() {
    int const UINT_MAX = 4294967295;

    val_or_err_t lanes_score = {
        .value = -420
    };
    printf("value (set): %d\n", lanes_score.value);
    printf("err (unset): %u\n", lanes_score.err);

    
    val_or_err_t teejs_score = {
        .err = UINT_MAX
    };
    printf("value (unset): %d\n", teejs_score.value);
    printf("err (set): %u\n", teejs_score.err);
  
}
