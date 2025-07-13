#include <stdio.h>
#include  <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct Queue{
    Node *front;
    Node *rear;
}Queue;

Queue *createQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

int main(void) {
    printf("Hello, World!\n");
    return 0;
}
