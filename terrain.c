#include <math.h>
#include <time.h>

#include "terrain.h"
#include "grid.h"
#include "noise.h"

static void contour_generate(int* contour, TerrainData data) {
    time_t seed = time(NULL);
    srand(seed);

    float rand1 = (float)rand()/(float)(RAND_MAX) + 1;
    float rand2 = (float)rand()/(float)(RAND_MAX) + 2;
    float rand3 = (float)rand()/(float)(RAND_MAX) + 3;

    for (int x = 0; x < data.width; ++x) {
        float height = data.peakheight / rand1 * sin((float)x / data.flatness * rand1 + rand1);
        height += data.peakheight / rand2 * sin((float)x / data.flatness * rand2 + rand2);
        height += data.peakheight / rand3 * sin((float)x / data.flatness * rand3 + rand3);
        height += data.offset;
        contour[x] = (int)height;
    }
}

static void caves_generate(Grid* terrain, TerrainData data) {
    Noise noise;
    noise_create(&noise, data.width, data.height);
    noise_generate(&noise);

    for (int y = data.offset; y < data.height; ++y) {
        for (int x = 0; x < data.width; ++x) {
            if (noise_get(&noise, x, y) < 0.7f /*&& grid_get(terrain, x, y) != 0*/) {
                grid_set(terrain, x, y, 0);
            }
        }
    }

    noise_remove(&noise);
}

void terrain_generate(Grid* terrain, TerrainData data) {
    int* contour = (int*)malloc(sizeof(int) * data.width);

    contour_generate(contour, data);

    for (int x = 0; x < data.width; ++x) {
        grid_set(terrain, x, contour[x], 1);

        for (int y = contour[x] + 1; y < data.height; ++y) {
            if (y < contour[x] + 4) {
                grid_set(terrain, x, y, 2);
            } else {
                grid_set(terrain, x, y, 3);
            }
        }
    }

    // caves_generate(terrain, data);

    free(contour);
}