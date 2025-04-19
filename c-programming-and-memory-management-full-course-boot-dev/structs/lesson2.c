struct City {
    char *name;
    int lat;
    int lon;
};

/*
Zero Initializer
----------------
int main() {
  struct City c = {0};
}



Positional Initializer
----------------------
int main() {
  struct City c = {"San Francisco", 37, -122};
}



Designated Initializer
----------------------
It's easier to read (has the field names)
If the fields change, you don't have to worry about breaking the ordering
int main() {
  struct City c = {
    .name = "San Francisco",
    .lat = 37,
    .lon = -122
  };
}
*/

// Accessing Fields
// Accessing a field in a struct is done using the . operator. For example:
// struct City c;
// c.lat = 41; // Set the latitude
// printf("Latitude: %d", c.lat); // Print the latitude

struct Coordinate {
    int x;
    int y;
    int z;
};

struct Coordinate new_coord(int x, int y, int z) {
  struct Coordinate e = {
    .x = x,
    .y = y,
    .z = z,
  };
  return __event; 
}
