#pragma once

typedef struct Noise {
    float* grid;
    int width;
    int height;
} Noise;

void noise_create(Noise* noise, int width, int height);

void noise_remove(Noise* noise);

void noise_generate(Noise* noise);

float noise_get(Noise* noise, int x, int y);

void noise_set(Noise* noise, int x, int y, float value);