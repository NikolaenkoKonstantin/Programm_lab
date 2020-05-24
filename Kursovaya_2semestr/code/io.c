#include "h_files/io.h"

//for beauty
void title(){
    printf("  $$$   $$$$    $$$   $$$$   $$$$$ \n");
    printf(" $      $   $  $   $  $   $    $   \n");
    printf("  $$$   $$$$   $   $  $$$$     $   \n");
    printf("     $  $      $   $  $ $      $   \n");
    printf("  $$$   $       $$$   $  $     $ \n\n");
}


//screen delay
void delay(){
    char s[100];
    printf("\n\nTo continue write whatever you want... ");
    fgets(s, 10, stdin);
    fgets(s, 10, stdin);
}


//Enter numbers
int input(char *s1)
{
    int f = 0, u = 0;
    char s[100];
//if everything is normal, an integer greater than 0 is returned, otherwise if the string contains a non-numeric character, the value -1 is returned
    printf("%s", s1);
    scanf("%100s", s);
    int t = strlen(s);

    for(int i = 0; i < t; i++ )
    {
        if((charToInt(s[i]) <= 9) && (charToInt(s[i]) >= 0))
            f = f * 10 + charToInt(s[i]);
        else{
            u = -1;
            i = strlen(s) - 1;
        }
    }

    if(u == -1) f = u;

    return f;
}


//reference
void spravka()
{
    CLS;
    printf("Author: 9305_NIKOLAENKO_KONSTANTIN");

    printf("\n\nInformation:\n");

    printf("\nThe database is based on the subject of football clubs\n");

    printf("\nCommands:\n");

    printf("\n1) Adding a new entry at the beginning or end of the database\n2) Deleting cards based on field matches\n3) Output the database first or from the end\n4) Search for cards by matching fields\n5) Editing a card by record number\n6) Sorting cards in ascending order\n7) Save card index\n8) EXIT\n\n");

    printf("Fields:\n\n1 column - numbering\n");

    printf("2 column - name of the club\n");

    printf("3 column - country of the club\n");

    printf("4 Column - probability of the club's passage to the Champions League\n");

    printf("5 column - wins last 10 matches(wins + draws <= 10)\n");

    printf("6 column - count draws last 10 matches(wins + draws <= 10)\n");
}


//information to the database
void inform()
{
    printf("1 column - numbering\n");

    printf("2 column - name of the club\n");

    printf("3 column - country of the club\n");

    printf("4 Column - probability of the club's passage to the Champions League\n");

    printf("5 column - wins last 10 matches\n");

    printf("6 column - count draws last 10 matches\n");

    printf("\nDatabase:\n");
}


//output node
void *output_node(node *temp, int i)
{
    printf("%2d| %18s | %15s | %6.2lf | %4.lf | %4.lf |\n", i, temp -> baza -> name, temp -> baza -> country, temp -> baza -> probability, temp -> baza -> statistics[0], temp -> baza -> statistics[1]);
}


//starting the list from the beginning
void output_list(head *q)
{
    if((q -> N) > 1)
    {
        node *temp = NULL;
        temp = q -> first;
        inform();
        printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");

        output_node(temp, 1);
        temp = temp -> next;

        int i = 2;
        while((temp -> next) != NULL)
        {
            printf("_ |_ _ _ _ _ _ _ _ _ _ | _ _ _ _ _ _ _ _ |_ _ _ _ |_ _ _ |_ _ _ |\n");
            output_node(temp, i);
            temp = temp -> next;
            i++;
        }

        printf("_ |_ _ _ _ _ _ _ _ _ _ | _ _ _ _ _ _ _ _ |_ _ _ _ |_ _ _ |_ _ _ |\n");
        output_node(temp, i);
        printf("_ |_ _ _ _ _ _ _ _ _ _ | _ _ _ _ _ _ _ _ |_ _ _ _ |_ _ _ |_ _ _ |\n\n");
    }
    else if(q -> N == 0)
        printf("\ndatabase is empty!\n");
    else if(q -> N  == 1)
    {
        node *temp = NULL;
        temp = q -> first;
        inform();

        printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");
        output_node(temp, 1);
        printf("_ |_ _ _ _ _ _ _ _ _ _ | _ _ _ _ _ _ _ _ |_ _ _ _ |_ _ _ |_ _ _ |\n\n");
    }
}


