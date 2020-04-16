#include "io.h"
#include "struct.h"
#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED

#define max 200

void searchForMatches(int r,person *futClub)
{
    char s[max];
    printf("\nEnter a string to search for matches:\n");
    //fgets(s,200,stdin);
    scanf("%s", &s);
    int i, j, c, k;
    int n, matchCounter = 0;
    int m = strlen(s);
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
                        difference = + 32;
                    else if((s[j] < 123) && (s[j] > 96))
                        difference = - 32;
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
                int f = u;
                output(futClub, f, 0);
            }
        }
    }
    if(matchCounter < 1)
    {
        printf("There is no match!!!\n");
    }
    else
    {
        printf("\n");
    }
}


#endif // SEARCH_H_INCLUDED
