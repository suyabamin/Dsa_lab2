#include<iostream>
#include<climits>
using namespace std;
int Find_cross(int arr[],int low,int mid,int high){
    int left=INT_MIN;
    int sum=0;
    for(int i=mid;i>=low;i--){
         sum=sum+arr[i];
         left=max(left,sum);
    }

    int right=INT_MIN;
    sum=0;
    for(int i=mid+1;i<=high;i++){
        sum=sum+arr[i];
        right=max(right,sum);
    }
    return left+right;
}

int find_Max(int arr[],int low,int high){
    if(high==low){
        return arr[low];
    }
    int mid=(high+low)/2;
    int left=find_Max(arr,low,mid);
    int right=find_Max(arr,mid+1,high);
    int cross=Find_cross(arr,low,mid,high);
    return max(left,max(right,cross));
}

int main(){
    int n;
    cout<<"enter size-";
    cin>>n;
    int arr[n];
    cout<<"enter array--";
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }

    int max_sum=find_Max(arr,0,n-1);
    cout<<"max sum="<<max_sum;
}