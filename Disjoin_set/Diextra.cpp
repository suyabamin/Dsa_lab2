#include <iostream>     // For input/output (cout, endl)
#include <vector>       // For using vector container
#include <queue>        // For using priority_queue

using namespace std;    // Allows us to write cout instead of std::cout

// Function to run Dijkstra's algorithm
// adj: adjacency list (node -> {neighbor, weight})
// start: source node (default = 0)
vector<int> run_dijkstras(vector<vector<pair<int, int>>> &adj, int start = 0)
{
    int n = adj.size();                 // Number of vertices in the graph

    // Distance array, initialized with a very large value (infinity)
    vector<int> dist(n, 1e9);

    // Min-heap priority queue: (distance, node)
    priority_queue<
        pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>
    > pq;

    dist[start] = 0;                    // Distance from start node to itself is 0
    pq.push({start, 0});                // Push start node into priority queue

    // Loop until all reachable nodes are processed
    while (!pq.empty())
    {
        auto node = pq.top();           // Get node with smallest distance
        pq.pop();                       // Remove it from queue

        int u = node.first;             // Current node
        int d = node.second;            // Distance of current node

        // If this distance is outdated, skip it
        if (d > dist[u])
        {
            continue;
        }

        // Traverse all neighbors of current node u
        for (auto neighbours : adj[u])
        {
            int v = neighbours.first;   // Neighbor node
            int v_d = neighbours.second;// Edge weight (u -> v)

            int new_dist = dist[u] + v_d; // New possible distance to v

            // If shorter path found, update distance
            if (new_dist < dist[v])
            {
                dist[v] = new_dist;     // Update distance
                pq.push({v, dist[v]});  // Push updated node into queue
            }
        }
    }

    // Print shortest distance from start node to every node
    int i = 0;
    for (auto d : dist)
    {
        cout << i << ":" << d << endl;  // Print node index and distance
        i++;
    }
}

int main()
{
    // Adjacency list for a graph with 6 nodes (0 to 5)
    vector<vector<pair<int, int>>> adj(6);

    // Adding edges (undirected graph)

    adj[0].push_back({1, 4});   // Edge: 0 -> 1 with weight 4
    adj[1].push_back({0, 4});   // Edge: 1 -> 0 with weight 4

    adj[0].push_back({2, 4});   // Edge: 0 -> 2 with weight 4
    adj[2].push_back({0, 4});   // Edge: 2 -> 0 with weight 4

    adj[1].push_back({2, 2});   // Edge: 1 -> 2 with weight 2
    adj[2].push_back({1, 2});   // Edge: 2 -> 1 with weight 2

    adj[1].push_back({3, 5});   // Edge: 1 -> 3 with weight 5
    adj[3].push_back({1, 5});   // Edge: 3 -> 1 with weight 5

    adj[2].push_back({3, 5});   // Edge: 2 -> 3 with weight 5
    adj[3].push_back({2, 5});   // Edge: 3 -> 2 with weight 5

    adj[2].push_back({4, 11});  // Edge: 2 -> 4 with weight 11
    adj[4].push_back({2, 11});  // Edge: 4 -> 2 with weight 11

    adj[3].push_back({4, 2});   // Edge: 3 -> 4 with weight 2
    adj[4].push_back({3, 2});   // Edge: 4 -> 3 with weight 2

    adj[3].push_back({5, 6});   // Edge: 3 -> 5 with weight 6
    adj[5].push_back({3, 6});   // Edge: 5 -> 3 with weight 6

    adj[4].push_back({5, 3});   // Edge: 4 -> 5 with weight 3
    adj[5].push_back({4, 3});   // Edge: 5 -> 4 with weight 3

    run_dijkstras(adj);          // Run Dijkstra from node 0

    return 0;                    // Program ends
}
