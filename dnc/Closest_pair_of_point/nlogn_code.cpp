#include<bits/stdc++.h>
using namespace std;

///--------------structure----------------
struct Point
{
    long double x,y;
};

///-----------helping_function--------------
bool compare(Point p1,Point p2)
{
    return p1.x<=p2.x;
}
long double dist(Point p1,Point p2)
{
    return sqrtl((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
};
int binSearch(Point point[],int n,long double value)
{
    int l=0,h=n-1,mid;
    while(l<h)
    {
        mid=(l+h)/2;
        if(value<=point[mid].x) h=mid-1;
        else l=mid+1;
    }
    return h;
}


///---------------main_function------------------------

long double closest(Point point[],int l,int h)
{
    int n;

    n=h-l+1;

    if(n==1) return -1;
    if(n==2) return dist(point[0],point[1]);
    if(n==3) return min(dist(point[0],point[1]),min(dist(point[0],point[2]),dist(point[2],point[1])));

    int mid=(h+l)/2;

    long double dl=closest(point,l,mid);
    long double dr=closest(point,mid+1,h);
    long double d=min(dl,dr);

    Point midPoint=point[mid];

    int low,high;

    low=binSearch(point,n,midPoint.x-d);
    high=binSearch(point,n,midPoint.x+d);

    for(int i=low; i<=high; i++)
    {
        for(int j=1; j<=7; j++)
        {
            d=min(d,dist(point[i],point[i+j]));
        }
    }
    return d;

}



///------------------driver_code----------------------
int main()
{
//    Point p[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};   //ans for this set is 1.414214
//    Point p[] = {{0,0}, {0,1}, {100, 45}, {2,3}, {9,9}};                  //ans for this set is 1
//    Point p[] = {{0,0}, {-4,1}, {-7, -2}, {4,5}, {1,1}};                  //ans for this set is 1.414214
    Point p[] = {{2,3}, {5,1}, {12, 30}};                                   //ans for this set is 3.605551

    int n = sizeof(p) / sizeof(p[0]);

    sort(p,p+n,compare);  //sort struct Point by X co-ordinate
    cout <<closest(p,0, n-1);
}
