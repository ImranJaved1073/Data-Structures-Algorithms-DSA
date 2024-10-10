#include <iostream>
#include "Stack.h"
#include <string>

using namespace std;

class RPNCalculator 
{
private:
    Stack<int> stack;

public:
    bool isInteger(const string& value)
    {
        if (value.empty()) {
            return false;
        }

        int i = 0;

        if (value[0] == '-') 
            i = 1;

        for (; value[i] != '\0'; i++)
        {
            if (value[i] < '0' || value[i] > '9')
                return false;
        }

        return true;
    }

    int mystoi(const string& value)
    {
        int result = 0;
        for (int i = 0; value[i] != '\0'; i++)
        {
            result = result * 10 + (value[i] - '0');
        }
        return result;
    }

    void push(const string& operand) 
    {
        if (isInteger(operand)) 
            stack.push(mystoi(operand));
        else 
            cout << "# INVALID INPUT.ENTER AN INTEGER." << endl;
    }

    void calculate(const string& op) 
    {
        if (stack.getNumberOfElements() < 2) 
        {
            cout << "# NOT ENOUGH OPERANDS TO PERFORM '" << op << "' OPERATION." << endl;
            return;
        }

        int b = stack.peek();
        stack.pop();
        int a = stack.peek();
        stack.pop();

        if (op == "+") 
            stack.push(a + b);

        else if (op == "-") 
            stack.push(a - b);

        else if (op == "*") 
            stack.push(a * b);

        else if (op == "/") 
        {
            if (b == 0) 
            {
                cout << "# DIVISION BY ZERO UNDEFINED." << endl;
                stack.push(a);
            }
            else 
            {
                stack.push(a / b);
            }
        }
        else if (op == "%") 
        {
            if (b == 0) 
            {
                cout << "# MODULO BY ZERO UNDEFINED." << endl;
                stack.push(a);
            }
            else 
            {
                stack.push(a % b);
            }
        }
    }

    void displayStack() 
    {
        Stack<int> tempStack = stack;
        cout << "OUTPUT : ";
        while (!tempStack.isEmpty()) {
            cout << tempStack.peek() << " ";
            tempStack.pop();
        }
        cout << endl;
    }

    void displayStackTop() 
    {
        cout << "OUTPUT IS: ";
        if (stack.isEmpty()) 
        {
            cout << "STACK IS EMPTY." << endl;
        }
        else {
            cout << stack.peek() << endl;
        }
    }
};

int main() {
    RPNCalculator calculator;

    bool status = true;

    cout << "--------------------------------------------------\n";
    cout << "REVERSE POLISH NOTATION CALCULATOR BEGINS\n";
    cout << "TO EXIT THE ALGORITHM JUST ENTER 'q'\n";
    cout << "--------------------------------------------------\n";

    cout << "ENTER INPUT : ";


    string input;
    while (status) 
    {
        cout << "ENTER INPUT : ";
        getline(cin, input);

        if (input.empty()) 
        {
            cout << "# INVALID INPUT. MUST ENTER SOMETHING." << endl;
        }

        if (input == "+" || input == "-" || input == "*" || input == "/" || input == "%")
        {
            calculator.calculate(input);
        }
        else if (input == "q") 
        {
            status = false;
        }
        else if (input == "^") 
        {
            calculator.displayStackTop();
        }
        else if (input == "?") 
        {
            calculator.displayStack();
        }
        else 
        {
            calculator.push(input);
        }
    }

    return 0;
}
