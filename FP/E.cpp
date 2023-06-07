#include <bits/stdc++.h>
using namespace std;

struct Path
{
    int tujuan, bahaya;
};

int findMaxDanger(int n, const vector<vector<Path>> &graph)
{
    vector<int> maxDanger(n + 1, 0);
    vector<bool> visited(n + 1, false);

    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        int bahaya = -pq.top().first;
        int village = pq.top().second;
        pq.pop();

        if (visited[village])
        {
            continue;
        }
        visited[village] = true;

        maxDanger[village] = bahaya;

        for (const Path &Path : graph[village])
        {
            int nextVillage = Path.tujuan;
            int nextDanger = max(bahaya, Path.bahaya);
            if (!visited[nextVillage])
            {
                pq.push({-nextDanger, nextVillage});
            }
        }
    }

    return maxDanger[n];
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<Path>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    int res = findMaxDanger(n, graph);
    cout << res << endl;

    return 0;
}