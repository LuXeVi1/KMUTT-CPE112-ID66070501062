#include <stdio.h>

// For clearing the data into the stack
// void push(int stack[], int value) {
//     if(top == MAX -1) {
//         printf("Stack Overflow!");
//     } else {
//         top++;
//         stack[top] = value;
//     }
// }
// For removing data from Stack
void pop(int stack[]) {
    int val;

    if (top == -1) {
        printf("Stack Underflow!");
    } else {
        val = stack[top];
        top--;
        return val;
    }
}
// For return datat top of stack
void peek() {

}
// For showing all the values in Stack
void display() {

}
// For removing the two characters that are adjacent and duplicate from the string
void shortenString() {

}

int main() {
    char string[11];

    printf("Enter a string (not more than 10 characters): ");
    scanf("%10s", string);

    if (strlen(string) > 10) {
        printf("String Overflow!\n");
    } else {
        shortenString(string);
    }

    return 0;
}