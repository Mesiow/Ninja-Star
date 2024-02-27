//
//  Game.cpp
//  Ninja Star
//
//  Created by Chris W on 2/17/24.
//

#include "Game.hpp"
#include "Sprite.hpp"

void game_load_textures(struct Game *game){
    game->playerTexture = LoadTexture("ninja_good-sheet.png");
    game->enemyTexture = LoadTexture("ninja_bad.png");
    game->starTexture = LoadTexture("shuriken.png");
}

void game_init(struct Game *game){
    game_load_textures(game);
    
    map_init(&game->map);
    map_load_textures(&game->map);
    
    player_init(&game->player, &game->playerTexture, &game->starTexture, Vector2{100.0f, 100.0f});
    enemy_init(&game->enemy, &game->enemyTexture,
               Vector2{SCREEN_WIDTH - 100.0f, SCREEN_HEIGHT - 300.0f});
}

void game_destroy(struct Game *game){
    map_unload(&game->map);
    player_destroy(&game->player);
    enemy_destroy(&game->enemy);
    
    UnloadTexture(game->playerTexture);
    UnloadTexture(game->enemyTexture);
}

void game_poll_input(struct Game *game){
    player_check_input(&game->player);
}

void game_check_collision(struct Game *game){
    //Map collision with player weapon
    if(map_check_collision(&game->map, player_get_star_rect(&game->player))){
        //printf("map collision\n");
        //get collided tile position
        
        star_bounce(&game->player.star, map_get_collided_tile(&game->map));
    }
    
    //Player weapon collision with enemy
    if(collision_rect_intersect(player_get_star_rect(&game->player), enemy_get_rect(&game->enemy))){
        printf("COLLISION\n");
    }
}

void game_update(struct Game *game){
    game_check_collision(game);
    
    player_update(&game->player, GetMousePosition());
    enemy_update(&game->enemy);
}

void game_draw(struct Game *game){
    map_draw(&game->map);
    player_draw(&game->player);
    enemy_draw(&game->enemy);
    
    //debug draw
    /*
    DrawRectanglePro(game->enemy.sprite->destrect, game->enemy.sprite->origin, 0, RED);*/
    DrawRectanglePro(game->player.star.destrect, game->player.star.origin, 0, BLUE);
     
}
