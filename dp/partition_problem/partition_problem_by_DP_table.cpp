#include<bits/stdc++.h>
using namespace std;


long check(int value[],int n,long amt)
{
    // sort(value,value+n);

    bool dp[n+1][amt+1];
    for(int i=1; i<=amt; i++) dp[0][i]=false;
    for(int i=0; i<=n; i++)   dp[i][0]=true;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=amt; j++)
        {
            if(dp[i-1][j]==true||(j-value[i-1]>=0&&dp[i-1][j-value[i-1]]==true))
                dp[i][j]=true;
            else
                dp[i][j]=false;
        }
    }

    return dp[n][amt];
}



int main()
{
//    int value[]= {1, 5, 11, 5};
//    int value[] = {2,4,11,10,5};

    int value[] = {2,4,2,3,2,4,2,3};

    int amt=0;
    int n=sizeof(value)/sizeof(int);

    for(int i=0; i<n; i++)  amt+=value[i];

    if(amt%2==1) cout<< "false\n";
    else
    {
        amt/=2;

        if(check(value,n,amt))
            cout<< "true\n";
        else
            cout<< "false\n";

    }
}

