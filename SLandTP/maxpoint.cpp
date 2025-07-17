// maximum points you can obtain  from cards

#include<bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints, int k){
    int lsum =0, rsum=0, sum=0;
    for(int i=0; i<k; i++){
        lsum += cardPoints[i];
        sum = lsum;
    }
    int rindex = cardPoints.size() - 1;
    for(int i=k-1; i>=0; i--){
        lsum -= cardPoints[i];
        rsum = rsum + cardPoints[rindex];
        rindex--;
        sum = max(sum, lsum+rsum);
    }
    return sum;
}

int main(){
    vector<int>arr= {1,2,3,4,5,6,1};
    int n = 3;
    int result = maxScore(arr, n);
    cout<<result<<endl;
}