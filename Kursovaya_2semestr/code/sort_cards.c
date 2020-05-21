#include "h_files/sort_cards.h"

void sort_names(head *q)
{
    if(q -> N > 1)
    {
        int k;
        node *p1 = NULL;
        node *temp = NULL;
        temp = q -> first -> next;

        while(temp -> next != NULL)
        {
            p1 = q -> first;
            k = 0;

            while((p1 != temp) && (k != 1))
            {
                if(strcmp(temp -> baza -> name, p1 -> baza -> name) < 0)
                {
                    transfer_node(p1, temp, q);
                    k = 1;
                }

                p1 = p1 -> next;
            }

            if(k == 1)
            {
                temp = temp -> next;
                delete_node(temp -> prev -> prev, q);
            }
            else
                temp = temp -> next;
        }

        p1 = q -> first;
        k = 0;

        while((p1 -> next != temp) && (k != 1))
        {
            if(strcmp(temp -> baza -> name, p1 -> baza -> name) < 0)
            {
                transfer_node(p1, temp, q);
                k = 1;
            }
            p1 = p1 -> next;
        }

        if(k == 1)
            delete_node(temp -> prev, q);
        else if(k != 1)
            if(strcmp(temp -> baza -> name, p1 -> baza -> name) < 0)
            {
                transfer_node(p1, temp, q);
                delete_node(temp -> prev, q);
            }
        output_list(q);
    }
    else
        printf("\nRESULT:\nSorting is not possible\n");
}


void sort_country(head *q)
{
    if(q -> N > 1)
    {
        int k;
        node *p1 = NULL;
        node *temp = NULL;
        temp = q -> first -> next;

        while(temp -> next != NULL)
        {
            p1 = q -> first;
            k = 0;


            while((p1 != temp) && (k != 1))
            {
                if(strcmp(temp -> baza -> country, p1 -> baza -> country) < 0)
                {
                    transfer_node(p1, temp, q);
                    k = 1;
                }

                p1 = p1 -> next;
            }

            if(k == 1)
            {
                temp = temp -> next;
                delete_node(temp -> prev -> prev, q);
            }
            else
                temp = temp -> next;
        }

        p1 = q -> first;
        k = 0;

        while((p1 -> next != temp) && (k != 1))
        {
            if(strcmp(temp -> baza -> country, p1 -> baza -> country) < 0)
            {
                transfer_node(p1, temp, q);
                k = 1;
            }
            p1 = p1 -> next;
        }

        if(k == 1)
            delete_node(temp -> prev, q);
        else if(k != 1)
            if(strcmp(temp -> baza -> country, p1 -> baza -> country) < 0)
            {
                transfer_node(p1, temp, q);
                delete_node(temp -> prev, q);
            }
        output_list(q);
    }
    else
        printf("\nRESULT:\nSorting is not possible\n");
}


void sort_probability(head *q)
{
    if(q -> N > 1)
    {
        int k;
        node *p1 = NULL;
        node *temp = NULL;
        temp = q -> first -> next;

        while(temp -> next != NULL)
        {
            p1 = q -> first;
            k = 0;


            while((p1 != temp) && (k != 1))
            {
                if(temp -> baza -> probability < p1 -> baza -> probability)
                {
                    transfer_node(p1, temp, q);
                    k = 1;
                }

                p1 = p1 -> next;
            }

            if(k == 1)
            {
                temp = temp -> next;
                delete_node(temp -> prev -> prev, q);
            }
            else
                temp = temp -> next;
        }

        p1 = q -> first;
        k = 0;

        while((p1 -> next != temp) && (k != 1))
        {
            if(temp -> baza -> probability < p1 -> baza -> probability)
            {
                transfer_node(p1, temp, q);
                k = 1;
            }
            p1 = p1 -> next;
        }

        if(k == 1)
            delete_node(temp -> prev, q);
        else if(k != 1)
            if(temp -> baza -> probability < p1 -> baza -> probability)
            {
                transfer_node(p1, temp, q);
                delete_node(temp -> prev, q);
            }
        output_list(q);
    }
    else
        printf("\nRESULT:\nSorting is not possible\n");
}


void sort_wins(head *q)
{
    if(q -> N > 1)
    {
        int k;
        node *p1 = NULL;
        node *temp = NULL;
        temp = q -> first -> next;

        while(temp -> next != NULL)
        {
            p1 = q -> first;
            k = 0;


            while((p1 != temp) && (k != 1))
            {
                if(temp -> baza -> statistics[0] < p1 -> baza -> statistics[0])
                {
                    transfer_node(p1, temp, q);
                    k = 1;
                }

                p1 = p1 -> next;
            }

            if(k == 1)
            {
                temp = temp -> next;
                delete_node(temp -> prev -> prev, q);
            }
            else
                temp = temp -> next;
        }

        p1 = q -> first;
        k = 0;

        while((p1 -> next != temp) && (k != 1))
        {
            if(temp -> baza -> statistics[0] < p1 -> baza -> statistics[0])
            {
                transfer_node(p1, temp, q);
                k = 1;
            }
            p1 = p1 -> next;
        }

        if(k == 1)
            delete_node(temp -> prev, q);
        else if(k != 1)
            if(temp -> baza -> statistics[0] < p1 -> baza -> statistics[0])
            {
                transfer_node(p1, temp, q);
                delete_node(temp -> prev, q);
            }
        output_list(q);
    }
    else
        printf("\nRESULT:\nSorting is not possible\n");
}


void sort_draws(head *q)
{
    if(q -> N > 1)
    {
        int k;
        node *p1 = NULL;
        node *temp = NULL;
        temp = q -> first -> next;

        while(temp -> next != NULL)
        {
            p1 = q -> first;
            k = 0;


            while((p1 != temp) && (k != 1))
            {
                if(temp -> baza -> statistics[1] < p1 -> baza -> statistics[1])
                {
                    transfer_node(p1, temp, q);
                    k = 1;
                }

                p1 = p1 -> next;
            }

            if(k == 1)
            {
                temp = temp -> next;
                delete_node(temp -> prev -> prev, q);
            }
            else
                temp = temp -> next;
        }

        p1 = q -> first;
        k = 0;

        while((p1 -> next != temp) && (k != 1))
        {
            if(temp -> baza -> statistics[1] < p1 -> baza -> statistics[1])
            {
                transfer_node(p1, temp, q);
                k = 1;
            }
            p1 = p1 -> next;
        }

        if(k == 1)
            delete_node(temp -> prev, q);
        else if(k != 1)
            if(temp -> baza -> statistics[1] < p1 -> baza -> statistics[1])
            {
                transfer_node(p1, temp, q);
                delete_node(temp -> prev, q);
            }
        output_list(q);
    }
    else
        printf("\nRESULT:\nSorting is not possible\n");
}


void sort_cards(head *q)
{
    char s[100];
    int g;
    int k = 0;

    while(k != 1)
    {
        CLS;
        printf("Select a field to sort:");
        printf("\n1) Name club\n2) Country of the club\n3) probability of the club's passage to the Champions League\n4) wins last 10 matches\n5) count draws last 10 matches\n\ncommand: ");

        scanf("%s", s);
        g = charToInt(s[0]);

        if(str_len(s) == 0)
        {
            if(g == 1)
            {
                k = 1;
                sort_names(q);
            }
            else if(g == 2)
            {
                k = 1;
                sort_country(q);
            }
            else if(g == 3)
            {
                k = 1;
                sort_probability(q);
            }
            else if(g == 4)
            {
                k = 1;
                sort_wins(q);
            }
            else if(g == 5)
            {
                k  = 1;
                sort_draws(q);
            }
        }
    }
}

