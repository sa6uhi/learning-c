int main() {
    
    // Arrays As Pointers in C
    // In C, arrays and pointers are closely related. 
    // An array name acts as a pointer to the first element of the array. That means array indexing and pointer arithmetic can be used interchangeably to access array elements. Let's go through this step-by-step to understand how this works.

    // Step-by-Step Walkthrough
    //Array Declaration:
    int numbers[5] = {1, 2, 3, 4, 5};

    // Array as Pointer:
    // The name numbers acts as a pointer to the first element of the array.
    int *numbers_ptr = numbers;
    // numbers_ptr is a pointer to the same place as numbers.

    //Accessing Elements via Indexing:
    // Access the third element (index 2)
    int value = numbers[2];

    //Which is the same as:
    int value = *(numbers + 2);
    // Here, numbers + 2 computes the address of the third element, and * dereferences it to get the value.

    // Pointer Arithmetic:
    // When you add an integer to a pointer, the resulting pointer is offset by that integer times the size of the data type.
    int *p = numbers + 2;  // p points to the third element
    int value = *p;        // value is 3

}