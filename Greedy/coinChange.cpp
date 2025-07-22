// greedy algorithm to find minimum number of coins

#include<bits/stdc++.h>
using namespace std;

int  coinChange(vector<int>& coins, int n){
    int count = 0;
    for(int i=coins.size()-1; i>=0; i--){
        count += n/coins[i];
        n = n % coins[i];
    }
    return count;
}

int main(){

    vector<int>coin = {1,2,5,10};
    int n = 39; 
    int result = coinChange(coin, n);
    cout<<result<<endl;
    return 0;
}