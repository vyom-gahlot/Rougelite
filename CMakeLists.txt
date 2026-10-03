cmake_minimum_required(VERSION 3.20)

project(Roguelite)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Roguelite
    main.cpp
    Game.cpp
    Player.cpp
    Enemy.cpp
    EnemyType.cpp
    Item.cpp
)