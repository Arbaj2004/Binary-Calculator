#include<stdio.h>
#include"var.h"


void create_stack( Stack *s,int size){
    s->size=size;
    s->top=0;
    s->S=( node **)malloc(sizeof( node *)*s->size);
}

void push_stack( Stack *s, node *p){
    if(s->top==s->size-1){
        printf("stack is full");
    }else{
        s->S[s->top]=p;
        s->top++;
    }
}

 node *pop_stack( Stack *s){
     node *p=NULL;
    if(s->top==0){
        printf("stack is empty");
    }else{
        p=s->S[s->top-1];
        s->top--;
    }return p;
}

int isEmpty_stack( Stack *s){
    return s->top==0;
}
