#pragma once

#include <SDL2/SDL.h>

typedef struct {
    float x;
    float y;
} Vector2;

Vector2 vec2_add(Vector2 v1, Vector2 v2);

Vector2 vec2_sub(Vector2 v1, Vector2 v2);

Vector2 vec2_mul(Vector2 v, float value);

Vector2 point_to_vec2(SDL_Point p);

typedef struct {
    float a11;
    float a12;
    float a13;
    float a14;
    float a21;
    float a22;
    float a23;
    float a24;
    float a31;
    float a32;
    float a33;
    float a34;
    float a41;
    float a42;
    float a43;
    float a44;
} Matrix;