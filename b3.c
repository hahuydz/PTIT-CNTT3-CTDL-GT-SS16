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
    if ( queue->front == NULL ) {
        printf("Queue is empty\n");
        return;
    }
    Node* node = queue->front;
    while ( node != NULL ) {
        printf("%d\t", node->data);
        node = node->next;
    }
}

int frontValue(Queue *queue, int *value) {
    if ( queue->front == NULL ) {
        printf("\nQueue is empty\n");
        return 0;
    }
    *value = queue->front->data;
    return  value;
}

int main(void) {
    Queue *queue = createQueue();
    for ( int i = 1; i <= 5; i++ ) {
        push(queue);
    }
    show(queue);

    int value ;
    if ( frontValue(queue, &value ) ) {
        printf("\n%d", value);
    }
    return 0;
}
