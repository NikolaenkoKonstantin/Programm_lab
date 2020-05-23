#include "h_files/edit_card.h"

//edit the fields in the card
void edit_card(head *q)
{
    node *temp = q -> first;

    char s[100];
    int f = -1, u = 0, l = 0;

    while(l != 1)
    {
        CLS;
        printf("If you want to go back to the menu write 0\nEnter the number of the card you want to edit(id no more %d):", q -> N);
        scanf("%s", s);

        u = 0;
        f = 0;

        for(int i = 0; i <= str_len(s); i++ )
        {
            if((charToInt(s[i]) <= 9) && (charToInt(s[i]) >= 0))
                f = f * 10 + charToInt(s[i]);
            else
            {
                u = 1;
                i = str_len(s);
            }
        }

        if(u == 0)
        {
            if(f <= q -> N)
            {
                l = 1;
                for(int i = 1; i < f; i++)
                {
                    temp = temp -> next;
                }
            }
        }
    }

    if((f > 0) && (f <= q -> N))
    {
        char s1[100];
        int g;
        int k = 0;

        while(k != 1)
        {
            CLS;
            printf("Select the field to edit:");
            printf("\n1) Name club\n2) Country of the club\n3) Wins and draws\n\ncommand: ");

            scanf("%s", s1);
            g = charToInt(s1[0]);

            if(str_len(s1) == 0)
            {
                if(g == 1)
                {
                    k = 1;
                    printf("Club: ");
                    scanf("%s", (temp -> baza -> name));
                }
                else if(g == 2)
                {
                    k = 1;
                    printf("Country: ");
                    scanf("%s", (temp -> baza -> country));
                }
                else if(g == 3)
                {
                    k = 1;
                    char s3[100];
                    int u = 0;
                    int l = 0;
                    int f1 = 0;

                    while(l != 1)
                    {
                        printf("Wins last 10 matches: ");
                        scanf("%s", s3);

                        u = 0;
                        f1 = 0;

                        for(int i = 0; i <= str_len(s3); i++ )
                        {
                            if((charToInt(s3[i]) <= 9) && (charToInt(s3[i]) >= 0))
                                f1 = f1 * 10 + charToInt(s3[i]);
                            else
                            {
                                u = 1;
                                i = str_len(s3);
                            }
                        }

                        if(u == 0)
                        {
                            if((f1 <= 10) && (f1 >= 0))
                            {
                                l = 1;
                                temp -> baza -> statistics[0] = f1;
                            }
                        }
                    }

                    char s4[100];
                    u = 0;
                    l = 0;
                    f1 = 0;

                    while(l != 1)
                    {
                        printf("Count draws last 10 matches(draws + wins <= 10): ");
                        scanf("%s", s4);

                        u = 0;
                        f1 = 0;

                        for(int i = 0; i <= str_len(s4); i++ )
                        {
                            if((charToInt(s4[i]) <= 9) && (charToInt(s4[i]) >= 0))
                                f1 = f1 * 10 + charToInt(s4[i]);
                            else
                            {
                                u = 1;
                                i = str_len(s4);
                            }
                        }

                        if(u == 0)
                        {
                            if((f1 <= (10 - temp -> baza -> statistics[0])) && (f1 >= 0))
                            {
                                l = 1;
                                temp -> baza -> statistics[1] = f1;
                            }
                        }
                    }

                    temp -> baza -> probability = (temp -> baza -> statistics[0] * 2 + temp -> baza -> statistics[1]) / 20;
                }
            }
        }
    }
    else CLS;
}
