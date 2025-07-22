// shortest job first

#include<bits/stdc++.h>
using namespace std;

int shortestJobFirst(vector<int>& tasks){
    sort(tasks.begin(), tasks.end());
    int wtime = 0, timer = 0;

    for(int i=0; i<tasks.size(); i++){
        wtime += timer;
        timer += tasks[i];
    }
    return (double)wtime/tasks.size();
}

int main(){
    vector<int>task = {4,3,7,1,2};
    int result = shortestJobFirst(task);
    cout<<result<<endl;
    return 0;
}