#include<bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int l=0, r=0;
        while(l<g.size() && r<s.size()){
            if(g[l] <= s[r]){
                l++;
            }
            r++;
        }
    return l;
}

int main(){
    vector<int>greed = {1,2,3};
    vector<int>size = {1,1,1};
    int result = findContentChildren(greed, size);
    cout<<result<<endl;
    return 0;
}