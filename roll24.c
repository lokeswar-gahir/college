#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} *first, *last, *temp, *temp1;
;

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

void insertAtFirst(){
    temp = (struct node*)malloc(sizeof(struct node));
    temp->link = NULL;
    printf("\nEnter the data : ");
    scanf("%d", &temp->data);
    temp->link = first;
    first = temp;
}

void middle(){
    int val;
    printf("\nEnter the data after which node to be added : ");
    scanf("%d", &val);
    temp = (struct node *) malloc(sizeof(struct node));
    temp ->link = NULL;
    printf("\nEnter the data : ");
    scanf("%d", &temp->data);
    temp1 = first;
    while(temp1!= NULL){
        if(temp1 ->data == val){
            temp->link = temp1->link;
            temp1->link = temp;
            break;
        }
        temp1 = temp1->link;
        
    }
}

void insertAtLast(){
    temp1 = (struct node*)malloc(sizeof(struct node));
    temp = first;
    printf("Enter the data :");
    while(temp->link!=NULL){
        temp=temp->link;
    }
    scanf("%d", &temp1->data);
    temp->link = temp1;
    temp1->link=NULL;
}

void main()
{
    int ch = 0;
    while (ch != 3)
    {
        printf("\n1. Create\n2. Display\n3. Exit\\n4. first\n5. middle\n6.last\n>>> ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        
        case 4:
            insertAtFirst();
            break;

        case 5:
            middle();
            break;
        case 6:
            insertAtLast();
            break;
        default:
            printf("Exited.");
            exit(0);
            break;
        
        
        }
    }
}