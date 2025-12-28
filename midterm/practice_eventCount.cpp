#include<iostream>
using namespace std;
int evencount(int arr[],int low,int high){
    if(high==low){
        if(arr[low]%2==0){
            return 1;
        }else{
        return 0;
        }
    }
    int mid=(low+high)/2;
    int left_count=evencount(arr,low,mid);
    int right_count=evencount(arr,mid+1,high);
    return left_count+right_count;
}
int main(){
int n;
cout<<"enter array size";
cin>>n;
int arr[n];
cout<<"enrer array--";
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int evencont=evencount(arr,0,n-1);
cout<<evencont;
}
