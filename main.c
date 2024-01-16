#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"basic.c"

int main(){
    char *expression=get_expression();
    printf("%s",expression);
    num_node=string_list(expression);
    
    // while(!isEmpty_queue(Q_end)){
    // num_node1=dequeue(&Q_end);
    // if(num_node1){
    // (num_node1);}
    // }
    create_queue(&Q_addition,10);
    num_node1=dequeue(&Q_end);
    display_linked_list_end_start(num_node1);
    num_node=dequeue(&Q_end);
    display_linked_list_end_start(num_node);
    num_node1=addTwoNumbers(num_node1,num_node);
    num_node=dequeue(&Q_addition);
    display_linked_list_end_start(num_node);
    // int i=0;
    // printf(">>>>>>\n");
    // while(operands[i]!='\0'){
    //     printf("%c",operands[i]);
    //     i++;
    // }
    // printf("%d",max_fraction);
    // printf(">>>>>>\n");

    
    return 0;
}