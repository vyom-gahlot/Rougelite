// Declarations
#pragma once

#include<vector>
struct Item;

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

    void addWeapon(Item itemName);
    void removeWeapon(Item itemName);

    void addArmor(Item itemName);
    void removeArmor(Item itemName);

    void addFootwear(Item itemNamee);
    void removeFootwear(Item itemName);

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

    struct Inventory {

        int gold;
        std::vector<Item> weapons {};
        std::vector<Item> armor {};
        std::vector<Item> footwear {}; 

    };
    Inventory inventory;

    struct EquippedItems{
        Item equippedWeapon;
        Item equippedArmor;
        Item equippedFootwear;
    };
    EquippedItems equippedItems;

};