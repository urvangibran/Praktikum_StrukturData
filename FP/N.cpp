#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int opr;
        cin >> opr;
        if (opr == 1)
        {
            if (st.empty())
            {
                st.push(1);
                st.push(0);
            }
            else if (st.size() == 1 && st.top() == 1)
                st.pop();
            else if (st.size() > 1 && st.top() == 1)
                st.pop();
            else if (st.size() > 1 && st.top() == 0)
            {
                st.pop();
                st.push(1);
                st.push(0);
                st.push(1);
                st.push(0);
            }
        }
        else if (opr == 0)
        {
            if (st.empty())
                st.push(0);
            else if (st.size() == 1 && st.top() == 1)
                st.push(0);
            else if (st.size() == 1 && st.top() == 0)
                st.pop();
            else if (st.size() > 1 && st.top() == 1)
                st.push(0);
            else if (st.size() > 1 && st.top() == 0)
                st.pop();
        }
    }
    cout << st.size();

    return 0;
}
