

#include "Player.h"
#include "Enemy.h"
#include "EnemyType.h"
#include "Item.h"
#include "Game.h"

#include<iostream>
#include<random>


void GameStart(){

    char startGame;

    std::cout<<"Enter any key to start the  game \n";
    std::cin>>startGame;
}

void displayScreen(Player &player, Enemy &enemy){

     int playerHealth = player.getHealth();
     int enemyHealth = enemy.getHealth();


    std::cout<<"Player Health : "<< playerHealth<<"\n";
    std::cout<<"Enemy Health : "<<enemyHealth<<"\n";

}

void selectEnemySize(int &enemySize){
    std::cout<<"Enter no. of enemies you wish to fight";
    std::cin>> enemySize;
}

Enemy** generateEnemies(int enemySize){
    

    Enemy** entity = new Enemy*[enemySize];

    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> enemychoice(0,2);

    for(int i = 0; i<enemySize; ++i){
        int chosenEnemy = enemychoice(gen);

        Enemy* chosenEntity;

        if(chosenEnemy==0){
            chosenEntity = new Goblin(100, 9, 4, 6);
        }else if(chosenEnemy == 1){
            chosenEntity = new Orc(150, 14, 9, 4);
        }else{
            chosenEntity = new Skeleton(80, 9, 5, 9);
        }   

        entity[i] = chosenEntity; 
    }    

    return entity;
};

void GameRun(Player& player, Enemy* enemy)
{
    bool gameRunning = true;
    int counter = 0;

    while (gameRunning)
    {
        displayScreen(player, *enemy);

        int playerAbility = player.chooseAbility();
        bool playerDodged = false;
        bool playerAbilityUsed = false;

        // Player gets the first move
        if (player.getSpeed() >= enemy->getSpeed())
        {
            switch (playerAbility)
            {
                case 0:
                {
                    int damage = player.playerAttack();
                    enemy->takeDamage(damage);
                    playerAbilityUsed = true;

                    if (enemy->getHealth() <= 0)
                    {
                        std::cout
                            << "The creature crumples to the ground. "
                               "Its final breath fades into the silence.\n";

                        gameRunning = false;
                    }

                    break;
                }

                case 1:
                    playerDodged = player.playerDash();
                    playerAbilityUsed = true;
                    break;

                case 2:
                    player.playerHeal();
                    playerAbilityUsed = true;
                    break;

                case 3:
                    player.playerShield();
                    playerAbilityUsed = true;
                    break;
            }

            if (!gameRunning)
                break;

            enemy->useAbility(player, playerDodged, counter);

            if (player.getHealth() <= 0)
            {
                std::cout
                    << "Your strength abandons you. "
                       "The world fades into darkness as you collapse "
                       "beneath the enemy's final blow.\n";

                gameRunning = false;
            }
        }

        // Enemy gets the first move
        else
        {
            // Dash must happen before the enemy attacks
            if (playerAbility == 1)
            {
                playerDodged = player.playerDash();
                playerAbilityUsed = true;
            }

            enemy->useAbility(player, playerDodged, counter);

            if (player.getHealth() <= 0)
            {
                std::cout
                    << "Your strength abandons you. "
                       "The world fades into darkness as you collapse "
                       "beneath the enemy's final blow.\n";

                gameRunning = false;
                break;
            }

            // Player acts after the enemy
            if (!playerAbilityUsed)
            {
                switch (playerAbility)
                {
                    case 0:
                    {
                        int damage = player.playerAttack();
                        enemy->takeDamage(damage);

                        if (enemy->getHealth() <= 0)
                        {
                            std::cout
                                << "The creature crumples to the ground. "
                                   "Its final breath fades into the silence.\n";

                            gameRunning = false;
                        }

                        break;
                    }

                    case 2:
                        player.playerHeal();
                        break;

                    case 3:
                        player.playerShield();
                        break;
                }
            }
        }

        player.resetDefense();
        enemy->resetDefense();
    }
}

void ChoosePlayerItems(Item &weapon, Item &armor, Item &footwear){

    int choice;

    std::cout<<"\nChoose weapon to use\n1. Rusty Shortsword\n2. Iron Cleaver\n";
    std::cin>>choice;

    switch(choice){
        case 1: 
            weapon =  Rusty_Shortsword;
            break;
        case 2: 
            weapon = Iron_Cleaver;
            break;
        default:
            weapon = Rusty_Shortsword;
    }

    std::cout<<"\nChoose armor to use\n1. Leather Vest\n2. Iron Cuirass\n";
    std::cin>>choice;

    switch(choice){
        case 1: 
            armor =  Leather_Vest;
            break;
        case 2: 
            armor = Iron_Cuirass;
            break;
        default:
            armor = Leather_Vest;
    }

    std::cout<<"\nChoose footwear to use\n1. Worn Boots \n2. Iron-Toed Boots \n";
    std::cin>>choice;

    switch(choice){
        case 1: 
            footwear =  Worn_Boots;
            break;
        case 2: 
            footwear = IronToed_Boots;
            break;
        default:
            footwear = Worn_Boots;
    }


}