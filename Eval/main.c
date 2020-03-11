//
//  main.c
//  Eval
//
//  Created by Chloé Merck on 17/02/2020.
//  Copyright © 2020 Chloé Merck. All rights reserved.
//

#include <stdio.h>
#include "Function.h"

int main() //Chloe Merck
{
    switch (AffichagemMenu())
    {
        case 1:
            printf("Vous avez choisis de Créer un Nouveau Jeux\n");
            break;
        case 2:
            printf("Vous avez choisis de charger une ancienne partie\n");
            break;
        case 3:
            printf("Vous avez choisis About\n");
            break;
        case 4:
            printf("Vous quitter le jeux\n");
            break;
            
        default:
            printf("Mauvais Choix\n");
            break;
            
    }
    
    return 0;
}


