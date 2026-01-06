#include<iostream>
#include<algorithm>
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
  int midian_ind=n/2;
  int midian=arr[midian_ind];
    int cost;
  for(int i=0;i<n;i++){
    cost=cost+abs(arr[i]-arr[midian_ind]);
  }
  cout<<cost;

}
