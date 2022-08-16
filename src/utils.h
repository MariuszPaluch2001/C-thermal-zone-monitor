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

typedef struct{
	unsigned int index;
	unsigned int temp;
} Thermal_Zone_Data;

char * read_data(char * file_path){
	FILE* fileptr;
	fileptr = fopen(file_path, "r");
    	if (fileptr == NULL) {
        	printf("File %s couldn't be opened.\n", file_path);
    		exit(-1);
    	}
    	
    	char * buff = NULL;
    	size_t buff_size = 10;
    	getline(&buff, &buff_size, fileptr);
    	fclose(fileptr);
    	return buff;
}

Thermal_Zone_Data * read_thermal_zone(int zone_index){
	char path_thermal_zone[MAX_USER_ZONES_NUMB] = "/sys/class/thermal/thermal_zone";
	get_filename_idx(path_thermal_zone, zone_index);
    	char * buff = read_data(path_thermal_zone);
   	Thermal_Zone_Data *zone_data = malloc(sizeof(Thermal_Zone_Data));
   	zone_data->index = zone_index;
   	zone_data->temp = atoi(buff);
	return zone_data;
}

double convert_m_cels_to_cels(int m_cels){
	return (double) m_cels / 1000;
}
