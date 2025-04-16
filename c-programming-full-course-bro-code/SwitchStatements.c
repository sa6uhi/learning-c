#include <stdio.h>

int main() {

    // switch = A more efficient alternative to using many "else if" statements
    //          allows a value to be tested for equality against many cases

    char grade;

    printf("\nEnter a letter grade:");
    scanf("%c",&grade);
    
    /*
    if(grade == 'A'){
        printf("perfect!\n");
    }
    else if(grade == 'B'){
        printf("You did good!\n");
    }
    else if(grade == 'C'){
        printf("You did okay\n");
    }
    else if(grade == 'D'){
        printf("At least it's not an F\n");
    }
    else if(grade == 'F'){
        printf("YOU FAILED\n");
    }
    else {
        printf("That is not a valid grade!\n");
    }
    */

    switch(grade){
        case 'A':
            printf("Perfect!\n");
            break; 
            // "break" is used to break out of the switch and exit, 
            // if it does not exist here, then if you enter 'A', it will print all the statements together
        case 'B':
            printf("You did good!\n");
            break;
        case 'C':
            printf("You did okay!\n");
            break;
        case 'D':
            printf("At least it's not an F!\n");
            break;
        case 'F':
            printf("YOU FAILED!\n");
            break;
        default:
            printf("Please enter only valid grades!\n");
    }



    int x = 5;

    switch (x) {
        case 1:
            printf("x is 1\n");
            break;
        case 2:
            printf("x is 2\n");
            break;
        case 3:
            printf("x is 3\n");
            break;
        case 4:
            printf("x is 4\n");
            break;
        case 5:
            printf("x is 5\n");
            break;
        default:
            printf("x is not between 1 and 5\n");
    }

    return 0;
}