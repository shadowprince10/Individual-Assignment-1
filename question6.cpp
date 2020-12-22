// QUESTION 6: Given a sorted (ascending) linked list, manipulate it to become a sorted (descending) linked list.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int number;
    node *next = NULL;
}*head, *tail;

node *create_new_node(int number)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node -> number = number;
    new_node -> next = NULL;
    return new_node;
}

void push_head(int number)
{
    node *temp = create_new_node(number);

    if (!head)
    {
        head = tail = temp;
    }

    else
    {
        temp -> next = head;
        temp = head;
    }
}

void push_tail(int number)
{
    node *temp = create_new_node(number);

    if (!head)
    {
        head = tail = temp;
    }

    else
    {
        tail -> next = temp;
        temp = tail;
    }
    
}

void push_mid(int number)
{
    node* temp = create_new_node(number);

    if (!head)
    {
        head = tail = temp;
    }

    else if (number < head -> number)
    {
        push_head(number);
    }

    else if (number > tail -> number)
    {
        push_tail(number);
    }

    else
    {
        node *current = head;
        
        while (current && current -> next -> number < number)
        {
            current = current -> next;
        }

        temp -> next = current -> next;
        current -> next = temp;
    }
}

void search_index (int n, int target)
{
    node* current = head;
    node* temp = head;
    current = head;

    if (!head)
    {
        return;
    }

    n -= target;

    if (n < 0)
    {
        return;
    }

    while (n != 0)
    {
        current = current -> next;
        n--;
    }

    printf("%d\n", current -> number);
}

void print_singleLL()
{
    node *temp = head;

    if (!head)
    {
        return;
    }

    while (temp)
    {
        printf("%d\n", temp -> number);
        temp = temp -> next;
    }
    puts("");
}


// Learning Resources:
