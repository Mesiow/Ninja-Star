//
//  Collision.hpp
//  Ninja Star
//
//  Created by Chris W on 2/22/24.
//

#ifndef Collision_hpp
#define Collision_hpp
#include <raylib.h>

bool collision_rect_intersect(Rectangle r1, Rectangle r2);
bool collision_rect_from_left(Rectangle oldRect, Rectangle currentRect, Rectangle tile);
bool collision_rect_from_right(Rectangle oldRect, Rectangle currentRect, Rectangle tile);
bool collision_rect_from_top(Rectangle oldRect, Rectangle currentRect, Rectangle tile);
bool collision_rect_from_bottom(Rectangle oldRect, Rectangle currentRect, Rectangle tile);

#endif /* Collision_hpp */
