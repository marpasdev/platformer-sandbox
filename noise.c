#include "noise.h"

#include <stdlib.h>
#include <time.h>

void noise_create(Noise* noise, int width, int height) {
    noise->width = width;
    noise->height = height;
    noise->grid = (float*)calloc(width * height, sizeof(float));
}

// just a testing version - rewrite to use a proper noise generation algorithm instead of
// pure random values
void noise_generate(Noise* noise) {
    time_t seed = time(NULL);
    srand(seed);
    float random = 0;
    for (int y = 0; y < noise->width; ++y) {
        for (int x = 0; x < noise->height; ++x) {
            random = (float)rand()/(float)(RAND_MAX);
            noise_set(noise, x, y, random);
        }
    }
}

void noise_remove(Noise* noise) {
    free(noise->grid);
}

float noise_get(Noise* noise, int x, int y) {
    if (x < noise->width && x >= 0 && y < noise->height && y >= 0) {
        return noise->grid[noise->width * y + x];
    } else {
        return -1;
    }
}

void noise_set(Noise* noise, int x, int y, float value) {
    if (x < noise->width && x >= 0 && y < noise->height && y >= 0) {
        noise->grid[noise->width * y + x] = value;
    }
}