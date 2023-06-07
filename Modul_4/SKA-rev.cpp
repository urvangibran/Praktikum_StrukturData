#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    map<int, int> mpReverse;

    for (int i = 0; i < n; i++)
    {
        mp[i] = i;
    }
    vector<int> adjList[100];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int j = 0; j < n; j++)
        {
            if (mp[a] != mp[b])
            {
                mp[b] = mp[a];
            }
        }
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        mpReverse.insert({mp[i], i});
    }

    int ans = mpReverse.size() - 1;
    // cout << mpReverse.size() - 1 << endl;

    if (ans == 0)
    {
        cout << "Kompleksitas entitas terbentuk" << endl;
    }
    else
    {
        cout << "Seluruh kosmik tidak berkaitan, butuh " << ans << " lagi" << endl;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << "mp " << i << ": " << mpReverse[i] << endl;
    // }
    return 0;
}