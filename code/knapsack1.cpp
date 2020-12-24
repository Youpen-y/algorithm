/* This is a way using binary bits to solve the 0/1 knapsack problem
** For a bit, 1 means inclueded and 0 means exclueded.
** eg. 1100 means first and second is inclued, and third and fourth is exclued.
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
	int result=0;
	int path[N];         //record the items that be included. eg. If the third item was included, then path[2] = 1；
    for(int i=0;i<pow(2,N);i++)  //there, i will go through the 2^n cases
    {
        int temp = i;           //can't change i in the loop, else you will change the iteration times, so pass its value to another local varible
        int tempweight=0;
        int tempvalue=0;
        for(int j=N-1;j>=0;j--)
        {
            if(temp%2==1)   //which means the jth bit is 1 
            {
                tempweight+=weight[j];
                tempvalue+=value[j];
            }
            temp=temp/2;   //this sentence equal to  i>>1

            if(tempweight<=W)
            {
                if(tempvalue>maxvalue){
                    maxvalue=tempvalue;
					result=i;
				}
            }
            if(temp==0)     //conditions for breaking out the inner loop
                break;
        }
    }
	for(int k=N-1;k>=0;k--){    //find the items compose the Maxvalue, 
		if(result%2==1)
			path[k]=1;
		else
			path[k]=0;
		result = result/2;
	}
	for(int k=0;k<N;k++){
		if(path[k]==1)
		    cout<<" ("<<value[k]<<", "<<weight[k]<<")";
	}
	
    cout<<"\nThe Maxvalue is "<<maxvalue<<endl;
}

// Driver code
int main()
{
    int val[] = { 42, 12, 40, 25 };
    int wt[] = { 5, 3, 4, 5 };
    int W = 10;
    int n = sizeof(val) / sizeof(val[0]);
    knapsack(wt,val,W,n);
    return 0;
}