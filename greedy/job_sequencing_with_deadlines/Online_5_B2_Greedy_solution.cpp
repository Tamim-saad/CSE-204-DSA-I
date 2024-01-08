/// this problem is similar to "job_sequencing_with_deadlines"

#include<bits/stdc++.h>
using namespace std;

struct People
{
    int waiting_time;
    int profit;
    int number;
};

bool compare(People a,People b)
{
    return a.profit>=b.profit;   //here (>=) is used to sort by non-increasing order
}


int main()
{
    int n,i,t,maxProfit=0;
    cin>>n;

    People p[n];
    int out[n];


    //-----input----------------
    for(i=0; i<n; i++)
    {
        cin>>p[i].waiting_time>>p[i].profit;

        p[i].number=i+1;
        out[i]=-1;
    }
    sort(p,p+n,compare);  //sort by non-increasing order


    //---------main_part---------
    for(i=0; i<n; i++)
    {
        t=p[i].waiting_time-1;

        while(out[t]!=-1) t--;  //finding possible maximum position in its waiting time range

        if(t>=0)                //check whether it can be possible to include within its waiting time range
        {
            out[t]=p[i].number;
            maxProfit+=p[i].profit;
        }
    }


    //-------show output---------

    cout<<"\n----------\n"<<endl;
    sort(out,out+n);

    for(i=0; i<n; i++)
    {
        if(out[i]!=-1)
            cout<<out[i]<<" ";
    }
    cout<<endl<<"Maximum profit: "<<maxProfit<<endl;

}



//sample input
//10
//9 15
//2 2
//5 18
//7 1
//4 25
//2 20
//5 8
//7 10
//4 12
//3 5
//
//sample output
//1 3 4 5 6 7 8 9
//Maximum profit: 109
