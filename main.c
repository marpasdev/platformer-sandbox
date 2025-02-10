#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "camera.h"
#include "grid.h"
#include "player.h"
#include "mathutils.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void init(SDL_Window** window, SDL_Renderer** renderer) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    *window = SDL_CreateWindow(
        "Platformer Sandbox",
        100,
        100,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
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

    SDL_Texture* textures[3];
    textures[0] = NULL;
    textures[1] = IMG_LoadTexture(renderer, "assets/grass.png");
    textures[2] = IMG_LoadTexture(renderer, "assets/dirt.png");

    Player player = { .speed = 100.0f, .pos = (Vector2){ .x = 0, .y = 0 }};

    SDL_Point player_end;
    SDL_QueryTexture(textures[1], NULL, NULL, &player_end.x, &player_end.y);

    Camera camera = { .pos = vec2_add(player.pos, vec2_mul(point_to_vec2(player_end), 0.5f)), .zoom = 1.0f, 
        .screen_width = WINDOW_WIDTH, .screen_height = WINDOW_HEIGHT };

    SDL_Event event;

    float delta_time = 0;
    unsigned int last_tick_time = SDL_GetTicks();

    bool running = true;
    while (running) {
        unsigned int tick_time = SDL_GetTicks();
        delta_time = (tick_time - last_tick_time) / 1000.0f;
        last_tick_time = tick_time;
        if (delta_time > 0.05f) delta_time = 0.05f;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_KEYDOWN) {
                player_keydown_state(&player, event.key.keysym.sym);
            }
            if (event.type == SDL_KEYUP) {
                player_keyup_state(&player, event.key.keysym.sym);
            }
            if (event.type == SDL_MOUSEWHEEL) {
                if (event.wheel.y > 0) camera.zoom *= 1.1f;
                if (event.wheel.y < 0) camera.zoom /= 1.1f;
            }
        }

        player_move(&player, delta_time);
        camera_update(&camera, &player, textures[2]);

        SDL_SetRenderDrawColor(renderer, 0, 180, 255, 255);
        SDL_RenderClear(renderer);

        grid_draw(&terrain, renderer, textures, 2, camera);

        player_draw(&player, renderer, textures[2], camera);

        SDL_RenderPresent(renderer);
    }

    quit(window, renderer);

    return 0;
}