#include<iostream>
#include<vector>
#include <queue>
using namespace std;

vector<int>run_dijkstras(vector<vector<pair<int,int>>>&adj,int start=0){
int n=adj.size();

vector<int>dist(n,1e9);   //[0,inf,inf,inf,inf,inf]
priority_queue<
pair<int,int>,
vector<pair<int,int>>,
greater<pair<int,int>>

>pq;

dist[start]=0;
pq.push({start,0});    // first time priroty queue insert 0 node and distence

while(!pq.empty()){
    auto node=pq.top();
    pq.pop();           //pop smolest distence node(because in priroty queue store smolest distance node top of the queue

    int u=node.first;    //current node
    int d=node.second;    //current node distance


    if(d>dist[u]){
        continue;
    }

    for(auto neighbours :adj[u])
    {
        int v=neighbours.first;     //neibur node
        int v_d=neighbours.second;  //edge weight

        int new_dist=dist[u]+v_d;

        //check new dist is less then old distance
        if(new_dist<dist[v]){
            dist[v]=new_dist;     //update distance
            pq.push({v,dist[v]});    //push update in queue
        }
    }
}
  int i=0;
  for(auto d:dist){
    cout<<i<<":"<<d<<endl;
    i++;
  }


}

int main(){
vector<vector<pair<int,int>>>adj(6);

// Adjacency list for a graph with 6 nodes (0 to 5)



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

    return 0;

}
