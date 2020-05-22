#include "h_files/option_With_List.h"

void malloc_node(node *temp)
{
    temp -> baza = malloc(sizeof(fut));
    temp -> baza -> name = malloc(30 * sizeof(char));
    temp -> baza -> country = malloc(30 * sizeof(char));
}


head *create_head()
{
    head *p = NULL;

    p = malloc(sizeof(head));
    if(p)
    {
        p -> N = 0;
        p -> first = NULL;
        p -> last = NULL;
    }

    return p;
}


node *create_node(head *q)
{
    node *temp;

    temp = malloc(sizeof(node));
    malloc_node(temp);

    temp -> prev = NULL;
    temp -> next = NULL;
    temp -> id = q -> N + 1;

    q -> N += 1;
    q -> first = temp;
    q -> last = temp;

    return temp;
}


void add_last(head *q)
{
    node *temp = NULL;

    temp = malloc(sizeof(node));
    malloc_node(temp);

    temp -> next = NULL;
    temp -> id = ((q -> N) + 1);
    temp -> prev = q -> last;

    q -> last -> next = temp;
    q -> last = temp;
    q -> N += 1;
}


node *add_first(head *q)
{
    node *temp;

    temp = malloc(sizeof(node));
    malloc_node(temp);

    temp -> prev = NULL;
    temp -> next = (q -> first);
    temp -> id = ((q -> N) + 1);

    q -> first -> prev = temp;
    q -> N += 1;
    q -> first = temp;

    return temp;
}


void delete_first(head *q)
{
    node *temp = NULL;

    temp = q -> first;

    if(temp -> next != NULL)
    {
        q -> first = temp -> next;
        temp -> next -> prev = NULL;
    }
    q -> N -= 1;

    if((q -> N) == 0)
        q -> last = NULL;

    free_node(temp);
}


void delete_node(node *temp, head *q)
{
    q -> N -= 1;
    temp = temp -> next;

    if((temp -> next) != NULL)
    {
        temp -> next -> prev = temp -> prev;
        temp -> prev -> next = temp -> next;
    }
    else
    {
        q -> last -> prev -> next = NULL;
        q -> last = q -> last -> prev;
    }

    free_node(temp);
}


node *copy_node(node *p, node *temp)
{
    temp -> id = p -> id;

    strcpy(temp -> baza -> name, p -> baza -> name);

    strcpy(temp -> baza -> country, p -> baza -> country);

    temp -> baza -> probability =  p -> baza -> probability;

    temp -> baza -> statistics[0] =  p -> baza -> statistics[0];

    temp -> baza -> statistics[1] =  p -> baza -> statistics[1];

    return temp;
}


void transfer_node(node *p, node *temp, head *q)
{
    int f = 0;
    node *p1 = malloc(sizeof(node));
    node *p3;

    if(p == q -> first)
    {
        f = 1;
        p3 = add_first(q);
    }

    q -> N += 1;
    malloc_node(p1);
    p1 = copy_node(temp, p1);

    p1 -> next = p;
    p1 -> prev = p -> prev;
    p1 -> prev -> next = p1;

    p -> prev = p1;

    if(f == 1){
        delete_first(q);
        free(p3);
    }
}


void copy_list(head *q1, head *q)
{
    node *temp1 = create_node(q1);;
    node *temp = q -> first;

    while(temp -> next != NULL)
    {
        temp1 = copy_node(temp, temp1);

        temp = temp -> next;
        add_last(q1);
        temp1 = temp1 -> next;
    }

    temp1 = copy_node(temp, temp1);
}
