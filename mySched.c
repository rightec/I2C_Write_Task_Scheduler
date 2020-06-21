#include "mySched.h"

/*Declaration*/
myTasks_t taskQueue[MAX_SCHED_LIST];
int g_CurrentItem = 0;
int g_ActualSize = 0;


void resetList(){
    int i = 0;
    for (i=0; i< MAX_SCHED_LIST; i++){
        taskQueue[i].sDataLenght = 0;
        taskQueue[i].task_prio = -1; /*not set is -1*/
        taskQueue[i].u8Address = 0;
        taskQueue[i].u8Data = NULL;
        taskQueue[i].callback = NULL;
        
        printf("Fill and reset element %d\n",i);
    }
    g_CurrentItem = -1;
}

void pop(bool *_res, myTasks_t *_popItem)
{
    if (g_CurrentItem == -1){
        /* There is nothing to pop*/
    *_res = false;
    }else{
        /*POP from the head*/
        _popItem->callback = taskQueue[g_CurrentItem].callback;
        _popItem->sDataLenght = taskQueue[g_CurrentItem].sDataLenght;
        _popItem->task_prio = taskQueue[g_CurrentItem].task_prio;
        _popItem->u8Address = taskQueue[g_CurrentItem].u8Address;
        _popItem->u8Data = taskQueue[g_CurrentItem].u8Data;

        g_CurrentItem--;
        g_ActualSize--;

        *_res = true;
    }    
}

