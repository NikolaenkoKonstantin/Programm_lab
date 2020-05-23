#include "h_files/command_selecting.h"

void command_selecting(head *q)
{
    char s[100];
    int f = 9;

    while(f != 8)
    {
        printf("Select a command:\n0) Reference\n1) Add\n2) Delete by search\n3) database\n4) Search\n5) Edit card\n6) Sort cards\n7) Save card index\n8) Exit\n\nCommand:");
        scanf("%s", s);
        f = charToInt(s[0]);

        CLS;

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

                while(k != 1)
                {
                    CLS;
                    printf("Select the printing method:\n0) back\n1) At first\n2) From the end\n\nCommand:");

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
                        else if(g == 0)
                        {
                            k = 1;
                            CLS;
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
            else if(f == 7)
            {
                FILE *filewrite = fopen("data_base.csv", "w");

                save_data(q, filewrite);

                if (fclose(filewrite) == EOF)
                    printf("Closing error code: %d\n", errno);
                else
                    printf("Closing OK\n");
            }
        }
    }
}
