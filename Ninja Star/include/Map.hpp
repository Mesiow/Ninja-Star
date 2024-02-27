//
//  Map.hpp
//  Ninja Star
//
//  Created by Chris W on 2/20/24.
//

#ifndef Map_hpp
#define Map_hpp

#include <raylib.h>
#include <iostream>
#include <string>

enum Rect{
    Top = 0,
    Bottom,
    Left,
    Right
};

struct CollidedRect{
    enum Rect rect;
    float normal; //-1 to 1 value for the side of the rect that was collided with
};

struct Map{
    std::wstring level;
    int tileWidth = 32;
    int tileHeight = 32;
    int levelWidth;
    int levelHeight;
    Rectangle collidedTile; //updated when there is a collision
    
    Texture2D wallTexture;
    Texture2D floorTexture;
};

void map_init(struct Map* map);
void map_load_textures(struct Map *map);
void map_unload(struct Map *map);
void map_draw(struct Map *map);

bool map_check_collision(struct Map *map, Rectangle rect); //aabb check against any rect
Vector2 map_get_collided_tile_pos(struct Map *map);
Rectangle map_get_collided_tile(struct Map *map);

#endif /* Map_hpp */
