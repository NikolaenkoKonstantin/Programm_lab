#include "split.h"

int str_len(char *s){
    int r = 0;
    while(s[r] != ';') r++;
    r--;
    return r;
}


int charToInt(char numeric)
{
    return numeric - 48;
}


void split(char *mes, head *q){
    node *temp = NULL;

    int i = 0;
    int znak;
    if((q -> N) == 0) temp = create_node(q);
    else{
        add_last(q);
        temp = q -> last;
    }

    temp -> znach = 0;

    if(mes[0] == '-'){
        i = 1;
        znak = -1;
    }
    else znak = 1;

    while(mes[i] != ';'){
        temp -> znach = temp -> znach * 10 + charToInt(mes[i]);
        i++;
    }
    temp -> znach = temp -> znach * znak;
}
