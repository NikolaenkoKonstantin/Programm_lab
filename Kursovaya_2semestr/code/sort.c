#include "h_files/sort.h"

//sort function
void sortMega(head *q, int n)
{
    /*sorts by conditions using the transfer_mode moving function*/
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
            if((n == 1) && (strcmp(temp -> baza -> name, p1 -> baza -> name) < 0)){
                transfer_node(p1, temp, q);
                k = 1;

            }else if((n == 2) && (strcmp(temp -> baza -> country, p1 -> baza -> country) < 0)){
                transfer_node(p1, temp, q);
                k = 1;

            }else if((n == 3) && (temp -> baza -> probability > p1 -> baza -> probability)){
                transfer_node(p1, temp, q);
                k = 1;

            }else if((n == 4) && (temp -> baza -> statistics[0] > p1 -> baza -> statistics[0])){
                transfer_node(p1, temp, q);
                k = 1;

            }else if((n == 5) && (temp -> baza -> statistics[1] > p1 -> baza -> statistics[1])){
                transfer_node(p1, temp, q);
                k = 1;
            }

            p1 = p1 -> next;
        }

        if(k == 1){
            temp = temp -> next;
            delete_node(temp -> prev -> prev, q);

        }else temp = temp -> next;
    }

    p1 = q -> first;
    k = 0;

    while((p1 -> next != temp) && (k != 1))
    {
        if((n == 1) && (strcmp(temp -> baza -> name, p1 -> baza -> name) < 0)){
            transfer_node(p1, temp, q);
            k = 1;

        }else if((n == 2) && (strcmp(temp -> baza -> country, p1 -> baza -> country) < 0)){
            transfer_node(p1, temp, q);
            k = 1;

        }else if((n == 3) && (temp -> baza -> probability > p1 -> baza -> probability)){
            transfer_node(p1, temp, q);
            k = 1;

        }else if((n == 4) && (temp -> baza -> statistics[0] > p1 -> baza -> statistics[0])){
            transfer_node(p1, temp, q);
            k = 1;

        }else if((n == 5) && (temp -> baza -> statistics[1] > p1 -> baza -> statistics[1])){
            transfer_node(p1, temp, q);
            k = 1;
        }

        p1 = p1 -> next;
    }

    if(k == 1)
        delete_node(temp -> prev, q);

    else if((n == 1) && (strcmp(temp -> baza -> name, p1 -> baza -> name) < 0)){
        transfer_node(p1, temp, q);
        delete_node(temp -> prev, q);

    }else if((n == 2) && (strcmp(temp -> baza -> country, p1 -> baza -> country) < 0)){
        transfer_node(p1, temp, q);
        delete_node(temp -> prev, q);

    }else if((n == 3) && (temp -> baza -> probability > p1 -> baza -> probability)){
        transfer_node(p1, temp, q);
        delete_node(temp -> prev, q);

    }else if((n == 4) && (temp -> baza -> statistics[0] > p1 -> baza -> statistics[0])){
        transfer_node(p1, temp, q);
        delete_node(temp -> prev, q);

    }else if((n == 5) && (temp -> baza -> statistics[1] > p1 -> baza -> statistics[1])){
        transfer_node(p1, temp, q);
        delete_node(temp -> prev, q);
    }
}


//transition function for name
void sort_names(head *q)
{
    if(q -> N > 1){
        sortMega(q, 1);
        output_list(q);
    }
    else
        printf("\nRESULT:\nSorting is not possible\n");
}


//transition function for country
void sort_country(head *q)
{
    if(q -> N > 1){
        sortMega(q, 2);
        output_list(q);
    }
    else
        printf("\nRESULT:\nSorting is not possible\n");
}


//transition function for probability
void sort_probability(head *q)
{
    if(q -> N > 1){
        sortMega(q, 3);
        output_list(q);
    }
    else
        printf("\nRESULT:\nSorting is not possible\n");
}


//transition function for wins
void sort_wins(head *q)
{
    if(q -> N > 1){
        sortMega(q, 4);
        output_list(q);
    }
    else
        printf("\nRESULT:\nSorting is not possible\n");
}


//transition function for draws
void sort_draws(head *q)
{
    if(q -> N > 1){
        sortMega(q, 5);
        output_list(q);
    }
    else
        printf("\nRESULT:\nSorting is not possible\n");
}


//selecting sorting
void sort_cards(head *q)
{
    char s[300] = "Select a field to sort:\n0) back\n1) Name club\n2) Country of the club\n3) probability of the club's passage to the Champions League\n4) wins last 10 matches\n5) count draws last 10 matches\n\ncommand: ";
    int g;
    int k = 0;

    while(k != 1)//selecting a sort field
    {
        CLS;
        g = input(s);

        if((g <= 5) && (g >= 0)){
            if(g == 1){
                k = 1;
                sort_names(q);

            }else if(g == 2){
                k = 1;
                sort_country(q);

            }else if(g == 3){
                k = 1;
                sort_probability(q);

            }else if(g == 4){
                k = 1;
                sort_wins(q);

            }else if(g == 5){
                k  = 1;
                sort_draws(q);

            }else if(g == 0){
                k = 1;
            }
        }
    }
}
