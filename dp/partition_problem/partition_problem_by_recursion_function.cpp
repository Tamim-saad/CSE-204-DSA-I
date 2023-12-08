#include<bits/stdc++.h>
using namespace std;

//int coin_value[]= {1, 2, 4, 5, 10, 20, 40, 50, 100};



int check(int currentCapacity,int n,int coin_value[])
{
    if(currentCapacity==0) return true;
    if(n==0&&currentCapacity!=0) return false;


    if(coin_value[n-1]>currentCapacity)
        return check(currentCapacity,n-1,coin_value);

    return check(currentCapacity,n-1,coin_value)||check(currentCapacity-coin_value[n-1],n-1,coin_value);
}



int main()
{
    //int coin_value[]= {1, 5, 11, 5};
    int coin_value[] = {2,4,11,10,5};

    int amt=0;
    int n=sizeof(coin_value)/sizeof(int);

    for(int i=0; i<n; i++)  amt+=coin_value[i];
    if(amt%2==1) cout<< "false\n";

    else
    {
        amt/=2;
        if(check(amt,n,coin_value)) cout<< "true\n";
        else  cout<< "false\n";

    }
}

