#include <bits/stdc++.h>
using namespace std;

void print(int n)
{
    if(n&1) cout << n;
    cout << n + 100;
}

int main()
{
    int n; cin >> n;

    print(n);
}