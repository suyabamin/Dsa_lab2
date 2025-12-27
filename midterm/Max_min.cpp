
#include<iostream>
#include <climits>
using namespace std;
pair<int ,int >Find_MinMax(int A[],int low,int high){
    if(low==high){
        return {A[low],A[low]};
    }else if(high==low+1){
        if(A[low]<A[high]){
            return{A[high],A[low]};
        }else{
            return {A[low],A[high]};
        }
    }
    else{
        int mid=(high+low)/2;
        pair<int,int >left=Find_MinMax(A,low,mid);
        pair<int ,int >right=Find_MinMax(A,mid+1,high);

        int finalMax=max(left.first,right.first);
        int finalmin=min(left.second,right.second);
        return{finalMax,finalmin};
    }

}

int main(){
    int n;
    cout<<"enter size of array--";
    cin>>n;
    int arr[n];
    cout<<"enter array elements--";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    pair<int ,int >result=Find_MinMax(arr,0,n-1);
    cout<<"Maximum value="<<result.first<<endl;
    cout<<"min value="<<result.second<<endl;

}
