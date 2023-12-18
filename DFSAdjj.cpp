#include <iostream>

using namespace std;

const int MAX_SIZE = 100;


void dfsMatrix(int graph[MAX_SIZE][MAX_SIZE], int vertices, int current, bool visited[]) {
    visited[current] = true;
    cout << current << " ";

    for (int i = 0; i < vertices; ++i) {
        if (graph[current][i] == 1 && !visited[i]) {
            dfsMatrix(graph, vertices, i, visited);
        }
    }
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
    }

    int startVertex;
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;

    bool visited[MAX_SIZE] = {false};

    cout << "DFS (Adjacency Matrix): ";
    dfsMatrix(graph, vertices, startVertex, visited);

    cout << endl;

    return 0;
}
