#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string.h>
#include "player.h"
#include "game.h"

//Creation du joueur
void initialize(Player* player) //Sofiane Staili
{
	player->maxHP = 50;
	player->currentHP = player->maxHP;
	player->maxMana = 25;           //Ajout Chloe Merck Sofiane Staili
	player->currentMana = player->maxMana;  //Ajout Chloe Merck Sofiane Staili
	player->experience = 0;
	player->level = 1;
	player->ManaCost = 1;   //Ajout Chloe Merck Sofiane Staili

	player->chance = .015;
	player->baseDamage = 5;
	player->X = 0;
	player->Y = 0;


    	player->BouleDeFeu = 15;            //Ajout Chloe Merck
    	player->Electrocution = 20;         //Ajout Chloe Merck
	player->LancerDePierre = 25;        //Ajout Chloe Merck
	player->Tornade = 50;               //Ajout Chloe Merck


    	player->Or = 5;     //Ajout Chloe Merck


	printf("\nQuel est ton nom d'Aventurier?\n\n> ");
	fgets(player->name, 80, stdin);
	player->name[strlen(player->name)-1] = '\0';

	printf("\nBienvenue, %s!\n", player->name);
}





//Renvoi true si fichier bien chargé, sinon false
int load(Player* player) //Sofiane Staili
{
	FILE* inFile;
	inFile = fopen("data.txt", "r");
	if (inFile == NULL)
	{
		printf("Erreur de chargement de la sauvegarde.\n");
		return 0;
	}
	fgets(player->name, 80, inFile);
	if (player->name[strlen(player->name)-1] == '\n')
		player->name[strlen(player->name)-1] = '\0';

	fscanf(inFile, "%d/%d\n", &(player->currentHP), &(player->maxHP));
	fscanf(inFile, "%d %d\n", &(player->experience), &(player->level));
	fscanf(inFile, "%d/%d\n",&(player->currentMana), &(player->maxMana)); //Ajout Chloe Merck Sofiane Stailli
	fscanf(inFile, "%d %d\n", &(player->X), &(player->Y));
	fscanf(inFile, "%lf %lf\n", &(player->chance), &(player->baseDamage));
	fscanf(inFile,"%d\n",&(player->Or)); //Ajout Chloe Merck

	fclose(inFile);

	printf("%s's Sauvegarde correctement chargée!\n", player->name);
	printf("\nTe revoila aventurier!, %s!\n", player->name);
	return 1;
}

//Sauvegarde les données joueur dans file
void save(Player player) //Sofiane Staili
{
	FILE* saveFile;
	saveFile = fopen("data.txt", "w");
	fprintf(saveFile, "%s\n", player.name);
	fprintf(saveFile, "%d/%d\n", player.currentHP, player.maxHP);
	fprintf(saveFile, "%d/%d\n", player.currentMana, player.maxMana); //Ajout Chloe Merck Sofiane Staili
	fprintf(saveFile, "%d %d\n", player.experience, player.level);
	fprintf(saveFile, "%d %d\n", player.X, player.Y);
	fprintf(saveFile, "%.3f %.3f", player.chance, player.baseDamage);
	fprintf(saveFile,"%d",player.Or); //Ajout Chloe Merck

	fclose(saveFile);

	printf("Je me rappelerais de ton aventure n'ai crainte!\n");
}

//Deplace le joueur et donne une probabilitée de combat
void move(Player* player, int X, int Y) //Sofiane Staili
{
	player->X += X;
	player->Y += Y;

	if (player->X > 50)
		player->X= -50;
	if (player->X < -50)
		player->X = 50;

	if (rand()%25 > 5)
	{
		enemyEncounter(player);
	}
	else if(player->X == 50 && player->Y == 50) //Ajout Chloe Merck
    {
        Boss(player);
    }
	else if(rand()%35 > 3) //Ajout Chloe Merck
    {
        inventaireEncounter(player);
    }
}

