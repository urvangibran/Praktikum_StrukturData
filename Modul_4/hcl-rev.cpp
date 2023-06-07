#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, string> mp;
    map<string, int> cnt;
    string petak[] = {"A1", "B1", "C1", "A2", "B2", "C2", "A3", "B3", "C3"};
    for (int i = 0; i < 9; i++)
    {
        mp[petak[i]] = petak[i];
    }
    for (int i = 0; i < n; i++)
    {
        string a, b, str;
        cin >> a >> str >> b;
        if (mp[a] != mp[b])
        {
            string temp = mp[b];
            for (auto i = mp.begin(); i != mp.end(); i++)
            {
                if (i->second == temp)
                    i->second = mp[a];
            }
        }
    }
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        cnt[i->second]++;
    }
    int ans = 36;
    for (auto i = cnt.begin(); i != cnt.end(); i++)
    {
        ans -= (i->second * (i->second - 1)) / 2;
    }
    cout << ans << endl;
    return 0;
}