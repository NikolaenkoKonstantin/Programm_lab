#include "h_files/edit.h"

//editing in draws
void edit_draws(node *temp)
{
    int l = 0;
    char s[100] = "Count draws last 10 matches(draws + wins <= 10): ";

    while(l != 1)
    {
        int f = 0;
        f = input(s);//change is being made

        if(f != -1)
            if((f <= (10 - temp -> baza -> statistics[0])) && (f >= 0)){
                l = 1;
                temp -> baza -> statistics[1] = f;
            }
    }
}


//editing in wins
void edit_wins(node *temp)
{
    int l = 0;
    char s2[100] = "Wins last 10 matches: ";

    while(l != 1)
    {
        int f = 0;
        f = input(s2);//change is being made

        if(f != -1)
            if((f <= 10) && (f >= 0)){
                l = 1;
                temp -> baza -> statistics[0] = f;
            }
    }
}


//edit the fields in the card
void edit_card(head *q)
{
    int f = -2;

    while(f != 0)
    {
        CLS;
        output_list(q);
        char str[100] = "If you want to go back to the menu write 0\nEnter the number of the card you want to edit:";

        f = input(str);//enter the card number

        node *temp = q -> first;

        if(f != -1)
            if(f <= q -> N)
                for(int i = 1; i < f; i++)//search for the desired node
                    temp = temp -> next;

    if(f > 0)
    {
        int g;
        int k = 0;

        while(k != 1)//edit
        {
            CLS;
            printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");
            output_node(temp, 1);
            printf("_ |_ _ _ _ _ _ _ _ _ _ | _ _ _ _ _ _ _ _ |_ _ _ _ |_ _ _ |_ _ _ |\n\n");

            char s4[300] = "Select the field to edit:\n1) Name club\n2) Country of the club\n3) Wins and draws\n\ncommand: ";
            g = input(s4);//selecting an edit field

            if((g >= 0) && (g <= 3))
            {
                if(g == 0)k = 1;

                else if(g == 1){
                    k = 1;
                    char s9[10];
                    printf("Club: ");//change is being made
                    fgets(s9, 10, stdin);
                    fgets((temp -> baza -> name), 20, stdin);
                    temp -> baza -> name[strlen(temp -> baza -> name) - 1] = '\0';

                }else if(g == 2){
                    char s9[10];
                    k = 1;
                    printf("Country: ");//change is being made
                    fgets(s9, 10, stdin);
                    fgets((temp -> baza -> country), 20, stdin);
                    temp -> baza -> country[strlen(temp -> baza -> country) - 1] = '\0';

                }else if(g == 3){
                    k = 1;
                    edit_wins(temp);
                    edit_draws(temp);
                    temp -> baza -> probability = (temp -> baza -> statistics[0] * 2 + temp -> baza -> statistics[1]) / 20;
                }
            }
        }
    }
    }
}
