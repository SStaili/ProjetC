#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

#define FILE_SIZE 10;
void printAbout();      //Sofiane Staili
void printHelp();      //Sofiane Staili
void playGame(Player);  //Sofiane Staili
void lower(char*);      //Sofiane Staili
void pause(int);        //Sofiane Staili
void getName(char*, int);       //Sofiane Staili
void getSpecialName(char*);     //Sofiane Staili
void getNameObj(char*);         //Chloe Merck
void NameBoss(char*);           //Chloe Merck


#endif // GAME_H_INCLUDED
