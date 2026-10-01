// Declarations

#pragma once


class Player
{
public:
    Player(int hp, int atk, int spd, int def); // player constructor
    int chooseAbility(); // choose ability to use
    void useAbility(int chosenAbility);// use chosen ability
    void takeDamage(int damage); // take damage from enemies
    int playerAttack(); // use attack
    bool playerDash();// use to dash and try to dodge attack
    void playerHeal();// to heal duh
    void playerShield();// double defense for 1 turn
    int getSpeed();// get player speed
    void modifySpeed(int val);
    int getHealth();
    void resetDefense();
    int getDefense();
    bool isPlayerAlive();

private:
    int health;
    const int TOTAL_HEALTH;
    int attack;
    int speed;
    const int BASE_SPEED;
    int defense;
    const int  BASE_DEFENSE;
    enum class Ability{
        Attack,
        Dash,
        Heal,
        Shield
    };
    bool dodged = false;
};