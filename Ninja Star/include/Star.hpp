//
//  Star.hpp
//  Ninja Star
//
//  Created by Chris W on 2/16/24.
//

#ifndef Star_hpp
#define Star_hpp

#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>

//Player's main weapon
//Has the ability to only bounce off surfaces once
struct Star {
    Vector2 position;
    Vector2 origin;
    Vector2 velocity;
    float speed;
    float rotation;
    
    Texture2D *texture;
    Rectangle srcrect;
    Rectangle destrect;
    Rectangle oldDestRect;
    bool active;
    bool bounced;
};

void star_init(struct Star *star, Texture2D *texture);
void star_spawn(struct Star *star, Vector2 pos, Vector2 dir);
void star_destroy(struct Star *star);
void star_bounce(struct Star *star, Rectangle tile);
void star_update(struct Star *star);
void star_draw(struct Star *star);


#endif /* Star_hpp */
