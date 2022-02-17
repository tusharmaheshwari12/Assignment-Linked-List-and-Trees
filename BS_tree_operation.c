#include<stdio.h>
#include<stdlib.h>

struct node{
char data;
struct node *l;
struct node *r;
}*root = NULL, *temp = NULL, *t2, *t1;

void insert();
void delete1();
void search(struct node *t);
void inorder(struct node *t);
void create();
void delete();
void search1(struct node *t,int data);
int smallest(struct node *t);
int largest(struct node *t);

int flag=1;

void inorder(struct node *t)
{
    if (root == NULL)
    {
        printf("Empty");
        return;
    }
    if (t->l != NULL)    
        inorder(t->l);
    printf("%d -> ", t->data);
    if (t->r != NULL)    
        inorder(t->r);
}

void insert()
{

    create();
    if (root == NULL) 
        root = temp;
    else    
        search(root);    

}


void create()

{

    int data;
    printf("Enter element which you want to insert : ");
    scanf("%d", &data);
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->l = temp->r = NULL;

}

void search(struct node *t)

{

    if ((temp->data > t->data) && (t->r != NULL))      
        search(t->r);
    else if ((temp->data > t->data) && (t->r == NULL))
        t->r = temp;
    else if ((temp->data < t->data) && (t->l != NULL))   
        search(t->l);
    else if ((temp->data < t->data) && (t->l == NULL))
        t->l = temp;

}

void delete()
{
    int data;
    if (root == NULL)
    {
        printf("Empty");
        return;
    }
    printf("Enter the element which you want to delete : ");
    scanf("%d", &data);
    t1 = root;
    t2 = root;
    search1(root, data);

}


void search1(struct node *t, int data)
{
    if ((data>t->data))
    {
        t1 = t;
        search1(t->r, data);
    }
    else if ((data < t->data))
    {
        t1 = t;
        search1(t->l, data);
    }
    else if ((data==t->data))
    {
        delete1(t);
    }

}

void delete1(struct node *t)
{
    int k;
    if ((t->l == NULL) && (t->r == NULL))
    {
        if (t1->l == t)
        {
            t1->l = NULL;
        }
        else
        {
            t1->r = NULL;
        }
        t = NULL;
        free(t);
        return;
    }
    else if ((t->r == NULL))
    {
        if (t1 == t)
        {
            root = t->l;
            t1 = root;
        }
        else if (t1->l == t)
        {
            t1->l = t->l;
        }
        else
        {
            t1->r = t->l;
        }
        t = NULL;
        free(t);
        return;
    }

    else if (t->l == NULL)
    {
        if (t1 == t)
        {
            root = t->r;
            t1 = root;
        }
        else if (t1->r == t)
            t1->r = t->r;
        else
            t1->l = t->r;
        t == NULL;
        free(t);
        return;
    }
    else if ((t->l != NULL) && (t->r != NULL))  
    {
        t2 = root;
        if (t->r != NULL)
        {
            k = smallest(t->r);
            flag = 1;
        }
        else
        {
            k =largest(t->l);
            flag = 2;
        }
        search1(root, k);
        t->data = k;
    }
}

int smallest(struct node *t)

{
    t2 = t;
    if (t->l != NULL)
    {
        t2 = t;
        return(smallest(t->l));
    }
    else    
        return (t->data);
}

int largest(struct node *t)
{
    if (t->r != NULL)
    {
        t2 = t;
        return(largest(t->r));
    }
    else    
        return(t->data);

}

void main()
{
 int ch;
    printf("\nEnter 1 for Insert an element into tree\n");
    printf("Enter 2 for Delete an element from the tree\n");
    printf("Enter 3 for Inorder Traversal\n");
    printf("Enter 4 for Exit\n");

    while(1)

    {

        printf("\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:    
            insert();
            break;
        case 2:    
            delete();
            break;
        case 3:    
            inorder(root);
            break;
        case 4:    
            exit(0);
        default :     
            printf("\nInvalid Input\n");
            break;    

        }

    }

}



