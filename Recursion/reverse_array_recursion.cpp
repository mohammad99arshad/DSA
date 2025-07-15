#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
   cout << "The reversed array is:- " << endl;
   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
}

void reverseArray(int arr[], int start, int end){
    if(start<end){
        swap(arr[start], arr[end]);
        reverseArray(arr, start+1, end-1);
    }
}

int main(){
    int size;
    cin >> size;
    int arr[size];
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    reverseArray(arr, 0, size-1);
    printArray(arr, size);
    return 0;
}