/*
Filename: Problem3.cpp
Author:
    ID: U1401172
    Name: Seonghyun Moon
*/
#include <iostream>
#include<vector>
using namespace std;
/*
***
* C++ function to find array duplicated elements
* what is the time complexity ? Ans____O(n^2)___
*/
void findDuplicate(vector<int>&arr)
{
    bool exists= false;
    int n= arr.size();
    for(int i=0; i<n; i++)
    {
        for(int j=i+1 ;j<n; j++)
        {
            if(arr[i]==arr[j])
            {
                cout<<"The number "<<arr[i]<<" has a duplicate."<<endl;
            }
        }
        exists=true;

    if (!exists)
        cout<<"No duplicate!"<<endl;
}
}
int main()
{
//sample test data
    vector<int> A = {0, 0, 4, 3, 2, 7, 8, 2, 3, 1,10,10 };
    findDuplicate(A);
    return 0;
}
