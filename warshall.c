Pseudocode 
function transitiveClosure(graph): 
 reach = copy(graph) 
 for k from 0 to V-1: 
 for i from 0 to V-1: 
 for j from 0 to V-1: 
 reach[i][j] = reach[i][j] or (reach[i][k] and reach[k][j])  return reach 
function printTransitiveClosure(reach): 
 for i from 0 to V-1: 
 for j from 0 to V-1: 
 print reach[i][j] 



Program 
#include <stdio.h> 
#define V 4 
void printTransitiveClosure(int reach[][V]); 
void transitiveClosure(int graph[][V]) { 
 int reach[V][V]; 
 int i, j, k; 
 // Initialize reachability matrix as the input graph adjacency matrix  for (i = 0; i < V; i++) 
 for (j = 0; j < V; j++)
 reach[i][j] = graph[i][j]; 
 // Update reachability matrix using Warshall's algorithm 
 for (k = 0; k < V; k++) { 
 for (i = 0; i < V; i++) { 
 for (j = 0; j < V; j++) { 
 reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);  } 
 } 
 } 
 // Print the transitive closure matrix 
 printTransitiveClosure(reach); 
} 
void printTransitiveClosure(int reach[][V]) { 
 printf("The following matrix shows the transitive closure of the graph:\n");  for (int i = 0; i < V; i++) { 
 for (int j = 0; j < V; j++) { 
 printf("%d ", reach[i][j]); 
 } 
 printf("\n"); 
 } 
} 
int main() { 
 int graph[V][V] = {{1, 1, 0, 1}, 
 {0, 1, 1, 0}, 
{0, 0, 1, 1}, 
{0, 0, 0, 1}}; 
 transitiveClosure(graph); 
 return 0; 
} 


Results 
The following matrix shows the transitive closure of the graph: 
1 1 1 1  
0 1 1 1  
0 0 1 1  
0 0 0 1  
