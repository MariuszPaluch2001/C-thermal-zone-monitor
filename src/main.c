#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

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
	if (numb_thermal_zones > 100){
		printf("%d args is too much.\n", numb_thermal_zones);
		return 3;
	}
	read_thermal_zone(0);
	return 0;
}
