// Declarations

#pragma once


class Player
{
public:
    Player(); // player constructor
    int chooseAbility(); // choose ability to use
    void useAbility(int chosenAbility);// use chosen ability
    void takeDamage(int damage); // take damage from enemies
    void getHealth(); //get player health
    int playerAttack(); // use attack
    void playerDash();// use to dash and try to dodge attack
    void playerHeal();// to heal duh
    void playerShield();// double defense for 1 turn


private:
    int health;
    const int TOTAL_HEALTH = health;
    int attack;
    int speed;
    int defense;
    const int  BASE_DEFENSE = defense;
    enum class Ability{
        Attack,
        Dash,
        Heal,
        Shield
    };
    bool dodged = false;
};