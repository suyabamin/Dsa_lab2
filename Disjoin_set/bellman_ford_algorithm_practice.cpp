#include<iostream>
#include<vector>
using namespace std;

vector<int>run_bellman_ford(vector<vector<pair<int,int>>>&adj,int start=0){
int n=adj.size();  //number if vertex

//distance array, innitilization
vector<int>dist(n,1e9);
dist[start]=0;

//relaxezation all edges(n-1)times
for(int i=0;i<n-1;i++){

    //traverse all vertices
    for(int u=0;u<n;u++){
        //skip if vertex u is not reachable yet
      if(dist[u]==1e9){
        continue;
      }

      for(auto edge :adj[u]){
        int v=edge.first;     //vertex
        int w=edge.second;    //wight of the edge(u->v)

        //relaxation step
        if(dist[u]+w<dist[v])
        {
            dist[v]=dist[u]+w;
        }


      }

    }
}

for(int i=0;i<n;i++){
    cout<<i<<":"<<dist[i]<<endl;
}
return dist;
}

int main(){
vector<vector<pair<int,int>>>adj(5);
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
}
