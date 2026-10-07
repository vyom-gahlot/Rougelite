
#pragma once

#include <vector>

void generateRoom(std::vector<std::vector<char>> &room);

void displayRoom(std::vector<std::vector<char>> room);

void insertPlayer(std::vector<std::vector<char>> &room);

void MovePlayer(
    std::vector<std::vector<char>> &room,
    int &posX,
    int &posY
);

void CalculatePosition(
    std::vector<std::vector<char>> room,
    int &posX,
    int &posY
);

