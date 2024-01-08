#include<bits/stdc++.h>
using namespace std;

struct People
{
    int start;
    int end;
};

bool compare(People a,People b)
{
    if(a.end==b.end)
        return a.start<b.start;
    else
        return a.end<b.end;
}


int main()
{
    int n,k=0,flag=0;
    cin>>n;
    People p[n],out[n];

//-----------input----------------------
    for(int i=0; i<n; i++)
    {
        cin>>p[i].start>>p[i].end;
        if(p[i].start>p[i].end) flag=1;
    }

//-----------check_validity-----------------------
    if(flag)
    {
        cout<<"Please Enter Valid Input\n";
        return 0;
    }
    sort(p,p+n,compare);

//-----------get_output_array-----------

    int now=0;
    out[k++]=p[now];

    for(int next=1; next<n; next++)
    {
        while(p[now].end>p[next].start) next++;

        if(next<n)
        {
            now=next;
            out[k++]=p[now];
        }
    }

//-------------print------------------

    cout<<"Output:--------\n"<<k<<endl;
    for(int i=0; i<k; i++)
    {
        cout<<out[i].start<<" "<<out[i].end<<endl;
    }
}
