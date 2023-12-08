#include<bits/stdc++.h>
using namespace std;

long elementsLenArr[]={1, 2, 3, 4, 5, 6, 7, 8};
long profit[]={1, 5, 8, 9, 10, 17, 17, 20};



long maximize(long maxLen,int n)
{
    if(n<=0||maxLen<=0) return 0;

    if(elementsLenArr[n-1]>maxLen) maximize(maxLen,n-1);

    else return max(maximize(maxLen,n-1),profit[n-1]+maximize(maxLen-elementsLenArr[n-1],n));
}


int main()
{
    int len=sizeof(elementsLenArr)/sizeof(long);
    cout<<maximize(4,len+1);
}




//    for(long i=0;i<val_lim;i++)
//    {
//        for(long j=0;j<profitlim;j++)
//        {
//            cout << maximize(i,j) << " ";
//        }
//        cout<<endl;
//    }
