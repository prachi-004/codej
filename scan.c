#include<stdio.h>
void main()
{
int n,size,head,i,total=0,x=0,flag,abs();
void sort(int[],int);
printf("\n how many request:");
scanf("%d",&n);
int a[n+2];
printf("enter actual request");
for(i=1;i<=n;i++)
scanf("%d",&a[i]);
printf("enter initial head pointer");
scanf("%d",&head);
a[0]=head;
printf("enter disk size");
scanf("%d",&size);
printf("enter direction(Left=0 , Right=1):");
scanf("%d",&flag);
if(flag)
{
a[n+1]=size-1;
sort(a,n+2);
printf("\n sorted elements are:\n");
for(i=0;i<n+2;i++)
printf("\t%d",a[i]);
printf("\n");
while(a[x]!=head)
x++;
for(i=x;i<n+1;i++)
total+=abs(a[i]-a[i+1]);
total+=abs(a[i]-a[x-1]);
for(i=x-1;i>0;i--)
total+=abs(a[i]-a[i-1]);
}
else
{
a[n+1]=0;
sort(a,n+2);
printf("\n sorted elements:");
for(i=0;i<n+2;i++)
printf("\t%d",a[i]);
printf("\n");
while(a[x]!=head)
x++;
for(i=x;i>0;i--)
total+=abs(a[i]-a[i-1]);
total+=abs(a[i]-a[x+1]);
for(i=x+1;i<n+1;i++);
total+=abs(a[i]-a[i+1]);
printf("\n *****Total Head Momens: %d\n",total);
}

void sort(int a[],int n)
{
int i,j,temp;
for(i=0;i<n;i++)
for(j=0;j<n-1;j++)
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
