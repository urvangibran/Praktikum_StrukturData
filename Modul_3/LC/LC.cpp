#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> auto_looting;
    string str, bahan;
    while (getline(cin, str))
    {
        if (str == "#")
            break;
        auto_looting[str]++;
    }
    int n, totalCraft;
    cin >> n;
    while (n--)
    {
        int x, m, y;
        // x = banyak benda yang dibuat
        // m = banyak bahan yang dibutuhkan
        cin >> x >> m;
        bool succes = 1, used = 0;
        map<string, int> craft;
        totalCraft = INT_MAX;
        while (m--)
        {
            getline(cin, bahan);
            getline(cin, bahan);
            cin >> y;
            craft[bahan] += y;
            totalCraft = min(totalCraft, auto_looting[bahan] / y);
            if (auto_looting[bahan] - y * x < 0 && !used)
            {
                used = 1;
                succes = 0;
            }
            // cout << bahan << "=" << auto_looting[bahan] << endl;
        }
            // cout << "Total Craft " << totalCraft << endl;
        if(succes) { 
            cout << "Material Fulfilled, Crafting " << x << "!" << endl;
            for (auto pointer = craft.begin(); pointer != craft.end(); pointer++) {
                auto_looting[pointer->first] -= craft[pointer->first] * x;
                // cout << pointer->first << " " << auto_looting[pointer->first] << " " << craft[pointer->first] << endl;
            }
        } else {
            cout  << "Insufficient Material, Can only craft "<< totalCraft << "." << endl;
        }
    }
    return 0;
}