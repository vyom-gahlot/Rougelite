#pragma once

class Enemy
{
public:
    Enemy(); 
    int ChooseAbility(); // used to choose ability
    void useAbility(int chosenAbility);// used to use chosen Ability
    void takedamage(int damage);// used to deal damage to enemy
    int EnemyAttack(); // used for enemy attack
    void EnemyHeal(); // used to heal enemy
    void EnemyShield();


private:
    int health;
    const int TOTAL_HEALTH = health;
    int attack;
    int speed;
    int defense;
    const int  BASE_DEFENSE = defense;
    enum class Ability{
        Attack,
        Heal,
        Shield
    };
    
};