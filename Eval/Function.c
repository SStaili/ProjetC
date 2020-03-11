//
//  Function.c
//  Eval
//
//  Created by Chloé Merck on 17/02/2020.
//  Copyright © 2020 Chloé Merck. All rights reserved.
//

#include "Function.h"

int AffichagemMenu(void) // Chloe Merck
{
    int ChoixMenu;
    printf("MAIN MENU :\n");
    printf("1. Create a New Game\n");
    printf("2. Load Saved Game\n");
    printf("3. About\n");
    printf("4. Exit\n");
    scanf("%d", &ChoixMenu);
    
    return ChoixMenu;
    
    
}


void Etage1(int*tab, int tailleTableau) //Jean Baptiste
{
    for (int i = 0; i < 10; i++)
    {
        tab[i] = 0;
    }
}
int Recherche() //Chloe Merck
{
    int nbr, k, r,tab[30];
    printf("Entrer le nombre des éléments dans le tableau");
    scanf("%d",&nbr);
    
    printf("Entrer les éléments du tableau: ");
    for(k=0; k < nbr; k++){
        scanf("%d", &tab[k]);
    }
    
    printf("Entrez l'élément de recherche:");
    scanf("%d", &r);
    
    
    k = 0;
    
    while(k < nbr && r !=tab[k]){
        k++;
    }
    
    if (k < nbr) {
         printf("L'élément se trouve dans la position = %d", k + 1);
      } else {
         printf("Elément non trouvé");
      }
    
    return 0;
}



void NomPersonnage(Personnage *p) //Chloe Merck
{
    
    printf("Entrez le nom de votre héros");
    scanf("%s", p ->name);
    
    
}



