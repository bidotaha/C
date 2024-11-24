#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

#include "Platform_types.h"

typedef struct{
    void **QueueArray;   /* Pointer to array of void pointers */
    uint32 QueueMaxSize; /* Maximum elements in the Queue */
    sint32 ElementCount; /* Number of elements in the Queue */
    sint32 QueueFront;   /* Index of the front elements */
    sint32 QueueRear;    /* Index of the rear elements */
}Queue_t;

typedef enum{
    QUEUE_NOK = 0,     /* Queue operation not performed successfully */
    QUEUE_OK,          /* Queue operation performed successfully  */
    QUEUE_FULL,        /* Queue is full */
    QUEUE_EMPTY,       /* Queue is empty */
    QUEUE_NULL_POINTER /* NULL pointer passed to the Queue */
}QueueStatus_t;

Queue_t *CreateQueue(uint32 maxSize, QueueStatus_t *ret_status);
QueueStatus_t EnqueueElement(Queue_t *queue_obj, void *item_ptr);
void *DequeueElement(Queue_t *queue_obj, QueueStatus_t *ret_status);


#endif // QUEUE_H_
