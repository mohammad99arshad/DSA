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

Node *reverseList(Node *head)
{
  Node *prev = nullptr;
  Node *curr = head;
  Node *next = nullptr;

  while (curr != nullptr)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

void print(Node *head)
{
  Node *temp = head;
  while (temp != nullptr)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main()
{
  vector<int> arr = {2, 3, 4, 5, 6};
  Node *head = new Node(arr[0]);
  Node *tail = head;

  for (int i = 1; i < arr.size(); i++)
  {
    tail->next = new Node(arr[i]);
    tail = tail->next;
  }

  cout << "Original List: " << endl;
  print(head);

  head = reverseList(head);

  cout << "Reversed List: " << endl;
  print(head);

  return 0;
}
