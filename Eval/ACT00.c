//
//  ACT00.c
//  Eval
//
//  Created by Jean-Baptiste Salaun on 19/02/2020.
//  Copyright © 2020 Chloé Merck. All rights reserved.
//

#include "ACT00.h"
#include <stdio.h>
#include <stdbool.h>
#include "parsexec.h"

static char input[100] = "look around";

static bool getInput(void)
{
   printf("\n--> ");
   return fgets(input, sizeof(input), stdin) != NULL;
}

int main()
{
   printf("Welcome to Little Cave Adventure.\n");
   while (parseAndExecute(input) && getInput());
   printf("\nBye!\n");
   return 0;
}
