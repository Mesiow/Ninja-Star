//
//  Player.cpp
//  Ninja Star
//
//  Created by Chris W on 2/15/24.
//

#include "../include/Player.hpp"
#include "../include/Star.hpp"
#include "../include/Sprite.hpp"

void player_init(struct Player *player, Texture2D *texture, Texture2D *starTexture, Vector2 position){
    
    player->sprite = sprite_create_from_sheet(position.x, position.y, texture, 2.0f);
    
    star_init(&player->star, starTexture);
}

void player_destroy(struct Player *player){
    star_destroy(&player->star);
    sprite_destroy(player->sprite);
}

void player_animate(struct Player *player){
    player->animating = true;
    player->frameCounter++;
    
    int frameSpeed = 12;
    if(player->frameCounter >= (60/frameSpeed)){
        player->frameCounter = 0;
        player->currentFrame++;
        
        if(player->currentFrame > 3)
            player->currentFrame = 0;
        
        player->sprite->srcrect.x = (float)player->currentFrame * (float)player->sprite->texture->width / 3.0f;
        
        if(player->currentFrame == 0) player->animating = false; //play animation once
    }
}

void player_update_rotation(struct Player *player, Vector2 mousepos){
    //calc direction vector and angle for rotation
    Vector2 pos = {player->sprite->position.x, player->sprite->position.y};
    Vector2 dir = {mousepos.x - pos.x, mousepos.y - pos.y};
    double angle = atan2(dir.y, dir.x) * RAD2DEG;
    
    player->sprite->rotation = angle;
}

void player_check_input(struct Player *player){
    if(IsKeyPressed(KEY_X)){
        //spawn ninja star if one is not already active
        if(!player->star.active){
            player->animating = true;
            star_spawn(&player->star, player->sprite->position, GetMousePosition());
        }
    }
}

void player_update(struct Player *player, Vector2 mousepos){
    sprite_update(player->sprite);
    
    player_update_rotation(player, mousepos);
    
    star_update(&player->star);
}

void player_draw(struct Player *player){
    struct Sprite *s = player->sprite;
    
    if(player->animating){
        player_animate(player);
        DrawTexturePro(*s->texture, s->srcrect, s->destrect, s->origin, s->rotation, WHITE);
        //xplayer->animating = false;
    }else{
        DrawTexturePro(*s->texture, s->srcrect, s->destrect, s->origin, s->rotation, WHITE);
    }
    
    star_draw(&player->star);
}

Rectangle player_get_star_rect(struct Player *player){
    return player->star.destrect;
}
