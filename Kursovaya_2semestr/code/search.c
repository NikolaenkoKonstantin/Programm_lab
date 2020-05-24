#include "h_files/search.h"

//delete by number
void delete_by_number(head *q){
    /*deletes numbers as long as possible, or you need to enter 0 to go back*/
    char s[100] = "If you want to go back to the menu write 0\nEnter the index: ";
    int f = -2;

    while((f != 0) && (q -> N > 0))
    {
        CLS;
        int l = 0;
        output_list(q);
        f = input(s);

        if((f != 0) && (f <= q -> N) && (f >= 0)) l = -1;

        if(l == -1){
            node *temp = q -> first;

            for(int i = 1; i < f; i++) temp = temp -> next;

            if(temp == q -> first)delete_first(q);
            else delete_node(temp -> prev, q);
        }
    }

    if(q -> N == 0) printf("\n\nDatabase is empty and there is nothing to delete");
}


//delete function
node *delete_matches(head *q, node *temp, node *p){
    /*deletes what it found search_mega*/
    if((q -> first) == temp){
        temp = temp -> next;
        delete_first(q);
    }else{
        temp = temp -> next;
        delete_node(p, q);
    }

    return temp;
}


//Search function
void search_mega(head *q, char *s, int n, float b, float e, int f){
    /*the function is made for both complex search and delete by search
    If the search results indicate that it removes suitable cards from
     the main list, and if the search is complex, the function removes
     cards from the additional list that do not meet the condition*/
    int num = 0;
    node *temp = NULL;
    node *p = NULL;
    temp = q -> first;

    if((q -> N) > 0){
        int t = q -> N;

        for(int i = 1; i <= t; i++){
            if((n == 1) && (strstr((temp -> baza -> name), s) != NULL)){
                temp = delete_matches(q, temp, p);
                num++;

            }else if ((n == 2) && (strstr((temp -> baza -> country), s) != NULL)){
                temp = delete_matches(q, temp, p);
                num++;

            }else if((n == 3) && (((temp -> baza -> probability) >= b) && ((temp -> baza -> probability) <= e))) {
                temp = delete_matches(q, temp, p);
                num++;

            }else if((n == 4) && ((temp -> baza -> statistics[0]) == f)){
                temp = delete_matches(q, temp, p);
                num++;

            }else if((n == 5) && ((temp -> baza -> statistics[1]) == f)){
                temp = delete_matches(q, temp, p);
                num++;

            }else if((n == 6) && (strstr((temp -> baza -> name), s) == NULL)){
                temp = delete_matches(q, temp, p);
                num++;

            }else if ((n == 7) && (strstr((temp -> baza -> country), s) == NULL)){
                temp = delete_matches(q, temp, p);
                num++;

            }else if((n == 8) && (((temp -> baza -> probability) < b) || ((temp -> baza -> probability) > e))) {
                temp = delete_matches(q, temp, p);
                num++;

            }else if((n == 9) && ((temp -> baza -> statistics[0]) != f)){
                temp = delete_matches(q, temp, p);
                num++;

            }else if((n == 10) && ((temp -> baza -> statistics[1]) != f)){
                temp = delete_matches(q, temp, p);
                num++;
            }else{
                p = temp;
                temp = p -> next;
            }
        }
    }

    if((num == 0) && (n < 6)) printf("\nRESULT:\nThere is no match!!!\n\n");
}


//Entering of name
void input_name(head *q, int n)
{
    printf("Enter a name or part of a name: ");
    char s[100];

    scanf("%s", s);
    s[strlen(s)] = '\0';

    search_mega(q, s, n, 1, 1, 1);
}


//Entering of country
void input_country(head *q, int n)
{
    printf("Enter a name or part of a name: ");
    char s[100];

    scanf("%s", s);
    s[strlen(s)] = '\0';

    search_mega(q, s, n, 1, 1, 1);
}


