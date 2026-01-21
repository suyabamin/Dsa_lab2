#include<bits/stdc++.h>
using namespace std;
int main(){
int n,q;
cin>>n;
cin>>q;
int g[n];
for(int i=0;i<n;i++){
    cin>>g[i];
}
int s[q];
for(int i=0;i<q;i++){
    cin>>s[i];
}
sort(g,g+n);
sort(s,s+q);
int i=0,j=0;
int Count=0;
  while(i<n&&j<q){
        if(s[j]>=g[i]){
            i++;
            j++;
           Count++;
        }else{
            i++;
        }

  }
   cout<<Count;

}
