#include<bits/stdc++.h>
using namespace std;

struct Job
{
    int start;
    int end;
    int profit;
};

bool compare(Job a,Job b)
{
    if(a.end==b.end)
        return a.start<b.start;
    else
        return a.end<b.end;
}



int JobScheduling(Job arr[], int n)
{

    sort(arr+1,arr+n,compare); //sort all element. here used index starts from i=1

    int compatible[n+1];
    compatible[0]=compatible[1]=0;  //0 is not used in indexing

    for(int i=2; i<=n; i++)  //prepare non-conflicting compatible list
    {
        int j=i;
        while(arr[j].end>arr[i].start&&j>0) j--;
        compatible[i]=j;
    }


    int opt[n+1];
    opt[0]=0;   //0 is not used in indexing
    opt[1]=arr[1].profit;

    for(int i=1; i<=n; i++)   //preparing DP 1D-table
    {
        int include=arr[i].profit+opt[compatible[i]];
        int exclude=opt[i-1];

        opt[i]=max(include,exclude);  //maximize profit
    }

    return opt[n];
}



int main()
{
    int n;
    cin>>n;
    Job arr[n];

    //0 is not used in indexing
    for(int i = 1; i<=n; i++)
    {
        cin>>arr[i].start;
        cin>>arr[i].end;
        cin>>arr[i].profit;
    }

    cout<<"\nProfit: "<<JobScheduling(arr, n)<<endl<<endl;
}


///sample IO
/*
input-1:
6
0 6 60
1 4 30
3 5 10
5 7 30
5 9 50
7 8 10
output-1:80  //{1 4 30}+{5 9 50}


input-2:
2
1 4 10
4 8 20
output-2:30  //all job]


input-3:
3
1 5 60
4 8 100
6 10 60
output-3:120  //{1 5 60}+{6 10 60}

input-3:
5
1 3 20
3 6 20
5 12 100
7 9 70
10 14 60
output-3:170  //{1 3 20}+{3 6 20}+{7 9 70}+{10 14 60}

*/





///---------------to see sorted job list---------
//        for(int i = 1; i<=n; i++)
//            cout<<arr[i].start <<" --- "<<arr[i].end<<" --- "<<arr[i].profit<<endl ;


///----------------to see compatible set----------------
//        for(int i = 1; i<=n; i++)
//            cout<<" ----------- "<<compatible[i]<<" "<<endl ;


///----------------to see opt list----------------
//        for(int i = 1; i<=n; i++)
//            cout<<" ----opt------- "<<opt[i]<<" "<<endl ;



///binSearch function below is not correct properly :(  .So it is not used
//int binSearch(Job arr[],int n,int ind)   //here ind= position of current job
//{
//    int l,h,mid;
//
//    l=1;
//    h=n-1;
//
//    while(l<=h)
//    {
//        mid=(l+h)/2;
//        if(arr[ind].start<=arr[mid].end)
//            h=mid-1;
//        else
//            l=mid+1;
//    }
//
//    return mid;
//}

