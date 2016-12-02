#include <stdio.h>
#include <stdlib.h>

struct Node {
	int val;
	struct Node * next;
};

struct Node * add(struct Node * head, int vertex)
{
	struct Node * traverse = (struct Node *) malloc(sizeof(struct Node));
	traverse->val = vertex;
	traverse->next = head;	
	return traverse;
}

void breadthFirstSearch(struct Node * adjList[], int vertices, int parent[], int level[])
{
	struct Node * temp;
	int i, par, lev, flag = 1;	
	lev = 0;
	level[1] = lev;	
	while (flag) 
         {
	   flag = 0; 
           for (i = 1; i <= vertices; ++i)
           { 
             if (level[i] == lev) 
               { flag = 1;  
                 temp = adjList[i]; 
                 par = i; 
	         temp = temp->next;
		 continue;
					
					
		 level[temp->val] = lev + 1;
		 parent[temp->val] = par;
		 temp = temp->next;
				
	       }
	    }
		
	  ++lev;
	 }
}

void replace(struct Node * head, int oldVertex, int newVertex)
{
  struct Node * traverse = head;
	

  while (traverse->next != NULL) 
   {
     if (traverse->val == oldVertex) 
      {
	break;
      }
		
     traverse = traverse->next;
    }

    traverse->val = newVertex;
}

void printAdjacencyList(struct Node * adjList[], int vertices)
{
  int i;
  printf("\nAdjacency List -\n");
  for (i = 1; i <= vertices; ++i)
    { 
      printf("%d -> ", i);
      struct Node * temp = adjList[i];
      while (temp != NULL) 
       {
          printf("%d -> ", temp->val);
	  temp = temp->next;
       }
      printf("NULL\n");
    }
}

void printShortestPath(int parent[], int currentVertex, int startVertex)
{
  if (currentVertex == startVertex)
   {
     printf("%d ", currentVertex);
   } 
  else if (parent[currentVertex] == 0) 
   {
     printShortestPath(parent, startVertex, startVertex);
     printf("%d ", currentVertex);
    }
  else 
    {
      printShortestPath(parent, parent[currentVertex], startVertex);
      printf("%d ", currentVertex);
    }
}

int main()
{
  int vertices, edges, i, j, v1, v2;	
  vertices = 100;		
  struct Node * adjList[vertices + 1];	
  int parent[vertices + 1];	
  int level[vertices + 1];	
  
  for (i = 0; i <= vertices; ++i) 
   {
       adjList[i] = NULL;
       parent[i] = 0;
       level[i] = -1;
   }
		
   for (i = 1; i <= vertices; ++i)
   {		
      for (j = 1; j <= 6 && j + i <= vertices; ++j) 
        { 
           adjList[i] = add(adjList[i], i + j); 
           ++edges; 
        } 
   }
 int ladderCount, snakeCount; 
 printf("Enter the Number of Ladders - "); 
 scanf("%d", &ladderCount); 
 printf("Enter the Ladder Edges -\n"); 
 for (i = 0; i < ladderCount; ++i) 
  {
    scanf("%d%d", &v1, &v2);
    j = v1 - 6;
		
    if (j < 1) 
     j = 1;	
    for (; j < v1; ++j) 
    {
      replace(adjList[j], v1, v2);
    }
  }
	
  printf("Enter the Number of Snakes - ");
  scanf("%d", &snakeCount);
  printf("Enter the Snake Edges -\n");
   for (i = 0; i < snakeCount; ++i) 
    {
       scanf("%d%d", &v1, &v2);
	j = v1 - 6;
	if (j < 1) 
	 j = 1;
	for (; j < v1; ++j) 
         {
	   replace(adjList[j], v1, v2);
	 }
     }	
   printAdjacencyList(adjList, vertices);
   breadthFirstSearch(adjList, vertices, parent, level);
   printf("\nNumber of Moves required = %d\n", level[vertices]);
	
   if (level[vertices] != -1) 
    {
       printShortestPath(parent, vertices, 1);
    }	
  return 0;
}
