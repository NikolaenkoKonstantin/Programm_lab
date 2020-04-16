#include "split.h"
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#ifndef IO_H_INCLUDED
#define IO_H_INCLUDED
#define max 200

void inform()
{
    printf("\n1 column - numbering\n");
    printf("2 column - name of the club\n");
    printf("3 column - country of the club\n");
    printf("4 Column - probability of the club's passage to the Champions League\n");
    printf("5 column - wins last 10 matches\n");
    printf("6 column - count draws last 10 matches\n");
}


void output(person *mass, int n, int kod)
{
    if(kod)
    {
        inform();
        printf("\ndatabase:\n");
        for(int r = 0; r < n; r++)
            printf("%2d| %15s | %15s | %6.2lf | %4.lf | %4.lf\n", mass[r].number, mass[r].name, mass[r].country,
                   mass[r].probability, mass[r].statistics[0], mass[r].statistics[1]);
    }
    else
        printf("%2d| %15s | %15s | %6.2lf | %4.lf | %4.lf\n", mass[n].number, mass[n].name, mass[n].country,
               mass[n].probability, mass[n].statistics[0], mass[n].statistics[1]);
}


int fillStruct(person *futClub)
{
    char message[max];
    int m = 0;
    FILE *fileread = fopen("input.csv", "r");
    if (fileread == NULL)
    {
        perror("data error");
    }
    else
    {
        char mes[max];
        fgets(message, max, fileread);
        while (strcmp(message, mes) != 0)
        {
            char *str;
            m++;
            strcpy(mes, message);
            str = &message[0];
            split(str, futClub, m, 0, 0);
            fgets(message, max, fileread);
        }
        if (fclose(fileread) == EOF)
        {
            printf("Closing error code: %d\n", errno);
        }
        else
        {
            printf("Closing OK\n");
        }
    }

    output(futClub, m, 1);

    return m;
}


int enterFromKeyboard(person *futClub, int m)
{
    char s1[200];
    char s2[200];
    char s3[200];
    char s4[200];
    printf("\nStructure of an extension to a table:\n");
    printf("Enter the information , otherwise press 'Enter'\n");
    m++;
    for(int i = 0; i < 4; i++)
    {
        char *str;
        if(i == 0) { printf("Club: "); scanf("%s", &s1); s1[strlen(s1)] = ';'; str = &s1[0];
         }
        else if(i == 1) { printf("Country: "); scanf("%s", &s2); s2[strlen(s2)] = ';'; str = &s2[0]; }
        else if(i == 2) { printf("Wins last 10 matches: "); scanf("%s", &s3); s3[strlen(s3)] = ';'; str = &s3[0]; }
        else if(i == 3) { printf("Count draws last 10 matches: "); scanf("%s", &s4); s4[strlen(s4)] = ';'; str = &s4[0]; }
        split(str, futClub, m, 1, i);
    }
    int r = m;
    output(futClub,m, 1);
    return r;
}


#endif // IO_H_INCLUDED
