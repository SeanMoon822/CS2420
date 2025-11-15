/***
*
Date: Mar.20th.2023
Author: Seonghyun Moon
file name : Problem3.cpp
***/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//What is the time complexity? O(nlogn)
//interval class definition
class Interval
{
    public:
    int first, second;
    Interval(int x, int y)
    {
    first = x;
    second = y;
    }
};
//user defined function to compare two objects
bool comp(const Interval &lhs,const Interval &rhs)
{
    return lhs.first<rhs.first;
}
//function that merges overlapping intervals
vector<Interval> merge_intervals(vector<Interval>& v)
{
    sort(v.begin(), v.end(), comp);
    
    vector<Interval> result;
    Interval current = v[0];
    
    for(int k = 1; k < v.size(); k++){
        
        if(current.second >= v[k].first)
        {
            
            current.second = max(current.second, v[k].second);
        }
        else
        {
            
            result.push_back(current);
            current = v[k];
        }
    }
    result.push_back(current);
    return result;
}
int main()
{
//Sample Test Case
vector<Interval> vec 
{
    Interval(1, 4),
    Interval(3, 6),
    Interval(8, 10)
};
vector<Interval> result = merge_intervals(vec);
//output - merged intervals
for(auto i :result) 
{
    cout << "[" << i.first << ", " << i.second << "] "<<endl;
}
}