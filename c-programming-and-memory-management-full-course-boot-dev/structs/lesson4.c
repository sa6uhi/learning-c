// typedef keyword

/*
struct Pastry {
    char *name;
    float weight;
};

// This can also be written as:
typedef struct Pastry {
    char *name;
    float weight;
} pastry_t;

// In fact, you can optionally skip giving the struct a name:
typedef struct {
    char *name;
    float weight;
} pastry_t;

pastry_t muffin = {"Muffin", 0.3};

*/

typedef struct Coordinate {
    int x;
    int y;
    int z;
} coordinate_t;

coordinate_t new_coord(int x, int y, int z) {
    coordinate_t coord = {.x = x, .y = y, .z = z};
  
    return coord;
}
  
coordinate_t scale_coordinate(coordinate_t coord, int factor) {
    coordinate_t scaled = coord;
    scaled.x *= factor;
    scaled.y *= factor;
    scaled.z *= factor;
  
    return scaled;
}
