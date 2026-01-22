#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct CompareNodesComparator{

bool operator()(pair<int,int>a,pair<int,int>b){
return a.second>b.second;   //smaller weight gets higher priority
}
};


void prims(vector<vector<pair<int,int>>>&adj)
{
int n=adj.size();   //number of vertices in graph
vector<bool>visited(n,false);     // keeps track of visited vectiefes

//priroty queue strong {vertex,weight}
priority_queue<pair<int,int>,vector<pair<int,int>>,CompareNodesComparator>pq;

int rand=0;
pq.push({0,0});       //start from vertex 0 with weight 0

int cost=0;          //totol cost of minimum spanning tree

// countinue until prioroty queue  is empty
while(!pq.empty()){
    auto node=pq.top();      //get the node with minimum weight
    pq.pop();               // remove it form the priroty quwue

    int u=node.first;       /// current vertex
    int u_w= node.second;    // weight of edge used to reach u

    if(visited[u])   //if vertex is alraeady included in mst
        continue;     // skip it to avoid cycle

    cost+=u_w;        // add edge weight cost


    //traverse all adjacent vertices of u

    for(auto neighbour : adj[u]){
        int v=neighbour.first;   //adjecent vertex
        int v_w=neighbour.second;     // weight of edge (u->v)

        if(!visited[v]){
            pq.push({v,v_w});  //push it into prioroty queue
        }
    }
    visited[u]=true;

}

cout<<cost<<endl;

}


int main()
{
    vector<vector<pair<int,int>>>adj(6);

    adj[0].push_back({1, 4});       // Edge 0 → 1 with weight 4
    adj[1].push_back({0, 4});       // Edge 1 → 0 with weight 4

    adj[0].push_back({2, 4});       // Edge 0 → 2 with weight 4
    adj[2].push_back({0, 4});       // Edge 2 → 0 with weight 4

    adj[1].push_back({2, 2});       // Edge 1 → 2 with weight 2
    adj[2].push_back({1, 2});       // Edge 2 → 1 with weight 2

    adj[1].push_back({3, 5});       // Edge 1 → 3 with weight 5
    adj[3].push_back({1, 5});       // Edge 3 → 1 with weight 5

    adj[2].push_back({3, 5});       // Edge 2 → 3 with weight 5
    adj[3].push_back({2, 5});       // Edge 3 → 2 with weight 5

    adj[2].push_back({4, 11});      // Edge 2 → 4 with weight 11
    adj[4].push_back({2, 11});      // Edge 4 → 2 with weight 11

    adj[3].push_back({4, 2});       // Edge 3 → 4 with weight 2
    adj[4].push_back({3, 2});       // Edge 4 → 3 with weight 2

    adj[3].push_back({5, 6});       // Edge 3 → 5 with weight 6
    adj[5].push_back({3, 6});       // Edge 5 → 3 with weight 6

    adj[4].push_back({5, 3});       // Edge 4 → 5 with weight 3
    adj[5].push_back({4, 3});       // Edge 5 → 4 with weight 3

    prims(adj);                     // Call Prim’s algorithm

    return 0;
}
