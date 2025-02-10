#include "mathutils.h"

Vector2 vec2_add(Vector2 v1, Vector2 v2) {
    return (Vector2){ .x = v1.x + v2.x, v1.y + v2.y };
}

Vector2 vec2_sub(Vector2 v1, Vector2 v2) {
    return (Vector2){ .x = v1.x - v2.x, v1.y - v2.y };
}

Vector2 vec2_mul(Vector2 v, float value) {
    return (Vector2){ .x = v.x * value, .y = v.y * value };
}

Vector2 point_to_vec2(SDL_Point p) {
    return (Vector2){ .x = p.x, .y = p.y };
}