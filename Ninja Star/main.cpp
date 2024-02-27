//
//  main.cpp
//  Ninja Star
//
//  Created by Chris W on 2/15/24.
//
#include "include/Game.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ninja Star");

    SetTargetFPS(60);
    
    struct Game game;
    game_init(&game);
    
    Color color;
    color.r = 167;
    color.g = 83;
    color.b = 45;
    color.a = 1;
    
    while(!WindowShouldClose()){
        //poll input
        game_poll_input(&game);
        
        //logic
        game_update(&game);
        
        
        //Rendering
        BeginDrawing();

        ClearBackground(color);
    
        game_draw(&game);
        
        EndDrawing();
    }
    
    game_destroy(&game);
    CloseWindow();
    
    return 0;
}
