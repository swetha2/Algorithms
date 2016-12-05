#include<stdio.h>
#include<stdlib.h>
#define N 30;
int move[30]= {1,1,22,1,8,1,
               1,1,1,1,26,1,
               1,1,1,1,-4,1,
               -7,29,-9,1,1,1,
               1,1,-1,1,1,1};
void main()
{
  int i,l=0,s=0,count=0,start=0,end=30,max=0;
  for(i=1;i<=30;i++)
   {
         if(move[i]>1)
            l++;
         else if(move[i]<0)
             s++;
         else
              continue;
    }
    
 printf("the total number of ladders and snakes are %d and %d\n",l,s);
while(start<end)
{ 
 for(i=1;i<=6;i++)
  {
    if(move[i]>=max)
    { max=move[i]; count++;}
     
   }
start=start+max;
}
 printf("the minimum number of moves required is %d\n",count);
}
