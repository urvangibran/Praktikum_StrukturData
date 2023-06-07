#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    map<ll, ll> m;
    m[0] = 1;
    m[1] = 1;

    while (tc--)
    {
        ll gunung;
        cin >> gunung;
        auto pointer = m.find(gunung);
        if (pointer == m.end())
        {
            for (ll i = 2; i <= gunung; i++)
            {
                auto pointer2 = m.find(i);
                if (pointer2 == m.end());
                {
                    m[i] = 0;
                    for (int j = 0; j < i; j++)
                    {
                        m[i] += m[j] * m[i - j - 1];
                    }
                }
            }
        }
        ll res = m[gunung];
        cout << res << endl;
    }

    return 0;
}