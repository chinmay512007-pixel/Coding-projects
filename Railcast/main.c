#include <stdio.h>
#include "Trains.h"
int main(void){
    struct Train trains[Train_count];
    initialize_trains(trains);
    for(int i=0; i<Train_count;i++){
        display_train_information(trains[i]);
        printf("\n");
    }
    
    return 0;
}