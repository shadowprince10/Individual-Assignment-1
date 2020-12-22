// QUESTION 2: Given a linked list, determine whether it has a cycle. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int number;
    struct node* next; // untuk define pointer ke node selanjutnya
}*head, *tail;

node *create_node(int number)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node -> number = number;
    new_node -> next = NULL;
    return new_node;
}

// INGAT! single linked list tidak ada prev.
void push_head(int number)
{
    node *temp = create_node(number); // untuk membuat node baru

    if (!head) // kalau linked list kosong
    {
        head = tail = temp; // maka otomatis temp alias node baru adalah head sekaligus tail
    }

    else // kalau linked list memiliki >= 1 node
    {
        temp -> next = head; // membuat link antara temp dengan head
        head = temp; // setelah itu, baru bisa memindahkan head ke temp
    }
}

void push_tail(int number) // sama seperti push head, hanya berbeda di else-nya
{
    node *temp = create_node(number);

    if (!head)
    {
        head = tail = temp;
    }

    else
    {
        tail -> next = temp; // membuat link antara temp dan tail
        tail = temp; // setelah itu, baru bisa menjadikan temp alias node baru adalah tail
    }
}

void push_mid(int number)
{
    node* temp = create_node(number);

    if (!head)
    {
        head = tail = temp;
    }

    else if (number < head -> number) // apabila number lebih kecil dari number milik head, otomatis kita push head
    {
        push_head(number);
    }

    else if (number > tail -> number)
    {
        push_tail(number);
    }

    else
    {
        node* current = head; // triknya adalah membuat node baru current (sementara) untuk mengecek lokasi / posisi mana dia bisa meletakkan number
        
        while (current && current -> next -> number < number) // pakai looping while biar cek terus selama number yang kita insert lebih besar dari number dari node setelah node sementara current 
        {
            current = current -> next;
        }

        // kalau sudah keluar dari looping while atau kalau number yang diinsert telah menjadi lebih kecil daripada number dari node setelah node sementara current, akan menjalankan program ini:
        temp -> next = current -> next; // hubungkan node ke data selanjutnya dari current melalui current.
        current -> next = temp;
    }
}

bool check_cycle(node* linked_list)
{
    struct node *fast_pointer = head;
    struct node *slow_pointer = head;

    while (fast_pointer && slow_pointer && fast_pointer -> next)
    {
        slow_pointer = slow_pointer -> next;
        fast_pointer = fast_pointer -> next -> next;
        if (slow_pointer == fast_pointer)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int size, linked_list;
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &linked_list);
        push_mid(linked_list);
    }

    if (check_cycle(head) == true)
    {
        puts("It has a cycle");
    }

    else
    {
        puts("It has no cycle");
    }
    

    
}



// Learning Resources:
