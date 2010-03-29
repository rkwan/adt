#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "train.h"

Train* createTrain(int t_id, priority p_level, direction direction,
                    int loading_time, int crossing_time) {
	Train *train = malloc(sizeof(Train));
	train->t_id = t_id;
	train->p_level = p_level;
	train->direction = direction;
	train->loading_time = loading_time;
	train->crossing_time = crossing_time;

	return train;
}

void printTrain(Train *train) {
	if ( train == NULL ) 
		return;

	char p_level[5];
	char direction[5];

	int t_id = train->t_id;

	if (train->p_level == HIGH) 
		strncpy(p_level, "HIGH", 5);
	else
		strncpy(p_level, "LOW", 4);

	if (train->direction == EAST)
		strncpy(direction, "EAST", 5);
	else {
		strncpy(direction, "WEST", 5);
	}

	float loading_time = (float) train->loading_time/10;
	float crossing_time = (float) train->crossing_time/10;

	fprintf(stdout, "t_id:%d p_level:%s direction:%s loading_time:%.1fs crossing_time:%.1fs\n", t_id, p_level, direction, loading_time, crossing_time);

}
