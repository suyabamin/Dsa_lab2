#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct item{
int wigth;
int value;
};

bool customsort(item it1,item it2){
return (double)it1.value/it1.wigth>(double)it2.value/it2.wigth;
}

int main(){
int n;
cin>>n;
vector<item>v(n);
cout<<"enter value-";
for(int i=0;i<n;i++){
    cin>>v[i].value;
}
cout<<"enter wigth-";
for(int i=0;i<n;i++){
    cin>>v[i].wigth;
}
cout<<"enter capaceity-";
int capacity;
cin>>capacity;
sort(v.begin(),v.end(),customsort);

double remaning=capacity;
double totalprofit=0.0;

for(int i=0;i<n;i++){
    if(remaning==0){
        break;
    }if(v[i].wigth<=remaning){
      remaning=remaning-v[i].wigth;
      totalprofit=totalprofit+v[i].value;
    }else{
      totalprofit=totalprofit+((double)v[i].value*remaning/v[i].wigth);
      remaning=0;
    }
}

cout<<"total profit-"<<totalprofit;

}
