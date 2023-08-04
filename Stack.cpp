#include <stdio.h>
#include <stdlib.h>

// Structure to represent a complex number
typedef struct {
    double real;
    double imaginary;
} ComplexNumber;

// Structure to represent the complex number stack
typedef struct {
    ComplexNumber* array;
    int size;
    int capacity;
} ComplexStack;

// Function to initialize the complex number stack
void initializeStack(ComplexStack* stack, int capacity) {
    stack->array = (ComplexNumber*)malloc(capacity * sizeof(ComplexNumber));
    stack->size = 0;
    stack->capacity = capacity;
}

// Function to push a complex number to the stack
void push(ComplexStack* stack, ComplexNumber complex_num) {
    if (stack->size >= stack->capacity) {
        // If the stack is full, resize the array to double its capacity
        stack->capacity *= 2;
        stack->array = (ComplexNumber*)realloc(stack->array, stack->capacity * sizeof(ComplexNumber));
    }

    stack->array[stack->size] = complex_num;
    stack->size++;
}

// Function to pop a complex number from the stack
ComplexNumber pop(ComplexStack* stack) {
    if (stack->size == 0) {
        fprintf(stderr, "Stack is empty, cannot pop.\n");
        exit(EXIT_FAILURE);
    }

    ComplexNumber popped_complex = stack->array[stack->size - 1];
    stack->size--;

    return popped_complex;
}

// Function to free the memory used by the stack
void freeStack(ComplexStack* stack) {
    free(stack->array);
    stack->size = 0;
    stack->capacity = 0;
}

int main() {
    ComplexStack stack;
    initializeStack(&stack, 3);

    // Pushing complex numbers to the stack
    push(&stack, (ComplexNumber){2.0, 3.0});
    push(&stack, (ComplexNumber){-1.0, 5.0});
    push(&stack, (ComplexNumber){0.0, -2.0});

    // Popping complex numbers from the stack
    ComplexNumber popped1 = pop(&stack);
    ComplexNumber popped2 = pop(&stack);

    printf("Popped Complex Numbers:\n");
    printf("%f + %fi\n", popped1.real, popped1.imaginary); // Output: -1.000000 + 5.000000i
    printf("%f + %fi\n", popped2.real, popped2.imaginary); // Output: 2.000000 + 3.000000i

    freeStack(&stack);
    return 0;
}
