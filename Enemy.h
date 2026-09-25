#pragma once

class Enemy
{
public:
    Enemy(int hp, int atk, int def, int spd); 
    int ChooseAbility(); // used to choose ability
    void useAbility(int chosenAbility);// used to use chosen Ability
    void takeDamage(int damage);// used to deal damage to enemy
    int EnemyAttack(); // used for enemy attack
    void EnemyHeal(); // used to heal enemy
    void EnemyShield();
    int getSpeed();
    int getHealth();
    void resetDefense();
    int getMaxHealth();


private:
    int health;
    const int TOTAL_HEALTH;
    int attack;
    int speed;
    int defense;
    const int  BASE_DEFENSE;
    enum class Ability{
        Attack,
        Heal,
        Shield
    };
    
};