//Lorsque que le joueur rencontre une ennemi:
void enemyEncounter(Player* player) //Sofiane Staili
{
	Player enemy = createNPC(*player, sqrt(((player->X)*(player->X))+((player->Y)*(player->Y))));
	char prompt[30];
	int fightOver = 0;
	printf("\n Un(e) %s ", enemy.name);
	printf("niveau(%d) apparait ! ", enemy.level);
	printf("Il approche!\n");

	do
	{	printf("Que faire?! [Combattre /Fuir/Inspecter]\n\n> ");
		fgets(prompt, 30, stdin);
		prompt[strlen(prompt)-1] = '\0';
		lower(prompt);

		if (strcmp(prompt, "combattre") == 0)
		{
			fight(player, &enemy);
			fightOver = 1;
		}

		else if (strcmp(prompt, "inspecter") == 0)
		{
			printStats(enemy);
		}
		else if (strcmp(prompt, "fuir") == 0)
		{
			printf("Tu as fuis... Pas glorieux du tout! Mais sage de ta part.\n", enemy.level, enemy.name);
			fightOver = 1;
		}
		else
		{
			printf("GNAH?\n");
		}
	} while (fightOver != 1);
}

//Systeme de combat automatique
void fight(Player* player, Player* enemy) //Sofiane Staili
{
	printf("%s\tvs\t%s\n", player->name, enemy->name);
	printf("HP:  %d/%d\t\t%d/%d\n", player->currentHP, player->maxHP, enemy->currentHP, enemy->maxHP);
    	printf("Mana: %d/%d\n", player->currentMana, player->maxMana); //Ajout Chloe Merck Sofiane Staili
    	printf("\t\t\n");
	do
	{
		//Attaque du joueur

		//Si l'ennemi ne bloque pas
		if (rand()%100 > (enemy->chance)*100)
		{
			//Si il y'a coup critique
			if (rand()%50 < (player->chance)*100)
			{
				printf("%s met un critique!!\n", player->name);
				applyDamage(enemy, 1.5*player->baseDamage);
				printf("\t\t\n");
			}

			else
            {
                attaque(player,enemy); //Ajout Chloe Merck
                printf("\t\t\n");
            }

		}
		else
			printf("%s bloque l'attaque!\n", player->name);
		pause(1);

		//Attaques des ennemis

		//Si le joueur ne bloque pas
		if (rand()%100 > (player->chance)*100)
		{
			//Si il y'a coup critique
			if (rand()%100 < (enemy->chance)*100)
			{
				applyDamage(player, 1.5*enemy->baseDamage);
				printf("%s met un critique!!\n", enemy->name);
				printf("\t\t\n");
			}
			else
			{
			    printf("Attaque ennemies  de %s !\n", enemy->name);
				applyDamage(player, enemy->baseDamage);
				printf("\t\t\n");
			}
		}
		else
			printf("%s bloque l'attaque!\n", enemy->name);
			printf("\t\t\n");
		pause(1);

        printf("HP:  %d/%d\t\t%d/%d\n", player->currentHP, player->maxHP, enemy->currentHP, enemy->maxHP);
        printf("Mana: %d/%d\n", player->currentMana, player->maxMana); //Ajout Chloe Merck Sofiane Stailli
        printf("\t\t\n");

	} while (isDead(*player) != 1 && isDead(*enemy) != 1);

	if (isDead(*player))
	{
		printf("Tu es mort de maniere douloureuse... oups....\n");
		player->X = 0;
		player->Y = 0;
		player->currentHP = player->maxHP;
		player->currentMana = player->maxMana;
		pause(3);
		printf("Wow, tu ouvres les yeux et tu te rends compte que tu es dans un jeu. Vive le RESPAWN!\n");
		printf("\t\t\n");
	}
	else if (isDead(*enemy))
	{
		onFightWin(player, *enemy);
	}
}




