#include <bits/stdc++.h>
using namespace std;

struct Element
{
    double value;
    double weight;
    double profitPerUnit;
};

bool compare(Element a,Element b)
{
    return a.profitPerUnit<=b.profitPerUnit;    //non-decreasing order
}


double fractionalKnapsack(int capacity,Element arr[],int n)
{
    sort(arr,arr+n,compare); //sort by profitPerUnit

    double profit=0;

    for(int i=n-1; i>=0; i--)
    {
        if(arr[i].weight<=capacity)
        {
            capacity-=arr[i].weight;
            profit+=arr[i].value;
        }
        else
        {
            profit+=arr[i].profitPerUnit*capacity;  //including fraction
            break;
        }
    }
    return profit;
}


int main()
{
    int n, capacity;
    cin>>n;

    Element arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i].weight>>arr[i].value;
        arr[i].profitPerUnit=arr[i].value/arr[i].weight;
    }
    cin>>capacity;

    cout<<fractionalKnapsack(capacity, arr, n)<<endl;
}




//5
//5 30
//10 40
//15 45
//22 77
//25 90
//60
//answer=230
