#include "mySched.c"

void main(){    
    myTasks_t popItem;

    myTasks_t s_pushItem_1 = {
    task_prio: 3,
    u8Address : 0,
    u8Data : NULL,
    sDataLenght : 6,
    callback : NULL
};
    

    bool retPop = false;

    printf ("Hello Scheduler\n");
    resetList();

    pop(&retPop, &popItem);

    if (retPop == true){
        printf ("We pop from the queue\n");
    }else{
        printf ("We DID NOT pop from the queue\n");
    }

}