//Si le combat est gagné, on récupere l'xp
void onFightWin(Player* player, Player NPC) //Sofiane Staili
{
	//gain d'xp (fomrule de runescape prise sur le net
	int exp = (int)sqrt(240*NPC.level + NPC.maxHP);
	printf("\nVictoire!! %d points d'experience en plus!.", exp);
	printf("\t\t\n");
	player->experience += exp;

	//Montée de niveau
	if (canLevelUp(player))
	{
		levelUp(player);
	}
}

//Améliore les stats du joueur quand lvl up
void levelUp(Player* player) //Sofiane Staili
{
	player->level++;

	player->maxHP += sqrt(player->level);
	player->currentHP = player->maxHP;
	player->maxMana += sqrt(player->level)+2; //Ajout Chloe Merck Sofiane Staili
	player->currentMana = player->maxMana; //Ajout Chloe Merck

	player->chance += player->level*.001;
	player->baseDamage += sqrt(player->level*2);

	printf("\nGenial! Tu es maintenant niveau %d !", player->level);
	printf("\t\t\n");
}

//Verifie l'xp du joueur pour le monter de niveau.
//inspiré du systeme de leveling de runescape (récupéré sur le net)
int canLevelUp(Player * player) //Sofiane Staili
{
	double netXP = 300;
	double i;
	for (i=1.0; i<player->level; i=i+1.0)
	{
		netXP+=(i+300*pow(2.0, (i/7.0)));
	}
	netXP*=.25;

	if (player->experience > netXP)
		return 1;
	return 0;
}

//Affiche les stats du joueur ou de l'ennemis
void printStats(Player player) //Sofiane Staili
{
	printf("\nTes stats: \n", player.name);
	printf("HP:\t%d/%d\n", player.currentHP, player.maxHP);
	printf("Mana:\t%d/%d\n",player.currentMana, player.maxMana);
	printf("XP:\t%d\nNiveau:\t%d\n", player.experience, player.level);

	printf("Lieu: ");
	if (player.Y < 0)
		printf("%d Nord, ", -1*player.Y);
	else if (player.Y > 0)
		printf("%d Sud, ", player.Y);
	else if (player.Y == 0)
		printf("0, ");
	if (player.X < 0)
		printf("%d Ouest\n", -1*player.X);
	else if (player.X > 0)
		printf("%d Est\n", player.X);
	else if (player.X == 0)
		printf("0\n");
	printf("Degats:\t%.2f\n", player.baseDamage);
}

//Permet de dire que player est mort
int isDead(Player player) //Sofiane Staili
{
	if (player.currentHP <= 0)
		return 1;
	else
		return 0;
}

//Applique les dommages à l'ennemi
void applyDamage(Player* player, double damage) //Sofiane Staili
{
	player->currentHP -= damage;
	if (player->currentHP < 0)
		player->currentHP = 0;
}

//Permet de creer un ennemi basé sur le niveau du joueur et sur la distance qu'il a parcouru
Player createNPC(Player player, double distance) //Sofiane Staili
{
	Player enemy;
	char enemyName[50];

	enemy.X = player.X;
	enemy.Y = player.Y;

	enemy.level = player.level
					+ (rand()%(1+(int)distance))
					- (rand()%(1+(int)(sqrt(200)-distance)));

	if (enemy.level > 100)
		enemy.level = 100;
	if (enemy.level < 1)
		enemy.level = 1;

	if (enemy.Y > 70 || enemy.Y < -70)
		getSpecialName(enemyName);
	else
		getName(enemyName, enemy.level);
	strcpy(enemy.name, enemyName);

	enemy.experience = 0;

	enemy.maxHP = 30+enemy.level*sqrt(enemy.level+1)-rand()%(enemy.level+1);
	enemy.currentHP = enemy.maxHP;

	enemy.chance = .01*(rand()%(1+enemy.level))/2;
	enemy.baseDamage = 3.0+enemy.level*sqrt(rand()%(enemy.level+1));

	return enemy;
}

//Attaque joueur

