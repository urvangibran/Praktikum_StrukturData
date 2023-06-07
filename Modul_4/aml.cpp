#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &room, int visited[], int k)
{
    visited[k] = 1;
    for (int i = 0; i < room[k].size(); i++)
    {
        if (visited[room[k][i]] == 0)
        {
            dfs(room, visited, room[k][i]);
        }
    }
}

bool telusuri(vector<vector<int>> &room)
{
    int visited[1001] = {0};
    dfs(room, visited, 0);
    for (int i = 0; i < room.size(); i++)
    {
        if (visited[i] == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> room(n);
    for (int i = 0; i < n; i++)
    {
        int q;
        cin >> q;
        for (int j = 0; j < q; j++)
        {
            int k;
            cin >> k;
            room[i].push_back(k);
        }
    }
    if (telusuri(room))
    {
        cout << "Para peserta LBH berhasil keluar!" << endl;
    }
    else
    {
        cout << "Para peserta LBH terjebak selamanya." << endl;
    }
}