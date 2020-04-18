#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "struct.h"
#include "spisok_option.h"
#include "free_list.h"
#include "io.h"
#include "search.h"
#include "command_selecting.h"

int main()
{
    head *q = NULL;
    q = create_head();

    fill_list(q);
    command_selecting(q);

    if((q -> N) == 1) free_head(q);
    else if((q -> N) > 1) free_list(q);
    else if ((q -> N) == 0) free(q);

    printf("\nEND");

    return 0;
}
