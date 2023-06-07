#include <iostream>
#include <stack>
#include <string>

using namespace std;

int hitungPostfix(string exp)
{
    stack<int> stak_nomor;

    int len = exp.length();
    for (int i = 0; i < len; i++)
    {
        if (exp[i] == ' ')
        {
            continue;
        } 
        else if (isdigit(exp[i])) 
        {
            int num = 0;
            if (isdigit(exp[i])) 
            {
                num = (exp[i] - '0');
            }
            stak_nomor.push(num);
        } 
        else 
        {
            int num1 = stak_nomor.top();
            stak_nomor.pop();
            int num2 = stak_nomor.top();
            stak_nomor.pop();

            switch (exp[i]) {
                case '+':
                    stak_nomor.push(num2 + num1);
                    break;
                case '-':
                    stak_nomor.push(num2 - num1);
                    break;
                case '*':
                    stak_nomor.push(num2 * num1);
                    break;
                case '/':
                    stak_nomor.push(num2 / num1);
                    break;
            }
        }
    }

    return stak_nomor.top();
}

int main() {
    string exp;
    getline(cin, exp);

    cout << hitungPostfix(exp) << endl;

    return 0;
}
