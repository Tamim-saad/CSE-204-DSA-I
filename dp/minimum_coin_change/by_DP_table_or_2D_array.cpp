#include <bits/stdc++.h>
using namespace std;


long minCoins(int coin_value[],int n,long amt)
{
    sort(coin_value,coin_value+n);

    //set corner value
    long dp[n+1][amt+1];
    for(int i=1; i<=amt; i++) dp[0][i]=-1;///----***-----
    for(int i=0; i<=n; i++)   dp[i][0]=0;


    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=amt; j++)
        {
///----------------------***----------------------------
            if(j-coin_value[i-1]>=0)
            {

                if(dp[i-1][j]!=-1&&dp[i][j-coin_value[i-1]]!=-1)
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-coin_value[i-1]]);

                else if(dp[i-1][j]!=-1&&dp[i][j-coin_value[i-1]]==-1)
                    dp[i][j]=dp[i-1][j];

                else if(dp[i-1][j]==-1&&dp[i][j-coin_value[i-1]]!=-1)
                    dp[i][j]=1+dp[i][j-coin_value[i-1]];

                else if(dp[i-1][j]==-1&&dp[i][j-coin_value[i-1]]==-1)
                    dp[i][j]=-1;

            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
///----------------------***-----------------------------
        }
    }
    return dp[n][amt];
}



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int v,m;
        cin>>v>>m;

        int coins[m];
        for(int i=0; i<m; i++) cin>>coins[i];

        cout<<minCoins(coins,m,v)<<"\n";
    }
}
