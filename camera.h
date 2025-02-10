#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "mathutils.h"

typedef struct Player Player;

typedef struct Camera {
    Vector2 pos;
    float zoom;
    int screen_width;
    int screen_height;
} Camera;

Vector2 to_screen_coords(Vector2 world_coords, Camera camera);

SDL_Rect to_screen_rect(SDL_Rect rect, Camera camera);

void draw_to_screen(SDL_Renderer* renderer, Vector2 pos, SDL_Texture* texture, Camera camera);

void camera_update(Camera* camera, Player* player, SDL_Texture* texture);