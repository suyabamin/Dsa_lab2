#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>parents;
vector<int>ranks;

struct Edge{
int u,v,weight;
};
void make_set(int vertex){
  parents[vertex]=vertex;
  ranks[vertex]=0;
}


int find_set(int vertex){
if(vertex==parents[vertex]){
    return vertex;
}
return parents[vertex]=find_set(parents[vertex]);
}

void uinon_sets(int vert_a,int vert_b)
{
    int parent_a=find_set(vert_a);
    int parent_b=find_set(vert_b);
    if(parent_a!=parent_b){
        if(ranks[parent_a]<ranks[parent_b]){
            swap(parent_a,parent_b);
        }
        parents[parent_b]=parent_a;

        if(ranks[parent_a]==ranks[parent_b]){
            ranks[parent_a]++;
        }
    }
}

int main(){
    int n=4;
    vector<Edge>edges={

        {1, 2, 10},                 // Edge between 1 and 2 with weight 10
        {1, 3, 6},                  // Edge between 1 and 3 with weight 6
        {1, 4, 5},                  // Edge between 1 and 4 with weight 5
        {2, 4, 15},                 // Edge between 2 and 4 with weight 15
        {3, 4, 4}                   // Edge between 3 and 4 with weight 4

    };

    sort(edges.begin(),edges.end(),[](Edge a,Edge b){
    return a.weight<b.weight;
    });

    parents.resize(n+1);
    ranks.resize(n+1);

    for(int i=1;i<=n;i++){
        make_set(i);
    }
    int mst_weight=0;
    cout<<"edges in the minimum spanning tree :\n";


    for(auto edge: edges){
        if(find_set(edge.u)!=find_set(edge.v))
        {
            cout<<edge.u<<"-"<<edge.v<<" (weight "<<edge.weight<<")\n";
            mst_weight+=edge.weight;
            uinon_sets(edge.u,edge.v);
        }
    }
    cout<<"total weight of mst =" <<mst_weight<<endl;

}
