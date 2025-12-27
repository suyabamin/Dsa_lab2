#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

 void greedycoinchange(vector<int>coins,int amount){
    vector<int>result;
    sort(coins.rbegin(),coins.rend());
    int k=0;
    while (amount>0 && coins.size()>k)
    {
       if(amount>=coins[k]){
           result.push_back(coins[k]);
           amount=amount-coins[k];
       }else{
        k++;
       }
    }
    int count=0;
    cout<<"used note--";
    for(int i=0;i<result.size();i++){
      cout<<result[i]<<", ";
      count++;
    }

    cout<<"total note="<<result.size();
    
 }

int main(){
    vector<int>coin={1,2,5,10,20,50,100,500,1000};
    int amount;
    cin>>amount;
    
     greedycoinchange(coin,amount);
     
}