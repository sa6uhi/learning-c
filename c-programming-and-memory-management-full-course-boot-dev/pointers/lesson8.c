#include <stdio.h>

int main() {
    // Integer Array
    int numbers[5] = {1, 2, 3, 4, 5};

    // Iterate and print each element
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    /*
    Updating Values in an Array
    The syntax for updating values in an array is the same as how you access them:
    arr[index] = value
    Using our numbers example:
    */

    // Update some values
    numbers[1] = 20;
    numbers[3] = 40;

    // Print updated array
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}

void update_file(int filedata[200], int new_filetype, int new_num_lines){
    filedata[1] = new_num_lines;
    filedata[2] = new_filetype;
    filedata[199] = 0;
}
  