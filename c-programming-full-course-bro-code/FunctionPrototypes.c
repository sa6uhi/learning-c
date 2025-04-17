#include <stdio.h>

// void hello(char name[], int age) {
//     printf("Hello %s, you are %d years old\n", name, age);
// }

void hello (char[], int); // function prototype
// function declaration without a body, before main()

int main() {

    // function prototype = a function declaration without a body, before main()
    // Many C compilers do not check for parameter matching, missing arguments will result in unexpected behavior
    // Ensures that calls to a function are made with the correct arguments by flagging an error if arguments are missing

    char name[] = "Sabuhi";
    int age = 21;
    // hello(name); error: too few arguments to function 'hello'
    hello(name, age);

}

void hello(char name[], int age) { // after the main function
    printf("Hello %s, you are %d years old\n", name, age);
}