/* HDU1237 ¼òµ¥¼ÆËãÆ÷ */
 
#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cstdio>
 
using namespace std;
 
int main()
{
    string s;
    stack<char> op;
    stack<double> operand;
    double operand1, operand2;
 
    while(getline(cin, s) && s != "0") {
        for(int i=0; s[i]; i++) {
            if(isdigit(s[i])) {
                operand1 = 0;
                while(isdigit(s[i])) {
                    operand1 = operand1 * 10 + s[i] - '0';
                    i++;
                }
                i--;
                operand.push(operand1);
            } else if(s[i] == '+' || s[i] == '-') {
                if(op.empty())
                    op.push(s[i]);
                else {
                    char sop = op.top();
                    op.pop();
                    operand2 = operand.top();
                    operand.pop();
                    operand1 = operand.top();
                    operand.pop();
                    if(sop == '+')
                        operand.push(operand1 + operand2);
                    else
                        operand.push(operand1 - operand2);
                    op.push(s[i]);
                }
            } else if(s[i] == '*' || s[i] == '/') {
                char cop = s[i];
                i += 2;
                operand2 = 0;
                while(isdigit(s[i])) {
                    operand2 = operand2 * 10 + s[i] - '0';
                    i++;
                }
                i--;
                operand1 = operand.top();
                operand.pop();
                if(cop == '*')
                    operand.push(operand1 * operand2);
                else
                    operand.push(operand1 / operand2);
            }
        }
 
        while(!op.empty()) {
            char sop = op.top();
            op.pop();
            operand2 = operand.top();
            operand.pop();
            operand1 = operand.top();
            operand.pop();
            if(sop == '+')
                operand.push(operand1 + operand2);
            else
                operand.push(operand1 - operand2);
        }
 
        printf("%.2f\n", operand.top());
    }
 
    return 0;
}

