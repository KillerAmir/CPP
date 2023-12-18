#include <iostream>
#include <list>

using namespace std;


void dfsList(list<int> adjList[], int current, bool visited[]) {
    visited[current] = true;
    cout << current << " ";

    for (int neighbor : adjList[current]) {
        if (!visited[neighbor]) {
            dfsList(adjList, neighbor, visited);
        }
    }
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    list<int> adjList[vertices];

    cout << "Enter the edges (vertex1 vertex2):" << endl;
    for (int i = 0; i < edges; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        adjList[v1].push_back(v2); 
        adjList[v2].push_back(v1);
    }

    int startVertex;
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;

    bool visited[vertices] = {false};

    cout << "DFS (Adjacency List): ";
    dfsList(adjList, startVertex, visited);

    cout << endl;

    return 0;
}
