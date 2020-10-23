/* This is a way using binary bits to solve the 0/1 knapsack problem
**For a bit, 1 means inclueded and 0 means exclueded.
**
** author: youpen_y
*/

#include<iostream>
#include<cmath>
using namespace std;

//Function to show the maxvalue,
//it takes the weight[], value[], and totalVolume: W, and objects totalNumber: N as parameters
void knapsack(int weight[],int value[],int W,int N)
{

    int maxvalue=0;           
    for(int i=0;i<pow(2,N);i++)  //there, i will go through the 2^n cases
    {
        int temp = i;           //can't change i in the loop, else you will change the iteration times, so pass its value to another local varible
        int tempweight=0;
        int tempvalue=0;
        for(int j=0;j<N;j++)
        {
            if(temp%2==1)   //which means the jth bit is 1 
            {
                tempweight+=weight[j];
                tempvalue+=value[j];
            }
            temp=temp/2;   //this sentence equal to  i>>1

            if(tempweight<=W)
            {
                if(tempvalue>maxvalue)
                    maxvalue=tempvalue;
            }
            if(temp==0)     //conditions for breaking out the inner loop
                break;
        }
    }
    cout<<"The Maxvalue is "<<maxvalue<<endl;
}

// Driver code
int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    knapsack(wt,val,W,n);
    return 0;
}
