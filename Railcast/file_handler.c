#include <stdio.h>
#include "file_handler.h"
int load_trains_from_file(struct Train trains[], const char* filename){
    FILE* file= fopen(filename, "r");
    if(file==NULL){
        printf("Error loading the file\n");
        return -1;
    }
    char line[250];
    int count=0;
    while(fgets(line, sizeof(line), file)!=NULL){
        int id;
        int delay;
        int status;
        char name[50];
        char current_station[50];
        char next_station[50];
        char extra;
        
int fields = sscanf(
    line,
    "%d|%49[^|]|%49[^|]|%49[^|]|%d|%d %c",
    &id, name, current_station, next_station,
    &delay, &status, &extra
);

        
        if(fields!=6||id<=0||delay<0||status<ON_TIME||status>CANCELLED){
            printf("Error:Invalid Train record in file\n");
            fclose(file);
            return -1;
        }
        if(count>=max_count){
            printf("Error: Too many Train records\n");
            fclose(file);
            return -1;
        }
        trains[count].id=id;
        snprintf(trains[count].name, sizeof(trains[count].name), "%s", name);
        snprintf(trains[count].current_station, sizeof(trains[count].current_station), "%s", current_station);
        snprintf(trains[count].destination_station,sizeof(trains[count].destination_station), "%s", next_station);
        trains[count].delay_minutes = delay;
        trains[count].status = (enum TrainStatus)status;
        count++;
    }
    if(ferror(file)){
        printf("Could not read the file contents");
        fclose(file);
        return -1;
    }
    fclose(file);
    return count;
}