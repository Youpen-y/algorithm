/*
** Find subarray whose sum is value s
*/

#include<iostream>

using namespace std;

int main()
{
    int n, m, i, front=1, back=1;
    cin>>n>>m;
    int a[n+1], summ[n+1];
    for(i = 1;i <= n;i++){
        cin>>a[i];
    }
    summ[0] = 0;
    for(i=1;i<=n;i++){
        summ[i]=summ[i-1]+a[i];     //store the sum of subarray in array[i]
    }
    while(front<=n&&back<=n){
        if(summ[front]-summ[back-1]<m){ 
            front++;
        }
        if(summ[front]-summ[back-1]>m){
            back++;
        }
        else
        {
            break;
        }
        
    }
    if(front>n||back>n)
        cout<<-1<<endl;
    else
    {
        cout<<back<<" "<<front<<endl;
    }
    return 0;
}