#include<bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int>& st, int element) {
    if (st.empty() || element > st.top()) {
        st.push(element);
        return;
    }
    int temp = st.top();
    st.pop();
    sortedInsert(st, element);
    st.push(temp);
}

void sortStack(stack<int>& st){
    if(st.empty()) return;
    int temp = st.top();
    st.pop();
    sortStack(st);
    sortedInsert(st, temp);
}

void printStack(stack<int>st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){
    stack<int>st;
    st.push(4);
    st.push(2);
    st.push(8);
    st.push(7);
    sortStack(st);
    cout<<"sorted stack is :";
    printStack(st);
    return 0;
}