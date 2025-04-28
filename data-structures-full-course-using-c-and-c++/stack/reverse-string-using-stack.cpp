#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

/* class Stack
{
    private:
        char stack[101];
        int top;
    public:
        void push(int x);
        void pop();
        int top();
        bool isEmpty();
}; */

void reverse(char* C, int n) // char C[]
{
    stack<char> S;
    for (int i = 0; i < n; i++) {
        S.push(C[i]);
    }

    for (int i = 0; i < n; i++) {
        C[i] = S.top();
        S.pop();
    }
}

int main()
{
    char C[51];

    printf("Enter a string: ");
    gets(C);

    reverse(C, strlen(C));
    printf("Reversed string: %s\n", C);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n) for stack , this can be reduced to O(1) if we use linked list
// Space Complexity: O(1) if we use linked list

