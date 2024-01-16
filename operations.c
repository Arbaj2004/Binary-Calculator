#include<stdio.h>
#include"queue.c"

node*addTwoNumbers(node *num1,node *num2){
    int carr=0,sum=0;
    node *p=NULL,*t=NULL,*ans=NULL;
    while(num1 && num2){
        if(num1->data==-1){
            t=(node *)malloc(sizeof(node));
            t->data=-1;
            t->next=NULL;
            t->prev=NULL;
            t->prev=p;
            p->next=t;
            p=t;
            num1=num1->prev;
            num2=num2->prev;
        }
        t=(node *)malloc(sizeof(node));
        sum=num1->data+num2->data+carr;
        t->data=sum%10;
        carr=sum/10;
        t->next=NULL;
        t->prev=NULL;
        if(ans==NULL){
            ans=t;
            p=t;
        }else{
            t->prev=p;
            p->next=t;
            p=t;
        }
        num1=num1->prev;
        num2=num2->prev;
    }
    while(num1 || num2 || carr!=0){
        t=(node *)malloc(sizeof(node));
        if(num1){
            sum=num1->data+carr;
            num1=num1->prev;
        }else if(num2){
            sum=num2->data+carr;
            num2=num2->prev;
        }else{
            sum=carr;
        }
        carr=sum/10;
        t->data=sum%10;
        t->next=NULL;
        t->prev=NULL;
        t->prev=p;
        p->next=t;
        p=t;
    }
    enqueue(&Q_addition,p);
    return ans;
}
