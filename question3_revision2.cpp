#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// QUESTION 3: 3. Find the middle element of a linked list.

// In order to find middle element of linked list in one pass, you need to maintain two pointers, one increment at each node while other increments after two nodes at a time. By having this arrangement, when first pointer reaches end, second pointer will point to middle element of linked list.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int number;
    node *next;
}*head, *tail;

node *create_new_node(int number)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node -> number = number;
    new_node -> next = NULL; 
    return new_node;
}

// INGAT! single linked list tidak ada prev.
void push_head(int number)
{
    node *temp = create_new_node(number); // untuk membuat node baru

    if (!head) // kalau linked list kosong
    {
        head = tail = temp; // maka otomatis temp alias node baru adalah head sekaligus tail
    }

    else // kalau linked list memiliki >= 1 node
    {
        temp -> next = head; // membuat link antara temp dengan head
        temp = head; // setelah itu, baru bisa memindahkan head ke temp
    }
}

void push_tail(int number) // sama seperti push head, hanya berbeda di else-nya
{
    node *temp = create_new_node(number);

    if (!head)
    {
        head = tail = temp;
    }

    else
    {
        tail -> next = temp; // membuat link antara temp dan tail
        temp = tail; // setelah itu, baru bisa menjadikan temp alias node baru adalah tail
    }
}

void push_mid(int number)
{
    node* temp = create_new_node(number);

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

// FLOYD'S ALGORITHM
int search_mid()
{
    struct node *fast_pointer = head;
    struct node *slow_pointer = head;

    if (head == NULL)
    {
        return;
    }

    while (fast_pointer && slow_pointer && fast_pointer -> next)
    {
        slow_pointer = slow_pointer -> next;
        fast_pointer = fast_pointer -> next -> next;
    }
    puts("The middle element is: ");
    return slow_pointer -> number;
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

int main()
{
    int size, element;
    
    do
    {
        scanf("%d", &size);
    } while (size <= 0); 
    

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &element); // ceritanya, elemen linked list-nya sudah tersorting.
        push_mid(element);
    }

    print_singleLL();
    search_mid();
    

    return 0;
}



// Learning Resources:
// 1. https://www.mycplus.com/tutorials/data-structures/find-the-middle-element-of-linked-list-in-c/#:~:text=In%20order%20to%20find%20middle,middle%20element%20of%20linked%20list.
// 2. https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/
