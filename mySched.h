#ifndef MYSCHED_H
#define MYSCHED_H

#include "stdint.h"
#include "stdio.h"
#include <stdbool.h> 

#define MAX_SCHED_LIST      5 /*Max number of element in the array*/

typedef struct myTasks
{
    /* Prepare data */
    int task_prio;  /*task priority*/
    uint8_t u8Address;
    uint8_t *u8Data;
    size_t sDataLenght;
    void (*callback)(bool);
}myTasks_t;


extern void resetList();
bool push(myTasks_t i2cWriteTask);
void pop(bool *_res, myTasks_t *_popItem);

bool isAPriorityTask(int _prio);
int searchFirstPlace();


#endif // MYSCHED_H
