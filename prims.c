Pseudocode 
function primMST(graph): 
 Initialize key array with INF values 
 Initialize mstSet array with false values 
 key[0] = 0 
parent[0] = -1 
 for count from 0 to V-1: 
 u = minKey(key, mstSet) 
 mstSet[u] = true 
 for each vertex v adjacent to u: 
 if graph[u][v] != 0 and mstSet[v] == false and graph[u][v] < key[v]:  parent[v] = u
8 
ANALYSIS & DESIGN OF ALGORITHMS laboratory Semester IV 
Department of Artificial Intelligence and Machine Learning 
 key[v] = graph[u][v] 
 print MST edges and weights using parent array 
function minKey(key, mstSet): 
 min = INF 
 for v from 0 to V-1: 
 if mstSet[v] == false and key[v] < min: 
 min = key[v] 
 min_index = v 
 return min_index 


Program 
#include <stdio.h> 
#include <stdbool.h> 
#define V 5 
#define INF 9999 
int graph[V][V] = { 
 {0, 2, 0, 6, 0}, 
 {2, 0, 3, 8, 5}, 
 {0, 3, 0, 0, 7}, 
 {6, 8, 0, 0, 9}, 
 {0, 5, 7, 9, 0} 
}; 
int minKey(int key[], bool mstSet[]) { 
 int min = INF, min_index; 
 for (int v = 0; v < V; v++) 
 if (mstSet[v] == false && key[v] < min) 
 min = key[v], min_index = v; 
 return min_index; 
} 
void primMST() { 
 int parent[V]; 
 int key[V]; 
bool mstSet[V]; 
 for (int i = 0; i < V; i++) 
 key[i] = INF, mstSet[i] = false; 
 key[0] = 0; 
 parent[0] = -1; 
 for (int count = 0; count < V - 1; count++) { 
 int u = minKey(key, mstSet); 
 mstSet[u] = true; 
 for (int v = 0; v < V; v++) 
 if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])  parent[v] = u, key[v] = graph[u][v]; 
 }printf("Edge \tWeight\n"); 
 for (int i = 1; i < V; i++) 
 printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]); } 
int main() { 
 primMST(); 
 return 0; 
} 


Results 
Edge Weight 
0 - 1 2 
1 - 2 3 
0 - 3 6 
1 - 4 5 

