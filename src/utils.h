#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define STR_NUMB_BUFF 5
#define MAX_USER_ZONES_NUMB 100

void get_filename_idx(char* gen_filename, int index){
	char str_idx[STR_NUMB_BUFF];
	snprintf( str_idx, STR_NUMB_BUFF, "%d", index);
	strcat(gen_filename, str_idx);
	strcat(gen_filename, "/temp");		
}

struct thermal_zone_data{
	int index;
	double temp;
	char * path;
};

unsigned int read_thermal_zone(int zone_index){
	char path_thermal_zone[MAX_USER_ZONES_NUMB] = "/sys/class/thermal/thermal_zone";
	get_filename_idx(path_thermal_zone, zone_index);
	FILE* fileptr;
	fileptr = fopen(path_thermal_zone, "r");
    	if (fileptr == NULL) {
        	puts("file can not open \n");
    		return 0;
    	}
    	
    	char * buff = NULL;
    	size_t buff_size = 10;
    	getline(&buff, &buff_size, fileptr);
   	
   	printf("%s\n", buff);
    	fclose(fileptr);
	return 10000;
}
