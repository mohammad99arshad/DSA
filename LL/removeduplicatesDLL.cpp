#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *prev;
  Node(int data)
  {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

Node *removeDulpicate(Node *head)
{
  Node *temp = head;
  while (temp && temp->next)
  {
    if (temp->data == temp->next->data)
    {
      Node *del = temp->next;
      temp->next = del->next;
      if (del->next)
        del->next->prev = temp;
      delete del;
    }
    else
    {
      temp = temp->next;
    }
  }
  return head;
}
void print(Node *head)
{
  while (head)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}
int main()
{
  vector<int> arr = {
      1,
      1,
      2,
      2,
      3,
      4,
      4,
  };
  Node *head = new Node(arr[0]);
  Node *tail = head;

  for (int i = 1; i < arr.size(); i++)
  {
    tail->next = new Node(arr[i]);
    tail = tail->next;
  }

  cout << "Before deletion: ";
  print(head);

  head = removeDulpicate(head);

  cout << "After deletion: ";
  print(head);

  return 0;
}