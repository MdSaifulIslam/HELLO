#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int array[10];
int front =-1, rear = -1;

void enQueue(int data){
    if(isFull()){
        printf("Overflow\n");
        return;
    }

    if(front == rear == -1){
        rear++;
        array[rear] = data;
        return;
    }

    if(rear == 9){
        rear = 0;
        array[rear] = data;
        return;
    }

    rear ++;
    array[rear] = data;
    return;
}

int deQueue(){
    if(isEmpty()){
        printf("Underflow\n");
        return INT_MIN;
    }
    int x;

    if(front == rear){
        x = array[front];
        front = rear = -1;
        return x;
    }

    if(front == 9){
        x = array[front];
        front = 0;
        return x;
    }

    x = array[front];
    front ++;
    return x;
}

void display(){
    int i;
    if(isEmpty()){
        printf("Underflow\n");
        return;
    }

    if(front > rear){
        for(i=front; i <= 9; i++){
            printf("%d ", array[i]);
        }
        for(i=0; i <= rear; i++){
            printf("%d ", array[i]);
        }
        printf("\n");

        return;
    }

    for(i=front; i<= rear;i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    return;
}

int isFull(){
    return (front == 0 && rear == 9) || (rear + 1 == front);
}

int isEmpty(){
    return front == rear == -1;
}

int main(void){
    enQueue(5);
    enQueue(2);
    enQueue(3);
    enQueue(4);

    display();

    deQueue();
    deQueue();
    deQueue();
    deQueue();
    deQueue();
    deQueue();

    display();
}