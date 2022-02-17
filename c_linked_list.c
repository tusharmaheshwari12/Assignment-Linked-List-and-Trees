#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node* next;
};

struct node* last = NULL;

void insertAtFront()
{

	int data;
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));

	printf("\nEnter value which you want to insert at front: \n");
	scanf("%d", &data);

	if (last == NULL) {
		temp->info = data;
		temp->next = temp;
		last = temp;
	}


	else {
		temp->info = data;
		temp->next = last->next;

		last->next = temp;
	}
}


void insertAtLast()
{

    int data;
 

    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
 

    printf("\nEnter value which you want to insert at last: \n");
    scanf("%d", &data);

    if (last == NULL) {
        temp->info = data;
        temp->next = temp;
        last = temp;
    }

    else {
        temp->info = data;
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}


void insertInBetween()
{

    int data, value;
 

    struct node *temp, *n;
 

    printf("\nEnter element after which you want to insert: \n");
    scanf("%d", &value);
    temp = last->next;
 
    do {
 

        if (temp->info == value) {
            n = (struct node*)malloc(sizeof(struct node));
 

            printf("\nEnter value which you want to insert: \n");
            scanf("%d", &data);
            n->info = data;
            n->next = temp->next;
            temp->next = n;
 

            if (temp == last)
                last = n;
            break;
        }
        else
            temp = temp->next;
    } while (temp != last->next);
}

void deletefirst()
{
    struct node* temp;

    if (last == NULL)
        printf("\nUnderFlow\n");
 

    else {
        temp = last->next;
        last->next = temp->next;
        free(temp);
    }
}

void deletelast()
{
    struct node* temp;

    if (last == NULL)
        printf("\nUnderFlow\n");
 
    temp = last->next;
 

    while (temp->next != last)
        temp = temp->next;
 

    temp->next = last->next;
    last = temp;
}
void display()
{

	if (last == NULL)
		printf("\nUnderFlow\n");


	else {
		struct node* temp;
		temp = last->next;

		do {
			printf("%d ", temp->info);
			temp = temp->next;
		} while (temp != last->next);
	}
}


int select1()
{
    int cho;
    printf("\nEnter 1 for Insertion at Beginning\n");
    printf("Enter 2 for Insertion at End\n");
    printf("Enter 3 for Insertion in Between\n");
    printf("Enter 4 for Deletion of First Node\n");
    printf("Enter 5 for Deletion of Last Node\n");
    printf("Enter 6 for Display\n");
    printf("Enter 7 for Quit\n");

    
    scanf("%d",&cho);
    return cho;
}

int main()
{

    int count=0;
    while(1)
    {
        switch(select1())
        {
            case 1:
            insertAtFront();
            break;
            
            case 2:
            insertAtLast();
            break;
            
            case 3:
            insertInBetween();
            break;

            case 4:
            deletefirst();
            break;

            case 5:
            deletelast();
            break;
            
            case 6:
            display();
            break;
            
            case 7:
            exit(0);
            break;
            
            default:
            printf("Invalid Input\n");
            
        }
    }
    
}


