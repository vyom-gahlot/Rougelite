

#include "Player.h"
#include "Enemy.h"

#include "Game.h"

#include<iostream>


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

void GameRun(Player &player, Enemy &enemy){
    bool GameRunning = true;

    int enemyMaxHealth = enemy.getMaxHealth();

    std::cout<<"Enemy Max health : "<< enemyMaxHealth;

    while(GameRunning){

        displayScreen(player, enemy);

        int playerAbility = player.chooseAbility();
        int enemyAbility = enemy.ChooseAbility();
        bool playerDodged = false;

        if(player.getSpeed()>=enemy.getSpeed()){
             switch(playerAbility){
                case 0: {
                    int damage = player.playerAttack();
                    enemy.takeDamage(damage);
                    if(enemy.getHealth()<=0){
                        std::cout<<"The creature crumples to the ground. Its final breath fades into the silence. \n";
                        GameRunning = false;
                    }
                    break;}
                case 1:
                     playerDodged = player.playerDash();
                    break;
                case 2:
                    player.playerHeal();
                    break;
                case 3: 
                    player.playerShield();
            }
            switch(enemyAbility){
                case 0: {
                    int damage = enemy.EnemyAttack();
                    if(playerDodged){
                        player.takeDamage(0);
                    }else{
                    player.takeDamage(damage);
                    }
                    if(player.getHealth()<=0){
                        std::cout<<"Your strength abandons you. The world fades into darkness as you collapse beneath the enemy's final blow. \n";
                        GameRunning = false;
                    }}
                    break;
                case 1:
                    enemy.EnemyHeal();
                    break;
                case 2:
                    enemy.EnemyShield();
            }
        } else{
            switch(enemyAbility){
                case 0: {
                    if(playerAbility==1){
                        playerDodged = player.playerDash();
                    }
                    int damage = enemy.EnemyAttack();
                    if(playerDodged){
                        player.takeDamage(0);
                    }else{
                    player.takeDamage(damage);
                    }
                    if(player.getHealth()<=0){
                        std::cout<<"Your strength abandons you. The world fades into darkness as you collapse beneath the enemy's final blow. \n";
                        GameRunning = false;
                    }
                    break;}
                case 1:
                    enemy.EnemyHeal();
                    break;
                case 2:
                    enemy.EnemyShield();
            }   
            switch(playerAbility){
                case 0: {
                    int damage = player.playerAttack();
                    enemy.takeDamage(damage);
                    if(enemy.getHealth()<=0){
                        std::cout<<"The creature crumples to the ground. Its final breath fades into the silence. \n";
                        GameRunning = false;
                    }
                    break;}
                case 1:
                    player.playerDash();
                    break;
                case 2:
                    player.playerHeal();
                    break;
                case 3: 
                    player.playerShield();
            }
        }

        player.resetDefense();
        enemy.resetDefense();
    }
}