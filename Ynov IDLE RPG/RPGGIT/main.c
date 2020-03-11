#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "game.h"

#define FILE_SIZE 10;



int main() //Sofiane Staili
{
	srand(time(NULL));
	char prompt[10];
	Player player;

	do
	{
		printf("\nYnov - Le RPG IDLE pour flemmard\n\n");
		printf("> Nouveau\n> Charger\n> Histoire\n> Quitter\n\n> ");
		fgets(prompt, 10, stdin);
		prompt[strlen(prompt)-1] = '\0';
		lower(prompt);
		if (strcmp(prompt, "nouveau") == 0)
		{
			initialize(&player);
			playGame(player);
		}
		if (strcmp(prompt, "charger") == 0)
		{
			if (load(&player))
				playGame(player);
			else
				continue;
		}
		if (strcmp(prompt, "histoire") == 0)
		{
			printAbout();
		}
	} while (strcmp(prompt, "quitter") != 0);
}

