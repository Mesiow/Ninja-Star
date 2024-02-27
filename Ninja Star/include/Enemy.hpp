//
//  Enemy.hpp
//  Ninja Star
//
//  Created by Chris W on 2/19/24.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include <raylib.h>

struct Enemy {
    struct Sprite *sprite;
};

void enemy_init(struct Enemy *enemy, Texture2D *texture, Vector2 position);
void enemy_destroy(struct Enemy *enemy);

void enemy_update(struct Enemy *enemy);
void enemy_draw(struct Enemy *enemy);

Rectangle enemy_get_rect(struct Enemy *enemy);

#endif /* Enemy_hpp */
