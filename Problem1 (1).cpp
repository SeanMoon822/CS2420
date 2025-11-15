/*
    * Filename: Problem1.cpp
    * Author:
    ID: U1401172
    Name: Seonghyun Moon
*/
#include<iostream>
using namespace std;
/*
    * function thatfinds the maximum sum of a contiguous subarray
    * what is the Time Complexity the function? Ans____O(n^3)___
*/
int maxSubArraySum(int a[], int n)
{
    int max_sum=0;
    int subarr[n];
    int sum=0; 

     for(int i=0; i<n; i++) 
    {
        for(int j=i; j<n; j++) 
        {
            for(int m=i; m<=j; m++)
            {
                sum += a[m];
                subarr[i]=sum;
                sum=0;
            }
        }
        max_sum=subarr[0];
    }

    for(int i=0; i<n; i++)
    {
        if(max_sum<a[i])
        {
            max_sum=a[i];

        }
    }
    return max_sum;
}

int main()
{
    //sample test data
    int A[] = {-3,-6, -1, -14,-2};
    //int A ={0,-2,4}
    int size = sizeof(A)/sizeof(A[0]);
    int max_sum = maxSubArraySum(A, size);
    cout<<max_sum<<endl;
    return 0;
}

