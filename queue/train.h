#ifndef TRAIN_H
#define TRAIN_H

typedef enum { LOW, HIGH } priority;
typedef enum { EAST, WEST } direction;

typedef struct {
	int t_id;
	priority p_level;
	direction direction;
	int loading_time;
	int crossing_time;
}Train;

Train* createTrain(int t_id, priority p_level, direction direction,
                    int loading_time, int crossing_time);
void printTrain(Train *train);
#endif
