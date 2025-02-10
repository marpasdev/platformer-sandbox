#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>

#include "player.h"
#include "camera.h"
#include "mathutils.h"

void player_move(Player* player, float delta_time) {
    if (player->isMovingUp) {
        player->pos.y -= player->speed * delta_time;
    }
    if (player->isMovingDown) {
        player->pos.y += player->speed * delta_time;
    }
    if (player->isMovingLeft) {
        player->pos.x -= player->speed * delta_time;
    }
    if (player->isMovingRight) {
        player->pos.x += player->speed * delta_time;
    }
} 

// TODO: divide into two functions - one for pressing the key and
// the other for keyup, changing the states
void player_keydown_state(Player* player, SDL_Keycode code) {
    if (code == SDLK_w || code == SDLK_UP) {
        player->isMovingUp = true;
    }
    if (code == SDLK_s || code == SDLK_DOWN) {
        player->isMovingDown = true;
    }
    if (code == SDLK_a || code == SDLK_LEFT) {
        player->isMovingLeft = true;
    }
    if (code == SDLK_d || code == SDLK_RIGHT) {
        player->isMovingRight = true;
    }
}

void player_keyup_state(Player* player, SDL_Keycode code) {
    if (code == SDLK_w || code == SDLK_UP) {
        player->isMovingUp = false;
    }
    if (code == SDLK_s || code == SDLK_DOWN) {
        player->isMovingDown = false;
    }
    if (code == SDLK_a || code == SDLK_LEFT) {
        player->isMovingLeft = false;
    }
    if (code == SDLK_d || code == SDLK_RIGHT) {
        player->isMovingRight = false;
    }  
}

void player_draw(Player* player, SDL_Renderer* renderer, 
    SDL_Texture* texture, Camera camera) {
    draw_to_screen(renderer, player->pos, texture, camera);
}