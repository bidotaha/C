#include "Queue.h"

static uint8 Queue_is_full (Queue_t *queue_obj){
    return (queue_obj->ElementCount == queue_obj->QueueMaxSize);
}
static uint8 Queue_is_empty (Queue_t *queue_obj){
    return (0 == queue_obj->ElementCount);
}



Queue_t *CreateQueue(uint32 maxSize, QueueStatus_t *ret_status){
    Queue_t *my_queue;
    my_queue = (Queue_t *)malloc(sizeof(Queue_t));
    if (my_queue == NULL){
        *ret_status = QUEUE_NULL_POINTER;
        my_queue = NULL;
    }
    else{
        my_queue->QueueArray = (void **)calloc(maxSize,sizeof(void *));
        if(NULL == my_queue->QueueArray){
            *ret_status = QUEUE_NOK;
            my_queue = NULL;
        }
        else{
            my_queue->ElementCount = 0;
            my_queue->QueueFront = -1;
            my_queue->QueueRear = -1;
            my_queue->QueueMaxSize = maxSize;
            *ret_status = QUEUE_OK;
        }
    }
    return my_queue;
}
QueueStatus_t EnqueueElement(Queue_t *queue_obj, void *item_ptr){
    QueueStatus_t status = QUEUE_NOK;
    if((NULL == queue_obj) || (NULL == item_ptr)){
        status = QUEUE_NOK;
    }
    else{
        if(Queue_is_full(queue_obj)){
            status = QUEUE_FULL;
        }
        else{
        (queue_obj->QueueRear)++;
        if(queue_obj->QueueRear == queue_obj->QueueMaxSize){
            queue_obj->QueueRear =0;
        }
        queue_obj->QueueArray[queue_obj->QueueRear] = item_ptr;
        if(queue_obj->ElementCount ==0){
            queue_obj->QueueFront = 0;
            queue_obj->ElementCount = 1;
        }
        else{
            (queue_obj->ElementCount)++;
        }
        status = QUEUE_OK;
        }
    }
return status;
}
void *DequeueElement(Queue_t *queue_obj, QueueStatus_t *ret_status){
    void *ReturnEelem = NULL;
    if((NULL == queue_obj) || (NULL == ret_status)){
        *ret_status = QUEUE_NULL_POINTER;
    }
    else{
        if(Queue_is_empty(queue_obj)){
            *ret_status = QUEUE_EMPTY;
            ReturnEelem = NULL;
        }
        else{
            ReturnEelem = queue_obj->QueueArray[queue_obj->QueueFront];
            (queue_obj->QueueFront)++;

            if(queue_obj->QueueFront == queue_obj->QueueMaxSize){
                queue_obj->QueueFront =0;
            }
            else{}
            if(1 == queue_obj->ElementCount){
                queue_obj->QueueFront = -1;
                queue_obj->QueueRear = -1;
            }
            else{}
            (queue_obj->ElementCount)--;
            *ret_status = QUEUE_OK;

        }

    }
     return ReturnEelem;
}
void *QueueFront(Queue_t *queue_obj, QueueStatus_t *ret_status){
        void *ReturnEelem = NULL;
        if(NULL == queue_obj || (NULL == ret_status)){
            *ret_status = QUEUE_NOK;
        }
        else{
            if(Queue_is_empty(queue_obj)){
            *ret_status = QUEUE_EMPTY;
            ReturnEelem = NULL;
        }
        else{
            ReturnEelem = queue_obj->QueueArray[queue_obj->QueueFront];
            *ret_status = QUEUE_OK;
            }
        }
    return ReturnEelem;
}
void *QueueRear(Queue_t *queue_obj, QueueStatus_t *ret_status){
            void *ReturnEelem = NULL;
        if(NULL == queue_obj || (NULL == ret_status)){
            *ret_status = QUEUE_NOK;
        }
        else{
            if(Queue_is_empty(queue_obj)){
            *ret_status = QUEUE_EMPTY;
            ReturnEelem = NULL;
        }
        else{
            ReturnEelem = queue_obj->QueueArray[queue_obj->QueueRear];
            *ret_status = QUEUE_OK;
            }
        }
    return ReturnEelem;
}
QueueStatus_t GetQueueCount(Queue_t *queue_obj, uint32 *QueueCount){
    QueueStatus_t status = QUEUE_NOK;
    if(NULL == queue_obj || (NULL == QueueCount)){
        status = QUEUE_NULL_POINTER;
    }
    else{
            if(Queue_is_empty(queue_obj)){
            QueueCount = 0;
        }
        else{
           *QueueCount = queue_obj->ElementCount;
            }
            status = QUEUE_OK;
    }
    return status;
}
QueueStatus_t DestroyQueue(Queue_t *queue_obj){
    QueueStatus_t status = QUEUE_NOK;
    if (NULL == queue_obj){
        status = QUEUE_NULL_POINTER;
    }
    else{
        free(queue_obj->QueueArray);
        free(queue_obj);
        status = QUEUE_OK;
    }
    return status;
}

