//
//  Collision.cpp
//  Ninja Star
//
//  Created by Chris W on 2/22/24.
//

#include "Collision.hpp"

bool collision_rect_intersect(Rectangle r1, Rectangle r2){
    if((r1.x < (r2.x + r2.width) && (r1.x + r1.width) > r2.x) &&
            (r1.y < (r2.y + r2.height) && (r1.y + r1.height) > r2.y))
        return true;
    
    return false;
}

bool collision_rect_from_left(Rectangle oldRect, Rectangle currentRect, Rectangle tile){
    return ((oldRect.x + oldRect.width) < tile.x) && ((currentRect.x + currentRect.width) >= tile.x);
}

bool collision_rect_from_right(Rectangle oldRect, Rectangle currentRect, Rectangle tile){
    return ((oldRect.x > (tile.x + tile.width)) && (currentRect.x < (tile.x + tile.width)));
}

bool collision_rect_from_top(Rectangle oldRect, Rectangle currentRect, Rectangle tile){
    return (((oldRect.y + oldRect.height) < tile.y) && ((currentRect.y + currentRect.height) >= tile.y));
}

bool collision_rect_from_bottom(Rectangle oldRect, Rectangle currentRect, Rectangle tile){
    return ((oldRect.y >= (tile.y + tile.height)) && (currentRect.y < (tile.y + tile.height)));
}
