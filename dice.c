#include<stdio.h>
#include<stdlib.h>
typedef int bool;
#define true 1
#define false 0
int queue[50];
int front=-1,rare=50;
struct queueEntry
{
    int v;     
    int dist;  
};
struct queueEntry s,qe,d;
void push(struct queueEntry p)
{
  if(front==50)
   {
     printf("queue if full\n");
     exit(0);
   }
 queue[++front]=p.dist; 
}
void pop()
{
 int temp;
  if(rare==-1)
   {
     printf("queue is empty\n");
     exit(1);
   }
  temp=queue[rare--];
}
int MIN_DICE(int moves[],int N)
{
  int i,j,v1;
  bool visit[50];
  for(i=0;i<N;i++)
   visit[i]=false;

   visit[0]=true;
     s.v=0;
     s.dist=0;
     push(s);
 while(queue)
 {
   qe.dist=queue[front];
   v1=qe.v;
 
   if(v1==N)
    break;
 
pop();

 for(j=v1+1;j<=6 ;++j)
  {//printf("inside j for loop\n");
      if(!visit[j])
        {
           d.dist=qe.dist+1;
           visit[j]=true; 
           
           if(moves[j]!=-1)
            { d.v=moves[j];printf("ifpushing d %d\n",d.v); qe.dist++;}
           else
             { d.v=j;  printf("elsepushing d %d\n",d.v);}
          push(d);
         }
     }
 return qe.dist;
 }
}

void main()
{
 int N=30,i,min,l=0,s=0;
 int moves[N];
 
 for(i=0;i<N;i++)
  moves[i]=i+1;
 
 moves[2]=21;
 moves[4]=7;
 moves[10]=25;
 moves[19]=28;

 moves[16]=3;
 moves[18]=6;
 moves[20]=8;
 moves[26]=0;

 for(i=0;i<N;i++)
  {
    if(moves[i]>(i+1))
     l++;
    else if(moves[i]<i)
          s++;
         //continue;
    else
       continue;
      //s++;
   }
 printf("the number of ladders and snakes are %d and %d\n",l,s);
 min=MIN_DICE(moves,N);
 printf("the minimum number of dice required is %d\n",min);
}
