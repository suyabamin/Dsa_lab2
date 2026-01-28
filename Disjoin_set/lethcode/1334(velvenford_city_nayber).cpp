#include<iostream>
#include<vector>
using namespace std;

vector<int>run_bellman_ford(vector<vector<pair<int,int>>>&adj,int start=0){
int n=adj.size();


vector<int>dist(n,1e9);
dist[start]=0;


for(int i=0;i<n-1;i++){


    for(int u=0;u<n;u++){

      if(dist[u]==1e9){
        continue;
      }

      for(auto edge :adj[u]){
        int v=edge.first;
        int w=edge.second;

        if(dist[u]+w<dist[v])
        {
            dist[v]=dist[u]+w;
        }
      }

    }
}

return dist;
}

int main(){
   int n=4;
  int  distanceThreshold = 4;
  vector<vector<pair<int,int>>>adj(n);
adj[0].push_back({1,3});
adj[1].push_back({0,3});

adj[1].push_back({2,1});
adj[0].push_back({1,1});

adj[1].push_back({3,4});
adj[3].push_back({1,4});

adj[2].push_back({3,1});
adj[3].push_back({2,1});

int answerCity=-1;
int minCount=1e9;

for(int i=0;i<n;i++){
    vector<int>dist=run_bellman_ford(adj,i);
    int Count=0;
    for(int j=0;j<n;j++){
        if(i!=j && dist[j]<=distanceThreshold){
            Count++;
        }
        if(Count<minCount||(Count==minCount&& i>answerCity)){
            minCount=Count;
            answerCity=i;
        }
    }
}
cout<<answerCity;
}
