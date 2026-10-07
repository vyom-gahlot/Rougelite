#include "Room.h"

#include <iostream>


void generateRoom(std::vector<std::vector<char>> &room){

    room = {
        {'#','#','#','#',' ','#','#','#','#'},
        {'#',' ',' ',' ',' ',' ',' ','#','#'},
        {'#',' ',' ',' ',' ','#',' ',' ','#'},
        {'#',' ',' ','#',' ',' ',' ',' ','#'},
        {'#','#','#','#',' ','#','#',' ','#'},
        {'#',' ','2',' ',' ',' ','#',' ','#'},
        {'#',' ',' ','#','#',' ','3',' ','#'},
        {'#',' ',' ','#',' ',' ',' ',' ','#'},
        {'#',' ',' ','#',' ','#','#','C','#'},
        {'#','#',' ','#','#','#','#','#','#'},
    };

}


void displayRoom(std::vector<std::vector<char>> room){

    for(int i = 0; i < room.size(); i++){

        for(int j = 0; j < room[i].size(); j++){

            std::cout << room[i][j] << room[i][j];

        }

        std::cout << "\n";
    }
}


void insertPlayer(std::vector<std::vector<char>> &room){

    for(int i = 0; i < room[0].size(); i++){

        if(room[0][i] == ' '){

            room[0][i] = 'P';

            break;
        }
    }
}


void MovePlayer(
    std::vector<std::vector<char>> &room,
    int &posX,
    int &posY
){

    char playerMove;

    std::cout << "\nUse WASD to move around the room\n";
    std::cin >> playerMove;


    int newX = posX;
    int newY = posY;


    switch(playerMove){

        case 'w':
            newX--;
            break;

        case 's':
            newX++;
            break;

        case 'a':
            newY--;
            break;

        case 'd':
            newY++;
            break;

        default:
            std::cout << "Invalid move\n";
            return;
    }


    // Check if the new position is outside the room
    if(newX < 0 || newX >= room.size() ||
       newY < 0 || newY >= room[newX].size()){

        std::cout << "Invalid move\n";
        return;
    }


    // Check if the player is trying to move into a wall
    if(room[newX][newY] == '#'){

        std::cout << "You cannot move there!\n";
        return;
    }


    // Remove player from old position
    room[posX][posY] = ' ';


    // Update player's position
    posX = newX;
    posY = newY;
}


void CalculatePosition(
    std::vector<std::vector<char>> room,
    int &posX,
    int &posY
){

    for(int i = 0; i < room.size(); i++){

        for(int j = 0; j < room[i].size(); j++){

            if(room[i][j] == 'P'){

                posX = i;
                posY = j;

                return;
            }
        }
    }


    std::cout << "\nPlayer not found\n";
}

