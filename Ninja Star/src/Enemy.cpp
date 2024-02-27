//
//  Enemy.cpp
//  Ninja Star
//
//  Created by Chris W on 2/19/24.
//

#include "Enemy.hpp"
#include "../include/Sprite.hpp"

void enemy_init(struct Enemy *enemy, Texture2D *texture, Vector2 position){
    enemy->sprite = sprite_create(position.x, position.y, texture);
    enemy->sprite->rotation = 60.0f;
    sprite_scale(enemy->sprite, 2.0f);
}

void enemy_destroy(struct Enemy *enemy){
    sprite_destroy(enemy->sprite);
}

void enemy_update(struct Enemy *enemy){
    
}

void enemy_draw(struct Enemy *enemy){
    struct Sprite *s = enemy->sprite;
    DrawTexturePro(*s->texture, s->srcrect, s->destrect, s->origin, s->rotation, WHITE);
}

Rectangle enemy_get_rect(struct Enemy *enemy){
    return enemy->sprite->destrect;
}
