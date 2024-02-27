//
//  Sprite.cpp
//  Ninja Star
//
//  Created by Chris W on 2/20/24.
//

#include "../include/Sprite.hpp"
#include <stdio.h>
#include <stdlib.h>

Sprite *sprite_create(unsigned int x, unsigned int y, Texture2D *texture){
    struct Sprite *sprite = (struct Sprite*)malloc(sizeof(struct Sprite));
    
    sprite->position.x = x;
    sprite->position.y = y;
    sprite->texture = texture;
    
    sprite->origin = { texture->width / 2.0f, texture->height / 2.0f };
    
    //part of texture to be used for drawing (in this case the entire texture)
    sprite->srcrect = {0, 0, (float)sprite->texture->width, (float)sprite->texture->height};
    
    //1st param: position for texture/sprite to appear at
    //2nd param: texture size (scale if needed by multiplying)
    sprite->destrect = {
        (float)sprite->position.x, (float)sprite->position.y,
        (float)sprite->texture->width, (float)sprite->texture->height
    };
    
    return sprite;
}

Sprite *sprite_create(Texture2D *texture){
    struct Sprite *sprite = (struct Sprite*)malloc(sizeof(struct Sprite));
    
    sprite->position.x = 0;
    sprite->position.y = 0;
    sprite->texture = texture;
    
    sprite->origin = { texture->width / 2.0f, texture->height / 2.0f };
    
    //part of texture to be used for drawing (in this case the entire texture)
    sprite->srcrect = {0, 0, (float)sprite->texture->width, (float)sprite->texture->height};
    
    //1st param: position for texture/sprite to appear and it
    //2nd param: texture size (scale if needed by multiplying)
    sprite->destrect = {
        (float)sprite->position.x, (float)sprite->position.y,
        (float)sprite->texture->width, (float)sprite->texture->height
    };
    
    return sprite;
}

Sprite *sprite_create_from_sheet(unsigned int x, unsigned int y, Texture2D *sheet, float scale){
    struct Sprite *sprite = (struct Sprite*)malloc(sizeof(struct Sprite));
    
    sprite->position.x = x;
    sprite->position.y = y;
    sprite->texture = sheet;
    
    sprite->texture->width *= scale;
    sprite->texture->height *= scale;
    
    //part of texture to be used for drawing (in this case the entire texture)
    sprite->srcrect = {0, 0, (float)sprite->texture->width / 3.0f, (float)sprite->texture->height};
    
    sprite->origin = { sprite->srcrect.width / 2.0f, sprite->srcrect.height / 2.0f };
    
    //1st param: position for texture/sprite to appear and it
    //2nd param: texture size (scale if needed by multiplying)
    sprite->destrect = {
        (float)sprite->position.x, (float)sprite->position.y,
        (float)sprite->texture->width / 3.0f, (float)sprite->texture->height
    };
    
    return sprite;
}

void sprite_destroy(struct Sprite *sprite){
    if(sprite != NULL)
        free(sprite);
}

void sprite_scale(struct Sprite *sprite, float scale){
    sprite->scale = scale;
    
    sprite->texture->width *= scale;
    sprite->texture->height *= scale;
    
    //update origin and src rect after scaling texture
    sprite->origin = { sprite->texture->width / 2.0f, sprite->texture->height / 2.0f };
    
    //part of texture to be used for drawing (in this case the entire texture)
    sprite->srcrect = {0, 0, (float)sprite->texture->width, (float)sprite->texture->height};
    
    //1st param: position for texture/sprite to appear and it
    //2nd param: texture size (scale if needed by multiplying)
    sprite->destrect = {
        (float)sprite->position.x, (float)sprite->position.y,
        (float)sprite->texture->width, (float)sprite->texture->height
    };
}

void sprite_update(struct Sprite *sprite){
    sprite->destrect.x = sprite->position.x;
    sprite->destrect.y = sprite->position.y;
}

Vector2 sprite_get_position(struct Sprite *sprite){
    Vector2 position = { sprite->destrect.x, sprite->destrect.y};
    return position;
}

Size sprite_get_size(struct Sprite *sprite){
    struct Size s;
    s.width = sprite->destrect.width;
    s.height = sprite->destrect.height;
    
    return s;
}

bool sprite_detect_collision(struct Sprite *s1, struct Sprite *s2){
    Vector2 s1Pos = sprite_get_position(s1);
    Vector2 s2Pos = sprite_get_position(s2);
    
    Size s1Size = sprite_get_size(s1);
    Size s2Size = sprite_get_size(s2);
    
    if(s1Pos.x + s1Size.width >= s2Pos.x &&
       s2Pos.x + s2Size.width >= s1Pos.x &&
       s1Pos.y + s1Size.height >= s2Pos.y &&
       s2Pos.y + s2Size.height >= s1Pos.y){
        return true;
    }
    return false;
}
