#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct Queue {
    Node *front;
    Node *rear;
}Queue;

Queue *createQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

Node *createNode() {
    int data;
    printf("Nhap data: ");
    scanf("%d", &data);

    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int push(Queue *queue) {
    Node *newNode = createNode();
    if (queue->front == NULL) {
        queue->front = queue->rear = newNode;
    }else {
        queue->rear->next = newNode;
        queue->rear = queue->rear->next;
    }
    return newNode->data;
}

void show(Queue *queue) {
    if ( queue->front == NULL ) {
        printf("Queue is empty\n");
        return;
    }
    Node *node = queue->front;
    while (node != NULL) {
        printf("%d\t", node->data);
        node = node->next;
    }
}

int main(void) {
    Queue *queue = createQueue();
    for ( int i = 1; i <= 5; i++ ) {
        push(queue);
    }
    show(queue);
    return 0;
}
