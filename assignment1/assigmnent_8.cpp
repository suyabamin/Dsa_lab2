#include <bits/stdc++.h>
using namespace std;

vector<int>tree[100];
bool visited[100];
int solve(int u,int parent,bool canTake)
{
    int ans=0;
    for(int v:tree[u])
        {
        if(v==parent) {
            continue;
        }
        ans+=solve(v,u,true);
    }
    if(canTake)
        {
        int take = 1;
        for(int v:tree[u]){
            if(v==parent){
                continue;
            }
            take += solve(v, u, false);
        }
        return max(ans,take);
    }

    return ans;
}
int main(){
    int n;
    cout<<"enter amount of nodes:- ";
    cin >> n;
    cout<<"enter edges--";
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    cout <<solve(1,-1,true)<< endl;
}
