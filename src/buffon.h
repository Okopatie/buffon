#ifndef BUFFON_H_
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "raylib.h"

#define BUFFON_H_

#define BOARD_WIDTH 600
#define BOARD_HEIGHT 600
#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 800
#define STICK_LENGTH 100
#define Y_PADDING 10

typedef struct {
    float x1;
    float y1;
    float x2;
    float y2;
    bool crossing;
} Stick;

Stick GenerateStick();

typedef struct {
    int len;
    int capacity;
    int num_crossing;
    Stick *list;
} StickList;


StickList *CreateStickList();
void AddToStickList(StickList *sl);

float RandomFloatInRange(float start, float stop);

#endif
