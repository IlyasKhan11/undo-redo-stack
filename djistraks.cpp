#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using Graph = vector<vector<pii>>;

constexpr int INF = INT_MAX;

vector<int> dijkstra(int n, const Graph &adj, int start) {
    vector<int> dist(n, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue; // No need to process outdated distances

        for (const auto &[v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return move(dist);
}

int main() {
    int n = 5; // Number of nodes
    Graph adj(n);

    // Adding edges (u, v, w)
    adj[0] = {{1, 10}, {2, 3}};
    adj[1] = {{2, 1}, {3, 2}};
    adj[2] = {{1, 4}, {3, 8}, {4, 2}};
    adj[3] = {{4, 7}};
    adj[4] = {{3, 9}};

    int start = 0;
    vector<int> distances = dijkstra(n, adj, start);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "To " << i << " : " << (distances[i] == INF ? -1 : distances[i]) << "\n";
    }

    return 0;
}
