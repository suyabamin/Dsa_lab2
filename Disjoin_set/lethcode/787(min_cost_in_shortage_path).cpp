#include<iostream>
#include<vector>
using namespace std;

int run_bellman_ford(vector<vector<pair<int,int>>>&adj,int start,int des,int k){
int n=adj.size();


vector<int>dist(n,1e9);
dist[start]=0;


for(int i=0;i<=k;i++){

    vector<int>temp=dist;
    for(int u=0;u<n;u++){

      if(dist[u]==1e9){
        continue;
      }

      for(auto edge :adj[u]){
        int v=edge.first;
        int w=edge.second;


        if(dist[u]+w<temp[v])
        {
            temp[v]=dist[u]+w;
        }


      }

    }
dist=temp;
}
    if(dist[des]==1e9){
        return -1;
    }
    return dist[des];
}

int main(){
    int n=4;
    int src=0;
    int dst=3;
    int k=1;
    vector<vector<pair<int,int>>>adj(n);
  adj[0].push_back({1, 100});
    adj[1].push_back({2, 100});
    adj[2].push_back({0, 100});
    adj[1].push_back({3, 600});
    adj[2].push_back({3, 200});

  int cha=  run_bellman_ford(adj,src,dst,k);
  cout<<cha;

}
