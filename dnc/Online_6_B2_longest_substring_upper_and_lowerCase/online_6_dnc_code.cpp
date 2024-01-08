#include<bits/stdc++.h>
using namespace std;

string divide_and_conquer(string s)
{
    int flag=1,flag1=0,flag2=0,x,i,count;
    for(x=0; x<s.size(); x++)
    {
        char u,d,c;
        string left,right,s1,s2;
        int flag1=0,flag2=0;
        c=s[x];
        d=tolower(c);
        u=toupper(c);
        for(i=0; i<s.size(); i++)
        {
            if(s[i]==d) flag1=1;
            if(s[i]==u) flag2=1;
        }
        if(flag1==1&&flag2==1) continue;
        else
        {
            flag=0;
            left=s.substr(0,x);
            right=s.substr(x+1,s.size()-x);

            s1=divide_and_conquer(left);
            s2=divide_and_conquer(right);

            if(s1.size()>=s2.size()) return s1;
            else return s2;
        }
    }
    if(flag==1) return s;
}


int main()
{
    string s = "xyYAAYaxyXZa";
    cout << divide_and_conquer(s) << endl;
    return 0;
}
