#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(int argc, char* argv[]){
	const int numb_thermal_zones = atoi(argv[1]);
	if (argc != 2){
		puts("Incorrect number of args.");
		return 1;
	}
	if (numb_thermal_zones <= 0){
		printf("'%s' is not correct arg.\n", argv[1]);
		return 2;
	}
	if (numb_thermal_zones > 100){
		printf("%d args is too much.\n", numb_thermal_zones);
		return 3;
	}
	char dupa[30] = "dupa";
	printf("%s \n", get_filename_idx(dupa, 1));
	return 0;
}
