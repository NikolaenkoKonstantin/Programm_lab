#include "struct.h"
#include "command_selecting.h"
#include "search.h"
#include "io.h"
#include "split.h"
#include <stdlib.h>
#include <locale.h>

#define max 200

int main()
{
    setlocale(LC_ALL, "Russian");
    person *futClub;
    if ((futClub = malloc(200 * sizeof(person))) == NULL)
    {
        printf("Error memory allocation!");
    }
    else
    {
        int count = fillStruct(futClub);
        count = command_selecting(futClub, count);

        free(futClub);
    }
    return 0;
}
