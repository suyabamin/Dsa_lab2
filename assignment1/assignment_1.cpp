#include<iostream>
using namespace std;
struct qarray{
int start;
int End;
};

int main(){
int n,q;
cout<<"enter size of array-";
cin>>n;
cout<<"enter number of quary-";
cin>>q;
int arr[n];
cout<<"enter array-";
for(int i=0;i<n;i++){
    cin>>arr[i];
}


 qarray ar[q];

 for(int i=0;i<q;i++){
    cout<<"enter"<<i<<"st quary start and end";
    cin>>ar[i].start;
    cin>>ar[i].End;
 }

 for(int i=0;i<q;i++){
        int Count=0;
    for(int j=ar[i].start-1;j<ar[i].End;j++){
        if(arr[j]==0){
            Count++;
        }
    }
    cout<<Count<<endl;
 }

}
