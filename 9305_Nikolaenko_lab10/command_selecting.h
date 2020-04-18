#ifndef COMMAND_SELECTING_H_INCLUDED
#define COMMAND_SELECTING_H_INCLUDED
#include <string.h>
#include "spisok_option.h"
#include "io.h"
#include "split.h"

void command_selecting(head *q)
{
    char s[50];
    int f;
    printf("\nSelect a command:\n1) Add\n2) Delete by search\n3) database\n4) Exit\n\nCommand:");
    fgets(s, 200, stdin);
    f = charToInt(s[0]);
    if(str_len(s) == 1){
            if(f == 1)
                enterFromKeyboard(q);
            else if(f == 2)
                search_matches(q);
            else if(f == 3)
             output_list(q);
    }

    while(f != 4)
    {
        if(str_len(s) == 0){
            if(f == 1)
                enterFromKeyboard(q);
            else if(f == 2)
                search_matches(q);
            else if(f == 3)
             output_list(q);
        }

            printf("\nSelect a command:\n1) Add\n2) Delete by search\n3) database\n4) Exit\n\nCommand:");
            scanf("%s", &s);
            f = charToInt(s[0]);
    }
}


#endif // COMMAND_SELECTING_H_INCLUDED
