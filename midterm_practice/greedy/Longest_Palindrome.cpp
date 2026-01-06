#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
cin>>s;

unordered_map<char,int>freq;

for(char i:s){
    freq[i]++;
}
int ans=0;
bool odd=false;
for(auto it:freq){
    if(it.second%2==0){
          ans=ans+it.second;
    }else{
    ans=ans+it.second-1;
    odd=true;
    }
}

if(odd){
    ans=ans+1;
}
cout<<ans;

}
