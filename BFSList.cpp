#include <iostream>
#include <queue>
#include <list>

using namespace std;


void bfsList(list<int> adjList[], int vertices, int start) {
    bool visited[vertices] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    cout << endl;
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
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;

    cout << "BFS (Adjacency List): ";
    bfsList(adjList, vertices, startVertex);

    return 0;
}
