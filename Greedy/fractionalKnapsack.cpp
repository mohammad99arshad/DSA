#include<bits/stdc++.h>
using namespace std;

struct Item{
    long long value, weight;
};
bool cmp(Item a, Item b){
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {
    int n = val.size();
    vector<Item>items(n);
    for(int i=0; i<n; i++){
        items[i].value = val[i];
        items[i].weight = wt[i];
    }
    sort(items.begin(), items.end(), cmp);

    double totalVal = 0.0;
    for(int i=0; i<n && capacity > 0; i++){
        if(capacity >= items[i].weight){
            totalVal += items[i].value;
            capacity -= items[i].weight;
        }else{
            totalVal += (double)capacity * (items[i].value / items[i].weight);
            break;
        }
    }
    return totalVal;
    
}

int main(){
    vector<long long>arr1 = {60,100,120};
    vector<long long>arr2 = {10,20,30};
    int cap = 50;
    int result = fractionalKnapsack(arr1, arr2, cap);
    cout<<result<<endl;
    return 0;
}


