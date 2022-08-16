#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
void read_sensors(unsigned int numb_zones){
	for (int i; i < numb_zones; i++){
		Thermal_Zone_Data *data = read_thermal_zone(i);
		printf("Thermal_zone_%d\n", data->index);
		printf("Temp: %d\n", data->temp);
		free(data);
	}
}
int main(int argc, char* argv[]){
	if (argc != 2){
		puts("Incorrect number of args.");
		return 1;
	}
	const int numb_thermal_zones = atoi(argv[1]);
	if (numb_thermal_zones <= 0){
		printf("'%s' is not correct arg.\n", argv[1]);
		return 2;
	}
	if (numb_thermal_zones > MAX_USER_ZONES_NUMB){
		printf("%d args is too much.\n", numb_thermal_zones);
		return 3;
	}
	read_sensors(numb_thermal_zones);
	return 0;
}
