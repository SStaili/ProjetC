#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Player //Sofiane Staili
{
	char name[80];

	int currentHP;
	int maxHP;
	int experience;
	int level;
	int currentMana; //Ajout Chloe Merck Sofiane Staili
	int maxMana;    //Ajout Chloe Merck Sofiane Staili
	int ManaCost;   //Ajout Chloe Merck Sofiane Staili

	int X, Y;

	double chance;
	double baseDamage;

    int BouleDeFeu;        // Ajout Chloe Merck
    int Electrocution;      // Ajout Chloe Merck
    int LancerDePierre;     // Ajout Chloe Merck
    int Tornade;            // Ajout Chloe Merck

    int potion;             // Ajout Chloe Merck
    int mana;               // Ajout Chloe Merck
    int Or;                 // Ajout Chloe Merck

} Player;






void initialize(Player*); //Sofiane Staili
int  load(Player*); //Sofiane Staili
void save(Player); //Sofiane Staili

void move(Player*, int, int);   //Sofiane Staili

void enemyEncounter(Player*);   //Sofiane Staili
void fight(Player*, Player*);   //Sofiane Staili


void onFightWin(Player*, Player); //Sofiane Staili
void levelUp(Player*);      //Sofiane Staili
int  canLevelUp(Player*);       //Sofiane Staili

void printStats(Player); //Sofiane Staili

int  isDead(Player);    //Sofiane Staili

void applyDamage(Player*, double);  //Sofiane Staili
void attaque(Player*,Player*);      //Sofiane Staili

void inventaireEncounter(Player* player);   //Chloe Merck
void AjoutObj(Player*);     //Chloe Merck

void Boss(Player*);     //Chloe Merck
Player createBoss(Player,double); //Chloe Merck



Player createNPC(Player, double); //Sofiane Staili
Player createNPCS(Player, double); //Chloe Merck



#endif
