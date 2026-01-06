#include<iostream>
#include<cmath>
using namespace std;
int main(){
int n;
cout<<"enter pair amount-";
cin>>n;
int x[n],y[n];
for(int i=0;i<n;i++){
    cin>>x[i];
    cin>>y[i];
}
double min_value=1e9;
double distance;
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        distance=sqrt(((x[j]-x[i])*(x[j]-x[i]))+((y[j]-y[i])*(y[j]-y[i])));

    }
    if(distance<min_value){
        min_value=distance;
    }
}
cout<<min_value;

}
