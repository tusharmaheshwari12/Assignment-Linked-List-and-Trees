#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * nxt;
};

struct Node * head=NULL;

struct Node * createNode(){
    struct Node *new;
    new=(struct Node*)malloc(sizeof(struct Node));
    return(new);
}

void at_beg(){
struct Node *temp;
temp = createNode();
printf("\nEnter Value:\n");
scanf("%d",&temp->data);
temp->nxt = head;
head = temp;
}

void at_end()
{
    struct Node *temp, *new;
    temp=createNode();
    printf("\nEnter Value:\n");
    scanf("%d",&temp->data);
    temp->nxt=NULL;
    
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        new=head;
        while(new->nxt!=NULL)
        {
            new =new->nxt;
        }
        new->nxt=temp;
    }
}

void in_between()
{
    int i,pos;
    struct Node *temp, *new;
    
    temp=createNode();
    
    if(temp==NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        printf("\nEnter Value:\n");
        scanf("%d",&temp->data);
        
        printf("Enter position after which you want to add no\n");
        scanf("%d",&pos);
        
        new=head;
        
        for(int i=1;i<pos;i++)
        {
            new=new->nxt;
            
            if(new==NULL){
                printf("\n You cant add here\n");
                return;
            }
        }
        temp->nxt=new->nxt;
        new->nxt=temp;
    }
}

int node_count()
{
    int count=1;
    struct Node  *temp;
    temp=createNode();
    temp=head;
    if(head==NULL)
    {
        count=0;
        printf("Total Nodes = %d",count);
    }
    else
    {
    while(temp->nxt!=NULL)
    {
        temp=temp->nxt;
        count+=1;
        
    }
    printf("Total Nodes = %d",count);
}
}



void deleteLast()
{
    struct Node *temp, *secondLastNode;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        temp = head;
        secondLastNode = head;

        while(temp->nxt != NULL)
        {
            secondLastNode = temp;
            temp = temp->nxt;
        }

        if(temp == head)
        {
            head = NULL;
        }
        else
        {

            secondLastNode->nxt = NULL;
        }

        free(temp);

        printf("SUCCESSFULLY DELETED LAST NODE OF LIST\n");
    }
}


void deleteFirst()
{
    struct Node *temp;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        temp = head;
        head = head->nxt;

        free(temp);

        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
}


struct Node* copy(struct Node *head){
  if(head==NULL)
  {
   return NULL;
  }
  else{
  struct Node *new;
  new = (struct Node*)malloc(sizeof(struct Node));
  new->data = head->data;
  new->nxt = copy(head->nxt);
  return new;
   }
   }
   
void cp(struct Node *head)
  {
    struct Node *save=head;
     while(save!=NULL)
   { 
     printf("%d ",save->data); 
     save = save->nxt;
     }
    printf("\n");
      }

void display()
{
    struct Node *temp;
    
    if (head==NULL)
    {
        printf("\nUnderFlow\n");
    }
    else
    {
        temp=head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->nxt;
        }
    }
}

int select1()
{
    int cho;
    printf("\nEnter 1 for Insertion at Begining\n");
    printf("Enter 2 for Insertion at End\n");
    printf("Enter 3 for Insertion in Between\n");
    printf("Enter 4 for Deletion of First Node\n");
    printf("Enter 5 for Deletion of Last Node\n");
    printf("Enter 6 for Counting Total No. of Nodes\n");
    printf("Enter 7 for Copy\n");
    printf("Enter 8 for Display\n");
    printf("Enter 9 to Quit\n");    
    scanf("%d",&cho);
    return cho;
}
void main()
{
    int count=0;
    while(1)
    {
        switch(select1())
        {
            case 1:
            at_beg();
            break;
            
            case 2:
            at_end();
            break;
            
            case 3:
            in_between();
            break;

            case 4:
            deleteFirst();
            break;
            
            case 5:
            deleteLast();
            break;

            case 6:
            node_count();
            break;
            
            case 7:
            printf("copied  list is:\n");
            struct Node *d = copy(head);
            cp(d);
            break;

            case 8:
            display();
            break;
            
            case 9:
            exit(0);
            break;
            
            default:
            printf("Invalid Input\n");
            
        }
    }
    
}

