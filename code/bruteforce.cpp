/* A Naive recursive implementation of 
 0-1 Knapsack problem */
#include <bits/stdc++.h> 
using namespace std; 
  
// A utility function that returns 
// maximum of two integers 
int max(int a, int b) { return (a > b) ? a : b; } 
  
// Returns the maximum value that 
// can be put in a knapsack of capacity
int knapSack(int totalWeight, int weight[], int value[], int n) 
{ 
  
    // Base Case 
    if (n == 0 || totalWeight == 0) 
        return 0; 
  
    // If weight of the nth item is more 
    // than Knapsack capacity W, then 
    // this item cannot be included 
    // in the optimal solution 
    if (weight[n] > totalWeight) 
        return knapSack(totalWeight, weight, value, n - 1); 
  
    // Return the maximum of two cases: 
    // (1) nth item included 
    // (2) not included 
    else
        return max( 
            value[n] + knapSack(totalWeight - weight[n],  weight, value, n - 1), 
            knapSack(totalWeight, weight, value, n - 1)); 
} 
  
// Driver code 
int main() 
{ 
    int val[] = { 42, 12, 40, 25 }; 
    int wt[] = { 7, 3, 4, 5 }; 
    int W = 10; 
    int n = sizeof(val) / sizeof(val[0]); 
    cout << knapSack(W, wt, val, n); 
    return 0; 
} 