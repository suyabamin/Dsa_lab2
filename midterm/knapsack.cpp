#include<bits/stdc++.h>
#include<vector>
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
cout<<"enter weight--";
for(int i=0;i<n;i++){
    cin>>v[i].wigth;
}
int capacity;
cin>>capacity;

sort(v.begin(),v.end(),customsort);   ///value per index

double remaing=capacity;
double totalprofit=0.0;

for(int i=0;i<n;i++){
    if(remaing==0){
        break;
    }if(v[i].wigth<=remaing){
       remaing=remaing-v[i].wigth;
       totalprofit=totalprofit+v[i].value;
    }else{
    totalprofit=totalprofit+((double)v[i].value*remaing/v[i].wigth);
    remaing=0;
    }
}
cout<<"total profit="<<totalprofit;
}
