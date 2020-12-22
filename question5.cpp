// QUESTION 5: Find the Nth node from the end of the linked list. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
a -> z -> d -> b -> c -> e
N = 1 OUTPUT e
N = 2 OUTPUT c
N = 3 OUTPUT b
N = 4 OUTPUT d
N = 5 OUTPUT z
N = 6 OUTPUT a
*/

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

void search_nth (int n)
{
    int size = 0;
    node* current = head;
    current = head;

    if (!head)
    {
        return;
    }

    while (current)
    {
        current = current -> next;
        size++;
    }

    // cek kalau n < size single linked list supaya kalau benar, berarti dia tidak perlu melakukan apa-apa.
    if (size < n)
    {
        return;
    }

    for (int j = 0; j < size - n + 1; j++)
    {
        current = current -> next;
    }

    printf("%d\n", current -> number);
}

int main()
{
    int n, linked_list;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &linked_list);
        push_mid(linked_list);
    }

    search_nth(n);

    return 0;
}

// Learning Resources:
// 1. https://www.geeksforgeeks.org/search-an-element-in-a-linked-list-iterative-and-recursive/
// 2. https://codeforwin.org/2018/05/c-program-to-search-an-element-in-linked-list.html
// 3. https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/