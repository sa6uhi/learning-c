#include <stdio.h>

int main(){

    // format specifier % = defines and formats a type of data to be displayed
    /*
    %c = charactor
    %s = string(array of charactors)
    %f = float
    %lf = double
    %d = integer

    %.1 = decimal precision
    %1 = minimum field width
    %- = left align
    */
    float item1 = 5.75;
    float item2 = 10.00;
    float item3 = 100.99;

    printf("Item 1: $%.2f\n", item1);
    printf("Item 2: $%.2f\n", item2);
    printf("Item 3: $%.2f\n", item3);

    // Set the minimum field width to be 8 and set them left align
    printf("Item 1: $%-8.2f\n", item1);
    printf("Item 2: $%-8.2f\n", item2);
    printf("Item 3: $%-8.2f\n", item3);

    // Set the minimum field width to be 8 and set them right align
    printf("Item 1: $%8.2f\n", item1);
    printf("Item 2: $%8.2f\n", item2);
    printf("Item 3: $%8.2f\n", item3); 

}