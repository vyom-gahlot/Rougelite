#pragma once

class Player;

class Enemy
{
public:
    Enemy(int hp, int atk, int def, int spd); 
    virtual ~Enemy() = default;
    virtual int ChooseAbility() =0; // used to choose ability , virtual function
    virtual void useAbility(Player& player, bool playerDodged, int& counter) = 0;
    void takeDamage(int damage);// used to deal damage to enemy
    int EnemyAttack(); // used for enemy attack
    void EnemyHeal(); // used to heal enemy
    void EnemyShield();
    int getSpeed();
    int getHealth();
    void resetDefense();
    int getMaxHealth();


protected:
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