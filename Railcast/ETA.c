#include <math.h>
#include "ETA.h"
double calculate_travel_time(double distance_km, double speed_kmph){
    if(!isfinite(distance_km)||!isfinite(speed_kmph)||distance_km<0||speed_kmph<=0 ){
        return -1;
    }
    return distance_km/speed_kmph;
}
double calculate_arrival_time(double travel_time, double delay){
    if(!isfinite(travel_time)||!isfinite(delay)||travel_time<0||delay<0){
        return -1;
    }
    return (travel_time*60)+delay;
}