
#include <iostream>
#include <queue>
using namespace std;

int graph[10][10], visited[10];
int n;

void DFS(int vertex)
{
    cout << vertex << " ";
    visited[vertex] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

void BFS(int start)
{
    queue<int> q;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    q.push(start);

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();

        cout << vertex << " ";

        for (int i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    int edges, u, v, start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;

        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    }

    cout << "Enter edges (u v):" << endl;

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "DFS Traversal: ";
    DFS(start);

    cout << endl;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "BFS Traversal: ";
    BFS(start);

    cout << endl;

    return 0;
}
