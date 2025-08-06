#include<bits/stdc++.h>
using namespace std;

void tcombo(int pos, int target, vector<int>& candidates, vector<int>&current, vector<vector<int>>& res){
    if(target == 0){
        res.push_back(current);
        return;
    }
    if(pos == candidates.size()) return;

    if(candidates[pos] <= target){
        current.push_back(candidates[pos]);
        tcombo(pos, target-candidates[pos], candidates, current, res);
        current.pop_back();
    }
    tcombo(pos+1, target, candidates, current, res);
}

vector<vector<int>> comibnation(vector<int>& candidates, int target){
    vector<vector<int>>res;
    vector<int>current;
    tcombo(0, target, candidates, current, res);
    return res;
}


int main() {
    vector<int> arr = {3, 4, 5, 6, 2, 8, 9};
    int target = 10;

    vector<vector<int>> res = comibnation(arr, target);

    cout << "[\n";
    for (const auto& combo : res) {
        cout << "  [";
        for (int i = 0; i < combo.size(); i++) {
            cout << combo[i];
            if (i != combo.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
    cout << "]\n";

    return 0;
}