//Entering the number of probability
void input_probability(head *q, int n)
{
    int beg;
    char s3[400] = "Enter the area of probability of passage to the Champions League (Probability in percentage form from 0 to 100)\nfrom: ";
    int l = 0, f;

    while(l != 1){
        f = input(s3);
        if((f != -1) && (f <= 100) && (f >= 0)) l = 1;
    }

    beg = f;
    l = 0;
    char s4[100] = "before: ";

    while(l != 1){
        f = input(s4);
        if((f != -1) && (f <= 100) && (f >= 0)) l = 1;
    }

    int en = f;
    float o = 100;
    float b = beg / o;
    float e = en / o;

    search_mega(q, s3, n, b, e, 1);
}


//Entering the number of wins
void input_wins(head *q, int n)
{
    char s3[100] = "Wins last 10 matches: ";
    int l = 0;
    int k = 0;

    while(l != 1){
        k = input(s3);
        if((k != -1) && (k <= 10) && (k >= 0)) l = 1;
    }

    search_mega(q, s3, n, 1, 1, k);
}


//Entering the number of draws
void input_draws(head *q, int n)
{
    char s3[100] = "Wins last 10 matches: ";
    int l = 0;
    int k = 0;

    while(l != 1){
        k = input(s3);
        if((k != -1) && (k <= 10) && (k >= 0)) l = 1;
    }

    search_mega(q, s3, n, 1, 1, k);
}


//Deleting cards, selecting a field
void deleteCards(head *q)
{
    if(q -> N > 0){
        char s[400] = "Select which field you want to find matches for:\n0) back\n1) by number\n2) Name club\n3) Country of the club\n4) probability of the club's passage to the Champions League\n5) wins last 10 matches\n6) count draws last 10 matches\n\ncommand: ";
        int g;
        int k = 0;

        while(k != 1)//selecting a deletion option
        {
            CLS;
            g = input(s);

            if((g < 7) && (g >= 0)){
                if(g == 1){
                    k = 1;
                    delete_by_number(q);

                }else if(g == 2){
                    k = 1;
                    input_name(q, 1);

                }else if(g == 3){
                    k = 1;
                    input_country(q, 2);

                }else if(g == 4){
                    k = 1;
                    input_probability(q, 3);

                }else if(g == 5){
                    k  = 1;
                    input_wins(q, 4);

                }else if(g == 6){
                    k = 1;
                    input_draws(q, 5);

                }else if(g == 0) k = 1;
            }
        }
    }else printf("\n\nDatabase is empty and there is nothing to delete");
}


//function selection
void choose(head *q1, char *s, int n){
    int u = 0;

    while(u != 1)////selecting fields for complex search
    {
        CLS;
        int f = input(s);

        if((f > 0) && (f < 3)){
            if(f == 2) u = 1;
            else if(f == 1){
                u = 1;
                if (n == 1) input_name(q1, 6);
                else if (n == 2) input_country(q1, 7);
                else if (n == 3) input_probability(q1, 8);
                else if (n == 4) input_wins(q1, 9);
                else if (n == 5) input_draws(q1, 10);
            }
        }
    }
}


//search combination
void search_match(head *q)
{
    head *q1 = create_head();
    copy_list(q1, q);

    char s1[100] = "Search by name:\n1) Yes\n2) No\n\nCommand: ";
    choose(q1, s1, 1);

    char s2[100] = "Search by country:\n1) Yes\n2) No\n\nCommand: ";
    choose(q1, s2, 2);

    char s3[100] = "Search by probability:\n1) Yes\n2) No\n\nCommand: ";
    choose(q1, s3, 3);

    char s4[100] = "Search by wins:\n1) Yes\n2) No\n\nCommand: ";
    choose(q1, s4, 4);

    char s5[100] = "Search by draws:\n1) Yes\n2) No\n\nCommand: ";
    choose(q1, s5, 5);

    CLS;

    if(q1 -> N != 0) output_list(q1);
    else printf("\nRESULT:\nNo matches!!!\n\n");

    if((q1-> N) == 1) free_head(q1);
    else if((q1 -> N) > 1) free_list(q1);
    else if ((q1-> N) == 0) free(q1);
}
