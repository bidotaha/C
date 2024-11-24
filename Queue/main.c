#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

uint32 Queue1max = 0;
Queue_t *Queue1;

void *Queueretval;
uint32 Queucount = 0;

uint32 num1 = 0x11, num2 = 0x22, num3 = 0x33, num4 = 0x44, num5 = 0x55;

int main()
{
    QueueStatus_t returnqueuestatus = QUEUE_NOK;

    printf("enter the number of elements : ");
    scanf("%i",&Queue1max);

    Queue1 = CreateQueue(Queue1max,&returnqueuestatus);
    printf("0x%x\n",Queue1);


    returnqueuestatus = EnqueueElement(Queue1,&num1);
    printf("%i\n",returnqueuestatus);

    returnqueuestatus = EnqueueElement(Queue1,&num2);
    printf("%i\n",returnqueuestatus);

    Queueretval = QueueRear(Queue1,&returnqueuestatus);
    printf("%i\n",returnqueuestatus);
    printf("0x%x\n",*((uint32 *)Queueretval));

    returnqueuestatus = EnqueueElement(Queue1,&num3);
    printf("%i\n",returnqueuestatus);

    returnqueuestatus = EnqueueElement(Queue1,&num4);
    printf("%i\n",returnqueuestatus);

    returnqueuestatus = EnqueueElement(Queue1,&num5);
    printf("%i\n",returnqueuestatus);

    returnqueuestatus = EnqueueElement(Queue1,&num5);
    printf("%i\n",returnqueuestatus);

    returnqueuestatus = GetQueueCount(Queue1,&Queucount);
    printf("%i\n",returnqueuestatus);
    printf("count = %i\n",Queucount);

    Queueretval = DequeueElement(Queue1,&returnqueuestatus);
    printf("%i\n",returnqueuestatus);
    printf("0x%x\n",*((uint32 *)Queueretval));

    Queueretval = DequeueElement(Queue1,&returnqueuestatus);
    printf("%i\n",returnqueuestatus);
    printf("0x%x\n",*((uint32 *)Queueretval));

    Queueretval = QueueFront(Queue1,&returnqueuestatus);
    printf("%i\n",returnqueuestatus);
    printf("0x%x\n",*((uint32 *)Queueretval));

    Queueretval = DequeueElement(Queue1,&returnqueuestatus);
    printf("%i\n",returnqueuestatus);
    printf("0x%x\n",*((uint32 *)Queueretval));

    Queueretval = DequeueElement(Queue1,&returnqueuestatus);
    printf("%i\n",returnqueuestatus);
    printf("0x%x\n",*((uint32 *)Queueretval));

    Queueretval = DequeueElement(Queue1,&returnqueuestatus);
    printf("%i\n",returnqueuestatus);
    printf("0x%x\n",*((uint32 *)Queueretval));

    Queueretval = DequeueElement(Queue1,&returnqueuestatus);
    printf("%i\n",returnqueuestatus);


    returnqueuestatus = DestroyQueue(Queue1);
    printf("%i\n",returnqueuestatus);

    return 0;
}

