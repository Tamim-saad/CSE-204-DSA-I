#include <bits/stdc++.h>
using namespace std;

int minimumCoins(int coins[], int n, int amt)
{
    sort(coins,coins+n);
    int table[amt+1];
    table[0]=0;

    for(int i=1; i<=amt; i++) table[i]=INT_MAX;

    for(int i=1; i<=amt; i++)
    {
        for(int j=0; j<n&&coins[j]<=i; j++)
        {
            int pre_res=table[i-coins[j]];
            if(pre_res!=INT_MAX&&pre_res+1<table[i])
            {
                table[i]=pre_res+1;
            }
        }
    }
    return table[amt];
}

int main()
{
    int coins[] = {9,6,5,1};
    //int coins[] = {1,5,6,9};
    int size= sizeof(coins) / sizeof(coins[0]);
    int V = 30;
    cout << "Minimum coins required is "
         << minimumCoins(coins, size, V);
    return 0;
}


//int main()
//{
//   	int t;
//    cin >> t;
//    while (t--)
//    {
//        int v, m;
//        cin >> v >> m;
//
//        int coins[m];
//        for(int i = 0; i < m; i++) cin >> coins[i];
//
//	    cout << minimumCoins(coins, m, v) << "\n";
//    }
//}
