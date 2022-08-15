#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	const int numb_thermal_zones = atoi(argv[1]);
	if (numb_thermal_zones <= 0){
		printf("'%s' is not correct arg.\n", argv[1]);
		return 1;
	}

	return 0;
}
