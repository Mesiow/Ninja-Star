//
//  Game.hpp
//  Ninja Star
//
//  Created by Chris W on 2/17/24.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Map.hpp"
#include "Collision.hpp"

static const int SCREEN_WIDTH = 640;
static const int SCREEN_HEIGHT = 480;

struct Game {
    struct Player player;
    struct Enemy enemy;
    struct Map map;
    
    Texture2D playerTexture;
    Texture2D enemyTexture;
    Texture2D starTexture;
};

void game_init(struct Game *game);
void game_destroy(struct Game *game);
void game_poll_input(struct Game *game);
void game_update(struct Game *game);
void game_draw(struct Game *game);

#endif /* Game_hpp */
