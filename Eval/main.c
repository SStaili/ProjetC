//
//  main.c
//  Eval
//
//  Created by Chloé Merck on 17/02/2020.
//  Copyright © 2020 Chloé Merck. All rights reserved.
//

#include <stdio.h>
#include "Function.h"
#include "Personnage.h"

int main(void)
{
    int choix = 0;
    switch (AffichagemMenu())
    {
        case 1:
            printf("Vous avez choisis de Créer un Nouveau Jeux\n");
            choix = 1;
            break;
        case 2:
            printf("Vous avez choisis de charger une ancienne partie\n");
            choix = 2;
            break;
        case 3:
            printf("Vous avez choisis About\n");
            choix = 3;
            break;
        case 4:
            printf("Vous quitter le jeux\n");
            choix = 4;
            break;
            
        default:
            printf("Mauvais Choix\n");
            break;
    }

    if (choix == 1)
        printf()
    
    return 0;
}


