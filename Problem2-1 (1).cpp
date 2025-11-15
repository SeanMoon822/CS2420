/***
Date: Mar.20th.2023
Author: Seonghyun Moon
file name : Problem1.cpp
***/
#include <iostream>
using namespace std;
/*
the method that Sorts an array with 0's and 1's so that all the 0's appear first
in the array and
all the 1's at the end of the array.
What is the time complexity of this function? O(n)
*/
void sort_ZeroOne_elements(int array[], int num_elements)
{
    int narr[num_elements];
    int count=0;
    for(int i=0; i<num_elements; i++)
    {
        if(array[i]==0)
        {
            narr[count]=array[i];
            count+=1;
        }
        else
        {

        }
    }
    for(int j=0; j<num_elements; j++)
    {
        if(array[j]==1)
        {
            narr[count]=array[j];
            count+=1;
        }
        else
        {

        }
    }
    for(int k=0; k<num_elements; k++)
    {
        array[k]=narr[k];
    }
}
int main()
{
    int arr[] = {0, 1, 0, 1, 1, 0, 1};
    int num_elements = sizeof(arr) /sizeof(arr[0]);
    sort_ZeroOne_elements(arr, num_elements);
    cout << " Sorted Array = {";
    for (auto i: arr)
    cout << i << " ";
    cout<<"}"<<endl;
    return 0;
}