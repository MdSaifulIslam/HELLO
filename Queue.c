#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Queue{
    int front, rear, size;
    unsigned capacity;
    int * array;
};

struct Queue * createQueue(unsigned capacity){
    struct Queue * Q = (struct Queue *) malloc(sizeof(struct Queue));
    Q->capacity = capacity;
    Q->front = Q->size = 0;
    Q->rear = capacity -1;
    Q->array = (int *) malloc(Q->capacity * sizeof(int));

    return Q;
}  


int isFull(struct Queue * Q){
    return Q->capacity == Q->size;
}

int isEmpty(struct Queue * Q){
    return Q->size == 0;
}

void enQueue(struct Queue * Q, int data){
    if(isFull(Q))
        return;
    Q->rear = (Q->rear + 1)
                % Q->capacity;
    Q->array[Q->rear] = data;
    Q->size = Q->size + 1;
}

int deQueue(struct Queue * Q){
    if(isEmpty(Q))
        return INT_MIN;

    int data = Q->array[Q->front];
    Q->front = (Q->front + 1) 
                % Q->capacity;
    Q->size = Q->size -1;
    return data;
}
int frontData(struct Queue * Q){
    if(isEmpty(Q))
        return INT_MIN;

    return Q->array[Q->front];
}

int rearData(struct Queue * Q){
    if(isFull(Q))
        return INT_MIN;
    return Q->array[Q->rear];
}

int main(void){
    struct Queue * Q  = createQueue(100);

    enQueue(Q, 10);
    enQueue(Q, 43);
    enQueue(Q, 34);
    enQueue(Q, 13);
    enQueue(Q, 43);
    enQueue(Q, 76);

    printf("%d ", deQueue(Q));
    printf("%d ", deQueue(Q));
    printf("%d ", frontData(Q));
    printf("%d ", rearData(Q));

    return 0;
}

