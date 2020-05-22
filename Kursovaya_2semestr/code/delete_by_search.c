#include "h_files/delete_by_search.h"

void search_name(head *q)
{
    printf("Enter a name or part of a name: ");
    char s[100];

    scanf("%s", s);
    s[strlen(s)] = '\0';

    node *temp = NULL;
    node *p = NULL;
    temp = q -> first;

    size_t num = 0;

    if((q -> N) > 0)
    {
        while((temp -> next) != NULL)
        {
            if(strstr((temp -> baza -> name), s) != NULL)
            {
                if((q -> first) == temp)
                {
                    temp = temp -> next;
                    delete_first(q);
                }
                else
                {
                    temp = temp -> next;
                    delete_node(p, q);
                }
                num++;
            }
            else
            {
                p = temp;
                temp = p -> next;
            }
        }

        if(strstr((temp -> baza -> name), s) != NULL)
        {
            if((q -> first) == temp)
                delete_first(q);
            else
                delete_node(p, q);
            num++;
        }
    }

    if(num == 0)
        printf("\nRESULT:\nThere is no match!!!\n\n");
}


void search_country(head *q)
{
    printf("Enter a name or part of a name: ");
    char s[100];

    scanf("%s", s);
    s[strlen(s)] = '\0';

    node *temp = NULL;
    node *p = NULL;

    size_t num = 0;

    if((q -> N) > 0)
    {
        temp = q -> first;
        while((temp -> next) != NULL)
        {
            if(strstr((temp -> baza -> country), s) != NULL)
            {
                if((q -> first) == temp)
                {
                    temp = temp -> next;
                    delete_first(q);
                }
                else
                {
                    temp = temp -> next;
                    delete_node(p, q);
                }
                num++;
            }
            else
            {
                p = temp;
                temp = p -> next;
            }
        }

        if(strstr((temp -> baza -> country), s) != NULL)
        {
            if((q -> first) == temp)
                delete_first(q);
            else
                delete_node(p, q);
            num++;
        }
    }

    if(num == 0)
        printf("\nRESULT\nThere is no match!!!\n\n");
}


void search_probability(head *q)
{
    printf("Enter the area of probability of passage to the Champions League (Probability in percentage form from 0 to 100)\n");
    int beg;
    char s3[100];
    int u = 0;
    int l = 0;
    int k = 0;

    while(l != 1)
    {
        printf("from: ");
        scanf("%s", s3);

        u = 0;
        k = 0;

        for(int i = 0; i <= str_len(s3); i++)
        {
            if((charToInt(s3[i]) <= 9) && (charToInt(s3[i]) >= 0))
                k = k * 10 + charToInt(s3[i]);
            else
            {
                u = 1;
                i = str_len(s3);
            }
        }

        if((u == 0) && (k <= 100) && (k >= 0))
            l = 1;
    }
    beg = k;

    l = 0;
    while(l != 1)
    {
        printf("before: ");
        scanf("%s", s3);

        u = 0;
        k = 0;

        for(int i = 0; i <= str_len(s3); i++)
        {
            if((charToInt(s3[i]) <= 9) && (charToInt(s3[i]) >= 0))
                k = k * 10 + charToInt(s3[i]);
            else
            {
                u = 1;
                i = str_len(s3);
            }
        }

        if((u == 0) && (k <= 100) && (k >= 0))
            l = 1;
    }

    int en = k;

    float o = 100;
    float b = beg / o;
    float e = en / o;

    node *temp = NULL;
    node *p = NULL;
    temp = q -> first;

    size_t num = 0;

    if((q -> N) > 0)
    {
        while((temp -> next) != NULL)
        {
            if(((temp -> baza -> probability) >= b) && ((temp -> baza -> probability) <= e))
            {
                if((q -> first) == temp)
                {
                    temp = temp -> next;
                    delete_first(q);
                }
                else
                {
                    temp = temp -> next;
                    delete_node(p, q);
                }
                num++;
            }
            else
            {
                p = temp;
                temp = p -> next;
            }
        }

        if(((temp -> baza -> probability) >= b) && ((temp -> baza -> probability) <= e))
        {
            if((q -> first) == temp)
            {
                delete_first(q);
            }
            else
                delete_node(p, q);
            num++;
        }
    }

    if(num == 0)
        printf("\nRESULT:\nThere is no match!!!\n\n");
}


