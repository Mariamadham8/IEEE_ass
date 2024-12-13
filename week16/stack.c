/*
//stack base on array
#include<stdio.h>
#include <stdlib.h>
#define max 5


double arr[max];
int top =-1;

void push(int data)
{
    if(top>=max-1 )
    {
        printf("stack is full\n");
    }
    else
    {
         top +=1;
         arr[top]=data;
        
       
    }
    
}

void pop()
{
    double temp=0;
    if(top<0)
    {
        printf("stack is empty\n");
        exit(1);
    }
    else
    {
         temp=arr[top];
         arr[top]=0;
         top-=1;
    }
    printf("deleted element : %.0f\n",temp);
}

void size()
{
   printf("Size of stack: %d\n", top + 1);
}

void show_stack()
{
    for(int i=0;i<max;i++)
    {
        printf("%.0f\t",arr[i]);
    }
    printf("\n");
}



int main()
{
    push(1);
    push(2);
    push(3);
    show_stack();
    pop();
    show_stack();
    size();

    push(1);
    push(2);
    push(3);
    show_stack();
    push(3);
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();

    
    return 0;
}
*/

//#########################################################################333

//stack based on linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct stack {
    struct node* top;
};

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) {
        printf("memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct stack* createstack() {
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    if (!stack) {
        printf("memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    return stack;
}

void push(struct stack* stack, int data) {
    struct node* newnode = createnode(data);
    newnode->next = stack->top;
    stack->top = newnode;
    printf("pushed %d onto the stack\n", data);
}

int isempty(struct stack* stack) {
    return stack->top == NULL;
}

int pop(struct stack* stack) {
    if (isempty(stack)) {
        printf("stack is empty\n");
        return -1;
    }
    struct node* temp = stack->top;
    int popped = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return popped;
}

int peek(struct stack* stack) {
    if (isempty(stack)) {
        printf("stack is empty\n");
        return -1;
    }
    return stack->top->data;
}

void display(struct stack* stack) {
    if (isempty(stack)) {
        printf("stack is empty\n");
        return;
    }
    struct node* current = stack->top;
    printf("stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freestack(struct stack* stack) {
    while (!isempty(stack)) {
        pop(stack);
    }
    free(stack);
}

int main() {
    struct stack* stack = createstack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    display(stack);

    printf("top element is %d\n", peek(stack));

    printf("popped element is %d\n", pop(stack));
    display(stack);

    freestack(stack);

    return 0;
}
