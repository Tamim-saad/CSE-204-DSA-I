#include<bits/stdc++.h>
using namespace std;


void merge_sort(int l,int h,int arr[])
{
    //return case
    if(l==h) return;

    int mid=(l+h)/2;

    //divide into 2 part
    merge_sort(l,mid,arr);
    merge_sort(mid+1,h,arr);

    //declare and initialize further necessary variable
    int i,j,k,sorted_array[h-l+1];
    i=l;
    j=mid+1;
    k=0;

    //transfer to sorted_array as an intermediate array
    while(i<=mid&&j<=h)
    {
        if(arr[i]<arr[j]) sorted_array[k++]=arr[i++];
        else              sorted_array[k++]=arr[j++];
    }
    //transfer rest part of the array
    while(i<=mid) sorted_array[k++]=arr[i++];
    while(j<=h)   sorted_array[k++]=arr[j++];

    //changing the main array
    for(i=l; i<=h; i++)
    {
        arr[i]=sorted_array[i-l];
    }

    return;
}


int main()
{
    int t,n,i,j;

//    int arr[]= {10,15,1,2,9,16,11};
    int arr[]= {11,1,87,15,25,-48,85,11,25,11,48};

    n=sizeof(arr)/sizeof(arr[0]);

//    cout<<"Enter size:";
//    cin>>n;
//    int arr[n];
//    for(j=0; j<n; j++) cin>>arr[j];

    merge_sort(0,n-1,arr);

    for(j=0; j<n; j++) cout << arr[j] << " ";
}
