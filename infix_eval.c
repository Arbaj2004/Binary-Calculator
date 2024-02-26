#include"operations.c"

int prec(int x){
    if(x==-11||x==-13){
        return 1;
    }else if(x==-17||x==-19){
        return 2;
    }else if(x=='('){
        return 5;
    }else if(x==')'){
        return 0;
    }
}

int check_for_operator(int x){
    if(x==-11 || x==-13||x==-17||x==-19){
        return 1;
    }else{
        return 0;
    }
}

void evaluate_(){
    create_stack(&operand,100);
    create_stack(&operand_end,100);
    create_stack(&operator,100);
    while(!isEmpty_queue(Q)){
        node *t=dequeue(&Q);
        node *t1=dequeue(&Q_end);
        if(check_for_operator(t->data)!=1){
            push_stack(&operand,t);
            push_stack(&operand_end,t1);
        }else{
            if(operator.top!=0){
                while(operator.top!=0 && prec(t->data)<=prec(operator.S[operator.top-1]->data)){
                    int sign1=1;
                    int sign2=1;
                    node *a2=pop_stack(&operand);
                    if(a2->data<0){
                        sign2=-1;
                    }
                    node *a1=pop_stack(&operand);
                    if(a1->data<0){
                        sign1=-1;
                    }
                    node* b2=pop_stack(&operand_end);
                    node* b1=pop_stack(&operand_end);
                    node *op1=pop_stack(&operator);
                    //write logic to handle -,-  || -,+ || +,- || ++ for add and sub
                    if(op1->data==-11){
                        addTwoNumbers(b1,b2,1);
                    }else if(op1->data==-13){
                        //sub
                    }else if(op1->data==-17){
                        //mul
                    }else if(op1->data==-19){
                        //div
                    }
                }
            }
            push_stack(&operator,t);
        }
    }
    while(!isEmpty_stack(&operator)){
        int sign1=1;
        int sign2=1;
        node *a2=pop_stack(&operand);
        if(a2->data<0){
            sign2=-1;
        }
        node *a1=pop_stack(&operand);
        if(a1->data<0){
            sign1=-1;
        }
        node* b2=pop_stack(&operand_end);
        node* b1=pop_stack(&operand_end);
        node *op1=pop_stack(&operator);
        //write logic to handle -,-  || -,+ || +,- || ++ for add and sub
        if(op1->data==-11){
            addTwoNumbers(b1,b2,1);
        }else if(op1->data==-13){
            subTwoNumbers(b1,b2,1);
        }else if(op1->data==-17){
            multiTwoNumbers(b1,b2);
        }else if(op1->data==-19){
            //div
        }
    }
}

