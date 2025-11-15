/*
File name: Assignment7.cpp
Developer Name: Seonghyun Moon
Date: Apr.26th.2023
*/
#include<iostream>
#include<string>
using namespace std;

void dec_to_bin(int number)
{
   int SIZE = 20;
   int binary[SIZE];
   int top = 0;
    
   while(number>0)
   {
      binary[top] = number%2;
      number/=2;
      top++;
   }
   for(int i=top-1;i>=0;i--)
   {
      cout<<binary[i];
   }
}
//Make a function to convert decimal numbers to binary numbers.
int main()
{
   int num;
   cout << "Enter a decimal number: ";
   cin >> num;
   dec_to_bin(num);
   return 0;
}
