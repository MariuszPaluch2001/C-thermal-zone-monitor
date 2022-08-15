#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char * get_filename_idx(char* gen_filename, int index){
	char str_idx[5];
	snprintf( str_idx, 5, "%d", index);
	strcat(gen_filename, str_idx);
	puts("dupa_blada");
	return gen_filename;		
}

unsigned int read_thermal_zone(int zone_index){
	char path_thermal_zone[100] = "/sys/class/thermal/thermal_zone";	
	return 10000;
}
