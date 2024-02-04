/* Stack Data Structure */

#include <iostream>
using namespace std;

#define MAXSIZE 10

// define the stack
struct Stack {
    int items[MAXSIZE];
    int top = -1;
};

//check if stack is empty or not
bool isFull(Stack *s) {
    if(s->top == MAXSIZE) return true;
    return false;
}

//check for underflow
bool isEmpty(Stack *s) {
    if(s->top == -1) return true;
    return false;
}

//insert element into stack
void push(Stack *s, int data) {
    if(isFull(s)) 
        cout << "Overflow! Cannot insert element into Stack" << endl;
    else {
        s->top += 1;
        s->items[s->top] = data;
        cout << data << " inserted into Stack" << endl;
    }
}

//remove the top element from stack
void pop(Stack *s) {
    if(isEmpty(s)) 
        cout << "Underflow! Nothing to remove from Stack" << endl;
    else {
        cout << s->items[s->top] << " is removed from Stack" << endl;
        s->top = s->top - 1;
    }
}

//peek at top
void peek(Stack *s) {
    if (isEmpty(s))
        cout << "Stack is empty!" << endl;
    else 
        cout << "Element at top of stack is : " << s->items[s->top] << endl;
}

//print the stack
void printStack(Stack *s) {
    for(int i = s->top; i >= 0; i--) 
        cout << s->items[i] << endl;
}

int main() {
    Stack *s = new Stack();

    push(s, 4);
    push(s, 1);
    push(s, 7);
    pop(s);
    push(s, 8);
    peek(s);
    isEmpty(s);
    isFull(s);
    printStack(s);
    delete s;

    return 0;
}
