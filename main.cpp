
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    vector<vector<pair<int, int>>> adj;

    void dfsHelper(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (auto edge : adj[v]) {
            if (!visited[edge.first]) {
                dfsHelper(edge.first, visited);
            }
        }
    }

public:
    Graph(int size) {
        adj.resize(size);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    void display() {
        cout << "Graph's adjacency list:\n";

        for (int i = 0; i < (int)adj.size(); i++) {
            cout << i << " --> ";

            for (auto edge : adj[i]) {
                cout << "(" << edge.first << ", "
                     << edge.second << ") ";
            }
            cout << endl;
        }
    }

    void DFS(int start) {
        vector<bool> visited(adj.size(), false);

        cout << "DFS starting from vertex "
             << start << ":\n";

        dfsHelper(start, visited);
        cout << endl;
    }

    void BFS(int start) {
        vector<bool> visited(adj.size(), false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS starting from vertex "
             << start << ":\n";

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            cout << current << " ";

            for (auto edge : adj[current]) {
                int next = edge.first;

                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph graph(7);

    graph.addEdge(0, 1, 12);
    graph.addEdge(0, 2, 8);
    graph.addEdge(0, 3, 21);
    graph.addEdge(2, 3, 6);
    graph.addEdge(2, 6, 2);
    graph.addEdge(2, 4, 4);
    graph.addEdge(2, 5, 5);
    graph.addEdge(4, 5, 9);
    graph.addEdge(5, 6, 6);

    graph.display();
    graph.DFS(0);
    graph.BFS(0);

    return 0;
}
