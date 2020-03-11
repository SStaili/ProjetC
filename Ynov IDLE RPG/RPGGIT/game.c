#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "game.h"


#define FILE_SIZE 10;

void playGame(Player player) //Sofiane Staili
{
	char prompt[30];
	printf("Dit 'aide' pour qu'une voix divine te guide");
	do
	{
		printf("\n> ");
		fgets(prompt, 30, stdin);
		prompt[strlen(prompt)-1] = '\0';
		lower(prompt);
		printf("\n");

		if (strcmp(prompt, "aide") == 0)
			printHelp();
		else if (strcmp(prompt, "repos") == 0)
		{
			player.currentHP = player.maxHP;
            player.currentMana = player.maxMana;
			printf("Pret pour retourner au combat !.\n");
		}
		else if (strcmp(prompt, "stats") == 0)
			printStats(player);
		else if (strcmp(prompt, "aller nord") == 0)
		{
			if (player.Y == -50)
				printf("tu ne peux pas aller plus au nord! ");
			else
			{
				printf("tu montes au nord. ");
				move(&player, 0, -1);
			}
			if (player.Y > 40)
				printf("\nil fait froid dehors.");
			printf("\n");
		}
		else if (strcmp(prompt, "aller sud") == 0)
		{
			if (player.Y == 50)
				printf("tu ne peux pas aller plus au sud! ");
			else
			{
				printf("tu descends au sud. ");
				move(&player, 0, 1);
			}
			if (player.Y  > -40)
				printf("\nil fait froid dehors.");
			printf("\n");
		}
		else if (strcmp(prompt, "aller est") == 0)
		{
			printf("tu vas a l'est. ");
			move(&player, 1, 0);
			if (player.X == -50)
				printf("tu es tellement parti a l'est que tu es a l'ouest (LOL)!");
			printf("\n");
		}
		else if (strcmp(prompt, "aller ouest") == 0)
		{
			printf("tu vas a l'ouest. ");
			move(&player, -1, 0);
			if (player.X == 50)
				printf("tu es tellement parti a l'ouest que tu es a l'est (LOL)!");
			printf("\n");
		}
		else if(strcmp(prompt,"inventaire")==0) //Ajout Chloe Merck else if inventaire
        {
            printf("Tes vivres:\n");
            printf("Or: %d\n",player.Or);
        }
		else if (strcmp(prompt, "sauvegarder") == 0)
			save(player);
		else if (strcmp(prompt, "quitter") == 0)
			break;
		else
			printf("GNAH?\n");
	} while (strcmp(prompt, "quitter") != 0);
}

//Permet de prendre en lowecase les input
void lower(char* s) //Sofiane Staili
{
	int i;
	for (i=0; i<strlen(s); i++)
	{
		s[i] = tolower(s[i]);
	}
}

//Affiche la page about
void printAbout() //Sofiane Staili
{
	printf("Vous etes un eleve d'Ynov campus et vous avez oublier de rendre le dossier d'inscription\n");
	printf("Vous vous depechez de vous rendre au campus quand soudain, une fois au portique un flash vous ebloui\n");
    printf("Une fois la vision de retour, une plaine et rien d'autre, deplacez vous et vivez l'aventure....\n");
    printf("....La plus basique qu'il soit...(LOL)  \n");
    printf("....votre destin ne dependra que de ma reussite a coder ce jeu... \n");
    printf("....Oui c'est le dieu de ce monde qui te parle allez au boulot va buter du monstre!! \n");
    printf("....Ah! et si tu as besoin d'aide dis 'aide' BONNE CHANCE! ...*Pouf*... \n");
    printf("Les combats sont automatique! \n");
    printf("Projet réalisé par...\n"); //Ajout Chloe Merck
}

void printHelp() //Sofiane Staili
{
	printf("Commandes:\n");
	printf("\tPartir au north   - aller nord\n");
	printf("\tPartir au sud     - aller sud\n");
	printf("\tPartir a l'est    - aller est\n");
	printf("\tPartir a l'ouest  - aller ouest\n");
	printf("\tSe reposer        - repos\n");
	printf("\tvoir les Stats    - stats\n");
	printf("\tvoir Inventaire   - inventaire\n"); //Ajout Chloe Merck
	printf("\tVoir l'aide       - aide\n");
	printf("\tSauvegarder       - sauvegarder\n");
	printf("\tQuitter le jeu    - quitter\n");
}

void pause(int sec) //Sofiane Staili
{
	int returnTime = time(0) + sec;
	while (time(0) < returnTime) ; //attend la fin ;
}

//prend le nom du NPC
void getName(char* name, int level) //Sofiane Staili
{
	int terminal = (level/5)+rand()%5;
	int i;
	FILE* nameFile;
	nameFile = fopen("names.txt", "r");
	if (nameFile == NULL)
	{
		strcpy(name, "NPC");
		return;
	}

	for (i=0; i<terminal; i++)
	{
		fscanf(nameFile, "%s", name);
	}
	fclose(nameFile);
}

//Pour les zones enneigées - |Y| > 70 //Sofiane Staili
void getSpecialName(char* name)
{
	int terminal = 25+rand()%5;
	int i;
	FILE* nameFile;
	nameFile = fopen("names.txt", "r");
	if (nameFile == NULL)
	{
		strcpy(name, "NPC de glace");
		return;
	}
	for (i=0; i<terminal; i++)
	{
		fscanf(nameFile, "%s", name);
	}
	fclose(nameFile);
}

//Nom Boss

void NameBoss(char* name) //Chloe Merck
{
    int terminal = rand()%5;
    int i;
    FILE* bossFile;
    bossFile= fopen("boss.txt","r");

    if(bossFile == NULL)
    {
        strcpy(name,"NPC Boss");
        return;
    }

    for(i=0; i <terminal;i++)
    {
        fscanf(bossFile,"%s",name);
    }
    fclose(bossFile);
}

//Pour l'inventaire

void getNameObj(char* name) //Chloe Merck
{
   int terminal = rand()%5;
   int i;
   FILE* inventaireFile;
   inventaireFile = fopen("inventaire.txt","r");

   if(inventaireFile == NULL)
   {
       strcpy(name, "NPCS");
       return;
   }

   for(i=0; i<terminal; i++)
   {
       fscanf(inventaireFile,"%s",name);
   }
   fclose(inventaireFile);
}
