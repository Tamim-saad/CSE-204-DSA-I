#include<bits/stdc++.h>
using namespace std;


///Greedy method doesn’t give optimal solution alaways
///For example: {9, 6, 5, 1} and V = 11
///Greedy method would print {9,1,1}
///But optimal solution is {6,5}



int minimum_coin_by_greedy(int arr[], int amt,int n)
{
    sort(arr,arr+n);
    vector<int> vc;

    int sum=0;

    for(int i=n-1; i>=0; i--)
    {
        if(arr[i]<=amt)
        {
            while(arr[i]<=amt)
            {
                amt-=arr[i];
                sum+=arr[i];
                vc.emplace_back(arr[i]);
            }
        }
    }

    for(auto x:vc) cout<<x<<" ";
    return sum;
}



///-----------------driver_code----------------------
int main()
{

    int arr[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};

    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<"\nMaximum possible amount by greedy method: "<<minimum_coin_by_greedy(arr,93,n)<<endl;
}
