
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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

    // Step 1: Depth First Search
    void DFS(int start) {
        vector<bool> visited(adj.size(), false);

        cout << "DFS starting from vertex "
             << start << ":\n";

        dfsHelper(start, visited);
        cout << endl;
    }

    // Step 1: Breadth First Search
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

    // Step 4: Dijkstra's shortest path algorithm
    void dijkstra(int start) {
        int n = adj.size();
        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);

        dist[start] = 0;

        for (int i = 0; i < n; i++) {
            int u = -1;

            for (int j = 0; j < n; j++) {
                if (!visited[j] &&
                    (u == -1 || dist[j] < dist[u])) {
                    u = j;
                }
            }

            if (u == -1 || dist[u] == INT_MAX) {
                break;
            }

            visited[u] = true;

            for (auto edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        cout << "\nShortest network delays from computer "
             << start << ":\n";

        for (int i = 0; i < n; i++) {
            cout << "Computer " << i << ": ";

            if (dist[i] == INT_MAX) {
                cout << "Unreachable";
            } else {
                cout << dist[i] << " ms";
            }

            cout << endl;
        }
    }
};

int main() {
    // Step 3: Computer Network Simulation
    cout << "Computer Network Simulation\n";
    cout << "Vertices represent computers and routers.\n";
    cout << "Edges represent network connections.\n";
    cout << "Weights represent delays in milliseconds.\n\n";

    Graph graph(11);

    // Connections between remaining original vertices
    graph.addEdge(0, 1, 8);
    graph.addEdge(0, 2, 15);
    graph.addEdge(1, 3, 10);
    graph.addEdge(1, 2, 6);
    graph.addEdge(2, 3, 4);
    graph.addEdge(3, 4, 9);

    // Connections for six new vertices
    graph.addEdge(1, 5, 5);
    graph.addEdge(2, 6, 7);
    graph.addEdge(3, 7, 12);
    graph.addEdge(4, 8, 3);
    graph.addEdge(5, 9, 6);
    graph.addEdge(6, 10, 8);

    // Additional connections
    graph.addEdge(7, 8, 4);
    graph.addEdge(8, 9, 7);
    graph.addEdge(9, 10, 5);

    // Display graph
    graph.display();

    // Step 1: DFS and BFS
    graph.DFS(0);
    graph.BFS(0);

    // Step 4: Shortest paths
    graph.dijkstra(0);

    return 0;
}
