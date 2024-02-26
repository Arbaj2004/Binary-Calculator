#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"infix_eval.c"


int main(){
    char *expression=get_expression();
    num_node=string_list(expression);  
    evaluate_(); 
    display_linked_list_start_end(pop_stack(&operand));

     
    return 0;
}