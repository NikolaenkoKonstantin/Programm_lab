#include "h_files/io.h"

void inform()
{
    printf("\n1 column - numbering\n");
    printf("2 column - name of the club\n");
    printf("3 column - country of the club\n");
    printf("4 Column - probability of the club's passage to the Champions League\n");
    printf("5 column - wins last 10 matches\n");
    printf("6 column - count draws last 10 matches\n");
    printf("\ndatabase:\n");
}


void *output_node(node *temp){
    printf("%2d| %15s | %15s | %6.2lf | %4.lf | %4.lf\n", temp -> id, temp -> baza -> name, temp -> baza -> country, temp -> baza -> probability, temp -> baza -> statistics[0], temp -> baza -> statistics[1]);
}


void output_list(head *q){
    if((q -> N) > 0)
    {
        node *temp = NULL;

        temp = q -> first -> next;

        inform();

        while((temp -> next) != (q -> first))
        {
            output_node(temp);
            temp = temp -> next;
        }

        output_node(temp);
        output_node(q -> first);
    }
    else printf("\ndatabase is empty!\n");
}


void enterFromKeyboard(head *q)
{
    node *temp = NULL;
    if((q -> N) == 0) temp = create_node(q);
    else {
        add_last(q);
        temp = q -> first;
    }

    printf("\nStructure of an extension to a table:\n");
    printf("Enter the information , otherwise press 'Enter'\n");

    printf("Club: ");
    scanf("%s", (temp -> baza -> name));

    printf("Country: ");
    scanf("%s", (temp -> baza -> country));

    printf("Wins last 10 matches: ");
    scanf("%f", &(temp -> baza -> statistics[0]));

    printf("Count draws last 10 matches: ");
    scanf("%f", &(temp -> baza -> statistics[1]));

    temp -> baza -> probability = (temp -> baza -> statistics[0] * 2 + temp -> baza -> statistics[1]) / 20;
}


void fill_list(head *q){
    char message[max];

    FILE *fileread = fopen("input.csv", "r");

    if (fileread == NULL) perror("data error");
    else
    {
        char mes[max];

        fgets(message, max, fileread);

        while (strcmp(message, mes) != 0)
        {
            char *str;

            strcpy(mes, message);

            str = &message[0];

            split(str, q);

            fgets(message, max, fileread);
        }

        if (fclose(fileread) == EOF) printf("Closing error code: %d\n", errno);
        else printf("Closing OK\n");
    }

    output_list(q);
}
