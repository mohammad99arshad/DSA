// Minimum number of mplatfomrs required for a railway

#include<bits/stdc++.h>
using namespace std;

int findPlatform(vector<int>& Arrival, vector<int>& Departure){
    int maxcount = 0, count = 0, i = 0, j = 0;
    int n = Arrival.size();
    sort(Arrival.begin(), Arrival.end());
    sort(Departure.begin(), Departure.end());
    while(i < n){
        if(Arrival[i] <= Departure[j]){
            count++;
            i++;
        }else{
            count--;
            j++;
        }
        maxcount = max(count, maxcount);
    }
    return maxcount;
}

int main(){
    vector<int>arr1 = {900,945,955,1100,1500,1800};
    vector<int>arr2 = {920,1200,1130,1150,1900,2000};
    int result = findPlatform(arr1, arr2);
    cout<<result<<endl;
    return 0;
}