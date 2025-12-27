#include<iostream>
#include<map>
using namespace std;
int main(){
    map<string,int>map1;
    map1.insert({"sunny",233});
    map1.insert({"su",234});
    map1.insert({"suuu",235});

    //map print
    for(auto i=map1.begin();i!=map1.end();i++){
        cout<<i->first<<":"<<i->second<<endl;
    }
    map1["su"]=100;
       
    //map print for each loop
    cout<<"second way"<<endl;
    for(auto i:map1){
        cout<<i.first<<" "<<i.second<<endl;
    }
}