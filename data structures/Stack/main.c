#include <stdio.h>
#define SIZE 50

typedef struct{
    int array[SIZE];
    int top;
}Stack;

void inicializarStack(Stack* stack){
    stack->top = -1;
}

void push(Stack* stack, int x){
    if(stack->top == SIZE-1){
        printf("overflow! ");

    }else{
        stack->array[++stack->top] = x;
        printf("Elemento adicionado com sucesso! \n");
    }


}

int pop(Stack* stack){
    if(stack->top == -1){
        printf("underflow! ");
        return -1;
    }else{
        return stack->array[stack->top--];
    }
}

int peek (Stack *stack) {  
    if (stack->top == -1) {  
        printf("Stack is empty!\n");  
        return -1; // Indica retorno invalido 
    }  
    return stack->array[stack->top]; 
}

int main()
{
    Stack stack;
    
    inicializarStack(&stack);
    push(&stack,20);
    push(&stack,40);
    
    
    printf("Elemento do topo: %d\n", peek(&stack));  
  
    printf("Elemento retirado: %d\n", pop(&stack));  


}