#pragma once

#include "Enemy.h"
#include "Player.h"



class Goblin : public Enemy
{
    public:
        Goblin(int hp, int atk, int def, int spd);
        int ChooseAbility() override;
        int Stab(Player& player);
        void Scream(int& count, Player& player);
        void useAbility(Player& player, bool playerDodged, int& counter);

    private:
        enum class Ability{
        Stab,
        Scream
    };

};


class Orc : public Enemy
{
    public:
        Orc(int hp, int atk, int def, int spd);
        int ChooseAbility() override;
        int Crush();
        int Bash(Player& player);
        void useAbility(Player& player, bool playerDodged, int& counter);

    
    private:
        enum class Ability{
            Crush,
            Bash
        };
};

class Skeleton : public Enemy
{
    public:
        Skeleton(int hp, int atk, int def, int spd);
        int ChooseAbility() override;
        int Splinter(Player &player);
        void Reassemble();
        void useAbility(Player& player, bool playerDodged, int& counter);
    private:
        enum class Ability{
            Splinter,
            Reassemble
        };

};