#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

int main()
{
    int n, res = 36;
    string a, penghubung, b;
    cin >> n;
    map<string, string> vertex;
    map<string, int> jumlahUnion;
    string listS[] = {"A1", "B1", "C1", "A2", "B2", "C2", "A3", "B3", "C3"};
    for (int i = 0; i < 9; i++)
    {
        vertex[listS[i]] = listS[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a >> penghubung >> b;
        if (vertex[a] != vertex[b])
        {
            string temp = vertex[b];
            for (auto it = vertex.begin(); it != vertex.end(); it++)
            {
                if (it->second == temp)
                    it->second = vertex[a];
            }
        }
    }
    for (auto it = vertex.begin(); it != vertex.end(); it++)
    {
        jumlahUnion[it->second]++;
    }
    for (auto it = jumlahUnion.begin(); it != jumlahUnion.end(); it++)
    {
        res -= it->second * (it->second - 1) / 2;
        // res -= pengurangJumlah;
    }
    cout << res << endl;
    return 0;
}