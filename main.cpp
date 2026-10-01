#include "Player.h"
#include "Enemy.h"
#include "Game.h"
#include "EnemyType.h"

#include <iostream>
#include <vector>


int main(){

    GameStart();
    Player player {100, 8, 8, 8};
    int enemySize = 0;
    selectEnemySize(enemySize);
    Enemy** entity = generateEnemies(enemySize);

    int count = 0;
    bool PlayerAlive = true;

    while((count < enemySize) && (PlayerAlive)){
    GameRun(player, entity[count]);
    PlayerAlive = player.isPlayerAlive();

    delete entity[count];
    entity[count] = nullptr;
    count++;
    }

    for (int i = count; i < enemySize; ++i)
    {
        delete entity[i];
        entity[i] = nullptr;
    }

    delete[] entity;

    return 0;
}