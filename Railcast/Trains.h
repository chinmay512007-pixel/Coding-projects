#ifndef TRAINS_H
#define TRAINS_H
#define Train_count 3
//Defining the train status enum
enum TrainStatus{
    ON_TIME,
    DELAYED,
    CANCELLED
};
struct Train {
    int id;
    char name[50];
    char current_station[50];
    char destination_station[50];
    int delay_minutes;
    enum TrainStatus status;
};
void initialize_trains(struct Train trains[]);
void display_train_information(struct Train train);
#endif // TRAINS_H