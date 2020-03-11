//
//  Player.h
//  Eval
//
//  Created by Jean-Baptiste Salaun on 04/03/2020.
//  Copyright © 2020 Chloé Merck. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include <stdio.h>

typedef struct Personnage Personnage; //Chloe Merck

struct Personnage{
    int pv;
    int force;
    int defense;
    char name[100];
    
};

#endif /* Player_h */
