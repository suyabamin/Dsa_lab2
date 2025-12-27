#include<iostream>
#include<climits>
using namespace std;
pair<int ,int>Max_min(int arr[],int low,int high){
              if(high==low){
                return{arr[low],arr[low]};
              }else if(high==low+1){
                if(arr[high]>arr[low]){
                return {arr[high],arr[low]};
               }else{
                return{arr[low],arr[high]};
               }
              }else{
                int mid=(high+low)/2;
                pair<int ,int >left=Max_min(arr,low,mid);
                pair<int,int >right=Max_min(arr,mid+1,high);

                int  Max_find=max(left.first,right.first);
                 int Min_find=min(left.second,right.second);
                return {Max_find,Min_find};
              }
              
}
int main(){
    int n;
    cout<<"enter array  size:-";
    cin>>n;
    int arr[n];
    cout<<"enter array element";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

  pair<int ,int>result=Max_min(arr,0,n-1);
  cout<<"max"<<result.first<<endl;
  cout<<"min"<<result.second;
}