#include<bits/stdc++.h>
using namespace std;

void print_maxActivities(int s[],int f[],int n){
     int i,j;
     int Count=1;
     cout<<"the solution set :"<<endl;
     i=0;
     cout<<" "<<i+1;
     for(int j=1;j<n;j++){
        if(s[j]>=f[i]){
            Count++;
            cout<<" "<<j+1;
            i=j;
        }
     }
     cout<<endl;
     cout<<"selected activities="<<Count;
}

int main(){
int s[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12, 15};
int f[] = {4, 5, 6, 7, 8, 9,10,11,12,13,14,18};


int n=sizeof(s)/sizeof(s[0]);

vector<pair<int,int>>activities(n);
for(int i=0;i<n;i++){
    activities[i]={f[i],s[i]};
}
sort(activities.begin(),activities.end());
for(int i=0;i<n;i++){
    f[i]=activities[i].first;
    s[i]=activities[i].second;
}
for(int i=0;i<n;i++){
    cout<<s[i]<<" ";
}
cout<<endl;
for(int i=0;i<n;i++){
    cout<<f[i]<<" ";
}

print_maxActivities(s,f,n);
}
