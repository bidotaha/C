#include "stack_ds.h"

static stack_status_t stack_full(stack_ds_t *my_stack){
    if (my_stack->stack_pointer == STACK_MAX_SIZE-1){
        return STACK_FULL;
    }
    else {
        return STACK_NOT_FULL;
    }
}
static stack_status_t stack_empty(stack_ds_t *my_stack){
    if (my_stack->stack_pointer == -1){
        return STACK_EMPYY;
    }
    else {
        return STACK_NOT_FULL;
    }
}
return_status_t stack_push(stack_ds_t *my_stack ,uint32_t value){
    return_status_t ret = R_NOK;
    if((NULL == my_stack) || (STACK_FULL == stack_full(my_stack))){
        printf("value (%i) can't push to stack \n",value);
        ret = R_NOK;
    }
    else{
        (my_stack->stack_pointer)++;
        my_stack->data[my_stack->stack_pointer] = value;
        printf("value (%i) pushed to stack \n",value);
        ret = R_OK;
    }
    return ret;
}

return_status_t stack_pop(stack_ds_t *my_stack ,uint32_t *value){
    return_status_t ret = R_NOK;
    if((NULL == my_stack) || (NULL == value) || (STACK_EMPYY == stack_empty(my_stack))){
        printf("stack is empty can't pop any value \n");
        ret = R_NOK;
    }
    else{
        * value = my_stack->data[my_stack->stack_pointer];
        printf("value (%i) pop from stack \n",*value);
        (my_stack->stack_pointer)--;
        ret = R_OK;
    }
    return ret;
}

return_status_t stack_top(stack_ds_t *my_stack ,uint32_t *value){
    return_status_t ret = R_NOK;
    if((NULL == my_stack) || (NULL == value) || (STACK_EMPYY == stack_empty(my_stack))){
        printf("stack is empty can't reed any value \n");
        ret = R_NOK;
    }
    else{
        * value = my_stack->data[my_stack->stack_pointer];
        printf("value (%i) is stack top \n",*value);
        ret = R_OK;
    }
    return ret;
}


return_status_t stack_init(stack_ds_t *my_stack){
    return_status_t ret = R_NOK;
    if(NULL == my_stack){
        ret = R_NOK;
    }
     else {
        my_stack->stack_pointer = -1;
        ret = R_OK;
     }

    return ret;
}

