#include<iostream>
#include<vector>
#include <climits>
using namespace std;
int main(){
    int n=5;
    int arr[5]={1,2,3,4,5};
      int maxsum=INT_MIN;
 for(int st=0;st<n;st++){
     int carrSum=0;
    for(int end=0;end<n;end++){
       carrSum=carrSum+arr[end];
       maxsum=max(carrSum,maxsum); 
    }

 }
 cout<<"max subarray sum="<<maxsum<<endl;

}