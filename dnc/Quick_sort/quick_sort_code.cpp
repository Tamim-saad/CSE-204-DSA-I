#include<bits/stdc++.h>
using namespace std;


int rearrange_and_get_pivot_position(int arr[],int low,int high)
{
    int j=low;
    for(int i=low; i<=high-1; i++)
    {
        if(arr[i]<arr[high])
        {
            swap(arr[i],arr[j]);
            j++;
        }
    }
    swap(arr[high],arr[j]);
    return j;
}


void quick_sort(int l,int h,int arr[])
{
    if(l>h) return;
    int pos=rearrange_and_get_pivot_position(arr,l,h);

    quick_sort(l,pos-1,arr);
    quick_sort(pos+1,h,arr);

}


int main()
{
    int t,n,i,j;

    int arr[]= {10,15,1,2,9,16,11};
    n=sizeof(arr)/sizeof(arr[0]);

//    cout<<"Enter size:";
//    cin>>n;
//    int arr[n];
//    for(j=0; j<n; j++) cin>>arr[j];

    quick_sort(0,n-1,arr);

    for(j=0; j<n; j++) cout << arr[j] << " ";
}
