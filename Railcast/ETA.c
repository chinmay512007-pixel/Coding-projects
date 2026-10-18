#include "ETA.h"
double calculate_travel_time(double distance_km, double speed_kmph){
    if(distance_km<0||speed_kmph<=0 ){
        return -1;
    }
    return distance_km/speed_kmph;
}
