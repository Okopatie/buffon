#include "buffon.h"

float RandomFloatInRange(float start, float stop) {
    int randint = rand();
    float range = stop - start;
    return start + range * (randint/((float)RAND_MAX+1));
}

Stick GenerateStick() {
    float x1 = RandomFloatInRange(0, BOARD_WIDTH);
    float y1 = RandomFloatInRange(0, BOARD_HEIGHT);
    float theta = RandomFloatInRange(-(PI), PI);
    float x2 = x1 + STICK_LENGTH * cosf(theta);
    float y2 = y1 + STICK_LENGTH * sinf(theta);
    int y1_int = (int)(y1 / STICK_LENGTH + 1);
    int y2_int = (int)(y2 / STICK_LENGTH + 1);
    bool crossing = y1_int != y2_int;
    Stick stick;
    stick.x1 = x1;
    stick.x2 = x2;
    stick.y1 = y1;
    stick.y2 = y2;
    stick.crossing = crossing;
    return stick;
}
StickList *CreateStickList() {
    StickList *sl = malloc(sizeof(StickList));
    sl->len = 0;
    sl->capacity = 1;
    sl->list = malloc(sizeof(Stick));
    sl->num_crossing = 0;
    return sl;
}

void AddToStickList(StickList *sl) {
    if (sl->len >= sl->capacity) {
	sl->capacity *= 2;
	sl->list = realloc(sl->list, sl->capacity * sizeof(Stick));
    }
    Stick stick = GenerateStick();
    if (stick.crossing) sl->num_crossing++;
    sl->list[sl->len] = GenerateStick();
    sl->len++;
}
