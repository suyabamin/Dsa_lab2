#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Dijkstra function
// adj: adjacency list (u -> {v, w})
// start: source node
vector<int> run_dijkstras(vector<vector<pair<int, int>>> &adj, int start)
{
    int n = adj.size();

    vector<int> dist(n, 1e9);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist[start] = 0;
    pq.push({0, start});   // (distance, node)

    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();

        int d = node.first;
        int u = node.second;

        if (d > dist[u])
            continue;

        for (auto neighbour : adj[u])
        {
            int v = neighbour.first;
            int w = neighbour.second;

            int new_dist = dist[u] + w;

            if (new_dist < dist[v])
            {
                dist[v] = new_dist;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main()
{
    // Example from LeetCode
    // times = [[2,1,1],[2,3,1],[3,4,1]]
    // n = 4, k = 2

    int n = 4;
    int k = 2;

    // Graph with nodes 1..n, so size n+1
    vector<vector<pair<int, int>>> adj(n + 1);

    // Directed edges
    adj[2].push_back({1, 1});
    adj[2].push_back({3, 1});
    adj[3].push_back({4, 1});

    vector<int> dist = run_dijkstras(adj, k);

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == 1e9)
        {
            cout << -1 << endl;
            return 0;
        }
        ans = max(ans, dist[i]);
    }


    cout << ans << endl;   // Output: 2

    return 0;
}


///  https://leetcode.com/problems/network-delay-time/description/
