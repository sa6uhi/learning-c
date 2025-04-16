#include <stdio.h>

int main() {
    
    int x; // declaration
    x = 123; // initialization
    int y = 321; // declaration and initialization

    int age = 21;
    float gpa = 3.05;
    char grade = 'A';
    char name[] = "Sabuhi Nazarov";

    printf("Hello, %s!\n", name);
    printf("You are %d years old.\n", age);
    printf("Your GPA is %.2f.\n", gpa);
    printf("Your grade is %c.\n", grade);

    return 0;
}