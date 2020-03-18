#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <locale.h>

#define max 200

typedef struct person
{
    char *name;
    char *country;
    int number;
    float probability;
    float statistics[2];
} person;

void output(person *mass, int r);
int charToInt(char numeric);
void split(char *mes, person *mass, int r);
int fillStruct(person *futClub);
int enterFromKeyboard(person *futClub, int m);
void searchForMatches(int r,person *futClub);

int main()
{
    setlocale(LC_ALL, "Russian");
    person *futClub;
    if ((futClub = malloc(200 * sizeof(person))) == NULL)
    {
        printf("Error memory allocation!");
    }
    else
    {
        printf("Instructions for the database:\n");
        printf("1 column-numbering\n");
        printf("2 column - the name of the club\n");
        printf("3 column - country of the club\n");
        printf("4 Column - probability of the club's passage to the Champions League\n");
        printf("5 column - number of wins over the last 10 matches\n");
        printf("6 column - number of draws for the last 10 matches\n");
        printf("Database from a file:\n");
        int count = fillStruct(futClub);
        count = enterFromKeyboard(futClub,count);
        printf("Extended database:\n");
        for(int i = 1; i <= count; i++)
        {
            output(futClub,i);
        }
        searchForMatches(count,futClub);
        free(futClub);
    }
    return 0;
}

void output(person *mass, int r)
{
    r = r - 1;
    printf("%2d| %15s | %15s | %6.2lf | %4.lf | %4.lf\n", mass[r].number, mass[r].name, mass[r].country,
           mass[r].probability, mass[r].statistics[0], mass[r].statistics[1]);
}

int charToInt(char numeric)
{
    return numeric - 48;
}

void split(char *mes, person *mass, int r)
{
    char *s;
    if ((s = malloc(20 * sizeof(char))) == NULL)
    {
        printf("Error memory allocation!");
    }
    else
    {
        mass[r - 1].number = r;
        int n = 0;
        int k = 0;
        for (int j = 0; j < strlen(mes); j++)
        {
            if (mes[j] != ';')
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
                if (n == 1)
                {
                    mass[r - 1].country = malloc(strlen(s) * sizeof(person));
                    strcpy(mass[r - 1].country, s);
                }
                if (n == 2)
                    mass[r - 1].statistics[0] = charToInt(s[k - 1]);
                if (n == 3)
                    mass[r - 1].statistics[1] = charToInt(s[k - 1]);
                n++;
                k = 0;
            }
        }
        mass[r - 1].probability = (mass[r - 1].statistics[0] * 2 + mass[r - 1].statistics[1]) / 20;
        free(s);
    }
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
            split(str, futClub, m);
            output(futClub, m);
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
    return m;
}

int enterFromKeyboard(person *futClub, int m)
{
    int size;
    char message[max];
    printf("\nStructure of an extension to a table:\n");
    printf("Name of the club';'country of the club';'number of wins in the last 10 matches';'number of draws in the last 10 matches';'\n");
    printf("Enter the information , otherwise press 'Enter'\n");
    fgets(message,max,stdin);
    while (strchr(message,';') != NULL)
    {
        char *str;
        size = m;
        m++;
        str = &message[0];
        split(str, futClub, m);
        printf("\nEnter the information , otherwise press 'Enter'\n");
        fgets(message, max, stdin);
    }
    int r = m;
    return r;
}

void searchForMatches(int r,person *futClub)
{
    char s[max];
    printf("\nEnter a string to search for matches:\n");
    fgets(s,20,stdin);
    int i, j, c,k;
    int n, matchCounter = 0;
    int m = strlen(s) - 1;
    printf("\nMatches found:\n");
    for(int u = 0; u < r; u++)
    {
        int difference;
        int ans = 0;
        n = 25;
        for (i = 0; i < (n - m + 1); i++)
        {
            k = 1;
            c = 1;
            for (j = 0; j < m; j++)
            {
                if((s[j] < 91) && (s[j] > 64))
                {
                    difference = + 32;
                }
                else if((s[j] < 123) && (s[j] > 96))
                {
                    difference = - 32;
                }
                if ((futClub[u].name[i + j] != s[j]) && (futClub[u].name[i + j] != s[j]+difference))
                {
                    c = 0;
                }
                if ((futClub[u].country[i + j] != s[j]) && (futClub[u].country[i + j] != s[j]+difference))
                {
                    k = 0;
                }
            }
            if (((c != 0) || (k != 0)) && (ans < 1))
            {
                matchCounter++;
                ans++;
                int f = u + 1;
                output(futClub,f);
            }
        }
    }
    if(matchCounter < 1)
    {
        printf("There is no match\n");
    }
    else
    {
        printf("\n");
    }
}
