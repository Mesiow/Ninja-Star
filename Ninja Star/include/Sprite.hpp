//
//  Sprite.hpp
//  Ninja Star
//
//  Created by Chris W on 2/20/24.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include <raylib.h>

struct Size{
    int width;
    int height;
};

struct Sprite {
    Vector2 position;
    Vector2 origin = {0, 0};
    Texture2D *texture;
    Rectangle srcrect;
    Rectangle destrect;
    
    float rotation;
    float scale = 1.0f;
};

Sprite *sprite_create(unsigned int x, unsigned int y, Texture2D *texture);
Sprite *sprite_create(Texture2D *texture); //create sprite without initial position
Sprite *sprite_create_from_sheet(unsigned int x, unsigned int y, Texture2D *sheet, float scale);

void sprite_destroy(struct Sprite *sprite);

void sprite_scale(struct Sprite *sprite, float scale);
//update position rect of sprite with position vector
void sprite_update(struct Sprite *sprite);

Vector2 sprite_get_position(struct Sprite *sprite);

bool sprite_detect_collision(struct Sprite *s1, struct Sprite *s2);


#endif /* Sprite_hpp */
