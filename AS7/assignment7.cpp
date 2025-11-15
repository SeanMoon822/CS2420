/*
file name: Assignment7.cpp
Written by: Seonghyun Moon
Date: May.11th.2023
*/
#include <iostream>
#include <stack>

using namespace std;

class MathStack 
{
private:
    float sum{}, diff{},mult{1};
    float div{1.0};
    float value1, value2; // Declare values to push to the stack.
public:
    
    MathStack(float v1, float v2); // Make a constructor.
    stack<float> add(); // member function to add two values.
    stack<float> subtract(); // member function to subtract two values.
    stack<float> multiply(); // member function to multiply two values.
    stack<float> divide(); // member function to divide two values.
};
MathStack::MathStack(float v1,float v2)
{
    value1 = v1;
    value2 = v2;
}

stack<float> MathStack::add() 
{
    stack<float> st;
    float result = value1 + value2;
    st.push(result);
    return st;
}
// Make an implementation of add function.

stack<float> MathStack::subtract() 
{
    stack<float> st;
    float result = value1 - value2;
    st.push(result);
    return st;
}
// Make an implementation of subtract function.
stack<float> MathStack::multiply() 
{
    stack<float> st;
    float result = value1 * value2;
    st.push(result);
    return st;
}
// Make an implementation of multiply function.
stack<float> MathStack::divide() 
{
    stack<float> st;
    float result = value1 / value2;
    st.push(result);
    return st;
}
// Make an implementation of divide function.
int main() 
{
    MathStack calc(10, 6);

    cout << "The sum is: " << calc.add().top() << endl;
    cout << "The difference: " << calc.subtract().top() << endl;
    cout << "The product is: " << calc.multiply().top() << endl;
    cout << "The division is: " << calc.divide().top() << endl;

    return 0;
}
// Main function to test the MathStack class works.
