#include <stdio.h>
#include "Trains.h"
#include "ETA.h"
int main(void){
    int train_id;
    double distance=0;
    double speed=0;
    struct Train trains[Train_count];
    initialize_trains(trains);
    printf("---Welcome To RailCast---\n");
    printf("Enter Train Id : ");
    if(scanf("%d", &train_id)!=1){
        printf("Invalid Input\n");
        return 1;
    }
    train_id=find_train_using_id(trains, train_id);
    if(train_id==-1){
        printf("Train not found\n");
        return 1;
    }
    display_train_information(trains[train_id]);
    printf("Enter remaining distance in KM: ");
    if(scanf("%lf",&distance)!=1){
        printf("Invalid input\n");
        return 1;
    }
    if(distance==0){
        printf("The train has arrived");
        return 0;
    }
    printf("Enter avg.speed in kmph: ");
    if(scanf("%lf",&speed)!=1){
        printf("Invalid input\n");
        return 1;
    }
    
    double time= calculate_travel_time(distance, speed);
    if(time<0){
        printf("Invalid condition");
    }
    else{
        printf("The estimated time in hours is %2f \n",time);
        printf("The estimated time in minutes is %2f ",time*60);
    }
    return 0;
}