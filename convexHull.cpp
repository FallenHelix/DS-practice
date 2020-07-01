#include <bits/stdc++.h>
using namespace std;
const double E = 1e-9, pi = 2 * acos(0);
struct Point {
    int x, y, id;
};
Point operator - (Point a, Point b){
    return (Point){a.x - b.x, a.y - b.y, -1};
}
long long cross(Point a, Point b){
    return 1ll * a.x * b.y - 1ll * a.y * b.x;
}
long long cross(Point a, Point b, Point c){
    return cross(b - a, c - a);
}
vector<Point> convex_hull(vector<Point> points){
    sort(points.begin(), points.end(), [&](Point a, Point b){
        if(a.y != b.y) return a.y < b.y;
        return a.x < b.x;
    });
    vector<Point> upper, lower;
    for(int i = 0; i < (int)points.size(); i++){
        while(upper.size() >= 2 && cross(upper.end()[-2], upper.end()[-1], points[i]) > 0)
            upper.pop_back();
        upper.push_back(points[i]);
    }
    for(int i = (int)points.size() - 1; i >= 0; i--){
        while(lower.size() >= 2 && cross(lower.end()[-2], lower.end()[-1], points[i]) > 0)
            lower.pop_back();
        lower.push_back(points[i]);
    }
    if(lower.size() > 2) upper.insert(upper.end(), lower.begin() + 1, lower.end() - 1);
    return upper;
}
// 1 => Strictly inside; -1 => Border; 0 => Outside
int point_in_poly(const vector<Point> & poly, Point p){
    int many = 0;
    for(int i = 0; i < (int)poly.size(); i++){
        Point a = poly[i], b = poly[i + 1 < (int) poly.size() ? i + 1 : 0];
        if(a.x > b.x) swap(a, b);
        if(a.x <= p.x && p.x <= b.x){
            if(abs(a.x - b.x) == 0){
                if(min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y)) return -1;
            } else {
                double y = a.y + 1. * (b.y - a.y) / (b.x - a.x) * (p.x - a.x);
                if(abs(y - p.y) <= E) return -1;
                if(y >= p.y && p.x < b.x) many++;
            }
        }
    }
    return many % 2;
}

struct comp
{
    bool operator()(Point a, Point b){
            if(a.y != b.y) return a.y < b.y;
            return a.x < b.x;
             }
};

#define FAST_IO ios_base::sync_with_stdio(false),cin.tie(NULL)

int main()
{
    FAST_IO;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t; 
    cin>>t;
    while(t--)
    {
        int n , q;
        cin>> n >> q; 
        vector<Point > poly(n) ; 
        vector<int> not_used (n ,1);
        for(int i = 0 ; i< n ;i++)
        {
            cin>> poly[i].x >> poly[i]. y;
            poly[i].id =  i;
        }
        vector<vector<Point>> hull_set;

        while(accumulate(not_used.begin(), not_used.end(), 0 ) >=3 )
        {
            vector<Point> can;  //all the points that can be used
            for(int i  =0; i< n; ++i)
            {
                if(not_used[i])
                {
                    can.push_back(poly[i]);
                }
            }
            vector<Point> hull = convex_hull(can);  //points of a new hull
            for(auto & p : hull)
            {
                not_used[p.id] = 0; //this point is used in a hull;
            }
            hull_set.push_back(hull);
        }

        for(int i =0 ; i< q; ++i)
        {
            Point p ; 
            cin>> p.x >> p.y;
            int ans = 0 ; 
            for(auto & currHull : hull_set)
            {
                if(point_in_poly(currHull, p) == 1)
                    ++ans;
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}
