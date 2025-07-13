#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

typedef struct Queue {
    struct Node* front;
    struct Node* rear;
}Queue;

Node* createNode() {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);

    Node* node = ( Node* )malloc(sizeof( Node ));
    node->data = data;
    node->next = NULL;
    return node;
}

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof( Queue ));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

int push(Queue* queue) {
    Node* newNode = createNode();
    if ( queue->front == NULL ) {
        queue->front = queue->rear = newNode;
    }else {
        queue->rear->next = newNode;
        queue->rear = queue->rear->next;
    }
    return newNode->data;
}

void show(Queue* queue) {
    if ( isEmpty(queue) ) {
        printf("Queue is empty\n");
        return;
    }
    Node* node = queue->front;
    while ( node != NULL ) {
        printf("%d\t", node->data);
        node = node->next;
    }
}

int pop(Queue* queue) {
    if ( isEmpty(queue) ) {
        printf("Queue is empty\n");
        return 0;
    }
    Node* node = queue->front;
    queue->front = queue->front->next;
    int data = node->data;
    free(node);
    return data;
}

int main(void) {
    Queue *queue = createQueue();
    for ( int i = 1; i <= 5; i++ ) {
        push(queue);
    }
    show(queue);
    pop(queue);
    printf("\nSau: \n");
    show(queue);
    return 0;
}
