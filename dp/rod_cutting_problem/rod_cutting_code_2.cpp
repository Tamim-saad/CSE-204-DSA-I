#include<bits/stdc++.h>
using namespace std;
long dp[100000];

long lenArr[]={1, 2, 3, 4, 5, 6, 7, 8};
long profit[]={1, 5, 8, 9, 10, 17, 17, 20};
long gbc=1;



long newwMax(long len)
{
    if(len<=0) return 0;
    if(dp[len]!=0) return dp[len];

    long maxi=-1;

    for(long i=1;i<=len;i++)
    {
        if(dp[len-i]!=0)
        {
            maxi=max(maxi,(profit[i-1]+dp[len-i]));
            continue;
        }

        maxi=max(maxi,(profit[i-1]+newwMax(len-i)));
        //cout<<gbc++<<" ";
    }
    dp[len]=maxi;
    return maxi;
}

int main()
{
//    long wtlim=sizeof(wt)/sizeof(long);
//    long val_lim=sizeof(val)/sizeof(long);
    //wtlim=5;

//    for(long i=0;i<val_lim;i++)
//    {
//        for(long j=0;j<wtlim;j++)
//        {
//            cout << maximize(i,j) << " ";
//        }
//        cout<<endl;
//    }

//          cout << maximize(i,j) << " ";

    cout<<endl<<newwMax(4);

    return 0;
}
