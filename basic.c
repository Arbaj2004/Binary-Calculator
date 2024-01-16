#include<stdio.h>
#include"operations.c"

int validate_expression(char *str){
    int i=0,temp=0;
    if(str[0]=='-'){
        i++;
    }
    if(str[i]=='\0'){
        return -1;
    }
    while(str[i]!='\0'){
        temp=0;
        while(str[i]<='9'&&str[i]>='0'){
            i++;
            temp++;
        }
        if(temp==0){
            return -1;
        }
        if(str[i]=='.'){
            int fract=0;
            temp=0;
            i++;
            if(str[i+1]<'0' && str[i+1]>'9'){
                return -1;
            }
            while(str[i]<='9'&&str[i]>='0'){
                i++;
                temp++;
                fract++;
        }if(fract>max_fraction){
            max_fraction=fract;
        }
        }
        if(temp==0){
            return -1;
        }
        if(str[i]=='+'||str[i]=='-'||str[i]=='/'||str[i]=='*'){
            i++;
            if(str[i]=='-'){
                i++;
            }
        }else if(str[i]=='\0'){
            return 1;
        }else{
            return -1;
        }
    }
    return 1;
}

char *get_expression(){
    printf("Enter the expression : ");
    char *str=(char *)malloc(sizeof(char)*100);
    scanf("%s",str);
    while(validate_expression(str)!=1){
        free(str);
        printf("Enter the valid expression again : ");
        str=(char *)malloc(sizeof(char)*100);
        scanf("%s",str);
    }
    return str;
}

node *string_list(char *str){
    operands=(char *)malloc(sizeof(char)*10);
    node *p=NULL,*t=NULL,*ans=NULL;
    create_queue(&Q,100);
    create_queue(&Q_end,100);
    int i=0;
    while(str[i]!='\0'){
        p=NULL,t=NULL,ans=NULL;
        if(str[i]=='-'){
            t=(node *)malloc(sizeof(node));
            t->data=-3;
            t->next=NULL;
            t->prev=NULL;
            ans=t;
            p=t;
            i++;
        }int decimal=-1;
        while((str[i]>='0' && str[i]<='9') || str[i]=='.'){
            
            t=(node *)malloc(sizeof(node));
            t->data=str[i]-'0';
            if(decimal!=-1){
                decimal++;
            }
            if(str[i]=='.'){
                t->data=-1;
                decimal=0;
            }
            t->next=NULL;
            t->prev=NULL;
            if(ans==NULL){
                ans=t;
                p=t;
            }else{
                t->prev=p;
                p->next=t;
                p=t;
            }i++;
        }
        while(decimal<max_fraction){
            decimal++;
            t=(node *)malloc(sizeof(node));
            t->data=0;
            t->next=NULL;
            t->prev=NULL;
            t->prev=p;
            p->next=t;
            p=t;
        }
        operands[operands_count++]=str[i];
        i++;
        enqueue(&Q,ans);
        enqueue(&Q_end,p);
    }
    return ans;
}

void display_linked_list_start_end(node *p){
    printf("\n");
    while (p){
        printf("%d ",p->data);
        p=p->next;
    }
}

void display_linked_list_end_start(node *p){
    printf("\n");
    while (p){
        printf("%d ",p->data);
        p=p->prev;
    }
}