#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void greedy_coinChange(vector<int>coins,int amount){
    sort(coins.rbegin(),coins.rend());
    int k=0;
    vector<int>result;

    while(amount>0&&coins.size()>k){
        if(amount>=coins[k]){
            result.push_back(coins[k]);
            amount=amount-coins[k];
        }else{
        k++;
        }
    }
    int count=0;
    cout<<"total coin is-";
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
        count++;
    }
    cout<<"total coin is="<<count;

}
int main(){
int n;
cout<<"enter amount--";
cin>>n;
vector<int>coin={1,2,5,10,20,50,100,500,1000};

greedy_coinChange(coin,n);
}
