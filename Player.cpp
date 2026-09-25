// Implementation
#include "Player.h"
#include "Enemy.h"
#include "Game.h"

#include <iostream>
#include <random>

Player::Player(){

    health = 100;
    attack = 10;
    speed = 8;
    defense = 8;
    BASE_DEFENSE = defense;
    TOTAL_HEALTH = health;
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
    defense = BASE_DEFENSE;
};

 