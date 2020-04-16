#include "struct.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#ifndef SPLIT_H_INCLUDED
#define SPLIT_H_INCLUDED

int str_len(char *s){
    int r = 0;
    while(s[r] != '\0') r++;
    r--;
    return r;
}
int charToInt(char numeric)
{
    return numeric - 48;
}


void split(char *mes, person *mass, int r, int q, int n)
{
    char *s;
    if ((s = malloc(20 * sizeof(char))) == NULL)
    {
        puts("Error memory allocation!");
    }
    else
    {
        mass[r - 1].number = r;
        if(!q) n = 0;
        int k = 0;
        for (size_t j = 0; j < strlen(mes); j++)
        {
            if ((mes[j] != ';'))
            {
                s[k] = mes[j];
                k++;
            }
            else
            {
                s[k] = '\0';
                if (n == 0)
                {
                    mass[r - 1].name = malloc(strlen(s) * sizeof(person));
                    strcpy(mass[r - 1].name, s);
                }
                else if (n == 1)
                {
                    mass[r - 1].country = malloc(strlen(s) * sizeof(person));
                    strcpy(mass[r - 1].country, s);
                }
                else if (n == 2)
                    mass[r - 1].statistics[0] = charToInt(s[k - 1]);
                else if (n == 3)
                    mass[r - 1].statistics[1] = charToInt(s[k - 1]);
                if(!q) n++;
                k = 0;
            }
        }
        mass[r - 1].probability = (mass[r - 1].statistics[0] * 2 + mass[r - 1].statistics[1]) / 20;
        free(s);
    }
}


#endif // SPLIT_H_INCLUDED
