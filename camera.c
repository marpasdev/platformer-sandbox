#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <math.h>

#include "camera.h"
#include "player.h"
#include "mathutils.h"

Vector2 to_screen_coords(Vector2 world_coords, Camera camera) {
    Vector2 screen_coords = { .x = 0, .y = 0 };
    screen_coords.x = (world_coords.x - camera.pos.x) * camera.zoom + camera.screen_width / 2;
    screen_coords.y = (world_coords.y - camera.pos.y) * camera.zoom + camera.screen_height / 2;
    return screen_coords; 
}

SDL_Rect to_screen_rect(SDL_Rect rect, Camera camera) {
    SDL_Rect screen_rect;
    screen_rect.x = (rect.x - camera.pos.x) * camera.zoom + camera.screen_width / 2;
    screen_rect.y = (rect.y - camera.pos.y) * camera.zoom + camera.screen_height / 2;
    screen_rect.w = (int)ceil(rect.w * camera.zoom);
    screen_rect.h = (int)ceil(rect.h * camera.zoom);
    return screen_rect;
}

void draw_to_screen(SDL_Renderer* renderer, Vector2 pos, SDL_Texture* texture, Camera camera) {
    SDL_Rect world_rect = { .x = pos.x, .y = pos.y };
    SDL_QueryTexture(texture, NULL, NULL, &world_rect.w, &world_rect.h);
    SDL_Rect screen_rect = to_screen_rect(world_rect, camera);
    SDL_RenderCopy(renderer, texture, NULL, &screen_rect);
}

void camera_update(Camera* camera, Player* player, SDL_Texture* texture) {
    int player_width;
    int player_height;
    SDL_QueryTexture(texture, NULL, NULL, &player_width, &player_height);

    camera->pos.x = (player->pos.x + (float)player_width / 2.0f);
    camera->pos.y = (player->pos.y + (float)player_height / 2.0f);    
}