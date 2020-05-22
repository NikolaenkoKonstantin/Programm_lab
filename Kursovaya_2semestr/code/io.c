#include "h_files/io.h"


void spravka()
{
    printf("Author: 9305_NIKOLAENKO_KONSTANTIN");

    printf("\n\nInformation:\n");

    printf("\nThe database is based on the subject of football clubs\n");

    printf("\nCommands:\n");

    printf("\n1) Adding a new entry at the beginning or end of the database\n2) Deleting cards based on field matches\n3) Output the database first or from the end\n4) Search for cards by matching fields\n5) Editing a card by record number\n6) Sorting cards in ascending order\n7) EXIT\n\n");
}


void inform()
{
    printf("1 column - numbering\n");

    printf("2 column - name of the club\n");

    printf("3 column - country of the club\n");

    printf("4 Column - probability of the club's passage to the Champions League\n");

    printf("5 column - wins last 10 matches\n");

    printf("6 column - count draws last 10 matches\n");

    printf("\ndatabase:\n");
}


void *output_node(node *temp, int i)
{
    printf("%2d| %15s | %15s | %6.2lf | %4.lf | %4.lf |\n", i, temp -> baza -> name, temp -> baza -> country, temp -> baza -> probability, temp -> baza -> statistics[0], temp -> baza -> statistics[1]);
}


void output_list(head *q)
{
    if((q -> N) > 1)
    {
        node *temp = NULL;

        temp = q -> first;

        inform();

        printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");

        output_node(temp, 1);
        temp = temp -> next;

        int i = 2;
        while((temp -> next) != NULL)
        {
            printf("_ |_ _ _ _ _ _ _ _ _| _ _ _ _ _ _ _ _ |_ _ _ _ |_ _ _ |_ _ _ |\n");
            output_node(temp, i);
            temp = temp -> next;
            i++;
        }

        printf("_ |_ _ _ _ _ _ _ _ _| _ _ _ _ _ _ _ _ |_ _ _ _ |_ _ _ |_ _ _ |\n");
        output_node(temp, i);
        printf("_ |_ _ _ _ _ _ _ _ _| _ _ _ _ _ _ _ _ |_ _ _ _ |_ _ _ |_ _ _ |\n\n");
    }
    else if(q -> N == 0)
        printf("\ndatabase is empty!\n");
    else if(q -> N  == 1)
    {
        node *temp = NULL;

        temp = q -> first;
        inform();
        printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");
        output_node(temp, 1);
        printf("_ |_ _ _ _ _ _ _ _ _| _ _ _ _ _ _ _ _ |_ _ _ _ |_ _ _ |_ _ _ |\n\n");
    }
}


void output_list_reverse(head *q)
{
    if((q -> N) > 1)
    {
        node *temp = NULL;

        temp = q -> last;

        inform();

        printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");

        output_node(temp, 1);
        temp = temp -> prev;

        int i = 2;
        while((temp -> prev) != NULL)
        {
            printf("_ |_ _ _ _ _ _ _ _ _| _ _ _ _ _ _ _ _ |_ _ _ _ |_ _ _ |_ _ _ |\n");
            output_node(temp, i);
            temp = temp -> prev;
            i++;
        }

        printf("_ |_ _ _ _ _ _ _ _ _| _ _ _ _ _ _ _ _ |_ _ _ _ |_ _ _ |_ _ _ |\n");
        output_node(temp, i);
        printf("_ |_ _ _ _ _ _ _ _ _| _ _ _ _ _ _ _ _ |_ _ _ _ |_ _ _ |_ _ _ |\n\n");
    }
    else if(q -> N == 0)
        printf("\ndatabase is empty!\n");
    else if(q -> N  == 1)
    {
        node *temp = NULL;

        inform();
        temp = q -> first;
        printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");
        output_node(temp, 1);
        printf("_ |_ _ _ _ _ _ _ _ _| _ _ _ _ _ _ _ _ |_ _ _ _ |_ _ _ |_ _ _ |\n\n");
    }
}


void enterFromKeyboard(head *q)
{
    node *temp = NULL;
    int k = 0, f;
    char s[100];

    if((q -> N) == 0)
        temp = create_node(q);
    else
    {
        while(k != 1)
        {
            CLS;
            printf("Choose:\n0) back\n1) add first\n2) add last\n\ncommand:");
            scanf("%s", s);
            f = charToInt(s[0]);
            if(str_len(s) == 0)
            {
                if(f == 2)
                {
                    k = 1;
                    add_last(q);
                    temp = q -> last;
                }
                else if(f == 1)
                {
                    k = 1;
                    add_first(q);
                    temp = q -> first;
                }
                else if(f == 0) {
                    k = 1;
                    CLS;
                }
            }
        }
    }

    if(f != 0){
    printf("\nStructure of an extension to a table:\n");
    printf("Enter the information , otherwise press 'Enter'\n");

    printf("Club: ");
    scanf("%s", (temp -> baza -> name));

    printf("Country: ");
    scanf("%s", (temp -> baza -> country));

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
    CLS;
}


void save_data(head *q, FILE *fileread)
{
    if(q -> N > 0)
    {
        node *temp = NULL;

        temp = q -> first;

        while(temp -> next != NULL)
        {
            fprintf(fileread, "%s|", temp -> baza -> name);

            fprintf(fileread, "%s|", temp -> baza -> country);

            fprintf(fileread, "%.lf|", temp -> baza -> statistics[0]);

            fprintf(fileread, "%.lf|", temp -> baza -> statistics[1]);

            fprintf(fileread, "%.2lf|\n", temp -> baza -> probability);

            temp = temp -> next;
        }

        fprintf(fileread, "%s|", temp -> baza -> name);

        fprintf(fileread, "%s|", temp -> baza -> country);

        fprintf(fileread, "%.lf|", temp -> baza -> statistics[0]);

        fprintf(fileread, "%.lf|", temp -> baza -> statistics[1]);

        fprintf(fileread, "%.2lf|", temp -> baza -> probability);
    }
    else
        fprintf(fileread, " ");
}


void fill_list(head *q)
{
    char message[max];

    FILE *fileread = fopen("data_base.csv", "r");

    if (fileread == NULL)
        perror("data error");
    else
    {
        char mes[max] = "(\_/)";

        fgets(message, max, fileread);

        if(strlen(message) > 3)
        {
            while (strcmp(message, mes) != 0)
            {
                char *str;

                strcpy(mes, message);

                str = &message[0];

                split(str, q);

                fgets(message, max, fileread);
            }
        }

        if (fclose(fileread) == EOF)
            printf("Closing error code: %d\n", errno);
        else
            printf("Closing OK\n");
    }

    output_list(q);

    command_selecting(q);

    FILE *filewrite = fopen("data_base.csv", "w");

    save_data(q, filewrite);

    if (fclose(filewrite) == EOF)
        printf("Closing error code: %d\n", errno);
    else
        printf("Closing OK\n");

}
