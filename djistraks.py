import heapq

INF = float('inf')

def dijkstra(n, adj, start):
    dist = [INF] * n
    dist[start] = 0
    pq = [(0, start)]  # Min-heap with (distance, node)

    while pq:
        d, u = heapq.heappop(pq)

        if d > dist[u]:  # Ignore outdated distances
            continue

        for v, w in adj[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                heapq.heappush(pq, (dist[v], v))

    return dist

# Number of nodes
n = 5
adj = [[] for _ in range(n)]

# Adding edges (u, v, w)
adj[0] = [(1, 10), (2, 3)]
adj[1] = [(2, 1), (3, 2)]
adj[2] = [(1, 4), (3, 8), (4, 2)]
adj[3] = [(4, 7)]
adj[4] = [(3, 9)]

start = 0
distances = dijkstra(n, adj, start)

print(f"Shortest distances from node {start}:")
for i in range(n):
    print(f"To {i} : {distances[i] if distances[i] != INF else -1}")
