#include "io.h"

//output a node to stdin
void output_node(node *temp){
    printf("%4.d| %4d|\n", temp -> id, temp -> znach);
}


//list output in stdin
void output_list(head *q){
    if((q -> N) > 0)
    {
        FILE *filewrite = fopen("output.csv", "w");

        node *temp = NULL;

        temp = q -> first;

        while((temp -> next) != NULL)
        {
            output_node(temp);
            temp = temp -> next;
        }
        output_node(temp);
    }
    else printf("\ndatabase is empty!\n");
}


//Entering information in the node
void enterFromKeyboard(head *q)
{
    node *temp = NULL;

    if((q -> N) == 0) temp = create_node(q);
    else
    {
        add_last(q);
        temp = q -> last;
    }

    int k;
    printf("\nEnter any value:");
    scanf("%d", &k);
    temp -> znach = k;
}


//Saving the list to a new output file
void save_data(head *q, FILE *fileread){
    node *temp = NULL;

    temp = q -> first;

    while(temp -> next != NULL)
    {
        if(temp -> znach % 2 != 0)
            fprintf(fileread, "%d;\n", temp -> znach);

        temp = temp -> next;
    }

    if(temp -> znach % 2 != 0)
        fprintf(fileread, "%d;", temp -> znach);

}


//Reading information from the input file
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
