#include <stdio.h>
#include <string.h>

int main() {

    char name[25];
    int age;

    printf("\nWhat is your name? ");
    // scanf("%s", &name);
    fgets(name, 25, stdin);
    name[strlen(name) -1] = '\0'; // Remove the newline character(last character) from the string
    // scanf("%[^\n]s", name); // This will read a string with spaces until a newline is encountered

    printf("\nHow old are you? ");
    scanf("%d", &age);

    printf("\nHello %s!\n", name);
    printf("You are %d years old.\n", age);

}