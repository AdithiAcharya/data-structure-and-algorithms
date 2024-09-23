Pseudocode 
function KruskalMST(edges, V, E): 
 sort edges in non-decreasing order of their weight 
 initialize parent array with -1 for each vertex 
 result = empty list 
 for i from 0 to E-1: 
 if size of result == V-1: 
 break 
 next_edge = edges[i] 
 xset = find(parent, next_edge.src) 
 yset = find(parent, next_edge.dest) 
 if xset != yset: 
 result.append(next_edge) 
 union(parent, xset, yset)
function find(parent, i): 
 while parent[i] != -1: 
 i = parent[i] 
 return i 
function union(parent, x, y): 
 parent[x] = y 


Program 
#include <stdio.h> 
#include <stdlib.h> 
#define MAX_VERTICES 4 
#define MAX_EDGES 5 
typedef struct Edge { 
 int src, dest, weight; 
} Edge; 
// Function to implement Kruskal's algorithm 
void KruskalMST(Edge* edges, int V, int E) { 
 Edge result[V]; 
 int e = 0; 
 int i = 0; 
 // Sort the edges based on weight (ascending order) 
 for (int i = 0; i < E - 1; i++) { 
 for (int j = 0; j < E - i - 1; j++) { 
 if (edges[j].weight > edges[j + 1].weight) { 
 Edge temp = edges[j]; 
 edges[j] = edges[j + 1]; 
 edges[j + 1] = temp; 
 } 
 } 
 } 
 int parent[V]; 
 for (int v = 0; v < V; v++) 
 parent[v] = -1; 
 while (e < V - 1 && i < E) { 
 Edge next_edge = edges[i++]; 
 int xset = next_edge.src; 
 int yset = next_edge.dest; 
 // Check if including this edge causes cycle or not 
 while (parent[xset] != -1) 
 xset = parent[xset]; 
 while (parent[yset] != -1) 
 yset = parent[yset]; 
 if (xset != yset) { 
 result[e++] = next_edge; 
 parent[xset] = yset; // Union of two sets 
 } 
 }
 printf("Edges of Minimum Cost Spanning  
Tree:\n"); 
 int minimumCost = 0; 
 for (i = 0; i < e; ++i) { 
 printf("%d - %d: %d\n", result[i].src, result[i].dest, result[i].weight);  minimumCost += result[i].weight; 
 } 
 printf("Minimum Cost Spanning Tree: %d\n", minimumCost); 
} 
int main() { 
 Edge edge[MAX_EDGES] = { { 0, 1, 10 }, 
 { 0, 2, 6 }, 
{ 0, 3, 5 }, 
{ 1, 3, 15 }, 
{ 2, 3, 4 } }; 
 KruskalMST(edge, MAX_VERTICES, MAX_EDGES); 
 return 0; 
} 

Results 
Edges of Minimum Cost Spanning Tree: 
2 - 3: 4 
0 - 3: 5 
0 - 1: 10 
Minimum Cost Spanning Tree: 19 
