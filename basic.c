#include<stdio.h>
#include"queue.c"

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
    // str="1.2*1.2";
    while(validate_expression(str)!=1){
        free(str);
        printf("Enter the valid expression again : ");
        str=(char *)malloc(sizeof(char)*100);
        scanf("%s",str);
    }
    return str;
}

node *createNode(int d){
    node *t=(node *)malloc(sizeof(node));
    t->data=d;
    t->next=NULL;
    t->prev=NULL;
    return t;
}

node *string_list(char *str){
    operands=(char *)malloc(sizeof(char)*10);
    operands[0]='~';
    node *p=NULL,*t=NULL,*ans=NULL;
    create_queue(&Q,100);
    create_queue(&Q_end,100);
    int i=0;
    while(str[i]!='\0'){
        p=NULL,t=NULL,ans=NULL;
        if(str[i]=='-'){
            t=createNode(-3);
            ans=t;
            p=t;
            i++;
        }int decimal=-1;
        int ttemp=0;
        while((str[i]>='0' && str[i]<='9' && str[i]!='\0') || str[i]=='.'){         
            t=createNode(str[i]-'0');
            if(decimal!=-1){
                decimal++;
            }
            if(str[i]=='.'){
                t->data=-7;
                decimal=0;
                ttemp=1;
            }
            if(ans==NULL){
                ans=t;
                p=t;
            }else{
                t->prev=p;
                p->next=t;
                p=t;
            }i++;
        }int q=0;
        while(decimal<max_fraction && max_fraction!=0){
            decimal++;
            t=createNode(0);
            if(ttemp==0 && q==0){
                t->data=-7;
                q++;
            }
            t->prev=p;
            p->next=t;
            p=t;
        }

        if(ans!=NULL){
        enqueue(&Q,ans);
        enqueue(&Q_end,p);
        }
        if(str[i]!='\0'){
            node *temp=NULL;
            if(str[i]=='+'){
                temp=createNode(-11);
            }else if(str[i]=='-'){
                temp=createNode(-13);
            }else if(str[i]=='*'){
                temp=createNode(-17);
            }else if(str[i]=='/'){
                temp=createNode(-19);
            }
            if(ans!=NULL){
            enqueue(&Q,temp);
            enqueue(&Q_end,temp);
            }
            i++;
        }
    }
    return ans;
}



void display_linked_list_start_end(node *p){
    printf("\n");
    while (p){        
        if(p->data==-7 || p->data==-8){
            printf(".");
        }else if(p->data==-3){
            printf("-");
        }else{
        printf("%d",p->data);
        }
        p=p->next;
    }
}

void display_linked_list_end_start(node *p){
    printf("\n");
    while (p){
        if(p->data==-7 || p->data==-8){
            printf(".");
        }else if(p->data==-3){
            printf("-");
        }
        else{
        printf("%d",p->data);
        }
        p=p->prev;
    }
}

node * copy_ll(node *root){
    node *t=NULL,*p=NULL,*ans=NULL;
    while(root){
        t=(node *)malloc(sizeof(node));
        t->data=root->data;
        t->next=NULL;
        t->prev=NULL;
        if(ans==NULL){
            ans=t;
            p=t;
        }else{
            t->next=p;
            p->prev=t;
            p=t;
        }
        root=root->prev;
    }
    return ans;
}

node *get_del_front_zeros(node *t){
    node *p=NULL;
    if(t->data==-3){
        p=t;
        t=t->next;
    }
    while(t->data==0){
        t=t->next;
    }
    if(p){
        p->next=t;
        t->prev=p;
        t=p;
    }return t;
}

int remove_decimal_Node(node *t){
    node *p=t;
    int is_dec=0;
    while(p){
        if(p->data==-7){
            is_dec=1;
        }
        p=p->prev;
    }
        node *r=t;
    int decimals=0,check=0;
    if(is_dec==1){
        p=t;
        while(p->data!=-7){
            if(p->data!=0){
                check++;
            }
            if(check!=0){
                decimals++;
            }
            
                r=p;
                p=p->prev;
            
        }
        r->prev=r->prev->prev;
        r->prev->next=r;
    }
    t=r;
    return decimals;
    
}

node *remove_zeros(node *t){
    int check=0;
    while(t){
        if(t->data!=0 && t->data!=-7){
            check++;
            return t;
        }
        if(check==0){
            t=t->prev;
        }
    }return t;
}

void insert_decimal_node(node *t,int i){
    node *p=NULL;
    if(i<=0){
        return;
    }
    int check=0,is_dec=0;
    while(t && i){
        if(t->data!=0){
            check++;
        }
            i--;
        p=t;
        t=t->prev;
    }
    node *q=createNode(-7);
    p->prev=q;
    q->next=p;
    q->prev=t;
    t->next=q;
}



