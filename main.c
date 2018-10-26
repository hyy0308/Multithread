#include <stdio.h>

void sorter(){
    int mylist[] =  {84, 24, 15, 12, 22, 110, 90};
    for (int i = 0; i < 7; i++) {
        printf("%d ",mylist[i]);
    }

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7 - i - 1; j++) {
            if (mylist[j] > mylist[j + 1]) {
                int temp = mylist[j];
                mylist[j] = mylist[j+1];
                mylist[j+1] = temp;
            }
        }
    }
    printf("_______________________");

    for (int i = 0; i < 7; i++) {
        printf("%d ",mylist[i]);
    }
}
void merger(){
    int arr1[] =  {1,2,5,7,9};
    int arr2[] =  {3,10,11,12,14};
    int arr3[10];
    int i = 0, j = 0, k = 0;
    while (i<5 && j <5)
    {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        }
        else{
            arr3[k++] = arr2[j++];
        }
    }
    while (i < 5) {
        arr3[k++] = arr1[i++];
    }
    while (j < 5) {
        arr3[k++] = arr2[j++];
    }
    for (int l = 0; l < 10; l++) {
        printf("%d ",arr3[l]);
    }
}
int main() {
    printf("Hello, World!\n");
    //sorter();
    merger();
    return 0;
}