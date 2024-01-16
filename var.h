#include<stdio.h>
#include<stdlib.h>

int max_fraction=0;

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
}node;

typedef struct Stack{
    int size;
    int top;
    struct node **S;
}Stack;

typedef struct Queue{
    int size;
    int front;
    int rear;
    struct node **Q;
}Queue;

char* operands;
int operands_count=0;

node *num_node=NULL;
node *num_node1=NULL;
Stack st;
Queue Q;
Queue Q_end;