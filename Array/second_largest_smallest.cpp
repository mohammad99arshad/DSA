#include<bits/stdc++.h>
using namespace std;

int secondLargest(vector<int> &arr, int n){
    int largest = arr[0];
    int slargest = INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]>largest){
            slargest = largest;
            largest = arr[i];
        }else if( arr[i]<largest && arr[i]>slargest){
            slargest = arr[i];
        }
    }
    return slargest;
}

int secondSmallest(vector<int> &arr, int n){
    int smallest = arr[0];
    int ssmallest = INT_MAX;
    for(int i=0; i<n; i++){
        if(arr[i]<smallest){
            ssmallest = smallest;
            smallest = arr[i];
        }else if(arr[i]>smallest && arr[i]<ssmallest){
            ssmallest = arr[i];
        }
    }
    return ssmallest;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<secondLargest(arr, n)<<endl;
    cout<<secondSmallest(arr, n)<<endl;
}