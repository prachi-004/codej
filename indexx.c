#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*newnode, *temp, *start, *temp1;
int m,n,i,x,no,a;
int dir[10][2];
a=0;
 
 
void create()
{
     i=0;
     start=NULL;
     while(i!=n)
     {
         newnode = (struct node*)malloc(sizeof(struct node));
         newnode->next=NULL;
         newnode->data=-1;
         if(start==NULL)
             start=temp=newnode;
          else
          {
            temp->next=newnode;
            temp=newnode;
              
          }   
          i++;
          
     }
     
}

void allocate()
{
    int cnt=1;
    int count=0;
    temp1=start;
    if(temp1->data==-1)
    {
        if(m<=n)
        {
            temp1->data=cnt;
            temp1=temp1->next;
            for(i=1;i<m-1; i++)
            {
                temp1->data=0;
                temp1=temp1->next;
            }
            temp1->data=-2;
            dir[a][0]=no;
            dir[a][1]=cnt;
            a++;
        }
        else
        {
            printf("\n Block can not be allocated");
            exit(0);
        }
    }
    else
    {
         while(temp->data-1)
         {
            temp1=temp1->next;
            count++;
            cnt ++;
         }
         if(m+count<=n)
         {
            temp1->data=cnt;
            for(i=1; i<m-1; i++)
            {   
               temp1=temp1->next;
               temp1->data=0;
            }
            temp1=temp1->next;
            temp1->data=-2;
            dir[a][0]=no;
            dir[a][1]=cnt;
            a++;
         }
         else
         {
            printf("\nBlocks can not be allocated");
            exit(0);
         }
    }
}


void deallocate()
{
    int bno,j;
    int count=1;
    temp1=start;
    for(j=0; j<10; j++)
    {
       if(dir[j][0]==x)
       {
           bno=dir[j][1];
           dir[j][0]=0;
           dir[j][1]=0;
           break;
       }
       
    }
    while(count!=bno)
    {
       count ++;
       temp1=temp1->next;
    }
    while(temp1=temp1->data!=2)
    {
       temp1->data=-1;
       temp1=temp1->next;
    }
    temp1->data=-1;
}


void display()
{
    int tot=0;
    temp1=start;
    while(temp1!=NULL)
    {
       printf("%d\t",temp1->data);
       if(temp1->data==-1)
       tot ++;
       temp1=temp1->next;
    }
    printf("\n Total allocated block are %d",n-tot);
    printf("\nTotal free blocksd are %d\n",tot);
    for(i=0;i<10;i++)
    {
       printf("%d\t%d",dir[i][0],dir[i][1]);
       printf("\n");
       
    }
}


void main()
{
    int ch;
    while(1)
    {
       printf("\n1:Create\n");
       printf("2:Add new\n");
       printf("3:Deallocate\n");
       printf("4:Display\n");
       printf("5:Exit\n");
       printf("\nEnter your choice");
       scanf("%d",&ch);
       switch(ch)
       {
           case 1:printf("Enter the size of disk :-");
           scanf("%d",&n);
           create();
           break;
           
           case 2:printf("\nEnter the file no.of allocated\n");
           scanf("%d",&no);
           printf("\nEnter the no.of blocks to be allocated");
           scanf("%d",&m);
           allocate();
           break;
           
           case 3:printf("\nEnter the file no.of delete\n");
           scanf("%d",&x);
           deallocate();
           break;
           
           case 4:display();
           break;
           
           case 5:exit(0);
           
       }
    }
}
