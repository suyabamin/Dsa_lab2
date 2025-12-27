#include<iostream>
#include <climits>
using namespace std;

int MaxCRossingSubArray(int A[],int low,int mid,int high){
    int leftSum=INT_MIN;
    int sum=0;
    
    for(int i=mid;i>=low;i--){
        sum=sum+A[i];
        leftSum=max(leftSum,sum);
    }

    int rightSum=INT_MIN ;
    sum=0;
    for(int i=mid+1;i<=high;i++){
        sum=sum+A[i];
        rightSum=max(rightSum,sum);
    }

   return leftSum+rightSum;
}


int MaxSubarray(int A[],int low,int high){
    if(low==high){
        return A[low];  /// its means leaf nood found;
    }
    int mid=(low+high)/2;
    int leftSum=MaxSubarray(A,low,mid);
    int rightSum=MaxSubarray(A,mid+1,high);

    int crossSum=MaxCRossingSubArray(A,low,mid,high);

    return max(leftSum,max(rightSum,crossSum));    ///compare which is greater

} 


int main(){
    int n;
    cout<<"enter size of array--";
    cin>>n;
    int A[n];
    cout<<"enter array elements--";
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int maxSum=MaxSubarray(A,0,n-1);

    cout<<"maximum subarray sum="<<maxSum<<endl;
}