//list output from the end
void output_list_reverse(head *q)
{
    if((q -> N) > 1)
    {
        node *temp = NULL;
        temp = q -> last;
        inform();
        printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");

        output_node(temp, 1);
        temp = temp -> prev;

        int i = 2;
        while((temp -> prev) != NULL)
        {
            printf("_ |_ _ _ _ _ _ _ _ _ _ | _ _ _ _ _ _ _ _ |_ _ _ _ |_ _ _ |_ _ _ |\n");
            output_node(temp, i);
            temp = temp -> prev;
            i++;
        }

        printf("_ |_ _ _ _ _ _ _ _ _ _ | _ _ _ _ _ _ _ _ |_ _ _ _ |_ _ _ |_ _ _ |\n");
        output_node(temp, i);
        printf("_ |_ _ _ _ _ _ _ _ _ _ | _ _ _ _ _ _ _ _ |_ _ _ _ |_ _ _ |_ _ _ |\n\n");
    }
    else if(q -> N == 0)
        printf("\ndatabase is empty!\n");
    else if(q -> N  == 1)
    {
        node *temp = NULL;
        inform();
        temp = q -> first;

        printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");
        output_node(temp, 1);
        printf("_ |_ _ _ _ _ _ _ _ _ _ | _ _ _ _ _ _ _ _ |_ _ _ _ |_ _ _ |_ _ _ |\n\n");
    }
}


//entering a card using the keyboard
void enterFromKeyboard(head *q)
{
    node *temp = NULL;
    int k = 0, f;

    if((q -> N) == 0)
        temp = create_node(q);
    else{
        while(k != 1)
        {//choice of adding
            CLS;
            char s1[100] = "Choose:\n0) back\n1) add first\n2) add last\n\ncommand:";
            f = input(s1);

            if((f >= 0) && ( f <= 2))
            {
                if(f == 2){
                    k = 1;
                    add_last(q);
                    temp = q -> last;

                }else if(f == 1){
                    k = 1;
                    add_first(q);
                    temp = q -> first;

                }else if(f == 0) k = 1;
            }
        }
    }

    if(f != 0)
    {//information input
        printf("\nStructure of an extension to a table:\n");
        printf("Enter the information , otherwise press 'Enter'\n");
        printf("Club: ");

        char s[10];

        fgets(s, 10, stdin);//enter the name of the club
        fgets((temp -> baza -> name), 20, stdin);
        temp -> baza -> name[strlen(temp -> baza -> name) - 1] = '\0';

        printf("Country: ");//enter the country name
        fgets((temp -> baza -> country), 20, stdin);
        temp -> baza -> country[strlen(temp -> baza -> country) - 1] = '\0';

        int l = 0;

        while(l != 1)//enter the number of wins
        {
            char s2[100] = "Wins last 10 matches: ";
            f = input(s2);

            if((f != -1) && (f <= 10) && (f >= 0)){
                l = 1;
                temp -> baza -> statistics[0] = f;
            }
        }

        l = 0;

        while(l != 1)//enter the number of draws
        {
            char s3[100] = "Count draws last 10 matches(draws + wins <= 10): ";
            f = input(s3);

            if((f != -1) && (f <= (10 - temp -> baza -> statistics[0])) && (f >= 0)){
                l = 1;
                temp -> baza -> statistics[1] = f;
            }
        }

        temp -> baza -> probability = (temp -> baza -> statistics[0] * 2 + temp -> baza -> statistics[1]) / 20;
    }
}


