#include<bits/stdc++.h>
using namespace std;


int findPlatform(int arr[], int dep[], int n)
{
    sort(arr,arr+n);
    sort(dep,dep+n);

    int i=1,j=0,maxi=1;

    while(i<n)
    {
        if(arr[i]<=dep[j])  //new train->i arrives the station sooner than train->j's (train->j is already present in station) departure.So 1 extra platform is needed
            i++;    //by increasing i, we add one extra platform in station

        else   //present new train->i arrives the station later than train->j's (train->j is already present in station) departure.So 1 platform became free
            j++;  //by increasing j, we free one used platform

        maxi=max(maxi,i-j); //(i-j) represnt present used platform .So each time we consider the maximum used platform(which is our answer)
    }
    return maxi;
}



///------------------driver_code----------------------
int main()
{

    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};

    int n=sizeof(arr)/sizeof(arr[0]),maxi=-1;

    cout<<findPlatform(arr,dep,n);
}
