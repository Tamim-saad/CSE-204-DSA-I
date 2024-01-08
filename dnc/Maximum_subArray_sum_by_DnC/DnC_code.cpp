#include<bits/stdc++.h>
using namespace std;


int largest_subArray_sum(int l,int h,int arr[])
{
    //return case
    if(h==l) return arr[l];

    int n,i,mid,maxLeft,maxRight;

    n=h-l+1;
    maxLeft=INT_MIN;
    maxRight=INT_MIN;
    mid=(l+h)/2;

    //divide into left and right part
    int left_largest=largest_subArray_sum(l,mid,arr);      //determine maximum for left subset
    int right_largest=largest_subArray_sum(mid+1,h,arr);   //determine maximum for right subset


    //determine maximum for cross set that starts from left array and ends to right array
    int left_sum=0;
    int right_sum=0;

    for(i=mid; i>=l; i--)
    {
        left_sum+=arr[i];
        maxLeft=max(maxLeft,left_sum);
    }
    for(i=mid+1; i<=h; i++)
    {
        right_sum+=arr[i];
        maxRight=max(maxRight,right_sum);
    }

    //return maximum of left subset, right subset and cross subset
    return max(maxLeft+maxRight,max(left_largest,right_largest));
}


int main()
{
    int n,i;

//    int arr[]= {-2,-3,4,-1,-2,1,5,-3};    //ans=7   ->{4,-1,-2,1,5}
//    int arr[]= {-2,1,-3,4,-1,2,1,-5,4};   //ans=6   ->{4,-1,2,1}
    int arr[]= {5,4,-1,7,8};              //ans=23  ->full array

    n=sizeof(arr)/sizeof(arr[0]);

///for console input ->
//    cout<<"Enter size:";
//    cin>>n;
//    int arr[n];
//    for(i=0;i<n;i++) cin>>arr[i];

    cout<<largest_subArray_sum(0,n-1,arr)<<endl;
}
