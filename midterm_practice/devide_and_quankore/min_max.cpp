#include<bits/stdc++.h>
using namespace std;

pair<int,int>find_minmax(int arr[],int low,int high){
    if(high==low){
        return {arr[low],arr[low]};
    }else if(high==low+1){
      if(arr[high]>arr[low]){
        return{arr[high],arr[low]};
      }else{
      return{arr[low],arr[high]};
      }
    }else{
      int mid=(low+high)/2;
      pair<int,int> lef=find_minmax(arr,low,mid);
      pair<int,int> riht=find_minmax(arr,mid+1,high);

      int find_max=max(lef.first,riht.first);
      int find_min=min(lef.second,riht.second);
      return{find_max,find_min};
    }
}

int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
pair<int,int>res=find_minmax(arr,0,n-1);
cout<<"max="<<res.first<<endl;
cout<<"min="<<res.second;
}
