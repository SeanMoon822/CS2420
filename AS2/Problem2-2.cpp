/***
Date: Mar.20th.2023
Author: Seonghyun Moon 
file name : Problem2.cpp
***/
#include <iostream>
using namespace std;
/*
The function to find the index.
What is the time complexity of this function?__________O(n)__________
*/
int findIndex(int array[], int size, int key)
{
    int index=0;
    for(int i=0; i<size; i++)
    {
        if(array[i]==key)
        {
            index=i;
            return index;
        }
    }
    return -1;
}

int main()
{
    //Sample test case
    int arr[] = { 6, 8, 3, 1, 3 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 9; //Target element -Key
    int index= findIndex(arr, n, key);
    if (index==-1)
    {
    cout << "Target value = " <<key<<" is not in the array"<<endl;
    }
    else
    {
    cout << "Target value = " << key << " is present at index = "<< index<<endl;
    }
    return 0;
}
