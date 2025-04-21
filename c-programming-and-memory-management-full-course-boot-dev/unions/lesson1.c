// Unions in C can hold one of several types. They're like a less-strict sum type from the world of functional programming. Here's an example union:

typedef union AgeOrName {
    int age;
    char *name;
} age_or_name_t;

// The age_or_name_t type can hold either an int or a char *, but not both at the same time (that would be a struct). We provide the list of possible types so that the C compiler knows the maximum potential memory requirement, and can account for that. This is how the union is used:

int main() {
    age_or_name_t lane = { .age = 29 };
    printf("age: %d\n", lane.age);
    // age: 29

    printf("name: %s\n", lane.name);
    // name:

    // We get... nothing? To be more specific, we get undefined behavior. A union only reserves enough space to hold the largest type in the union and then all of the fields use the same memory. So when we set .age to 29, we are writing the integer representation of 29 to the memory of the lane union:
    // 0000 0000 0000 0000 0000 0000 0001 1101
    // Then if we try to access .name, we read from the same block of memory but try to interpret the bytes as a char *, which is why we get garbage (which is interpreted as nothing in this case). Put simply, setting the value of .age overwrites the value of .name and vice versa, and you should only access the field that you set.


    return 0;
}

// EXERCISE

typedef enum SnekObjectKind {
    INTEGER,
    STRING,
} snek_object_kind_t;

typedef union SnekObjectData {
    int v_int;
    char *v_string;
} snek_object_data_t;
  
typedef struct SnekObject {
    snek_object_kind_t kind;
    snek_object_data_t data;
} snek_object_t;

void format_object(snek_object_t obj, char *buffer) {
    // You can use sprintf to write the formatted string to the buffer
    switch (obj.kind) {
        case INTEGER:
            sprintf(buffer, "int:%d", obj.data.v_int);
            break;
        case STRING:
            sprintf(buffer, "string:%s", obj.data.v_string);
            break;
        default:
            sprintf(buffer, "Unknown");
            break;
    }
}
  
  
snek_object_t new_integer(int i) {
    return (snek_object_t){
        .kind = INTEGER,
        .data = {.v_int = i}
    };
}
  
snek_object_t new_string(char *str) {
    // NOTE: We will learn how to copy this data later.
    return (snek_object_t){
        .kind = STRING,
        .data = {.v_string = str}
    };
}
