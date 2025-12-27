#include<iostream>
#include<map>
#include<string>
using namespace std;

void frequency_count(const string &st,map<char,int>&freq){
    for(int i=0;i<st.length();i++){
        freq[st[i]]++;
    }

}

int main(){
    cout<<"enter any string =";
    map<char,int>freq;
   
    string st;
    cin>>st;

    frequency_count(st,freq);

    for(auto i=freq.begin();i!=freq.end();i++){
        cout<<i->first<<":"<<i->second<<endl;
    }
}