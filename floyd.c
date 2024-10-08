Pseudocode 
function floydWarshall(graph): 
 dist = copy(graph) 
 for k from 0 to V-1: 
 for i from 0 to V-1: 
 for j from 0 to V-1: 
 if dist[i][k] + dist[k][j] < dist[i][j]: 
 dist[i][j] = dist[i][k] + dist[k][j] 
 return dist 
function printSolution(dist): 
 for i from 0 to V-1: 
 for j from 0 to V-1: 
 if dist[i][j] == INF
 print "INF" 
 else: 
 print dist[i][j] 



Program 
#include <stdio.h> 
#define INF 99999 
#define V 4 
void printSolution(int dist[][V]); 
void floydWarshall(int graph[][V]) { 
 int dist[V][V]; 
 int i, j, k; 
 // Initialize the solution matrix same as input graph matrix 
 for (i = 0; i < V; i++) 
 for (j = 0; j < V; j++) 
 dist[i][j] = graph[i][j]; 
 // Update the solution matrix by considering all vertices as intermediate vertices  for (k = 0; k < V; k++) { 
 for (i = 0; i < V; i++) { 
 for (j = 0; j < V; j++) { 
 if (dist[i][k] + dist[k][j] < dist[i][j]) 
 dist[i][j] = dist[i][k] + dist[k][j]; 
 } 
 } 
 } 
 printSolution(dist); 
} 
void printSolution(int dist[][V]) { 
 printf("The following matrix shows the shortest distances between every pair of  vertices:\n"); 
 for (int i = 0; i < V; i++) { 
 for (int j = 0; j < V; j++) { 
 if (dist[i][j] == INF) 
 printf("%7s", "INF"); 
 else 
 printf("%7d", dist[i][j]); 
 } 
 printf("\n"); 
 } 
} 
int main() { 
 int graph[V][V] = {{0, 5, INF, 10}, 
 {INF, 0, 3, INF}, 
{INF, INF, 0, 1}, 
{INF, INF, INF, 0}}; 
 floydWarshall(graph); 
 return 0; 
}



result:
The following matrix shows the shortest distances between every pair of vertices: 
 0 5 8 9 
 INF 0 3 4 
 INF INF 0 1 
 INF INF INF 0 
