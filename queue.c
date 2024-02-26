#include<stdio.h>
#include"stack.c"


void create_queue( Queue *q,int size){
    q->size=size;
    q->front=q->rear=0;
    q->Q=( node **)malloc(q->size*sizeof( node *));
}

void enqueue( Queue *q, node *x){
    if((q->rear+1)%q->size==q->front)
        printf("Queue is Full");
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

 node * dequeue( Queue *q){
     node* x=NULL;
    if(q->front==q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

int isEmpty_queue( Queue q){
    return q.front==q.rear;
}

int queue_size(Queue q){
    return q.front-q.rear;
}

