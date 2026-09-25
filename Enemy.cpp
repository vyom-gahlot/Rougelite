#include "Enemy.h"
#include "Player.h"
#include "Game.h"

#include<iostream>
#include<random>


Enemy::Enemy(int hp, int atk, int def, int spd)
    : health(hp),
      TOTAL_HEALTH(hp),
      attack(atk),
      speed(spd),
      defense(def),
      BASE_DEFENSE(def)
{
}


void Enemy::takeDamage(int damage){
    health -= damage;
};

int Enemy::ChooseAbility(){

    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> generateAbilityChoice(0,2);    

    int ChosenAbility = generateAbilityChoice(gen);

    switch(ChosenAbility){
        case 0: return (int)Ability::Attack;
        case 1: return (int)Ability::Heal;
        case 2: return (int)Ability::Shield;

        default: return (int)Ability::Attack;
    }

};

void Enemy::useAbility(int chosenAbility){

    switch(chosenAbility){
        case 0: 
            EnemyAttack();
            break;
        case 1: 
            EnemyHeal();
            break;
        case 2: 
            EnemyShield();
            break;
    }
};

int Enemy::EnemyAttack(){
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> variation(0, speed);

    std::cout<<"The enemy bares its teeth and lunges. Its strike tears through the air as you brace for impact. \n";
    return attack + variation(gen);
};

void Enemy::EnemyHeal()
{
    if (health == TOTAL_HEALTH) {
        EnemyAttack();
        return;
    }

    health += 20;

    if (health > TOTAL_HEALTH) {
        health = TOTAL_HEALTH;
    }

    std::cout << "Dark energy courses through the creature's wounds, "
                 "knitting flesh back together before your eyes.\n";
}


void Enemy::EnemyShield(){
    defense = 2*defense;
    std::cout<<"The creature lowers its stance. Its body hardens as it prepares to weather your assault. \n";
};

int Enemy::getSpeed(){
    return speed;
};

int Enemy::getHealth(){
    return health;
};

void Enemy::resetDefense(){
    defense = BASE_DEFENSE;
}

int Enemy::getMaxHealth(){
    return TOTAL_HEALTH;
}