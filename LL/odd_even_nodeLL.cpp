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

void oddEvenLL(Node *&head)
{
  if (!head || !head->next)
    return;

  Node *temp = head;
  vector<int> arr;

  while (temp && temp->next)
  {
    arr.push_back(temp->data);
    temp = temp->next->next;
  }
  if (temp)
    arr.push_back(temp->data);

  temp = head->next;
  while (temp && temp->next)
  {
    arr.push_back(temp->data);
    temp = temp->next->next;
  }
  if (temp)
    arr.push_back(temp->data);

  temp = head;
  int i = 0;
  while (temp)
  {
    temp->data = arr[i++];
    temp = temp->next;
  }
}

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

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5, 6};
  Node *head = new Node(arr[0]);
  Node *tail = head;

  for (int i = 1; i < arr.size(); i++)
  {
    tail->next = new Node(arr[i]);
    tail = tail->next;
  }

  cout << "before change" << endl;
  print(head);

  cout << "after change" << endl;
  oddEvenLL(head);
  print(head);

  return 0;
}
