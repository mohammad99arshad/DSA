#include<bits/stdc++.h>
using namespace std;

vector<int>getPrimeFactors(int n){
    vector<int>factors;
    while(n%2 == 0){
        factors.push_back(n);
        n /=2;
    }
    for(int i=3; i*i <= n; i+=2){
        while(n % i == 0){
            factors.push_back(i);
            n /= i;
        }
    }
    if(n>1){
        factors.push_back(n);
    }
    return factors;
}

vector<vector<int>>primeFactors(vector<int>& query){
    vector<vector<int>>result;
    for(int num : query){
        result.push_back(getPrimeFactors(num));
    }
    return result;
}

int main(){
    vector<int>arr = {2,3,4,5,6};
    vector<vector<int>>result = primeFactors(arr);
    for(const auto& factors: result){
        for(int factor: factors){
            cout<<factor<<" ";
        }
        cout<<endl;
    }
    return 0; 
}