void search_wins(head *q)
{
    char s3[100];
    int l = 0;
    int k = 0;

    while(l != 1)
    {
        printf("Wins last 10 matches: ");
        scanf("%s", s3);

        int u = 0;
        k = 0;

        for(int i = 0; i <= str_len(s3); i++ )
        {
            if((charToInt(s3[i]) <= 9) && (charToInt(s3[i]) >= 0))
                k = k * 10 + charToInt(s3[i]);
            else
            {
                u = 1;
                i = str_len(s3);
            }
        }

        if((u == 0) && (k <= 10) && (k >= 0))
            l = 1;
    }

    node *temp = NULL;
    node *p = NULL;
    temp = q -> first;

    size_t num = 0;

    if((q -> N) > 0)
    {
        while((temp -> next) != NULL)
        {
            if((temp -> baza -> statistics[0]) == k)
            {
                if((q -> first) == temp)
                {
                    temp = temp -> next;
                    delete_first(q);
                }
                else
                {
                    temp = temp -> next;
                    delete_node(p, q);
                }
                num++;
            }
            else
            {
                p = temp;
                temp = p -> next;
            }
        }

        if((temp -> baza -> statistics[0]) == k)
        {
            if((q -> first) == temp)
                delete_first(q);
            else
                delete_node(p, q);
            num++;
        }
    }

    if(num == 0)
        printf("\nRESULT:\nThere is no match!!!\n\n");
}


void search_draws(head *q)
{
    char s3[100];
    int l = 0;
    int k = 0;

    while(l != 1)
    {
        printf("Wins last 10 matches: ");
        scanf("%s", s3);

        int u = 0;
        k = 0;

        for(int i = 0; i <= str_len(s3); i++ )
        {
            if((charToInt(s3[i]) <= 9) && (charToInt(s3[i]) >= 0))
                k = k * 10 + charToInt(s3[i]);
            else
            {
                u = 1;
                i = str_len(s3);
            }
        }

        if((u == 0) && (k <= 10) && (k >= 0))
            l = 1;
    }

    node *temp = NULL;
    node *p = NULL;
    temp = q -> first;

    size_t num = 0;

    if((q -> N) > 0)
    {
        while((temp -> next) != NULL)
        {
            if((temp -> baza -> statistics[1]) == k)
            {
                if((q -> first) == temp)
                {
                    temp = temp -> next;
                    delete_first(q);
                }
                else
                {
                    temp = temp -> next;
                    delete_node(p, q);
                }
                num++;
            }
            else
            {
                p = temp;
                temp = p -> next;
            }
        }

        if((temp -> baza -> statistics[1]) == k)
        {
            if((q -> first) == temp)
                delete_first(q);
            else
                delete_node(p, q);
            num++;
        }
    }

    if(num == 0)
        printf("\nRESULT:\nThere is no match!!!\n\n");
}


void search_matches(head *q)
{
    char s[100];
    int g;
    int k = 0;

    while(k != 1)
    {
        CLS;
        printf("Select which field you want to find matches for:");
        printf("\n0) back\n1) Name club\n2) Country of the club\n3) probability of the club's passage to the Champions League\n4) wins last 10 matches\n5) count draws last 10 matches\n\ncommand: ");

        scanf("%s", s);
        g = charToInt(s[0]);

        if(str_len(s) == 0)
        {
            if(g == 1)
            {
                k = 1;
                search_name(q);
            }
            else if(g == 2)
            {
                k = 1;
                search_country(q);
            }
            else if(g == 3)
            {
                k = 1;
                search_probability(q);
            }
            else if(g == 4)
            {
                k = 1;
                search_wins(q);
            }
            else if(g == 5)
            {
                k  = 1;
                search_draws(q);
            }
            else if(g == 0){
                k = 1;
                CLS;
            }
        }
    }
}
