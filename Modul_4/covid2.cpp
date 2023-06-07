#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>> &matrix, int row, int col, int n)
{
    if (row < 0 || row >= n || col < 0 || col >= n || matrix[row][col] != '+')
    {
        return;
    }
    matrix[row][col] = -1;

    dfs(matrix, row - 1, col + 1, n);
    dfs(matrix, row + 1, col - 1, n);
    dfs(matrix, row + 1, col + 1, n);
    dfs(matrix, row - 1, col - 1, n);
    dfs(matrix, row - 1, col, n);
    dfs(matrix, row + 1, col, n);
    dfs(matrix, row, col - 1, n);
    dfs(matrix, row, col + 1, n);
}

int countIslands(vector<vector<char>> &matrix, int n)
{
    int islandCount = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == '+')
            {
                islandCount++;
                dfs(matrix, i, j, n);
            }
        }
    }

    return islandCount;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<char>> matrix(n, vector<char>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << countIslands(matrix, n) << endl;
    return 0;
}
