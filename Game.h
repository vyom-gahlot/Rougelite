#pragma once


void ChoosePlayerItems(Item &weapon, Item &armor, Item &footwear);
void GameStart();
void GameRun(Player &player, Enemy *enemy);
void selectEnemySize(int &enemySize);
Enemy** generateEnemies(int enemySize);
void displayScreen( Player &Player, Enemy &enemy);