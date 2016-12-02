#include<stdio.h>
#include<stdlib.h>
int main()
{
 int count=0,N=30,move[N],i,j,sum=0,d;
 for(i=1;i<=N;i++)
  move[i]=-1;
 
 move[1]=1;
 //dist[1][1]=0;

 move[3]=22;
 move[5]=8;
 move[11]=26;
 move[20]=29;

 move[17]=4;
 move[19]=7;
 move[21]=9;
 move[27]=1;

for(i=1;i<=N;i++)
 {
   printf("enter the dice value b/w 1 - 6\n");
   scanf("%d",&d);
   sum=sum+move[d];
   count++;
   if(sum==N)
    break;
  }
printf("the number of moves is %d\n",count);
return 0;
}  
 
