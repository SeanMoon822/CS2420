/*
filename: Assignment_P1.cpp
Developer Name: Seonghyun Moon
Date: Apr.27th.2023
*/
#include<iostream>
#include<string>
using namespace std;

int precedence(char op)
{
    if(op == '^')
        return 3;
    else if(op == '*' || op == '/')
        return 2;
    else if(op == '+' || op == '-')
        return 1;
    else
        return 0;
}
// Make a function to return the precedence of an operator.

string infixToPostfix(string &expn)
{
    string postfix = ""; // create an empty string called postfix to store the postfix expression.
    string tempNum = ""; // create an empty string called tempNum to store a temporary number string.
    char opStack[expn.length()];
    int top = -1;
    for(int i = 0; i < expn.length(); i++)
    {
        if(expn[i] == ' ')
            continue;
        else if(isdigit(expn[i]))
        {
            while(i < expn.length() && isdigit(expn[i]))
            {
                tempNum += expn[i];
                i++;
            }
            i--;
            postfix += tempNum;
            postfix += " ";
            tempNum = "";
        }
        else if(expn[i] == '(')
        {
            top++;
            opStack[top] = '(';
        }
        else if(expn[i] == ')')
        {
            while(top >= 0 && opStack[top] != '(')
            {
                postfix += opStack[top];
                postfix += " ";
                top--;
            }
            top--;
        }
        else
        {
            while(top >= 0 && precedence(opStack[top]) >= precedence(expn[i]))
            {
                postfix += opStack[top];
                postfix += " ";
                top--;
            }
            top++;
            opStack[top] = expn[i];
        }
    }
    while(top >= 0)
    {
        postfix += opStack[top];
        postfix += " ";
        top--;
    }
    return postfix;
}
// Make a function to convert an infix expression to a postfix expression.

int postfixEvaluate(const string &expn)
{
    int numStack[expn.length()];
    //Declare a stack array of the length of the exprssion.
    int top = -1;
    //Declare a top integer. 
    for(int i = 0; i < expn.length(); i++)
    {
        if(expn[i] == ' ')
            continue;
        else if(isdigit(expn[i]))
        {
            int num = 0;
            while(i < expn.length() && isdigit(expn[i]))
            {
                num = num * 10 + (expn[i] - '0');
                i++;
            }
            i--;
            top++;
            numStack[top] = num;
        }
        else
        {
            int op1 = numStack[top];
            top--;
            int op2 = numStack[top];
            top--;
            int result;
            if(expn[i] == '+')
                result = op2 + op1;
            else if(expn[i] == '-')
                result = op2 - op1;
            else if(expn[i] == '*')
                result = op2 * op1;
            else if(expn[i] == '/')
                result = op2 / op1;
            else if(expn[i] == '^')
            {
                result = 1;
                for(int j = 0; j < op1; j++)
                    result *= op2;
            }
            top++;
            numStack[top] = result;
        }
    }
    return numStack[top];
}
// Make a function to evaluate a postfix expression.

int main()
{
    string expn;
    cout << "Enter an infix expression: ";
    getline(cin, expn);
    string postfix = infixToPostfix(expn);
    cout << "Postfix expression: " << postfix << endl;
    int result = postfixEvaluate(postfix);
    cout << "The result: " << result << endl;
    return 0;
}
