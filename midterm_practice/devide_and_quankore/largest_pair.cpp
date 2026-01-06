#include<bits/stdc++.h>
using namespace std;
struct Pair{
int max1;
int max2;
};
Pair largestPari(int arr[],int low,int high){
    Pair result;
if(high==low){
    result.max1=arr[low];
    result.max2=INT_MIN;
    return result;
}

if(high==low+1){
    if(arr[low]>arr[high]){
        result.max1=arr[low];
        result.max2=arr[high];

    }else{
       result.max1=arr[high];
       result.max2=arr[low];
    }
    return result;
}

int mid=(low+high)/2;
Pair left=largestPari(arr,low,mid);
Pair right=largestPari(arr,mid+1,high);

if(left.max1>right.max2){
    result.max1=left.max1;
    result.max2=max(left.max2,right.max1);
}else{
result.max1=right.max1;
result.max2=max(right.max2,left.max1);
}
return result;

}
int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}

Pair ans=largestPari(arr,0,n-1);
cout<<"largest-"<<ans.max1<<endl;
cout<<"second largest--"<<ans.max2;
}
