#include<bits/stdc++.h>
using namespace std;

void genString(int n, string s, char c, vector<string>&res){
    if(s.length() == n){
        res.push_back(s);
        return;
    }
    genString(n, s + '0', '0', res);
    if(c != '1'){
        genString(n, s+'1', '1', res);
    }
}

vector<string> generateString(int n){
    vector<string>res;
    genString(n, "", '0', res);
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<string>res = generateString(n);
    for(string ch : res){
        cout<<ch<<endl;
    }
    return 0;
}