#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int x;
cin>>x;
for(int i=0;i<n;i++){
    if(arr[i]==0&&arr[i-1]==0&&arr[i+1]==0){
        arr[i]=1;
        x--;
        if(x==0){
            cout<<"true";
            return 0;
        }
    }

}
cout<<"false";
}
