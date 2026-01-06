#include<bits/stdc++.h>
using namespace std;
int vowel_count(char arr[],int low,int high){
       if(low==high){
        if(arr[low]=='a'||arr[low]=='e'||arr[low]=='i'||arr[low]=='o'||arr[low]=='u'){
            return 1;
        }else{
        return 0;
        }
       }
       int mid=(low+high)/2;
       int left=vowel_count(arr,low,mid);
       int right=vowel_count(arr,mid+1,high);
       return left+right;
}
int main(){
int n;
cin>>n;
char arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int Count=vowel_count(arr,0,n-1);
cout<<Count;
}
