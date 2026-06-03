#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node * next;
} Node;

Node * create_node(int data)
{
    Node * temp = malloc(sizeof(Node));
    temp -> val = data;
    temp -> next = NULL;
    return temp;
}

Node * insert_front(Node * head, int new_data)
{
    Node * new_node = create_node(new_data);
    new_node->next = head->next;
    head->next = new_node;
    return new_node;
}

Node * pop(Node * head, int pos)
{
    Node * curr = head;

    int i = 1;
    while(i != pos-1)
    {
        curr = curr->next;
        i++;

        if(curr == NULL) return NULL;
    }

    Node * trash = curr->next;
    curr->next = curr->next->next;
    free(trash);
    return head;
}


void print_list(Node * head)
{
    Node * curr = head;

    if(curr->next == NULL) {printf("Empty List\n"); return;}
    curr = curr->next;

    while(curr != NULL)
    {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    Node * le;
    le -> next = NULL;

    insert_front(le, 5);
    insert_front(le, 6);
    insert_front(le, 7);
    insert_front(le, 8);

    print_list(le);

    pop(le, 2);
    pop(le, 4);
    print_list(le);

    return 0;
}