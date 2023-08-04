#include <stdio.h>
#include <stdlib.h>

typedef struct ComplexNode {
    double real;
    double imag;
    struct ComplexNode* next;
} ComplexNode;

typedef struct ComplexLinkedList {
    ComplexNode* head;
} ComplexLinkedList;

ComplexNode* createComplexNode(double real, double imag) {
    ComplexNode* new_node = (ComplexNode*)malloc(sizeof(ComplexNode));
    new_node->real = real;
    new_node->imag = imag;
    new_node->next = NULL;
    return new_node;
}

void addAtBeginning(ComplexLinkedList* cll, double real, double imag) {
    ComplexNode* new_node = createComplexNode(real, imag);
    new_node->next = cll->head;
    cll->head = new_node;
}

void addAtEnd(ComplexLinkedList* cll, double real, double imag) {
    ComplexNode* new_node = createComplexNode(real, imag);
    if (cll->head == NULL) {
        cll->head = new_node;
        return;
    }
    ComplexNode* current = cll->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void addInBetween(ComplexLinkedList* cll, double prev_real, double prev_imag, double real, double imag) {
    ComplexNode* new_node = createComplexNode(real, imag);
    ComplexNode* current = cll->head;
    while (current != NULL) {
        if (current->real == prev_real && current->imag == prev_imag) {
            new_node->next = current->next;
            current->next = new_node;
            return;
        }
        current = current->next;
    }
    printf("(%.2lf + %.2lfi) not found in the list.\n", prev_real, prev_imag);
}

void printList(ComplexLinkedList* cll) {
    ComplexNode* current = cll->head;
    while (current != NULL) {
        printf("(%.2lf + %.2lfi) -> ", current->real, current->imag);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    ComplexLinkedList cll;
    cll.head = NULL;

    // Adding complex numbers
    addAtEnd(&cll, 2.0, 3.0);
    addAtEnd(&cll, 5.0, -1.0);
    addAtBeginning(&cll, 1.0, 2.0);
    addInBetween(&cll, 2.0, 3.0, 4.0, 5.0);

    // Printing the linked list
    printList(&cll);

    return 0;
}

