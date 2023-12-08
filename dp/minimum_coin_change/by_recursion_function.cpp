#include<bits/stdc++.h>
using namespace std;


long coin_value[]= {1, 2, 4, 5, 10, 20, 40, 50, 100};


long minimize(long currentCapacity,int n)
{
    if(n<=0) return INT_MAX;
    if(currentCapacity<=0) return 0;

    if(coin_value[n-1]>currentCapacity) return minimize(currentCapacity,n-1);

    else return min(minimize(currentCapacity,n-1),1+minimize(currentCapacity-coin_value[n-1],n));

}



int main()
{
    int n=sizeof(coin_value)/sizeof(long);
    cout<<endl<<minimize(83,n);
}


//ans=4;
