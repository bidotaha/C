#include <stdio.h>
#include <stdlib.h>

#include "stack_ds.h"

stack_ds_t stack1;
uint32_t value_t;
int main()
{
    return_status_t ret = R_NOK;
    ret = stack_init(&stack1);
    if (R_NOK == ret){
        printf("stack1 failed to be initialized !!\n");
    }
    else{
        ret = stack_push(&stack1,11);
        ret = stack_push(&stack1,22);
        ret = stack_push(&stack1,33);
        ret = stack_push(&stack1,44);
        ret = stack_push(&stack1,55);
        ret = stack_push(&stack1,66);
        ret = stack_pop(&stack1,&value_t);
        ret = stack_pop(&stack1,&value_t);
        ret = stack_pop(&stack1,&value_t);
        ret = stack_pop(&stack1,&value_t);
        ret = stack_top(&stack1,&value_t);
        ret = stack_pop(&stack1,&value_t);

    }
    return 0;
}
