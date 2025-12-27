#include<iostream>
#include <climits>
using namespace std;
int Max_cross_subarray(int arr[],int low,int mid,int high){
        int leftSum=INT_MIN;
        int sum=0;
        for(int i=mid;i>=low;i--){
            sum=sum+arr[i];
            leftSum=max(leftSum,sum);
        }
        sum=0;
        int rightsum=INT_MIN;
        for(int i=mid+1;i<=high;i++){
           sum=sum+arr[i];
           rightsum=max(rightsum,sum);
        }
        return leftSum+rightsum;

}

int Max_sub_array(int arr[],int low,int high){

    if(low==high){
        return arr[low];
    }
    int mid=(high+low)/2;
    int leftsum=Max_sub_array(arr,low,mid);
    int rightsum=Max_sub_array(arr,mid+1,high);
    int crosssum=Max_cross_subarray(arr,low,mid,high);

    return max(leftsum,max(rightsum,crosssum));
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

    int maxsum=Max_sub_array(arr,0,n-1);
    cout<<"max sum="<<maxsum;
}