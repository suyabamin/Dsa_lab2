#include<bits/stdc++.h>
using namespace std;

int jump(vector<int>&b,int n){
      if(n==0){
        return 0;
      }if(n==1){
      return abs(b[1]-b[0]);
      }
      int costing1=jump(b,n-1)+abs(b[n]-b[n-1]);
     int costing2 = (n>1?jump(b,n-2)+abs(b[n]-b[n-2]):INT_MAX);

      return min(costing1,costing2);

}
int main(){
int n;
cout<<"enter stone amount--";
cin>>n;
cout<<"enter sotns:";
vector<int>b(n);
for(int i=0;i<n;i++){
    cin>>b[i];
}
int frog=jump(b,n-1);
cout<<"minimum total cost="<<frog;
}
