Program 
#include <stdio.h> 
// Function to return the maximum of two integers 
int max(int a, int b) { 
 return (a > b) ? a : b; 
} 
// Function to solve the 0/1 Knapsack problem 
void knapsack(int W, int wt[], int val[], int n) { 
 int i, w; 
 int K[n + 1][W + 1]; 
 // Build table K[][] in bottom up manner 
 for (i = 0; i <= n; i++) { 
 for (w = 0; w <= W; w++) { 
 if (i == 0 || w == 0) { 
 K[i][w] = 0; 
 } else if (wt[i - 1] <= w) { 
 K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
 } else { 
 K[i][w] = K[i - 1][w]; 
 } 
 } 
 } 
 // Print the table K 
 printf("KnapSack Table:\n"); 
 for (i = 0; i <= n; i++) { 
 for (w = 0; w <= W; w++) { 
 printf("%d\t", K[i][w]); 
 } 
 printf("\n"); 
 } 
 // Print the result 
 printf("Maximum value that can be obtained: %d\n", K[n][W]); 
 // To find which items are included 
 int res = K[n][W]; 
 w = W; 
 printf("Items included:\n"); 
 for (i = n; i > 0 && res > 0; i--) { 
 if (res == K[i - 1][w]) 
 continue; 
 else { 
 printf("Item %d (Weight: %d, Value: %d)\n", i, wt[i - 1], val[i - 1]);  res = res - val[i - 1]; 
 w = w - wt[i - 1]; 
 } 
 } 
} 
int main() { 
 int n, W; 
 printf("Enter the number of items: "); 
 scanf("%d", &n); 
 int val[n], wt[n]; 
 printf("Enter the values of the items:\n"); 
 for (int i = 0; i < n; i++) { 
 printf("Value of item %d: ", i + 1); 
 scanf("%d", &val[i]); 
 } 
 printf("Enter the weights of the items:\n"); 
 for (int i = 0; i < n; i++) { 
 printf("Weight of item %d: ", i + 1); 
 scanf("%d", &wt[i]); 
 } 
 printf("Enter the maximum capacity of the knapsack: "); 
 scanf("%d", &W); 
 knapsack(W, wt, val, n); 
 return 0; 
}



Results 
Enter the number of items: 4 
Enter the values of the items: 
Value of item 1: 60 
Value of item 2: 100 
Value of item 3: 120 
Value of item 4: 50 
Enter the weights of the items: 
Weight of item 1: 10 
Weight of item 2: 20 
Weight of item 3: 30 
Weight of item 4: 5 
Enter the maximum capacity of the knapsack: 50 
KnapSack Table: 
0 0 0 0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 60  60 60 60 60 60 60 60 60 60 60 60  60 60 60 60 60 60 60 60 60 60 60  60 60 60 60 60 60 60 60 60 60 60  60 60 60 60 60 60 60 
0 0 0 0 0 0 0 0 0 0 60  60 60 60 60 60 60 60 60 60 100 100  100 100 100 160 160 160 160 160 160 160 160  160 160 160 160 160 160 160 160 160 160 160  160 160 160 160 160 160 160 
0 0 0 0 0 0 0 0 0 0 60  60 60 60 60 60 60 60 60 60 100 100  100 100 100 160 160 160 160 160 180 180 180  180 180 220 220 220 220 220 220 220 220 220  220 220 220 220 220 220 220 
0 0 0 0 0 50 50 50 50 50 60  60 60 60 60 60 60 60 60 60 100 100  100 100 100 160 160 160 160 160 180 180 180  180 180 220 220 220 220 220 220 220 220 220  220 220 220 220 220 220 220 
Maximum value that can be obtained: 220 
Items included: 
Item 3 (Weight: 30, Value: 120) 
Item 2 (Weight: 20, Value: 100) 
