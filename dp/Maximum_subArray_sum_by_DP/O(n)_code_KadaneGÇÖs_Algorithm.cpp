#include<bits/stdc++.h>
using namespace std;


int largest_subArray_sum(int l,int h,int arr[])
{
    int maxi=INT_MIN,sum=0;
    int n=h-l+1;

    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
        maxi=max(maxi,sum);
        if(sum<=0) sum=0;
    }

    return maxi;
}


int main()
{
    int n,i;

    int arr[]= {-2,-3,4,-1,-2,1,5,-3};    //ans=7   ->{4,-1,-2,1,5}
//    int arr[]= {-2,1,-3,4,-1,2,1,-5,4};   //ans=6   ->{4,-1,2,1}
//    int arr[]= {5,4,-1,7,8};              //ans=23  ->full array

    n=sizeof(arr)/sizeof(arr[0]);

///for console input ->
//    cout<<"Enter size:";
//    cin>>n;
//    int arr[n];
//    for(i=0;i<n;i++) cin>>arr[i];

    cout<<largest_subArray_sum(0,n-1,arr)<<endl;
}
