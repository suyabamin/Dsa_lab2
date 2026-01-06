#include<bits/stdc++.h>
using namespace std;

int mid_count_arr(int arr[],int low,int high){
   if(high==low){
    if(arr[low]%2==0){
        return 1;
    }else{
       return 0;
    }
   }
   int mid=(low+high)/2;
   int left=mid_count_arr(arr,low,mid);
   int right=mid_count_arr(arr,mid+1,high);

   return left+right;

}

int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int mid_count=mid_count_arr(arr,0,n-1);
cout<<mid_count;

}
