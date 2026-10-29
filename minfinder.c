#include <stdio.h>
#include "minfinder.h"
int minfinder(int* arr, int n, int* min){
    if(arr==NULL||n<=0||min==NULL){
        return -1;
    }
    *min=arr[0];
    for(int i=0; i<n;i++){
        if(arr[i] < *min){
            *min=arr[i];
        }
    }
    return *min;
}
