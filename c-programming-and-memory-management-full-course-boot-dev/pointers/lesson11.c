#include <stdio.h>

typedef struct Coordinate {
    int x;
    int y;
    int z;
} coordinate_t;

int main() {
    // Array Casting
    // Let's explore a special kind of psychopathy that's possible in C. 
    // Let's assume we have this array of 3 structs where each struct holds 3 integers:

    coordinate_t points[3] = {
    {5, 4, 1},
    {7, 3, 2},
    {9, 6, 8}
    };

    // Because arrays are basically just pointers (in most cases; more on that later), 
    // and we know that structs are contiguous in memory, we can cast the array of structs to an array of integers:
    int *points_start = (int *)points;
    // Then we can iterate over the known number of integers in the array of structs:

    for (int i = 0; i < 9; i++) {
    printf("points_start[%d] = %d\n", i, points_start[i]);
    }
    /*
    points_start[0] = 5
    points_start[1] = 4
    points_start[2] = 1
    points_start[3] = 7
    points_start[4] = 3
    points_start[5] = 2
    points_start[6] = 9
    points_start[7] = 6
    points_start[8] = 8
    */
}

void dump_graphics(graphics_t gsettings[10]) {
    int *ptr = (int *)gsettings;
    for (int i = 0; i < 30; i++) {
      printf("settings[%d] = %d\n", i, ptr[i]); // we add i to ptr and get that value in ptr[i]
    }
}
  
typedef struct Graphics {
    int fps;
    int height;
    int width;
} graphics_t;
  