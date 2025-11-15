/*
    Filename: Problem2.cpp
    Author:
    ID: U1401172
    Name: Seonghyun Moon
    Filename: Problem2.cpp
*/
#include <iostream>
using namespace std;
#define N 6 // size of square matrix ; row size = col size
/*
    * Function to calculate sum of each row
    * What is the time complexity of this Function? Ans=_________O(n^2)____________
**/
void row_sum(int arr[N][N])
{
    cout<<"row_sum"<<endl;
    for(int i=0; i<6; i++)
    {
        int row_sum=0;
        for(int j=0;j<6; j++)
        {
           
            row_sum+=arr[i][j];
        }
        cout<<row_sum<<" "<<endl;
    }
}
/*
    * The Function to calculate sum of each column
    * What is the time complexity of this function? Ans____O(n^2)_______
*/
void column_sum(int arr[N][N])
{
  
    cout<<"column_sum"<<endl;
    for(int j=0; j<6; j++)
    {
        int col_sum=0;
        for(int i=0; i<6; i++)
        {
            col_sum+=arr[i][j];
        }
        cout<<col_sum<<" "<<endl;
        
    }
}
/*
    * Function to calculate sum of diagonal elements
    * What is the time complexity this function? Ans_______O(n)______
**/
void diagonal_Sum(int arr[N][N])
{
    cout<<"dia_sum right"<<endl;
    int dia_sum=0;
    for(int i=0; i<6; i++)
    {
        dia_sum+=arr[i][i];
    }
        cout<<dia_sum<<" "<<endl;
    
}
 

    //main function that implements the function
int main()
{
    // Get the matrix elements
    int arr[N][N] = 
    {
    {1,2,3,4,5,0},
    {0,5,0,5,5,0},
    {6,0,0,0,5,0},
    {0,0,0,8,5,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0}
    };
    cout<<"**************************"<<endl;
    // Get each row sum
    row_sum(arr);
    cout<<"**************************"<<endl;
    // Get each column sum
    column_sum(arr);
    cout<<"**************************"<<endl;
    // Get diagonal sum
    diagonal_Sum(arr);
    cout<<"**************************"<<endl;
    return 0;
}