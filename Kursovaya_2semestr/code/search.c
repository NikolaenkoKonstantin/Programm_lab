#include "h_files/search.h"

void search_match_name(head *q)
{
    printf("Enter a name or part of a name: ");
    char s[100];

    scanf("%s", s);
    s[strlen(s)] = '\0';

    node *temp = NULL;
    node *p = NULL;
    temp = q -> first;

    if((q -> N) > 0)
    {
        while((temp -> next) != NULL)
        {
            if(strstr((temp -> baza -> name), s) == NULL)
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
            }
            else
            {
                p = temp;
                temp = p -> next;
            }
        }

        if(strstr((temp -> baza -> name), s) == NULL)
        {
            if((q -> first) == temp)
                delete_first(q);
            else
                delete_node(p, q);
        }
    }
}


void search_match_country(head *q)
{
    printf("Enter a name or part of a name: ");
    char s[100];

    scanf("%s", s);
    s[strlen(s)] = '\0';

    node *temp = NULL;
    node *p = NULL;

    if((q -> N) > 0)
    {
        temp = q -> first;
        while((temp -> next) != NULL)
        {
            if(strstr((temp -> baza -> country), s) == NULL)
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
            }
            else
            {
                p = temp;
                temp = p -> next;
            }
        }

        if(strstr((temp -> baza -> country), s) == NULL)
        {
            if((q -> first) == temp)
                delete_first(q);
            else
                delete_node(p, q);
        }
    }
}


void search_match_probability(head *q)
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

    if((q -> N) > 0)
    {
        while((temp -> next) != NULL)
        {
            if(((temp -> baza -> probability) < b) || ((temp -> baza -> probability) > e))
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
            }
            else
            {
                p = temp;
                temp = p -> next;
            }
        }

        if(((temp -> baza -> probability) < b) || ((temp -> baza -> probability) > e))
        {
            if((q -> first) == temp)
            {
                delete_first(q);
            }
            else
                delete_node(p, q);
        }
    }
}


void search_match_wins(head *q)
{
    char s3[100];
    int u = 0;
    int l = 0;
    int k = 0;

    while(l != 1)
    {
        printf("Wins last 10 matches: ");
        scanf("%s", s3);

        u = 0;
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

    if((q -> N) > 0)
    {
        while((temp -> next) != NULL)
        {
            if((temp -> baza -> statistics[0]) != k)
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
            }
            else
            {
                p = temp;
                temp = p -> next;
            }
        }

        if((temp -> baza -> statistics[0]) != k)
        {
            if((q -> first) == temp)
                delete_first(q);
            else
                delete_node(p, q);
        }
    }
}


void search_match_draws(head *q)
{
    char s3[100];
    int u = 0;
    int l = 0;
    int k = 0;

    while(l != 1)
    {
        printf("Wins last 10 matches: ");
        scanf("%s", s3);

        u = 0;
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

    if((q -> N) > 0)
    {
        while((temp -> next) != NULL)
        {
            if((temp -> baza -> statistics[1]) != k)
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
            }
            else
            {
                p = temp;
                temp = p -> next;
            }
        }

        if((temp -> baza -> statistics[1]) != k)
        {
            if((q -> first) == temp)
                delete_first(q);
            else
                delete_node(p, q);
        }
    }
}


void search_match(head *q)
{

    head *q1;

    q1 = create_head();
    copy_list(q1, q);

    char s[100];
    int f = 0, u = 0;

    while(u != 1)
    {
        CLS;
        printf("Search by name:\n1) Yes\n2) No\n\nCommand:");
        scanf("%s", s);

        f = charToInt(s[0]);

        if(str_len(s) == 0)
        {
            if(f == 2)
                u = 1;
            else if(f == 1)
            {
                u = 1;
                search_match_name(q1);
            }
        }
    }

    u = 0;

    while(u != 1)
    {
        CLS;
        printf("Search by country:\n1) Yes\n2) No\n\nCommand:");
        scanf("%s", s);

        f = charToInt(s[0]);

        if(str_len(s) == 0)
        {
            if(f == 2)
                u = 1;
            else if(f == 1)
            {
                u = 1;
                search_match_country(q1);
            }

        }
    }

    u = 0;
    while(u != 1)
    {
        CLS;
        printf("Search by probability:\n1) Yes\n2) No\n\nCommand:");
        scanf("%s", s);

        f = charToInt(s[0]);

        if(str_len(s) == 0)
        {
            if(f == 2)
                u = 1;
            else if(f == 1)
            {
                u = 1;
                search_match_probability(q1);
            }

        }
    }

    u = 0;

    while(u != 1)
    {
        CLS;
        printf("Search by wins:\n1) Yes\n2) No\n\nCommand:");
        scanf("%s", s);

        f = charToInt(s[0]);

        if(str_len(s) == 0)
        {
            if(f == 2)
                u = 1;
            else if(f == 1)
            {
                u = 1;
                search_match_wins(q1);
            }

        }
    }

    u = 0;

    while(u != 1)
    {
        CLS;
        printf("Search by draws:\n1) Yes\n2) No\n\nCommand:");
        scanf("%s", s);

        f = charToInt(s[0]);

        if(str_len(s) == 0)
        {
            if(f == 2)
                u = 1;
            else if(f == 1)
            {
                u = 1;
                search_match_draws(q1);
            }

        }
    }

    CLS;
    if(q1 -> N != 0)
        output_list(q1);
    else
        printf("\nRESULT:\nNo matches!!!\n\n");

    if((q1-> N) == 1)
        free_head(q1);
    else if((q1 -> N) > 1)
        free_list(q1);
    else if ((q1-> N) == 0)
        free(q1);
}
