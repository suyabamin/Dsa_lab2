#include <iostream>     // For input/output (cout)
#include <vector>       // For using vector container
#include <limits>       // For numeric limits (not strictly used here)

using namespace std;    // Avoid writing std:: everywhere

// Bellman-Ford function
// adj   → adjacency list of the graph
// start → source vertex (default = 0)
vector<int> run_bellman_ford(vector<vector<pair<int, int>>> &adj, int start = 0)
{
    int n = adj.size();                 // Number of vertices in the graph

    // Distance array, initialize all distances as infinity (1e9)
    vector<int> dist(n, 1e9);

    dist[start] = 0;                    // Distance of source node is 0

    // Relax all edges (n-1) times
    for (int i = 0; i < n - 1; i++)
    {
        // Traverse all vertices
        for (int u = 0; u < n; u++)
        {
            // Skip if vertex u is not reachable yet
            if (dist[u] == 1e9) continue;

            // Traverse all outgoing edges from u
            for (auto edge : adj[u])
            {
                int v = edge.first;     // Destination vertex
                int w = edge.second;    // Weight of the edge (u → v)

                // Relaxation step
                // If a shorter path to v is found
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;  // Update distance of v
                }
            }
        }
    }

    // Print shortest distance from source to each vertex
    for (int i = 0; i < n; i++)
    {
        cout << i << " : " << dist[i] << endl;
    }

    return dist;                        // Return distance array
}

int main()
{
    // Create adjacency list for a graph with 5 vertices (0 to 4)
    vector<vector<pair<int,int>>> adj(5);

    // Adding directed edges with weights

    adj[0].push_back({1, 6});   // Edge: 0 → 1 with weight 6
    adj[0].push_back({2, 7});   // Edge: 0 → 2 with weight 7

    adj[1].push_back({2, 8});   // Edge: 1 → 2 with weight 8
    adj[1].push_back({3, 5});   // Edge: 1 → 3 with weight 5
    adj[1].push_back({4, -4});  // Edge: 1 → 4 with weight -4 (negative)

    adj[2].push_back({3, -3});  // Edge: 2 → 3 with weight -3 (negative)
    adj[2].push_back({4, 9});   // Edge: 2 → 4 with weight 9

    adj[3].push_back({1, -2});  // Edge: 3 → 1 with weight -2 (negative)

    adj[4].push_back({0, 2});   // Edge: 4 → 0 with weight 2
    adj[4].push_back({3, 7});   // Edge: 4 → 3 with weight 7

    // Run Bellman-Ford from source node 0
     adj[0].push_back({1, 6});   // Edge: 0 → 1 with weight 6
    adj[0].push_back({2, 7});   // Edge: 0 → 2 with weight 7

    adj[1].push_back({2, 8});   // Edge: 1 → 2 with weight 8
    adj[1].push_back({3, 5});   // Edge: 1 → 3 with weight 5
    adj[1].push_back({4, -4});  // Edge: 1 → 4 with weight -4 (negative)

    adj[2].push_back({3, -3});  // Edge: 2 → 3 with weight -3 (negative)
    adj[2].push_back({4, 9});   // Edge: 2 → 4 with weight 9

    adj[3].push_back({1, -2});  // Edge: 3 → 1 with weight -2 (negative)

    adj[4].push_back({0, 2});   // Edge: 4 → 0 with weight 2
    adj[4].push_back({3, 7});   // Edge: 4 → 3 with weight 7

    // Run Bellman-Ford from source node 0
    run_bellman_ford(adj);

    return 0;                   // Program ends
}
