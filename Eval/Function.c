//
//  Function.c
//  Eval
//
//  Created by Chloé Merck on 17/02/2020.
//  Copyright © 2020 Chloé Merck. All rights reserved.
//

#include "Function.h"

int AffichagemMenu(void)
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


void Etage1(int*tab, int tailleTableau)
{
    for (int i = 0; i < 10; i++)
    {
        tab[i] = 0;
    }
}

