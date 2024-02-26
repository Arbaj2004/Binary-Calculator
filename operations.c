#include<stdio.h>
#include"basic.c"


node * addTwoNumbers(node *num1,node *num2,int req){
    int carr=0,sum=0;
    node *p=NULL,*t=NULL,*ans=NULL,*rev_ans=NULL;
    while(num1 && num2){
        if(num1->data==-7){
            t=createNode(-7);
            t->next=p;
            p->prev=t;
            p=t;
            num1=num1->prev;
            num2=num2->prev;
        }
        sum=num1->data+num2->data+carr;
        t=createNode(sum%10);
        carr=sum/10;
        if(rev_ans==NULL){
            rev_ans=t;
            p=t;
        }else{
            t->next=p;
            p->prev=t;
            p=t;
        }
        num1=num1->prev;
        num2=num2->prev;
    }
    while(num1 || num2 || carr!=0){
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
        t=createNode(sum%10);
        t->next=p;
        p->prev=t;
        p=t;
    }
    ans=p;
    if(req==1){
    push_stack(&operand,ans);
    push_stack(&operand_end,rev_ans);
    }
    return rev_ans;
}

void subTwoNumbers(node *num1,node *num2,int a){
    node*tempo=copy_ll(num1);
    node*temp=num2;
    int borrow=0,sub=0;
    node *p=NULL,*t=NULL,*ans=NULL,*rev_ans=NULL;
    while(num1 && num2){
        if(num1->data==-7){
            t=createNode(-7);
            t->next=p;
            p->prev=t;
            p=t;
            num1=num1->prev;
            num2=num2->prev;
        }
        if(num1->data<num2->data){
            borrow=1;
            if(num1->prev==NULL){
                return subTwoNumbers(temp,tempo,2);
            }
            if(num1->prev->data==-7){
                num1->prev->prev->data--;
            }else{
                num1->prev->data--;
            }
        }      
        sub=(num1->data+(10*borrow))-num2->data;
        borrow=0;
        t=createNode(sub);
        if(rev_ans==NULL){
            rev_ans=t;
            p=t;
        }else{
            t->next=p;
            p->prev=t;
            p=t;
        }
        num1=num1->prev;
        num2=num2->prev;
    }
        while(num1){
            if(num1->data<0){
                num1->data=num1->data+10;
                num1->prev->data--;
            }
            t=createNode(num1->data);
            t->next=p;
            p->prev=t;
            p=t;
            num1=num1->prev;
        }
    if(num2){
        return subTwoNumbers(temp,tempo,2);
    }
    if(a==2){
        t=createNode(-3);
        t->next=p;
        p->prev=t;
        p=t;
    }
    p=get_del_front_zeros(p);
    ans=p;
    push_stack(&operand,ans);
    push_stack(&operand_end,rev_ans);
}


void multiTwoNumbers(node *num1,node *num2){
    num1=remove_zeros(num1);
    int num1_dec=remove_decimal_Node(num1);
    int num2_dec=remove_decimal_Node(num2);
    int mult=0,carr=0,a=0,count_zero=0;
    node *q=NULL,*p=NULL,*t=NULL,*ans=NULL,*rev_ans=NULL;
    node *result=NULL;
    int count=0;
    while(num2){
        while(num2->data==0){
            count++;
            num2=num2->prev;
        }
        if(num2->data<0){
            num2=num2->prev;
        }
        rev_ans=NULL; 
        int i=0;
        while(i<count){
            i++;
            t=createNode(0);
            if(rev_ans==NULL){
                rev_ans=t;
                p=t;
            }else{
                t->next=p;
                p->prev=t;
                p=t; 
            }
        }
        q=num1;
        while(q){
            mult=(q->data*num2->data)+carr;
            t=createNode(mult%10);
            carr=mult/10;
            if(rev_ans==NULL){
                rev_ans=t;
                p=t;
            }else{
                t->next=p;
                p->prev=t;
                p=t;
        }
            q=q->prev;
        }
        while(carr){
            t=createNode(carr%10);
            t->next=p;
            p->prev=t;
            p=t;
            carr=carr/10;
        }
        if(result==NULL){
            result=rev_ans;
        }else{
        result=addTwoNumbers(result,rev_ans,2);
        }
        num2=num2->prev;
        count++;
    }
    rev_ans=result;
    while(result->prev){
        result=result->prev;
    }
    ans=result;
    insert_decimal_node(rev_ans,num1_dec+num2_dec);
    push_stack(&operand,ans);
    push_stack(&operand_end,rev_ans);
}