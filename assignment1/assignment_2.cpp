
#include<iostream>
using namespace std;
int main()
{
 int n;
 cout<<"enter array size-";
 cin>>n;
 cout<<"enter array:";
 int arr[n];
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }
 int Count=0;
 for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(arr[i]>arr[j]){
            Count++;
        }
    }
 }
 cout<<Count;
}
