#include<bits/stdc++.h>
using namespace std;


int maximize_profit(int n,int arr[])
{
    int max_profit,minSoFar;

    max_profit=0;
    minSoFar=arr[0];

    for(int i=1; i<n; i++)
    {
        if(arr[i]>=minSoFar)
            max_profit=max(max_profit,arr[i]-minSoFar);
        else
            minSoFar=arr[i];
    }
    return max_profit;
}


int main()
{
    int n,i;
    int arr[]= {7,1,5,3,6,4};                 //ans=5
//    int arr[]= {7,6,4,3,1};                   //ans=0
//    int arr[]= {100,180,260,310,40,535,695};    //ans=655
//    int arr[]= {4, 2, 2, 2, 4};                 //ans=2

    n=sizeof(arr)/sizeof(arr[0]);

//for console input ->
//    cout<<"Enter size:";
//    cin>>n;
//    int arr[n];
//    for(i=0;i<n;i++) cin>>arr[i];

    cout<<maximize_profit(n,arr)<<endl;
}
