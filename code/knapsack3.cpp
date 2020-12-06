/* Solve the knapsack problem by dynamic programming */
#include<iostream>

using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}
int knapSack(int totalWeight, int weight[], int value[],int n)
{
    int i, w;
    int K[n+1][totalWeight+1];

    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= totalWeight; w++)
        {
            if(i == 0 || w == 0){
                K[i][w] = 0;
            }else if(weight[i-1] <= w){
                K[i][w] = max(value[i-1]+K[i-1][w-weight[i-1]], K[i-1][w]);
            }else{
                K[i][w] = K[i-1][w];
            }
        }
    }
    return K[n][totalWeight];
}

//Driver code
int main() 
{ 
    int val[] = { 42, 12, 40, 25 }; 
    int wt[] = { 7, 3, 4, 5 }; 
    int W = 10; 
    int n = sizeof(val) / sizeof(val[0]); 
    cout << knapSack(W, wt, val, n); 
    return 0; 
} 