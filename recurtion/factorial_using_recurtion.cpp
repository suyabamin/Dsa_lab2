#include<iostream>
#include<vector>
using namespace std;

void refact(int i,int n,vector<int>&result,int cf){
    if(i>n){
        return;
    }
    cf=cf*i;
    result[i-1]=cf;
    refact(i+1,n,result,cf);

}

vector<int>fact(int n){
    vector<int>result(n);
    refact(1,n,result,1);
    return result;
}


int main(){
    int n;
    cout<<"enter any number=";
    cin>>n;
    vector<int>f=fact(n);
    cout<<"";
    for(int i:f){
       cout<<i<<endl;
    }
}