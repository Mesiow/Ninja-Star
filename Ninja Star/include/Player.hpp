//
//  Player.hpp
//  Ninja Star
//
//  Created by Chris W on 2/15/24.
//

#ifndef Player_hpp
#define Player_hpp

#include "Star.hpp"
#include "raylib/raymath.h"

struct Player {
    bool animating = false;
    int frameCounter = 0;
    int currentFrame = 0;
    
    struct Sprite *sprite;
    struct Star star; //player's weapon
};

void player_init(struct Player *player, Texture2D *texture, Texture2D *starTexture, Vector2 position);
void player_destroy(struct Player *player);

void player_check_input(struct Player *player);
void player_update(struct Player *player, Vector2 mousepos);
void player_draw(struct Player *player);

Rectangle player_get_star_rect(struct Player *player);

#endif
