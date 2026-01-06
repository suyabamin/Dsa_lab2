#include<iostream>
#include<algorithm>
using namespace std;
int main(){
int n,m;
cout<<"enter student-";
cin>>n;
cout<<"enter room-";
cin>>m;
int s[n];
int r[m];
cout<<"enter students-";
for(int i=0;i<n;i++){
    cin>>s[i];
}
cout<<"enter room-";
for(int i=0;i<m;i++){
    cin>>r[m];
}
sort(s,s+n);
sort(r,r+m);

int i=0,j=0,Count=0;
while(i<n&&j<m){
    if(r[m]>=s[i]){
        Count++;
        i++;
        j++;
    }else{
      i++;
    }
}
cout<<Count;

}
