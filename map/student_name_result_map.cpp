#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
    cout<<"how many student? =";
    map<string,int>stu;
    int n;
    cin>>n;
    string naem;
    int marks;
    for(int i=0;i<n;i++){
        cout<<"enter student name-";
       cin>>naem;
       cout<<"enter "<<naem<<" marks=";
       cin>>marks;
       stu[naem]=marks;
        
    }

    for(auto i=stu.begin();i!=stu.end();i++){
        cout<<i->first<<":"<<i->second<<endl;
    }
}