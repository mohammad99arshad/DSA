#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int s, int d) {
    adj[s].push_back(d);
    adj[d].push_back(s);
}

int main() {
    int n = 605; 
    vector<int> adj[n];

    addEdge(adj, 601, 602);
    addEdge(adj, 601, 604);
    addEdge(adj, 601, 603);
    addEdge(adj, 602, 603);
    addEdge(adj, 603, 604);

    return 0;
}
