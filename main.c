#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *lptr;
 struct node *rptr;
};
struct node *first=NULL;

void create();
void insertbeg();
void insertmid();
void insertend();
void deletebeg();
void deletemid();
void deleteend();
void sorting();
void print();

int main()
{

     int choice;
     START0:
     printf("\n\t  OPERATIONS IN DOUBLE LINKED LIST");
     printf("\n\t************************************");
     printf("\n1.Create\n2.Insert\n3.Delete\n4.Sort\n5.Print\n6.Clear Screen\n7.Exit");
     do
     {
        printf("\n\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
         {
            case 1: create();
                    break;
            case 2: printf("\n\n1.Insert at Beginning\n2.Insert at Middle\n3.Insert at End");
                    do
                    {
                        printf("\nEnter Choice : ");
                        scanf("%d",&choice);
                        switch(choice)
                        {
                            case 1: insertbeg();
                                    break;
                            case 2: insertmid();
                                    break;
                            case 3: insertend();
                                    break;
                            default :printf("\nWrong Choice!!!");
                        }
                    }while(choice!=1&&choice!=2&&choice!=3);
                    break;

            case 3: printf("\n\n1.Delete at Begining\n2.Delete at Middle\n3.Delete at End");
                    do
                    {
                        printf("\nEnter Choice : ");
                        scanf("%d",&choice);
                        switch(choice)
                        {
                            case 1: deletebeg();
                                    break;
                            case 2: deletemid();
                                    break;
                            case 3: deleteend();
                                    break;
                            default : printf("\nWrong Choice!!!");
                        }
                    }while(choice!=1&&choice!=2&&choice!=3);
                    break;
            case 4: sorting();
                    break;
            case 5: print();
                    break;
            case 6: system("cls");
                    goto START0;
                    break;
            case 7: printf("\nExiting...");
                    break;
            default: printf("\nWrong Choice!!!");
         }
     }while(choice!=7);
    return 0;
}

 void create()
 {
    char ch;
    struct node *ptr,*cpt;
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d",&ptr->data);
    ptr->lptr=NULL;
    ptr->rptr=NULL;
    first=ptr;
    do
     {
        cpt=(struct node *)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d",&cpt->data);
        ptr->rptr=cpt;
        cpt->lptr=ptr;
        ptr=cpt;
        printf("Want to Continue.(Press 'C' or 'E' to exit) : ");
        scanf(" %c",&ch);
     }while(ch=='C'||ch=='c');
      ptr->rptr=NULL;
 }

 void insertbeg()
 {
    struct node *ptr;
    if(first==NULL)
    {
        printf("Link List is Empty");
    }
    else
    {
        ptr=(struct node *)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d",&ptr->data);
        ptr->rptr=first;
        ptr->lptr=NULL;
        first=ptr;
        printf("Data %d is Inserted",ptr->data);
    }
 }

 void insertmid()
 {
    int num;
    struct node *ptr,*cpt;
    if(first==NULL)
    {
        printf("Link List is Empty");
    }
    else
    {
        printf("Enter Data After Which you Want to Insert : ");
        scanf("%d",&num);
        ptr=first;
         while(ptr!=NULL)
        {
            if(ptr->data==num)
            {
                break;
            }
            ptr=ptr->rptr;
        }
        if(ptr==NULL)
        {
            printf("Data %d is Not Found",num);
        }
        else
        {
            cpt=(struct node *)malloc(sizeof(struct node));
            printf("Enter Data : ");
            scanf("%d",&cpt->data);
            cpt->lptr=ptr;
            cpt->rptr=ptr->rptr;
            ptr->rptr=cpt;
            printf("Data %d is Inserted",cpt->data);
        }
    }
 }

 void insertend()
 {
    struct node *ptr,*cpt;
    if(first==NULL)
    {
        printf("Link List is Empty");
    }
    else
    {
        ptr=first;
         while(ptr->rptr!=NULL)
        {
            ptr=ptr->rptr;
        }
        cpt=(struct node *)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d",&cpt->data);
        cpt->lptr=ptr;
        cpt->rptr=NULL;
        ptr->rptr=cpt;
        printf("Data %d is Inserted",cpt->data);
    }
 }

 void deletebeg()
 {
     struct node *ptr;
     if(first==NULL)
     printf("Link List is Empty");
     else
     {
         ptr=first;
         first=ptr->rptr;
         first->lptr=NULL;
         printf("\nDeleted Data : %d\n",ptr->data);
         free(ptr);
     }
 }
 void deletemid()
 {
     int num;
     struct node *ptr,*cpt;
     if(first==NULL)
     {
         printf("Link List is Empty");
     }
     else
     {
         ptr=first;
         printf("\nEnter Data You Want to Delete : ");
         scanf("%d",&num);
         while(ptr!=NULL)
         {
             if(ptr->data==num)
                break;
             cpt=ptr;
             ptr=ptr->rptr;
         }
         if(ptr==NULL)
         {
             printf("Data %d is Not Found",num);
         }
         else
         {
             cpt->rptr=ptr->rptr;
             cpt=ptr->rptr;
             cpt->lptr=ptr->lptr;
             ptr->lptr=NULL;
             ptr->rptr=NULL;
             printf("\nData Deleted : %d\n",ptr->data);
             free(ptr);
         }
     }

 }
 void deleteend()
 {
     struct node *ptr,*cpt;
     if(first==NULL)
     {
         printf("Link List is Empty");
     }
     else
     {
         ptr=first;
         while(ptr->rptr!=NULL)
         {
             ptr=ptr->rptr;
         }
         cpt=ptr->lptr;
         cpt->rptr=NULL;
         ptr->lptr=ptr->rptr=NULL;
         printf("\nData Deleted : %d\n",ptr->data);
         free(ptr);
     }
 }

void sorting()
{
    int temp;
    struct node *ptr,*cpt;
    if(first==NULL)
    {
        printf("Link List is Empty");
    }
    else
    {
        ptr=first;
        while(ptr!=NULL)
        {
            cpt=ptr->rptr;
            while(cpt!=NULL)
            {
                if(ptr->data>cpt->data)
                {
                    temp=ptr->data;
                    ptr->data=cpt->data;
                    cpt->data=temp;
                }
                cpt=cpt->rptr;
            }
            ptr=ptr->rptr;
        }
        printf("\nData List is Sorted\n");
    }
}
 void print()
 {
        struct node *ptr;
        int i=1;
        if(first==NULL)
        {
            printf("Link List is Empty");
        }
        else
        {
            ptr=first;
            while(ptr!=NULL)
            {
                printf("\nData %d : %d",i,ptr->data);
                i++;
                ptr=ptr->rptr;
            }
        }
 }

