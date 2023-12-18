#include <iostream>
#include <stack>
#include <cctype>
#include <cmath>

using namespace std;


bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


int getPrecedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0; 
}


string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (char& c : infix) {
        if (isalnum(c)) {
            postfix += c; 
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); 
        } else if (isOperator(c)) {
            while (!s.empty() && getPrecedence(s.top()) >= getPrecedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}


double evaluatePostfix(string postfix) {
    stack<double> s;

    for (char& c : postfix) {
        if (isalnum(c)) {
            s.push(c - '0'); 
        } else if (isOperator(c)) {
            double operand2 = s.top();
            s.pop();
            double operand1 = s.top();
            s.pop();

            switch (c) {
                case '+':
                    s.push(operand1 + operand2);
                    break;
                case '-':
                    s.push(operand1 - operand2);
                    break;
                case '*':
                    s.push(operand1 * operand2);
                    break;
                case '/':
                    s.push(operand1 / operand2);
                    break;
                case '^':
                    s.push(pow(operand1, operand2));
                    break;
            }
        }
    }

    return s.top();
}

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);

   
    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    
    double result = evaluatePostfix(postfixExpression);
    cout << "Result: " << result << endl;

    return 0;
}
