#include "io.h"
#include "split.h"
#include <string.h>
#include "search.h"
#ifndef COMMAND_SELECTING_H_INCLUDED
#define COMMAND_SELECTING_H_INCLUDED

int command_selecting(person *club, int num)
{
    char k[200];
    int f;
    int n = num;
    printf("\nSelect a command:\n1) Add\n2) Search matches\n3) Exit\n\nCommand:");
    fgets(k, 200, stdin);
    f = charToInt(k[0]);
    if(str_len(k) == 1){
            if(f == 1)
                n = enterFromKeyboard(club, n);
            else if(f == 2)
                searchForMatches(n, club);
        }
        
    while(f != 3)
    {
        if(str_len(k) == 0){
            if(f == 1)
                n = enterFromKeyboard(club, n);
            else if(f == 2)
                searchForMatches(n, club);
        }

            printf("\nSelect a command:\n1) Add\n2) Search matches\n3) Exit\n\nCommand:");
            scanf("%s", &k);
            f = charToInt(k[0]);
    }
    return n;
}

#endif // COMMAND_SELECTING_H_INCLUDED
