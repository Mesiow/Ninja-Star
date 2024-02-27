//
//  Star.cpp
//  Ninja Star
//
//  Created by Chris W on 2/16/24.
//
#include "../include/Star.hpp"
#include "../include/raylib/raymath.h"
#include "../include/Game.hpp"

void star_init(struct Star *star, Texture2D *texture){
    star->texture = texture;
    star->rotation = 0.0f;
    star->position.x = -100;
    star->position.y = -100;
    
    star->origin = {texture->width / 2.0f, texture->height / 2.0f};
    //part of texture to be used for drawing (in this case the entire texture)
    star->srcrect = {0, 0, (float)star->texture->width, (float)star->texture->height};
    
    star->destrect = {
        (float)star->position.x, (float)star->position.y,
        (float)star->texture->width, (float)star->texture->height
    };
    
    star->active = false;
    star->bounced = false;
    star->speed = 190.0f;
}

void star_spawn(struct Star *star, Vector2 pos, Vector2 dir){
    star->active = true;
    
    //spawn at position and calc velocity vector
    star->position = pos;

    //velocity direction vector
    star->velocity = {dir.x - star->position.x, dir.y - star->position.y };
    star->velocity = Vector2Normalize(star->velocity);
}

void star_destroy(struct Star *star){
    star->active = false;
    star->bounced = false;
}

void star_bounce(struct Star *star, Rectangle tile){
    Vector2 bouncevector = star->velocity;
    //lets check which way to reflect the star based on which side of the tile it collided with
    
    //Left
     if(collision_rect_from_left(star->oldDestRect, star->destrect, tile) || collision_rect_from_right(star->oldDestRect, star->destrect, tile)) {
         bouncevector.x = -bouncevector.x;
    }
    else if(collision_rect_from_top(star->oldDestRect, star->destrect, tile) || collision_rect_from_bottom(star->oldDestRect, star->destrect, tile)){
        bouncevector.y = -bouncevector.y;
    }
    
    star->velocity = bouncevector;
}

void star_update(struct Star *star){
    if(star->active){
        star->oldDestRect = star->destrect;
        
        //star velocity
        star->position.x += (star->velocity.x * star->speed) * GetFrameTime(); //dt
        star->position.y += (star->velocity.y * star->speed) * GetFrameTime(); //dt
        
        star->destrect.x = star->position.x;
        star->destrect.y = star->position.y;
        
        //Window bounds check
        /*if((star->position.x >= (SCREEN_WIDTH + star->texture->width) || (star->position.x <= 0 - star->texture->width) ||
           (star->position.y <= 0 - star->texture->height) || (star->position.y >= (SCREEN_HEIGHT + star->texture->height)))){
            //Star logic
            //star already bounced once, destroy it
            if(star->bounced){
                star_destroy(star);
            }
            else {
                star->bounced = true;
                star_bounce(star);
            }
        }*/
    }
}

void star_draw(struct Star *star){
    if(star->active){
        DrawTexturePro(*star->texture, star->srcrect, star->destrect, star->origin, star->rotation, WHITE);
    }
}
