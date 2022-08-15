#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void get_filename_idx(char* gen_filename, int index){
	char str_idx[5];
	snprintf( str_idx, 5, "%d", index);
	strcat(gen_filename, str_idx);		
}

unsigned int read_thermal_zone(int zone_index){
	char path_thermal_zone[100] = "/sys/class/thermal/thermal_zone";
	get_filename_idx(path_thermal_zone, 0);

	return 10000;
}
