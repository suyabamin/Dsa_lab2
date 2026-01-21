#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct CompareNOdesComparator
{
    bool operator()(pair<int,int>a,pair<int,int>b){
        return a.second>b.second;
    }
};

void prims(vector<vector<pair<int ,int >>>&adj){
    int n=adj.size();
    vector<bool>visited(n,false);
    priority_queue<pair<int,int >,vector<pair<int,int>>,CompareNOdesComparator>pq;
    int rand=0;
    pq.push({0,0});
    int cost=0;
    while (!pq.empty())
    {
        auto node=pq.top();
        pq.pop();
        int u=node.first;
        int u_w=node.second;
        if(visited[u])
        continue;
        cost+=u_w;
        for(auto neighbour:adj[u]){
            int v=neighbour.first;
            int v_w=neighbour.second;
            if(!visited[v]){
                pq.push({v,v_w});
            }
        }
        visited[u]=true;
    }
    cout<<cost<<endl;
    
}

int main(){
   vector<vector<pair<int,int>>>adj(6);

adj[0].push_back({1,4});
adj[1].push_back({0,4});

// Edge: 0 - 2 (4)
adj[0].push_back({2,4});
adj[2].push_back({0,4});

// Edge: 1 - 2 (1)
adj[1].push_back({2,1});
adj[2].push_back({1,1});

// Edge: 1 - 3 (2)
adj[1].push_back({3,2});
adj[3].push_back({1,2});

// Edge: 2 - 4 (3)
adj[2].push_back({4,3});
adj[4].push_back({2,3});

// Edge: 3 - 4 (5)
adj[3].push_back({4,5});
adj[4].push_back({3,5});

// Edge: 3 - 5 (6)
adj[3].push_back({5,6});
adj[5].push_back({3,6});

// Edge: 4 - 5 (7)
adj[4].push_back({5,7});
adj[5].push_back({4,7});

prims(adj);
}