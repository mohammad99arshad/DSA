#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node(int data)
  {
    this->data = data;
    this->next = nullptr;
  }
};
void print(Node *head)
{
  Node *temp = head;
  while (temp)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}
void sorting(Node *head)
{
  if (!head)
    return;
  Node *temp = head;
  vector<int> arr;
  while (temp)
  {
    arr.push_back(temp->data);
    temp = temp->next;
  }
  int i = 0;
  temp = head;
  sort(arr.begin(), arr.end());
  while (temp)
  {
    temp->data = arr[i++];
    temp = temp->next;
  }
}

int main()
{
  vector<int> arr = {3, 5, 1, 4, 2};
  Node *head = new Node(arr[0]);
  Node *tail = head;
  for (int i = 1; i < arr.size(); i++)
  {
    tail->next = new Node(arr[i]);
    tail = tail->next;
  }
  cout << "Before Sorting: " << endl;
  print(head);
  cout << "After Sorting: " << endl;
  sorting(head);
  print(head);
  return 0;
}