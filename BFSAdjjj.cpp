#include <iostream>
#include <queue>

using namespace std;

const int MAX_SIZE = 100;


void bfsMatrix(int graph[MAX_SIZE][MAX_SIZE], int vertices, int start) {
    bool visited[MAX_SIZE] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int i = 0; i < vertices; ++i) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    cout << endl;
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    int graph[MAX_SIZE][MAX_SIZE] = {0};

    cout << "Enter the edges (vertex1 vertex2):" << endl;
    for (int i = 0; i < edges; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1][v2] = graph[v2][v1] = 1; 

    int startVertex;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;

    cout << "BFS (Adjacency Matrix): ";
    bfsMatrix(graph, vertices, startVertex);

    return 0;
}
