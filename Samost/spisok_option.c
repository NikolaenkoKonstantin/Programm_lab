#include "spisok_option.h"

//calculating the arithmetic mean of odd numbers
void arithmetic_mean(head *q){
    node *temp = NULL;
    int k = 0;
    float sum = 0;
    temp = q -> first;

    while(temp -> next != NULL){
        if(temp -> znach % 2 != 0){
            sum = sum + temp -> znach;
            k++;
        }
        temp = temp -> next;
    }

    if(temp -> znach % 2 != 0){
            sum = sum + temp -> znach;
            k++;
        }

    printf("%.2lf\n", sum/k);
}


//create head
head *create_head(){
    head *p = NULL;

    p = malloc(sizeof(head));
    if(p){
        p -> N = 0;
        p -> first = NULL;
        p -> last = NULL;
    }

    return p;
}


//create node
node *create_node(head *q){
    node *temp;

    temp = malloc(sizeof(node));

    temp -> next = NULL;
    temp -> id = q -> N + 1;

    q -> N += 1;
    q -> first = temp;
    q -> last = temp;

    return temp;
}


//add node in last
void add_last(head *q){
    node *temp = NULL;

    temp = malloc(sizeof(node));

    temp -> next = NULL;
    temp -> id = ((q -> N) + 1);

    q -> last -> next = temp;
    q -> last = temp;
    q -> N += 1;
}


// delete first node
void delete_first(head *q){
    node *temp = NULL;

    temp = q -> first;

    q -> first = (temp -> next);
    q -> N -= 1;

    if((q -> N) == 1) q -> last = NULL;

    free_node(temp);
}
