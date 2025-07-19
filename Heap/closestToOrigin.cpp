#include <bits/stdc++.h>
#define pp pair<int, pair<int, int>>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pp> maxheap;

    for (int i = 0; i < points.size(); i++) {
        int x = points[i][0], y = points[i][1];
        int distSq = x * x + y * y;

        maxheap.push({distSq, {x, y}});

        if (maxheap.size() > k) {
            maxheap.pop();
        }
    }

    vector<vector<int>> result;
    while (!maxheap.empty()) {
        pair<int, int> p = maxheap.top().second;
        result.push_back({p.first, p.second});
        maxheap.pop();
    }

    return result;
}

int main() {
    vector<vector<int>> points = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int k = 2;

    vector<vector<int>> res = kClosest(points, k);
    for (auto& point : res) {
        cout << "[" << point[0] << ", " << point[1] << "]" << endl;
    }

    return 0;
}
