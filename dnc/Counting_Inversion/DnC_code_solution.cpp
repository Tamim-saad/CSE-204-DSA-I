#include<bits/stdc++.h>
using namespace std;

string out="";

///-------------------------------------------------------------------------
int merge_and_count(vector<int> &lst,vector<int> a,vector<int> b)
{
    int i=0,j=0,t=0,ans=0;
    lst.clear();

    while(i<a.size()&&j<b.size())
    {
        if(a[i]>b[j])
        {
            t=i;
            while(t<a.size())
            {
                out=out+"("+to_string(a[t++])+","+to_string(b[j])+"),";
                ans++;
            }
            lst.push_back(b[j++]);
        }
        else  lst.push_back(a[i++]);
    }

    while(i<a.size()) lst.push_back(a[i++]);
    while(j<b.size()) lst.push_back(b[j++]);

    return ans;
}

///------------------------------------------------------------------------

int sort_and_count(vector<int> &lst)
{
    if(lst.size()<=1) return 0;

    vector<int> left_list(lst.begin(),lst.begin()+lst.size()/2);
    vector<int> right_list(lst.begin()+lst.size()/2,lst.end());

    int ra,rb,r=0;

    ra=sort_and_count(left_list);
    rb=sort_and_count(right_list );
    r=merge_and_count(lst,left_list,right_list );

    return r+ra+rb;
}
///------------------------------------------------------------------------

int main()
{
    long long i,n,x;
    cin>>n;
    vector<int> lst ;

    for( i=0; i<n; i++)
    {
        cin>>x;
        lst.push_back(x);
    }

    cout <<"\n-----------------------\n";
    cout<<sort_and_count(lst);

    if(out.size()<=0)
        cout<<"No inverted pairs exists \n";
    else
    {
        cout<<"\nInverted pairs are:\n";
        out.erase(out.size()-1);
        cout<<out<<endl;
    }
}

//sample input:
//5
//2 4 1 3 5

//sample output:
//3
//Inverted pairs are:
//(2,1),(4,1),(4,3)

