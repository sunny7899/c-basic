#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// A structure to represent a node in the priority queue
struct Node {
    int vertex;
    int distance;

    // Overload the < operator to make it a min-heap based on distance
    bool operator<(const Node& other) const {
        return distance > other.distance;
    }
};

void dijkstra(vector<vector<pair<int, int>>>& graph, int source) {
    int V = graph.size(); // Number of vertices
    vector<int> distances(V, INT_MAX); // Initialize distances as infinity
    distances[source] = 0;

    priority_queue<Node> pq;
    pq.push({source, 0});

    while (!pq.empty()) {
        int u = pq.top().vertex;
        int dist_u = pq.top().distance;
        pq.pop();

        // Skip if the distance is not updated
        if (dist_u > distances[u]) continue;

        // Update distances of adjacent vertices
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            // Relaxation step
            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push({v, distances[v]});
            }
        }
    }

    // Output the shortest distances
    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << "\t" << distances[i] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    // Graph represented as an adjacency list
    vector<vector<pair<int, int>>> graph(V);

    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight}); // Uncomment this for undirected graph
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    dijkstra(graph, source);

    return 0;
}
