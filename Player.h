// Declarations

#pragma once


class Player
{
public:
    Player(); // player constructor
    int chooseAbility(); // choose ability to use
    void useAbility(int chosenAbility);// use chosen ability
    void takeDamage(int damage); // take damage from enemies
    int playerAttack(); // use attack
    bool playerDash();// use to dash and try to dodge attack
    void playerHeal();// to heal duh
    void playerShield();// double defense for 1 turn
    int getSpeed();// get player speed
    int getHealth();
    void resetDefense();

private:
    int health;
    int TOTAL_HEALTH;
    int attack;
    int speed;
    int defense;
    int  BASE_DEFENSE;
    enum class Ability{
        Attack,
        Dash,
        Heal,
        Shield
    };
    bool dodged = false;
};