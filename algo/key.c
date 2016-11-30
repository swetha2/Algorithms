#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define n 100
int x2,y2,key;
struct dist{
 int   x[10],y[10];
double val[10];
};
struct dist d1;
void distance(int x1,int y1,int c)
{
  
  d1.x[c]=x1;
  d1.y[c]=y1;
  d1.val[c]=sqrt(pow((x2-x1),2)-pow((y2-y2),2));
  
}
void sort()
{
 int i,temp;
 for(i=0;i<n;i++)
  {
    if(d1.val[i]>d1.val[i+1])
      {
        temp=d1.val[i];
        d1.val[i]=d1.val[i+1];
        d1.val[i+1]=temp;
       }
   else
       continue;
   }
}
void main()
{
 int a[1000][1000],i,j,r,k=0,near,x,y;
 printf("the generated random numbers are \n");
 for(i=0;i<n;i++)
  {
    for(j=0;j<2;j++)
     {
       r=rand()%10;
       a[i][j]=r;
       printf("%d\t",a[i][j]);
     }
    printf("\n");
  }
printf("enter the key value\n");
scanf("%d",&key);
x2=a[key][0];
y2=a[key][1];
printf("enter the near_key\n");
scanf("%d",&near);
  for(i=0;i<n;i++)
    {   x=a[i][0];
        y=a[i][1];
        distance(x,y,k); k++;}
 sort();
printf("the %d near points are\n",near);
for(i=0;i<near;i++)
 {
   printf("%d & %d\n",d1.x[i],d1.y[i]);
 }
}
