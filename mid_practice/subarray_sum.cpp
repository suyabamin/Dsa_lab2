#include<iostream>
<<<<<<< HEAD
#include <climits>
using namespace std;

int  cross_sum(int arr[],int low,int mid,int high){
     int left=INT_MIN;
     int sum=0;
     for(int i=mid;i>=low;i--){
        sum=sum+arr[i];
        left=max(left,sum);
=======
#include<vector>
using namespace std;

  vector<int>sub;

int  cross_sum(int arr[],int low,int mid,int high){
     int left=INT_MIN;
     int sum=0;

     for(int i=mid;i>=low;i--){
        sum=sum+arr[i];
        if(left<sum){
            left=sum;
            sub.push_back(arr[i]);
        }
>>>>>>> 4b2d0db (added mid)
     }
     sum=0;
     int right=INT_MIN;
     for(int i=mid+1;i<=high;i++){
        sum=sum+arr[i];
<<<<<<< HEAD
        right=max(right,sum);
=======
       if(right<sum){
        right=sum;
         sub.push_back(arr[i]);
       }
>>>>>>> 4b2d0db (added mid)
     }
     return left+right;

}

int maxsubarray(int arr[],int low,int high){
    if(high==low){
        return arr[low];
    }
  int mid=(high+low)/2;
  int left=maxsubarray(arr,low,mid);
  int right=maxsubarray(arr,mid+1,high);
   int cross= cross_sum(arr,low,mid,high);
  return max(left,max(right,cross));
}
int main(){
    cout<<"Enter array size-";
    int n;
    cin>>n;
    int arr[n];
    cout<<"ENTER array element"<<"("<<n<<")";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int Max=maxsubarray(arr,0,n-1);
    cout<<"max sum"<<Max;
<<<<<<< HEAD
=======

    cout<<"subarray=";
     for(int x:sub){
        cout<<x<<" ";
     }
>>>>>>> 4b2d0db (added mid)
}
