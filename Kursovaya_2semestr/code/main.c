#include <stdio.h>
#include <stdlib.h>
#include "h_files\option_With_LIst.h"
#include "h_files\struct.h"
#include "h_files\free_List.h"
#include "h_files\io.h"


int main()
{
    head *q = NULL;
    q = create_head();

    fill_list(q);

    if((q -> N) == 1)
        free_head(q);
    else if((q -> N) > 1)
        free_list(q);
    else if ((q -> N) == 0)
        free(q);

    printf("\nEND");

    return 0;
}
