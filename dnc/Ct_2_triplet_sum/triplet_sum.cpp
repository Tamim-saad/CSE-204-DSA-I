#include<bits/stdc++.h>
using namespace std;

int triplet(int a[],int l,int h)
{
    if(h-l==2) return a[l]+a[l+1]+a[l+2];

    else
    {
        int left=triplet(a,l,l+2);
        int right=triplet(a,l+1,h);
        return max(left,right);
    }
}

int main()
{
     cout<<"Enter size:";
     int n;
    cin>>n;
    int arr[n];
    for(int j=0; j<n; j++) cin>>arr[j];

    cout<<triplet(arr,0,n-1);
}
