#include<bits/stdc++.h>
using namespace std;


int largest_subArray_sum(int n,int arr[])
{
    int maxi,dp[n+1];
    dp[0]=maxi=arr[0];

    for(int i=1; i<n; i++)
    {
        if(dp[i-1]>=0)
            dp[i]=dp[i-1]+arr[i]; //if previous contiguous sum is non-negative then we add current element with this contiguous sum series
        else
            dp[i]=arr[i];         //otherwise we start a new contiguous array from this current element

        maxi=max(maxi,dp[i]);     //each time we check for maximum subArray sum
    }

    return maxi;
}
///DP 1D-table is similar to kadane's algorithm code


int main()
{
    int n,i;

   // int arr[]= {-2,-3,4,-1,-2,1,5,-3};    //ans=7   ->{4,-1,-2,1,5}
    int arr[]= {-2,1,-3,4,-1,2,1,-5,4};   //ans=6   ->{4,-1,2,1}
//    int arr[]= {5,4,-1,7,8};              //ans=23  ->full array

    n=sizeof(arr)/sizeof(arr[0]);

///for console input ->
//    cout<<"Enter size:";
//    cin>>n;
//    int arr[n];
//    for(i=0;i<n;i++) cin>>arr[i];

    cout<<largest_subArray_sum(n,arr)<<endl;
}
