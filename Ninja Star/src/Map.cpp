//
//  Map.cpp
//  Ninja Star
//
//  Created by Chris W on 2/20/24.
//

#include "Map.hpp"
#include "../include/Game.hpp"

void map_init(struct Map* map){
    map->levelWidth = 20;
    map->levelHeight = 15;
    
           map->level += L"WWWWWWWWWWWWWWWWWWWW";
           map->level += L"W............W.....W";
           map->level += L"W............W.....W";
           map->level += L"W............W.....W";
           map->level += L"W............W.....W";
           map->level += L"W............W.....W";
           map->level += L"W............W.....W";
           map->level += L"W............WW....W";
           map->level += L"W..................W";
           map->level += L"W..................W";
           map->level += L"W..................W";
           map->level += L"W..................W";
           map->level += L"W..................W";
           map->level += L"W..................W";
           map->level += L"WWWWWWWWWWWWWWWWWWWW";
                            
}

void map_load_textures(struct Map *map){
    map->wallTexture = LoadTexture("cobblestone.png");
    map->floorTexture = LoadTexture("wood.png");
}

void map_unload(struct Map *map){
    UnloadTexture(map->wallTexture);
    UnloadTexture(map->floorTexture);
}

wchar_t map_get_tile(struct Map *map, int x, int y){
    if (x >= 0 && x < map->levelWidth && y >= 0 && y < map->levelHeight)
        return map->level[y * map->levelWidth + x];
    else
        return L' ';
}

void map_draw(struct Map *map){
    for(int x = 0; x < map->levelWidth; x++){
        for(int y = 0; y < map->levelHeight; y++){
            wchar_t tileid = map_get_tile(map, x, y);
            switch(tileid){
                case L'.': //Floor tile
                    DrawTexture(map->floorTexture, x * map->tileWidth, y * map->tileHeight, WHITE);
                    break;
                case L'W': //Wall tile
                    DrawTexture(map->wallTexture, x * map->tileWidth, y * map->tileHeight, WHITE);
                    break;
                case L' ': //Error
                    
                    break;
            }
        }
    }
}

bool map_check_collision(struct Map *map, Rectangle rect) {
    for(int x = 0; x < map->levelWidth; x++){
        for(int y = 0; y < map->levelHeight; y++){
            wchar_t tileid = map_get_tile(map, x, y);
        
            if(tileid == L'W'){
                int xpos = x * map->tileWidth;
                int ypos = y * map->tileHeight;
                
                Rectangle tile_rect;
                tile_rect.width = map->tileWidth;
                tile_rect.height = map->tileHeight;
                tile_rect.x = xpos;
                tile_rect.y = ypos;
                
                if(collision_rect_intersect(tile_rect, rect)){
                    map->collidedTile = tile_rect;
                    return true;
                }
            }
        }
    }
    return false;
}

Vector2 map_get_collided_tile_pos(struct Map *map){
    return Vector2{ map->collidedTile.x, map->collidedTile.y };
}

Rectangle map_get_collided_tile(struct Map *map){
    return map->collidedTile;
}
