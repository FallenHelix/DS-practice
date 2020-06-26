#include<bits/stdc++.h>

using namespace std; 


int direction(pair<int, int> p , pair<int, int> q, pair<int, int> r)
{
     int val = (q.second - p.second) * (r.first - q.first) - (q.first - p.first) * (r.second - q.second); 

    if(val == 0 )
        return 0;  //colinear
    return val > 0? 1 : 2; // clockwise or anticlockwise
}

void Jarvis(vector< pair<int, int> > a )
{
    // sort(a.begin(), a.end()  );
    pair<int, int> start = *a.begin();
    int index= 0 , point;
    vector<pair<int, int> > points;

    //PUsh the left most point into the set of points


    int n = a.size();
    if(n < 4)
    {
        return ;
    }
    for ( int i = 0 ; i< n; i++)
    {
        if(start.first < a[i].first)
        {
            start = a[i];
            index = i;
        }

    }



    vector<int> hull ; 

    point  = index;
    int endpoint, temp;

    do
    {
        points.push_back(a[point]);
        // endpoint = a[0];
        temp = (point+1)%n;
        for(int  j = 0 ; j< n; j++)
        {
            if(j != point )
            {
                int d = direction(a[point], a[j], a[temp]);
                if(d == 2)
                {
                    temp = j;
                }

            }
        }
        point = temp;      
    } while (point !=index);
    
    for(auto p :points)
    {
        cout<<"( "<<p.first<< ", " <<p.second<<" )"<<"\n";

    }


}

int main()
{

    vector< pair< int, int> > a =    {{0,0} , {1, 4}, {5, 5}, {9, 6},{7, 0}, {3, 1}, {3, 3}, {5, 2}};


    Jarvis(a);
}