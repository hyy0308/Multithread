#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>
#define NUMVALS 1024
int mylist[1024];
int sortedList[1024];
typedef struct {
    int start_index;
    int end_index;
} SortInfo;
int genRand(int low, int high) {
    // generate a random integer r such that low <= r <= high
    double r1, r2;
    int rtnval;
    r1 = drand48();
    r2 = (1 + high - low) * r1;
    rtnval = low + floor(r2);
    return(rtnval);
}
void *sorter(void *param){
    SortInfo *data = (SortInfo *) param;
    int start = data->start_index;
    int end  = data->end_index;
    int i,j,k;
    for (i = 0; i < NUMVALS/2; i++) {
        for (j = start; j < end - i; j++) {
            if (mylist[j] > mylist[j + 1]) {
                int temp = mylist[j];
                mylist[j] = mylist[j+1];
                mylist[j+1] = temp;
            }
        }
    }
    pthread_exit(0);
}
void *merger(void* param ){
    int* secondStart =(int *)param;
    //int secondStart = 512;
    int i = 0, j = *secondStart, k = 0;
    while (i<NUMVALS/2 && j <NUMVALS) {
        if (mylist[i] < mylist[j]) {
            sortedList[k++] = mylist[i++];
        } else{
            sortedList[k++] = mylist[j++];
        }
    }
    while (i < NUMVALS/2) {
        sortedList[k++] = mylist[i++];
    }
    while (j < NUMVALS) {
        sortedList[k++] = mylist[j++];
    }
    pthread_exit(0);
}
int main(){
    int i;
    for (i = 0; i < NUMVALS; ++i) {
        mylist[i] = genRand(0,5000);
    }
    SortInfo sortInfo1, sortInfo2;
    pthread_t tid1; /* thread identifier */
    pthread_t tid2; /* thread identifier */
    pthread_t tid3; /* thread identifier */
    pthread_attr_t attr; /* thread attributes */
    pthread_attr_init(&attr);
    sortInfo1.start_index = 0;
    sortInfo1.end_index = NUMVALS/2;
    sortInfo2.start_index = sortInfo1.end_index + 1;
    sortInfo2.end_index = NUMVALS-1;
    pthread_create(&tid1, &attr, sorter, &sortInfo1);
    pthread_create(&tid2, &attr, sorter, &sortInfo2);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    int secondStart = sortInfo2.start_index;
    pthread_create(&tid3, &attr, merger, &secondStart);
    pthread_join(tid3,NULL);
    return 0;
}

