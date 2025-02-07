#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct Grid {
    int* grid;
    int width;
    int height;
} Grid;

void grid_create(Grid* grid, int width, int height);

void grid_remove(Grid* grid);

int grid_get(Grid* grid, int x, int y);

void grid_set(Grid* grid, int x, int y, int value);

void grid_draw(Grid* grid, SDL_Renderer* renderer, SDL_Texture** textures, size_t textures_size, int tile_size);