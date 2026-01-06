#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
cin>>s;
int k=1;
int i=0,j=s.size()-1;
while(i>j){
   if(s[i]==s[j]){
    i++;
    j--;
   }else{
     j--;
     k--;
   }
}
if(k==0||k==1){
    cout<<"true";
}else{
cout<<"false";
}
}
