#include <stdio.h>
#include<limits.h>
#define INF 9999
#define cap 10

int find_min(int a[cap], int start)
{
	int i = 0;
	int min = i;
	a[start] = INT_MAX;
	for(i=0; i<sizeof(a); i++)
	{
		if(i == start)
			continue;
		else if(a[i] < a[min])
			min = i;
	}
	return min;
}
void Dijkstra(int G[cap][cap], int n, int start) {
  int cost[cap][cap];
  int distance[cap];
  int p[cap];
  int visited[cap], count, min_distance, next, i, j;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (G[i][j] == 0)
        cost[i][j] = INF;
      else
        cost[i][j] = G[i][j];

  for (i = 0; i < n; i++) {
    distance[i] = cost[start][i];
    p[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) {
    min_distance = INF;

    for (i = 0; i < n; i++)
      if (distance[i] < min_distance && !visited[i]) {
        min_distance = distance[i];
        next = i;
      }

    visited[next] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (min_distance + cost[next][i] < distance[i]) {
          distance[i] = min_distance + cost[next][i];
          p[i] = next;
        }
    count++;
  }

  for (i = 0; i < n; i++)
    if (i != start) {
      printf("\n\t\t Distance from user's position to EV Pump %d: %d Km.", i+1, distance[i]);
    }
    
    int min = find_min(distance, start);
	printf("\n\t\t Closest EV Pump is EV Pump %d at a distance of %d from user.", min+1, distance[min]);
}
int main() {
	int Graph[cap][cap];
  int i, j, n, u;
  n = 7;

  Graph[0][0] = 0;
  Graph[0][1] = 0;
  Graph[0][2] = 1;
  Graph[0][3] = 2;
  Graph[0][4] = 0;
  Graph[0][5] = 0;
  Graph[0][6] = 0;

  Graph[1][0] = 0;
  Graph[1][1] = 0;
  Graph[1][2] = 2;
  Graph[1][3] = 0;
  Graph[1][4] = 0;
  Graph[1][5] = 3;
  Graph[1][6] = 0;

  Graph[2][0] = 1;
  Graph[2][1] = 2;
  Graph[2][2] = 0;
  Graph[2][3] = 1;
  Graph[2][4] = 3;
  Graph[2][5] = 0;
  Graph[2][6] = 0;

  Graph[3][0] = 2;
  Graph[3][1] = 0;
  Graph[3][2] = 1;
  Graph[3][3] = 0;
  Graph[3][4] = 0;
  Graph[3][5] = 0;
  Graph[3][6] = 1;

  Graph[4][0] = 0;
  Graph[4][1] = 0;
  Graph[4][2] = 3;
  Graph[4][3] = 0;
  Graph[4][4] = 0;
  Graph[4][5] = 2;
  Graph[4][6] = 0;

  Graph[5][0] = 0;
  Graph[5][1] = 3;
  Graph[5][2] = 0;
  Graph[5][3] = 0;
  Graph[5][4] = 2;
  Graph[5][5] = 0;
  Graph[5][6] = 1;

  Graph[6][0] = 0;
  Graph[6][1] = 0;
  Graph[6][2] = 0;
  Graph[6][3] = 1;
  Graph[6][4] = 0;
  Graph[6][5] = 1;
  Graph[6][6] = 0;

	printf("\t\t  **********************************************************************************************  \n");
	printf("\t\t  ----------------------------------------------------------------------------------------------  \n\n");
	printf("%70s \n\n", "EV Pump Stations ");
	printf("\t\t  ----------------------------------------------------------------------------------------------  \n");
	printf("\t\t  **********************************************************************************************  \n\n\n\n");
	
	
	printf("\t\t List of EV pump stations nearby:\n\n");
	printf("\t\t   1. EV pump station 1 \n");
    printf("\t\t   2. EV pump station 2 \n");
    printf("\t\t   3. EV pump station 3 \n");
    printf("\t\t   4. EV pump station 4 \n");
    printf("\t\t   5. EV pump station 5 \n");
    printf("\t\t   6. EV pump station 6 \n");
    printf("\n\t\t Enter user's position : ");
    scanf("%d", &u);
    
  Dijkstra(Graph, n, u-1);

  return 0;
}
