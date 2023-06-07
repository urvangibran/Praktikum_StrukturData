#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector< int > adjList[100];
bool visited[100] = {0};
int max_final = 0;
map <int, int> mp;

void dfs(int cur, int maVertex){
    visited[cur] = 1;
    for(auto &i : adjList[cur]){
        if (!visited[i]){
            // cout << "pi ";
            // cout << maVertex  << " ";
            dfs(i, maVertex + 1);
        }
    }
    // cout << maVertex << " ";
    max_final = max(maVertex,max_final);
    mp[cur] = maVertex;
    visited[cur] = 0;
}

int main()
{
    int n, m, start;
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    if(max_final == n - 1) {
        cout << "Kompleksitas entitas terbentuk" << endl;
    } else {
        cout << "Seluruh kosmik tidak berkaitan, butuh "<< edge << " lagi" << endl;
    }
    return 0;
}