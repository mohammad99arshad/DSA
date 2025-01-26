#include<iostream>
#include<queue>
using namespace std;

void explainPriorityQueue() {
    // Declaration of priority queue
    priority_queue<int> pq;

    // Inserting elements in the priority queue
    pq.push(5);
    pq.push(1);
    pq.push(10);
    pq.push(30);
    pq.push(20);

    // Size of the priority queue
    cout << "Size of the priority queue: " << pq.size() << endl;

    // Top element of the priority queue
    cout << "Top element of the priority queue: " << pq.top() << endl;

    // Popping elements from the priority queue
    pq.pop();
    pq.pop();

    // Size of the priority queue
    cout << "Size of the priority queue: " << pq.size() << endl;

    // Top element of the priority queue
    cout << "Top element of the priority queue: " << pq.top() << endl;

    priority_queue<int, vector<int>, greater<int>> pqMin;
    pqMin.push(5);
    pqMin.push(1);
    pqMin.push(10);
    pqMin.push(30);
    pqMin.emplace(20);
    cout<<pqMin.top()<<endl;
}
int main() {
    explainPriorityQueue();
    return 0;
}