void attaque(Player* player,Player* enemy) //Chloe Merck
{

    if(player->currentMana != 0)
    {
       if(rand()%20 > (player->chance*100))
        {
            printf("%s lance boule de feu sur %s\n",player->name,enemy->name);
            applyDamage(enemy,player->BouleDeFeu * (player->baseDamage * .15));
            player->currentMana = player->currentMana - (player->ManaCost*5);
        }
        else if(rand()%10 >(player->chance*100))
        {
            printf("%s lance la foudre contre %s \n ", player->name, enemy->name);
            applyDamage(enemy,player->Electrocution *(player->baseDamage * .15));
            player->currentMana = player->currentMana - (player->ManaCost*10);

        }
        else if(rand()%10 >(player->chance*100))
        {
            printf("%s lance des pierres contre %s \n ", player->name, enemy->name);
            applyDamage(enemy,player->LancerDePierre *(player->baseDamage * .15));
            player->currentMana = player->currentMana - (player->ManaCost*15);
        }
        else if(rand()%5 >(player->chance*100))
        {
            printf("%s lance des tornades %s \n ", player->name, enemy->name);
            applyDamage(enemy,player->Tornade *(player->baseDamage * .15));
            player->currentMana = player->currentMana - (player->ManaCost*20);
        }
    }
    else
    {
        printf("%s Attaque a l'epee %s \n",player->name, enemy->name);
        applyDamage(enemy,player->baseDamage);
    }

}

//Permet creer objet inventaire
Player createNPCS(Player player, double distance) //Chloe Merck
{
    Player inventaire;
    char inventaireName[50];

    inventaire.X = inventaire.X;
    inventaire.Y = inventaire.Y;

    getNameObj(inventaireName);
    strcpy(inventaire.name, inventaireName);

    return inventaire;
}


void inventaireEncounter(Player* player) //Chloe Merck
{
    Player inventaire =createNPCS(*player, sqrt(((player->X)*(player->X))+(player->Y)*(player->Y)));

    char prompt[30];
    int inventaireOver = 0;

    printf("\n Un(e) %s\n", inventaire.name );

    do
    {
        printf("Que faire?! [Prendre/Laisser]\n\n>");
        fgets(prompt, 30, stdin);
        prompt[strlen(prompt)- 1] ='\0';
        lower(prompt);

        if(strcmp(prompt,"prendre")==0)
        {
            printf("Ajout %s dans votre inventaire\n",inventaire.name);
            AjoutObj(player);
            inventaireOver = 1;
        }
        else if(strcmp(prompt,"laisser")==0)
        {
            inventaireOver = 1;
        }
    }
    while(inventaireOver != 1);


}

void AjoutObj(Player* player) //Chloe Merck
{
        player->Or++;
}



Player createBoss(Player player, double distance) //Chloe Merck
{
    Player boss;
    char bossName[50];

    boss.X = player.X;
    boss.Y = player.Y;

    boss.level = 250;

    if(boss.Y == 25 && boss.X == 25)
    {
        NameBoss(bossName);
    }
    strcpy(boss.name, bossName);

    boss.experience = 0;

    boss.maxHP = 10000;
    boss.currentHP = 10000;

    boss.baseDamage = 25;

    return boss;
}

void Boss(Player* player) //Chloe Merck
{
   Player boss = createBoss(*player,sqrt(((player->X)*(player->X))+((player->Y)*(player->Y))));
   char prompt[30];
   int bossOver = 0;
   printf("\n Thor %s apparait ",boss.name);

   do
   {
       printf("Que faire?! [Affronter/Fuir]\n\n>");
       fgets(prompt, 30, stdin);
       prompt[strlen(prompt)-1]='\0';
       lower(prompt);

       if(strcmp(prompt,"affronter")==0)
       {
           fight(player,&boss);
           bossOver=1;
       }
       else if(strcmp(prompt,"fuir")==0)
       {
           printf("Tu as fuis...");
           bossOver=1;
       }
       else
       {
           printf("GNAH?\n");
       }
   }while(bossOver != 1);

}
