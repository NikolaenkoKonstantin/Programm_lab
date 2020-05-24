#include <stdio.h>
#include <stdlib.h>
#include "h_files\option_With_LIst.h"
#include "h_files\struct.h"
#include "h_files\io.h"


int main()
{
    head *q = NULL; //created head
    q = create_head();

    fill_list(q); //reading and main operation of the program

    //clean
    if((q -> N) == 1) free_head(q);
    else if((q -> N) > 1) free_list(q);
    else if ((q -> N) == 0) free(q);

    printf("\nEND\n");

    return 0;
}
