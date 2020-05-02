#include "h_files/split.h"


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


void split(char *mes, head *q)
{
    node *temp = NULL;

    if((q -> N) == 0) temp = create_node(q);
    else{
    add_last(q);
    temp = q -> last;
    }

    char *s;
    int n = 0;

    if ((s = malloc(20 * sizeof(char))) == NULL)
        puts("Error memory allocation!");
    else
    {
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

                if (n == 0) strcpy(temp -> baza -> name, s);
                else if (n == 1) strcpy(temp -> baza -> country, s);
                else if (n == 2) temp -> baza -> statistics[0] = charToInt(s[k - 1]);
                else if (n == 3) temp -> baza -> statistics[1] = charToInt(s[k - 1]);

                n++;
                k = 0;
            }
        }

        temp -> baza -> probability = (temp -> baza -> statistics[0] * 2 + temp -> baza -> statistics[1]) / 20;
        free(s);
    }
}
