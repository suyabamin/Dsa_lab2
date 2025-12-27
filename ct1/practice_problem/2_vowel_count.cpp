#include<iostream>
using namespace std;
char found_even(char arr[],int low,int high){
    //best
    if(high==low){
        if(arr[low]=='a'||arr[low]=='e'||arr[low]=='i'||arr[low]=='o'||arr[low]=='u'||arr[low]=='A'||arr[low]=='E'||arr[low]=='I'||arr[low]=='O'||arr[low]=='U'){
            return 1;
        }else{
            return 0;
        }
    }
    int mid=(low+high)/2;
    int left_count=found_even(arr,low,mid);
    int right_count=found_even(arr,mid+1,high);

    return left_count+right_count;
}

int main(){
    int  n;
    cout<<"enter array  size:-";
    cin>>n;
    char arr[n];
    cout<<"enter array element";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
 
    int even_num=found_even(arr,0,n-1);
    cout<<"vowel count--"<<even_num;
  
}