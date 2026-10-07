
#include "Player.h"
#include "Enemy.h"
#include "Game.h"
#include "EnemyType.h"
#include "Item.h"
#include "Room.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>


int main(){

    srand(time(0));

    GameStart();

    std::vector<std::vector<char>> room;

    int posX, posY;

    Item weapon, armor, footwear;

    ChoosePlayerItems(weapon, armor, footwear);

    Player player {100, 8, 8, 8, weapon, armor, footwear};


    // Generate the room
    generateRoom(room);

    // Place player at the start
    insertPlayer(room);

    // Find player's starting position
    CalculatePosition(room, posX, posY);

    displayRoom(room);


    bool PlayerAlive = true;
    bool gameWon = false;


    /*
        Player continues moving through the room.

        Empty space -> keep moving
        2           -> fight 2 enemies, then keep moving
        3           -> fight 3 enemies, then keep moving
        C           -> collect gold, then keep moving
        Bottom row  -> win
    */
    while(PlayerAlive && !gameWon){

        int oldX = posX;
        int oldY = posY;


        // Ask player to move
        MovePlayer(room, posX, posY);


        // Invalid movement
        if(oldX == posX && oldY == posY){

            displayRoom(room);

            continue;
        }


        // Store the tile the player moved onto
        char tile = room[posX][posY];


        /*
            ENCOUNTER: 2 ENEMIES
        */
        if(tile == '2'){

            std::cout << "\nYou encountered 2 enemies!\n";

            int enemySize = 2;

            Enemy** entity = generateEnemies(enemySize);


            for(int i = 0; i < enemySize && PlayerAlive; i++){

                GameRun(player, entity[i]);

                PlayerAlive = player.isPlayerAlive();

                delete entity[i];

                entity[i] = nullptr;
            }


            // Clean up any remaining enemies
            for(int i = 0; i < enemySize; i++){

                delete entity[i];

                entity[i] = nullptr;
            }

            delete[] entity;


            if(PlayerAlive){

                std::cout << "\nYou survived the encounter!\n";

                room[posX][posY] = 'P';
            }
            else{

                std::cout << "\nYou died.\n";

                break;
            }
        }


        /*
            ENCOUNTER: 3 ENEMIES
        */
        else if(tile == '3'){

            std::cout << "\nYou encountered 3 enemies!\n";

            int enemySize = 3;

            Enemy** entity = generateEnemies(enemySize);


            for(int i = 0; i < enemySize && PlayerAlive; i++){

                GameRun(player, entity[i]);

                PlayerAlive = player.isPlayerAlive();

                delete entity[i];

                entity[i] = nullptr;
            }


            // Clean up any remaining enemies
            for(int i = 0; i < enemySize; i++){

                delete entity[i];

                entity[i] = nullptr;
            }

            delete[] entity;


            if(PlayerAlive){

                std::cout << "\nYou survived the encounter!\n";

                room[posX][posY] = 'P';
            }
            else{

                std::cout << "\nYou died.\n";

                break;
            }
        }


        /*
            CHEST
        */
        else if(tile == 'C'){

            int gold = rand() % 51 + 50;

            std::cout << "\nYou found a chest!\n";

            std::cout << "You found "
                      << gold
                      << " gold!\n";


            player.addGold(gold);


            // Chest has been collected
            room[posX][posY] = 'P';
        }


        /*
            NORMAL FLOOR
        */
        else{

            room[posX][posY] = 'P';
        }


        /*
            END OF ROOM

            The bottom row is the exit.
        */
        if(posX == room.size() - 1){

            std::cout << "\nYou reached the end of the room!\n";
            std::cout << "You survived the dungeon!\n";
            std::cout << "VICTORY!\n";

            gameWon = true;
        }


        displayRoom(room);
    }


    if(!PlayerAlive){

        std::cout << "\nGAME OVER\n";
    }


    return 0;
}
