#include <iostream>
#include <stack>
#include <string>

using namespace std;

int hitungPostfix(string exp) {
    stack<int> stack;

    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == ' ') {
            continue;
        } else if (isdigit(exp[i])) {
            int num = 0;

            while (isdigit(exp[i])) {
                num = num * 10 + (int)(exp[i] - '0');
                i++;
            }
            i--;

            stack.push(num);
        } else {
            int val1 = stack.top();
            stack.pop();
            int val2 = stack.top();
            stack.pop();

            switch (exp[i]) {
                case '+':
                    stack.push(val2 + val1);
                    break;
                case '-':
                    stack.push(val2 - val1);
                    break;
                case '*':
                    stack.push(val2 * val1);
                    break;
                case '/':
                    stack.push(val2 / val1);
                    break;
            }
        }
    }

    return stack.top();
}

int main() {
    string exp;
    getline(cin, exp);

    cout << hitungPostfix(exp) << endl;

    return 0;
}
