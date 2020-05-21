#include "h_files/command_selecting.h"

void command_selecting(head *q)
{
    char s[100];
    int f = 8;

    while(f != 7)
    {
        printf("Select a command:\n0) Spravka\n1) Add\n2) Delete by search\n3) database\n4) Search\n5) Edit card\n6) Sort cards\n7) Exit\n\nCommand:");
        scanf("%s", s);
        f = charToInt(s[0]);

        system("cls");

        if(str_len(s) == 0)
        {
            if(f == 0)
                spravka();
            else if(f == 1)
                enterFromKeyboard(q);
            else if(f == 2)
                search_matches(q);
            else if(f == 3)
            {
                char s1[100];
                int g;
                int k = 0;

                printf("Select the printing method:\n1) At first\n2) From the end\n\nCommand:");

                fgets(s1, 100, stdin);
                g = charToInt(s1[0]);

                if(str_len(s1) == 1)
                {
                    if(g == 1)
                    {
                        k = 1;
                        output_list(q);
                    }
                    else if(g == 2)
                    {
                        k = 1;
                        output_list_reverse(q);
                    }
                }

                while(k != 1)
                {
                    system("cls");
                    printf("Select the printing method:\n1) At first\n2) From the end\n\nCommand:");

                    scanf("%s", s1);
                    g = charToInt(s1[0]);

                    if(str_len(s1) == 0)
                    {
                        if(g == 1)
                        {
                            k = 1;
                            output_list(q);
                        }
                        else if(g == 2)
                        {
                            k = 1;
                            output_list_reverse(q);
                        }
                    }
                }
            }
            else if(f == 4)
                search_match(q);
            else if(f == 5)
                edit_card(q);
            else if(f == 6)
                sort_cards(q);
        }
    }
}
