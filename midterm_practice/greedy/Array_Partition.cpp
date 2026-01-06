#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);

    int Count=0;
    for(int i=0;i<n;i=i+2){
        Count=Count+arr[i];
    }
    cout<<"\n"<<Count;
}
