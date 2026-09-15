#pragma once

class Enemy
{
public:
    Enemy(); 


private:
    int health;
    const int TOTAL_HEALTH = health;
    int attack;
    int speed;
    int defense;
    enum class Ability{
        Attack,
        Heal,
        Shield
    };
    
};