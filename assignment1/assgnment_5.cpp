#include<bits/stdc++.h>
using namespace std;

void activities_selection(int s[],int f[],int n){
    int i=0;
    int Count=1;
    cout<<"train are--"<<i+1;
      for(int j=1;j<n;j++){
        if(s[j]>=f[i]){
                Count++;
            cout<<j+1<<" ";
            i=j;
        }
      }
       cout<<endl<<"train amount="<<Count;
cout<<endl;

}

int main(){
int n;
cin>>n;
int s[n];
int f[n];
for(int i=0;i<n;i++){
    cin>>s[i];
}
for(int i=0;i<n;i++){
    cin>>f[i];
}
vector<pair<int,int>>activities(n);
for(int i=0;i<n;i++){
    activities[i]={f[i],s[i]};
}
sort(activities.begin(),activities.end());

for(int i =0;i<n;i++){
    f[i]=activities[i].first;
    s[i]=activities[i].second;
}
for(int i=0;i<n;i++){
    cout<<s[i]<<" ";
}
cout<<endl;
for(int j=0;j<n;j++){
    cout<<f[j]<<" ";
}
activities_selection(s,f,n);
}
