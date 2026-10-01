#include "Enemy.h"
#include "EnemyType.h"
#include "Player.h"
#include <iostream>
#include <random>

// Goblin

Goblin::Goblin(int hp, int atk, int def, int spd)
    : Enemy(hp, atk, def, spd)
{
}

int Goblin::ChooseAbility()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> generateAbilityChoice(0, 3);
    int chosenAbility = generateAbilityChoice(gen);

    switch (chosenAbility)
    {
        case 0:
            return (int)Ability::Scream;

        default:
            return (int)Ability::Stab;
    }
}

void Goblin::useAbility(Player& player, bool playerDodged, int& counter)
{
    int chosenAbility = ChooseAbility();

    switch (chosenAbility)
    {
        case (int)Ability::Stab:
        {
            int damage = Stab(player);

            if (playerDodged)
                damage = 0;

            player.takeDamage(damage);
            break;
        }

        case (int)Ability::Scream:
            Scream(counter, player);
            break;
    }
}

int Goblin::Stab(Player& player)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    int playerSpeed = player.getSpeed();

    std::uniform_int_distribution<int> variation(0, playerSpeed);

    std::cout
        << "The goblin grips its tiny, battered blade with both hands and "
           "stumbles toward you. With a vacant grin, it jabs wildly at your "
           "chest, apparently delighted by its own brilliant idea.";

    int returnedDamage = attack - variation(gen);

    if (returnedDamage < 0)
        returnedDamage = 0;

    return returnedDamage;
}

void Goblin::Scream(int& counter, Player& player)
{
    counter = 3;

    std::cout
        << "The goblin bares its crooked teeth and lets out a shrill, "
           "incomprehensible screech. Whatever thought was behind those "
           "beady eyes, it clearly wasn't a complicated one.";

    int newSpeed = player.getSpeed() / 2;
    player.modifySpeed(newSpeed);
}


// Orc

Orc::Orc(int hp, int atk, int def, int spd)
    : Enemy(hp, atk, def, spd)
{
}

int Orc::ChooseAbility()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> generateAbilityChoice(0, 2);
    int chosenAbility = generateAbilityChoice(gen);

    switch (chosenAbility)
    {
        case 0:
            return (int)Ability::Crush;

        default:
            return (int)Ability::Bash;
    }
}

void Orc::useAbility(Player& player, bool playerDodged, int& counter)
{
    int chosenAbility = ChooseAbility();

    switch (chosenAbility)
    {
        case (int)Ability::Crush:
        {
            int damage = Crush();

            if (playerDodged)
                damage = 0;

            player.takeDamage(damage);
            break;
        }

        case (int)Ability::Bash:
        {
            int damage = Bash(player);

            if (playerDodged)
                damage = 0;

            player.takeDamage(damage);
            break;
        }
    }
}

int Orc::Crush()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> generateDamageVariation(0, 10);

    std::cout
        << "The orc raises its weapon high above its head, muscles straining "
           "beneath its rough skin. With a furious bellow, it brings the blow "
           "crashing down with enough force to make the ground tremble "
           "beneath your feet.";

    return attack + generateDamageVariation(gen);
}

int Orc::Bash(Player& player)
{
    int defenseEffect = player.getDefense() * 1.2;
    int damageDealt = attack - defenseEffect;

    std::cout
        << "The orc steps forward and swings with a brutal sideways arc. "
           "The blow comes faster than something that large should be "
           "capable of, forcing you to brace yourself as its weapon crashes "
           "into your defenses.";

    if (damageDealt < 0)
        return 0;

    return damageDealt;
}


// Skeleton

Skeleton::Skeleton(int hp, int atk, int def, int spd)
    : Enemy(hp, atk, def, spd)
{
}

int Skeleton::ChooseAbility()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> generateAbilityChoice(0, 3);
    int chosenAbility = generateAbilityChoice(gen);

    float healthPercent = (float)health / (float)TOTAL_HEALTH;

    if (healthPercent < 0.5)
    {
        switch (chosenAbility)
        {
            case 0:
            case 1:
                return (int)Ability::Splinter;

            default:
                return (int)Ability::Reassemble;
        }
    }

    switch (chosenAbility)
    {
        case 0:
            return (int)Ability::Reassemble;

        default:
            return (int)Ability::Splinter;
    }
}

void Skeleton::useAbility(Player& player, bool playerDodged, int& counter)
{
    int chosenAbility = ChooseAbility();

    switch (chosenAbility)
    {
        case (int)Ability::Splinter:
        {
            int damage = Splinter(player);

            if (playerDodged)
                damage = 0;

            player.takeDamage(damage);
            break;
        }

        case (int)Ability::Reassemble:
            Reassemble();
            break;
    }
}

int Skeleton::Splinter(Player& player)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> boneCount(3, 4);
    std::uniform_int_distribution<int> variation(0, 3);

    int bones = boneCount(gen);
    int totalDamage = 0;

    for (int i = 0; i < bones; ++i)
    {
        totalDamage += attack + variation(gen);
        health -= (3 + variation(gen));
    }

    totalDamage -= player.getDefense();

    std::cout
        << "The skeleton suddenly twists its body and tears several bones "
           "free with a sickening crack. One after another, it hurls them "
           "toward you. The jagged pieces whistle through the air before the "
           "creature staggers backward, its own body noticeably less complete.";

    if (totalDamage < 0)
        return 0;

    return totalDamage;
}

void Skeleton::Reassemble()
{
    std::cout
        << "The scattered bones around the skeleton begin to twitch. One by "
           "one, they drag themselves across the ground and snap back into "
           "place until the creature stands whole again, its empty eye "
           "sockets fixed upon you.";

    health += 25;

    if (health > TOTAL_HEALTH)
        health = TOTAL_HEALTH;
}