#include <stdio.h>
#include <string.h>
#include "Trains.h"

void display_train_information(struct Train train){
    printf("Train ID: %d\n",train.id);
    printf("Train Name: %s\n",train.name);
    printf("Current Station: %s\n",train.current_station);
    printf("Destination: %s\n",train.destination_station);
    printf("Delay: %d\n",train.delay_minutes);
    switch(train.status){
        case ON_TIME:
            printf("STATUS: ON TIME\n");
            break;
        case DELAYED:
            printf("STATUS: DELAYED\n");
            break;
        case CANCELLED:
            printf("STATUS: CANCELLED\n");
            break;
    }
    
}
void initialize_trains(struct Train trains[]){
    trains[0] = (struct Train){
    11008, "Deccan Express", "Pune", "Mumbai", 15, DELAYED
    };
    trains[1]= (struct Train){
        17613, "Panvel Nanded Express", "Parbhani", "Nanded", 0, ON_TIME
    };
    trains[2]= (struct Train){
        12124, "Deccan Queen", "Pune", "Mumbai", 0, CANCELLED
    };
}