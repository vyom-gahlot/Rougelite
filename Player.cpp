// Implementation
#include "Player.h"
#include "Enemy.h"
#include "Game.h"
#include "Item.h"

#include <iostream>
#include <random>
#include <vector>

Player::Player(int hp, int atk, int spd, int def, Item weapon, Item armor, Item footwear)
    :
    base_health(hp),
    base_attack(atk),
    base_speed(spd),
    base_defense(def),
    health(base_health + weapon.hp + armor.hp + footwear.hp),   
    attack(base_attack + weapon.attack + armor.attack + footwear.attack),
    speed(base_speed + weapon.speed + armor.speed + footwear.speed),
    defense(base_defense + weapon.defense + armor.defense + footwear.defense),
    TOTAL_DEFENSE(base_defense + weapon.defense + armor.defense + footwear.defense),
    TOTAL_HEALTH(base_health + weapon.hp + armor.hp + footwear.hp),
    TOTAL_SPEED(base_speed + weapon.speed + armor.speed + footwear.speed),
    TOTAL_ATTACK(base_attack + weapon.attack + armor.attack + footwear.attack)
{    
};


void Player::takeDamage(int damage){

    health -= damage;
};

int Player::playerAttack(){

    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> variation(0, speed);

    std::cout<<"You tighten your grip and strike with all your might. Your attack tears through the enemy's defenses.\n";
    return attack + variation(gen);
};

bool Player::playerDash(){

    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dodgeChance(0,9);

    int dodgeRoll = dodgeChance(gen);

    if(dodgeRoll < 3){
        std::cout<<"The enemy lunges. You vanish from its path at the last moment, relying on speed and instinct to evade the blow.\n";
        return true;
    } else{
        std::cout<<"You move too late the attack finds its mark.\n";
        return false;
    }
};

void Player::playerHeal(){
    if(health == 100){
        std::cout<<"You invoke the power of the gods... only to discover you have nothing left to heal.\n";
    }else if(health < 100 && health > 80){
        health = TOTAL_HEALTH;
        std::cout<<"You close your eyes and gather what strength remains within you. Your wounds begin to mend as your vitality slowly returns.\n";
    } else{
        health += 20;
        std::cout<<"You close your eyes and gather what strength remains within you. Your wounds begin to mend as your vitality slowly returns. \n";
    }
}
void Player::playerShield(){
    defense = 2*defense;
    std::cout<<"You steady yourself and raise your guard. Your defenses harden as you prepare to withstand the coming assault. \n";
};

int Player::chooseAbility(){

    int playerChoice;
    std::cout<<"Choose Ability >> \n 1. Attack \n 2. Dash \n 3. Heal \n 4. Shield \n";
    std::cin>> playerChoice;

    switch(playerChoice){
        case 1: return (int)Ability::Attack;
        case 2: return (int)Ability::Dash;
        case 3: return (int)Ability::Heal;
        case 4: return (int)Ability::Shield;
        default:
            std::cout<<"Choose Valid options only (Press ctrl+C to quit)\n";
             return chooseAbility();
    }

}

void Player::useAbility(int ChosenAbility){

    switch(ChosenAbility){
        case 0: 
            Player::playerAttack();
            break;
        case 1: 
            Player::playerDash();
            break;
        case 2: 
                Player::playerHeal(); 
                break;
        case 3: 
            Player::playerShield();
            break;
    }
};

int Player::getSpeed(){

    return speed;
};

int Player::getHealth(){
    return health;
};

void Player::resetDefense(){
    defense = TOTAL_DEFENSE;
};

void Player::modifySpeed(int val){

    speed = val;
}

int Player::getDefense(){
    return defense;
}

bool Player::isPlayerAlive(){
    if(health == 0){
        return false;
    }

    return true;
}

void Player::addWeapon(Item itemName){
    if(itemName.type == "weapon"){
        inventory.weapons.push_back(itemName);
    } else{
        std::cout<<"Invalid weapon";
        return;
    }

    std::cout<<"Added Weapon to inventory";
}

void Player::removeWeapon(Item itemName){
    if(itemName.type == "weapon"){
        for(int i = 0; i < inventory.weapons.size(); i++ ){
            if(inventory.weapons[i].name == itemName.name){
                inventory.weapons.erase(inventory.weapons.begin() + i);
                break;
            }

        }
    }else{
        std::cout<<"Invalid weapon";
        return;
    }

}

void Player::addArmor(Item itemName){
    if(itemName.type == "armor"){
        inventory.armor.push_back(itemName);
    } else{
        std::cout<<"Invalid Armor";
        return;
    }

    std::cout<<"Added Armor to inventory";
}

void Player::removeArmor(Item itemName){
    if(itemName.type == "armor"){
        for(int i = 0; i < inventory.armor.size(); i++ ){
            if(inventory.armor[i].name == itemName.name){
                inventory.armor.erase(inventory.armor.begin() + i);
                break;
            }

        }
    }else{
        std::cout<<"Invalid Armor";
        return;
    }

}

void Player::addFootwear(Item itemName){
    if(itemName.type == "footwear"){
        inventory.footwear.push_back(itemName);
    } else{
        std::cout<<"Invalid Footwear";
        return;
    }

    std::cout<<"Added Footwear to inventory";
}

void Player::removeFootwear(Item itemName){
    if(itemName.type == "footwear"){
        for(int i = 0; i < inventory.footwear.size(); i++ ){
            if(inventory.footwear[i].name == itemName.name){
                inventory.footwear.erase(inventory.footwear.begin() + i);
                break;
            }

        }
    }else{
        std::cout<<"Invalid Footwear";
        return;
    }
}

void Player::equipWeapon(Item itemName){

    for(int i = 0; i < inventory.weapons.size(); i++){
        if(inventory.weapons[i].name == itemName.name){
        equippedItems.equippedWeapon = itemName;
        return;
        }
    }
    std::cout<<"\nWeapon does not exist in Inventory\n";

}

void Player::equipArmor(Item itemName){
    
    for(int i = 0; i < inventory.armor.size(); i++){
        if(inventory.armor[i].name == itemName.name){
        equippedItems.equippedArmor = itemName;
        return;
        }
    }
    std::cout<<"\nArmor does not exist in Inventory\n";
}

void Player::equipFootwear(Item itemName){
    
    for(int i = 0; i < inventory.footwear.size(); i++){
        if(inventory.footwear[i].name == itemName.name){
        equippedItems.equippedFootwear = itemName;
        return;
        }
    }
    std::cout<<"\nFootwear does not exist in Inventory\n";
}

void Player::unequipWeapon(){
    equippedItems.equippedWeapon = WeaponNone;
}

void Player::unequipArmor(){
    equippedItems.equippedArmor = ArmorNone;
}

void Player::unequipFootwear(){
    equippedItems.equippedFootwear = FootwearNone;
}