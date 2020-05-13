#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "struct.h"
#include "spisok_option.h"
#include "free_list.h"
#include "io.h"

int main()
{
    head *q = NULL;
    q = create_head();

    fill_list(q);

    printf("\nWant to add 1 item?\nIf Yes then write 1 otherwise 2\nCommand:");
    int g;
    scanf("%d", &g);
    if(g == 1) enterFromKeyboard(q);

    printf("\nWant to delete 1 item?\nIf Yes then write 1 otherwise 2\nCommand:");
    int h;
    scanf("%d", &h);
    if(h == 1) delete_first(q);

    printf("\n");

    output_list(q);

    arithmetic_mean(q);

    FILE *filewrite = fopen("output.csv", "w");

    save_data(q, filewrite);

    if (fclose(filewrite) == EOF) printf("Closing error code: %d\n", errno);
    else printf("Closing OK\n");

    if((q -> N) == 1) free_head(q);
    else if((q -> N) > 1) free_list(q);
    else if ((q -> N) == 0) free(q);

    printf("\nEND");

    return 0;
}
