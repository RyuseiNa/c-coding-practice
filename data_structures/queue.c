#include <stdio.h>
#define MAX_SIZE 100
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
}Queue;

void initQueue(Queue* queue){
    queue->front = -1;
    queue->rear = -1;
}
int isEmpty(Queue* queue){
    return(queue->front==-1&&queue->rear==-1);
}
int isFull(Queue* queue){
    return(queue->rear==MAX_SIZE-1);
}
void enqueue(Queue* queue,int data){
    if(isFull(queue)){
        printf("Queue is Full,\n");
        return;
    }
    if(isEmpty(queue)){
        queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = data;
}
void dequeue(Queue* queue){
    if(isEmpty(queue)){
        printf("Queue is Empty,Can't dequeue!!!\n");
        return;
    }
    int data = queue->items[queue->front];
    if (queue->front == queue->rear) {
        initQueue(queue);
    } else {
        queue->front++;
    }
}
void displayQueue(Queue* queue){
    if(isEmpty(queue)){
        printf("Queue is Empty.\n");
        return;
    }
    printf("Queue:");
    for(int i = queue->front;i<=queue->rear;i++){
        printf("%d,",queue->items[i]);

    }
    printf("\n");
}
int main(){
    Queue queue;
    initQueue(&queue);
    enqueue(&queue,10);
    enqueue(&queue,20);
    enqueue(&queue,30);
    enqueue(&queue,40);

    displayQueue(&queue);
    dequeue(&queue);
    displayQueue(&queue);

}