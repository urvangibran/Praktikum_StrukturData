#include <bits/stdc++.h>
using namespace std;

struct Graph
{
    int vertexCount;
    vector<vector<int>> adjList;

    void init(int b)
    {
        vertexCount = b;
        adjList.resize(vertexCount);
    }

    void add_edge(int vertex1, int vertex2)
    {
        adjList[vertex1].push_back(vertex2);
    }

    int bfs(int start)
    {
        vector<bool> visited(vertexCount, false);
        queue<pair<int, int>> q;

        q.push({start, 0});
        visited[start] = true;

        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();

            for (auto vertex : adjList[temp.first])
            {
                if (vertex == start)
                    return temp.second + 1;
                if (!visited[vertex])
                {
                    q.push({vertex, temp.second + 1});
                    visited[vertex] = true;
                }
            }
        }
        return -1;
    }
};

int main()
{
    int n;
    cin >> n;

    Graph grph;
    grph.init(n);

    int a, b;
    while (true)
    {
        cin >> a >> b;
        if (a == -1 && b == -1)
            break;
        grph.add_edge(a, b);
    }

    for (int i = 0; i < n; i++)
    {
        int res = grph.bfs(i);

        if (res == -1)
            cout << "gak bisa pulang mamah" << endl;
        else
            cout << res << endl;
    }
    return 0;
}
