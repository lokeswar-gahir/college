#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} *first, *last, *temp;

void create()
{
    int n, i;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);
    first = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value for first node : ");
    scanf("%d", &first->data);
    first->link = NULL;
    temp = first;
    for (i = 1; i < n; i++)
    {
        last = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value for node %d: ", i + 1);
        scanf("%d", &last->data);
        last->link = NULL;
        temp->link = last;
        temp = last;
    }
}

void display()
{
    printf("\nHere is the linked list : ");
    temp = first;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf(".\n");
}

void main()
{
    int ch = 0;
    while (ch != 3)
    {

        printf("\n1. Create\n2. Display\n3. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        default:
            printf("Exited.");
            exit(0);
            break;
        }
    }
}