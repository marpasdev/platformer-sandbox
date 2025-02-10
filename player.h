#pragma once

#include <SDL2/SDL.h>
#include <stdbool.h>

#include "mathutils.h"

typedef struct Camera Camera;

typedef struct Player {
    Vector2 pos;
    float speed;
    bool isMovingLeft;
    bool isMovingRight;
    bool isMovingUp;
    bool isMovingDown;
} Player;

void player_keydown_state(Player* player, SDL_Keycode code);

void player_keyup_state(Player* player, SDL_Keycode code);

void player_move(Player* player, float delta_time);

void player_draw(Player* player, SDL_Renderer* renderer, SDL_Texture* texture, Camera camera);