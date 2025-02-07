#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "grid.h"

void init(SDL_Window** window, SDL_Renderer** renderer) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    *window = SDL_CreateWindow(
        "Platformer Sandbox",
        100,
        100,
        800,
        600,
        SDL_WINDOW_SHOWN & SDL_WINDOW_RESIZABLE
    );

    *renderer = SDL_CreateRenderer(
        *window, -1,
        SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED
    );

    SDL_SetRenderDrawBlendMode(*renderer, SDL_BLENDMODE_BLEND);
}

void quit(SDL_Window* window, SDL_Renderer* renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

int main() {

    SDL_Renderer* renderer;
    SDL_Window* window;
    init(&window, &renderer);

    Grid terrain;
    grid_create(&terrain, 200, 200);

    // testing the grid
    grid_set(&terrain, 3, 3, 1);
    grid_set(&terrain, 4, 3, 1);

    SDL_Texture* textures[2];
    textures[0] = NULL;
    textures[1] = IMG_LoadTexture(renderer, "assets/grass.png");

    SDL_Event event;

    bool running = true;
    while (running) {

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 180, 255, 255);
        SDL_RenderClear(renderer);

        grid_draw(&terrain, renderer, textures, 2, 32);

        SDL_RenderPresent(renderer);
    }

    quit(window, renderer);

    return 0;
}