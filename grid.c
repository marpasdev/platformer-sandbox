#include "grid.h"
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "camera.h"

void grid_create(Grid* grid, int width, int height) {
    grid->grid = (int*)calloc(width * height, sizeof(int));
    grid->width = width;
    grid->height = height;
}

void grid_remove(Grid* grid) {
    free(grid->grid);
}

int grid_get(Grid* grid, int x, int y) {
    for (int y = 0; y < grid->height; ++y) {
        for (int x = 0; x < grid->width; ++x) {
            return grid->grid[y * grid->width + x];
        }
    }
}

void grid_set(Grid* grid, int x, int y, int value) {
    grid->grid[y * grid->width + x] = value;
}

// draw each tile in the grid, while transforming the coordinates based on the camera's position
void grid_draw(Grid* grid, SDL_Renderer* renderer, SDL_Texture** textures, size_t textures_size, Camera camera) {
    for (int y = 0; y < grid->height; ++y) {
        for (int x = 0; x < grid->width; ++x) {
            int tile_number = grid->grid[y * grid->width + x];
            if (tile_number != 0 && tile_number < textures_size) {
                int tile_size = 0;
                SDL_QueryTexture(textures[tile_number], NULL, NULL, &tile_size, NULL);
                Vector2 tile_pos = { .x = x * tile_size, .y = y * tile_size };
                draw_to_screen(renderer, tile_pos, textures[tile_number], camera);
            }
        }
    }
}