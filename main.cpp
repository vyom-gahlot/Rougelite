#include <iostream>

#include "Player.h"
#include "Enemy.h"
#include "Game.h"


int main(){

    GameStart();
    Player player;
    Enemy enemy {120, 12, 10,  9};
    GameRun(player, enemy);
    

    return 0;
}