#include<bits/stdc++.h>
using namespace std;

int Max_crossingSubarray(int arr[],int low,int mid,int high){
int leftsum=INT_MIN;
int sum=0;
for(int i=mid;i>=low;i--){
      sum=sum+arr[i];
      leftsum=max(leftsum,sum);
}
int right_sum=INT_MIN;
sum=0;
for(int i=mid+1;i<=high;i++){
    sum=sum+arr[i];
    right_sum=max(right_sum,sum);
}
return leftsum+right_sum;

}

int Maxsumsubarray(int arr[],int low,int high){
if(low==high){
    return arr[low];
}
int mid=(low+high)/2;
int leftsum=Maxsumsubarray(arr,low,mid);
int rightsum=Maxsumsubarray(arr,mid+1,high);
int cros_sum=Max_crossingSubarray(arr,low,mid,high);

return max(leftsum,max(rightsum,cros_sum));

}

int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int max_sum=Maxsumsubarray(arr,0,n-1);
cout<<max_sum;
}
