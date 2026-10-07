// Declarations
#pragma once

#include<vector>
#include "Item.h"


class Player
{
public:
    Player(int hp, int atk, int spd, int def, Item weapon, Item armor, Item footwear); // player constructor
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

    void equipWeapon(Item itemName);
    void unequipWeapon();

    void equipArmor(Item itemName);
    void unequipArmor();

    void equipFootwear(Item itemName);
    void unequipFootwear();
    void addGold(int amount);

private:
    const int base_health;
    int health;
    int TOTAL_HEALTH;

    const int base_attack;
    int attack;
    int TOTAL_ATTACK;

    const int base_speed;
    int speed;
    int TOTAL_SPEED;

    const int base_defense;
    int defense;
    int TOTAL_DEFENSE;
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
        Item equippedWeapon {};
        Item equippedArmor {};
        Item equippedFootwear {};
    };
    EquippedItems equippedItems;

};