#include<iostream>
using namespace std;
int  vowel_count(char arr[],int low,int high){
  if(high==low){
    if(arr[low]=='a'||arr[low]=='e'||arr[low]=='i'||arr[low]=='o'||arr[low]=='u'||arr[low]=='A'||arr[low]=='E'||arr[low]=='I'||arr[low]=='O'||arr[low]=='U'){
        return 1;
    }else{
    return 0;
    }
  }
  int mid=(low+high)/2;
  int left_count=vowel_count(arr,low,mid);
  int right_count=vowel_count(arr,mid+1,high);
  return left_count+right_count;

}
int main(){
int n;
cout<<"enter size-";
cin>>n;
char arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}

int total=vowel_count(arr,0,n-1);
cout<<total;
}
