#include "Enemy.h"

#include<iostream>
#include<random>


Enemy::Enemy(){
    health = 100;
    attack = 5;
    defense = 9;
    speed = 4;
};

void Enemy::takedamage(int damage){
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

    std::cout<<"The enemy bares its teeth and lunges. Its strike tears through the air as you brace for impact.";
    return attack + variation(gen);
};

void Enemy::EnemyHeal(){
    if(health == 100){
        EnemyAttack();
    }else if(health < 100 && health > 80){
        health = TOTAL_HEALTH;
        std::cout<<"Dark energy courses through the creature's wounds, knitting flesh back together before your eyes.";
    } else{
        health += 20;
        std::cout<<"Dark energy courses through the creature's wounds, knitting flesh back together before your eyes.";
    }
};

void Enemy::EnemyShield(){
    defense = 2*defense;
    std::cout<<"The creature lowers its stance. Its body hardens as it prepares to weather your assault.";
};