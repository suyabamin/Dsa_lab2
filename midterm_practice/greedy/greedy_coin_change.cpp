#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void greedycoinChange(vector<int>coin,int amount){
vector<int>result;
  sort(coin.rbegin(),coin.rend());
int k=0;
while(amount>0&&coin.size()>k){
        if(amount>=coin[k]){
            result.push_back(coin[k]);
            amount=amount-coin[k];
        }else{
        k++;
        }
}
    int Count=0;
    for(int i=0;i<result.size();i++){
            cout<<result[i]<<" ";
        Count++;
    }
    cout<<endl;
    cout<<Count;

}
int main(){
vector<int>coin={1,2,5,10,20,50,100,500,1000};
int amount;
cin>>amount;

greedycoinChange(coin,amount);

}
