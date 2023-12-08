#include<bits/stdc++.h>
using namespace std;
map<int,bool> mp;

//--------------determine profit------------------------
int maximize(int n,int capacity,int wt[],int val[])
{
    if(n<=0) return 0;
    if(wt[n-1]>capacity) return maximize(n-1,capacity,wt,val);

    return max(maximize(n-1,capacity,wt,val),val[n-1]+maximize(n-1,capacity-wt[n-1],wt,val));
}

//--------------determine element------------------------
void counting(int n,int capacity,int wt[],int val[])
{
    if(n<=0) return ;
    if(wt[n-1]>capacity) return   counting(n-1,capacity,wt,val);

    if(maximize(n-1,capacity,wt,val)<maximize(n-1,capacity-wt[n-1],wt,val)+val[n-1])
    {
        mp[n-1]=true;
        return  counting(n-1,capacity-wt[n-1],wt,val);
    }
    return  counting(n-1,capacity,wt,val);
}



int main()
{
        int n,capacity;

    int w[]= {20,10,40,30};
    int v[]= {40,100,50,60};
    n=4;
    capacity=60;


//for console input->
//    cin>>n;
//
//    int w[n],v[n];
//    for(int i=0; i<n; i++)
//    {
//        cin>>w[i]>>v[i];
//    }
//    cin>>capacity;


    cout<<endl<<maximize(n,capacity,w,v)<<endl;

    counting(n,capacity,w,v);

    for(int i=0; i<=n; i++)
        if(mp[i]==true) cout<<w[i]<<" ";
}




//sample IO
//4
//20 40
//10 100
//40 50
//30 60
//60
////----------
//200
//20 10 30