//saving to a file
void save_file(head *q)
{
    FILE *filewrite = fopen("data_base.csv", "w");//open file

    if (filewrite == NULL)
        perror("data error");
    else{
        if(q -> N > 0)
        {
            node *temp = NULL;
            temp = q -> first;
            int t = q -> N;

            for(int i = 1; i <= t; i++)//printing a list to a file
            {
                fprintf(filewrite, "%s|", temp -> baza -> name);

                fprintf(filewrite, "%s|", temp -> baza -> country);

                fprintf(filewrite, "%.lf|", temp -> baza -> statistics[0]);

                fprintf(filewrite, "%.lf|", temp -> baza -> statistics[1]);

                fprintf(filewrite, "%.2lf|\n", temp -> baza -> probability);

                temp = temp -> next;
            }
        }else fprintf(filewrite, " ");//if the list is empty, output a space

        if (fclose(filewrite) == EOF) printf("Closing error code: %d\n", errno);
        else printf("Closing OK\n");
    }
}


//translation from char to int
int charToInt(char numeric){
    return numeric - 48;
}


//splitting a line
void split(char *mes, head *q)
{
    node *temp = NULL;

    if((q -> N) == 0) temp = create_node(q);
    else{
        add_last(q);
        temp = q -> last;
    }

    char *s;
    int n = 0;

    if ((s = malloc(20 * sizeof(char))) == NULL)
        puts("Error memory allocation!");
    else{
        int k = 0;

        for (size_t j = 0; j < strlen(mes); j++)
        {
            if ((mes[j] != '|')){//adding characters up to the "|" separator character
                s[k] = mes[j];
                k++;

            }else{//Assign this string to the corresponding field
                s[k] = '\0';

                if (n == 0) strcpy(temp -> baza -> name, s);

                else if (n == 1) strcpy(temp -> baza -> country, s);

                else if (n == 2) temp -> baza -> statistics[0] = charToInt(s[k - 1]);

                else if (n == 3) temp -> baza -> statistics[1] = charToInt(s[k - 1]);

                n++;
                k = 0;
            }
        }
        //calculating the probability
        temp -> baza -> probability = (temp -> baza -> statistics[0] * 2 + temp -> baza -> statistics[1]) / 20;
        free(s);
    }
}


//reading from a file
void fill_list(head *q)
{
    char message[max];
    FILE *fileread = fopen("data_base.csv", "r");//open file

    if (fileread == NULL)
        perror("data error");
    else{
        char mes[max] = "Kostya\0";

        fgets(message, max, fileread);

        if(strlen(message) > 3){//reading the string until it is equal to the previous one
            while (strcmp(message, mes) != 0)
            {
                char *str;

                strcpy(mes, message);

                str = &message[0];

                split(str, q);

                fgets(message, max, fileread);
            }
        }

        if (fclose(fileread) == EOF) printf("Closing error code: %d\n", errno);
        else printf("Closing OK\n");
    }

    menu(q);//calling the menu
}


//menu
void menu(head *q)
{
    char s[400] = "Select a command:\n0) Reference\n1) Add\n2) Delete\n3) database\n4) Search\n5) Edit card\n6) Sort cards\n7) Save card index\n8) Exit\n\nCommand:";
    int f = 9;
    int d = 0;

    while(f != 8)
    {
        if(d == 1) delay();//delay before returning to the menu
        CLS;
        title();

        d = 1;
        f = input(s);//input of commands

        if((f < 8) && (f >= 0))
        {
            if(f == 0) spravka();

            else if(f == 1) enterFromKeyboard(q);

            else if(f == 2) deleteCards(q);

            else if(f == 3){
                int g, k = 0;

                while(k != 1){
                    CLS;
                    char s4[100] = "Select the printing method:\n0) back\n1) At first\n2) From the end\n\nCommand: ";
                    g = input(s4);//entering a command for the database output method

                    if((g >= 0) && (g <= 2)){
                        if(g == 1){
                            k = 1;
                            output_list(q);

                        }else if(g == 2){
                            k = 1;
                            output_list_reverse(q);

                        }else if(g == 0) k = 1;
                    }
                }
            }
            else if(f == 4) search_match(q);

            else if(f == 5) edit_card(q);

            else if(f == 6) sort_cards(q);

            else if(f == 7) save_file(q);
        }
    }
}

