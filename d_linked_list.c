#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    struct node *prev;  
    struct node *next;  
    int data;  
};  
struct node *head;  

void at_beg()  
{  
   struct node *ptr,*temp;   
   int item;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOverFlow");  
   }  
   else  
   {  
    printf("\nEnter value which you want to insert at beginning\n");  
    scanf("%d",&item);  
    ptr->data=item;  
   if(head==NULL)  
   {  
      head = ptr;  
      ptr -> next = head;   
      ptr -> prev = head;   
   }  
   else   
   {  
       temp = head;   
    while(temp -> next != head)  
    {  
        temp = temp -> next;   
    }  
    temp -> next = ptr;  
    ptr -> prev = temp;  
    head -> prev = ptr;  
    ptr -> next = head;  
    head = ptr;  
   }  
}  
     
}  
void at_last()  
{  
   struct node *ptr,*temp;  
   int item;  
   ptr = (struct node *) malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
       printf("\nEnter value which you want to insert at last\n");  
       scanf("%d",&item);  
        ptr->data=item;  
       if(head == NULL)  
       {  
           head = ptr;  
           ptr -> next = head;   
           ptr -> prev = head;   
       }  
       else  
       {  
          temp = head;  
          while(temp->next !=head)  
          {  
              temp = temp->next;  
          }  
          temp->next = ptr;  
          ptr ->prev=temp;  
          head -> prev = ptr;  
      ptr -> next = head;  
        }  
   }    
}  
  
void del_beg()  
{  
    struct node *temp;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head->next == head)  
    {  
        head = NULL;   
        free(head);    
    }  
    else  
    {  
        temp = head;   
        while(temp -> next != head)  
        {  
            temp = temp -> next;  
        }  
        temp -> next = head -> next;  
        head -> next -> prev = temp;  
        free(head);  
        head = temp -> next;  
    }  
  
}  
void del_last()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head->next == head)  
    {  
        head = NULL;   
        free(head);     
    }  
    else   
    {  
        ptr = head;   
        if(ptr->next != head)  
        {  
            ptr = ptr -> next;   
        }  
        ptr -> prev -> next = head;  
        head -> prev = ptr -> prev;    
        free(ptr);  
    }  
}  
  
void display()  
{  
    struct node *ptr;  
    ptr=head;  
    if(head == NULL)  
    {  
        printf("\nUnderFlow");  
    }     
    else  
    {  
        printf("\nDoubly Linked List :\n");  
          
        while(ptr -> next != head)  
        {  
          
            printf("%d ", ptr -> data);  
            ptr = ptr -> next;  
        }  
        printf("%d ", ptr -> data);  
    }  
              
}  

  
void main ()  
{  
int cho = 0;  
    while(cho != 9)  
    {  
	printf("\nEnter 1 for Insertion at Beginning\n");
	printf("Enter 2 for Insertion at End\n");
	printf("Enter 3 for Deletion from Beginning\n");
   	printf("Enter 4 for Deletion from Last\n");
    	printf("Enter 5 for Display\n");
    	printf("Enter 6 for Quit\n");
        scanf("\n%d",&cho);  
        switch(cho)  
        {  
            case 1:  
            at_beg();  
            break;  
            case 2:  
            at_last();  
            break;  
            case 3:  
            del_beg();  
            break;  
            case 4:  
            del_last();  
            break;  
            case 5:  
            display();  
            break;  
            case 6:  
            exit(0);  
            break;  
            default:  
            printf("Invalid Input");  
        }  
    }  
}  

