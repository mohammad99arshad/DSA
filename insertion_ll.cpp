#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *next;

  Node(int data)
  {
    this->data = data;
    this->next = nullptr;
  }
};

void insertAtHead(Node *&head, int d)
{
  Node *temp = new Node(d);
  temp->next = head;
  head = temp;
}

void insertAtTail(Node *&tail, int d)
{
  Node *temp = new Node(d);
  tail->next = temp;
  tail = temp;
}

void insertAtPos(Node *&head, int pos, int d)
{
  if (pos == 1)
  {
    insertAtHead(head, d);
    return;
  }

  Node *temp = head;
  int count = 1;
  while (count < pos - 1 && temp->next != nullptr)
  {
    temp = temp->next;
    count++;
  }

  Node *nodeToInsert = new Node(d);
  nodeToInsert->next = temp->next;
  temp->next = nodeToInsert;
}

void print(Node *head)
{
  while (head != nullptr)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

int main()
{
  vector<int> arr = {2, 3, 4, 5};
  Node *head = new Node(arr[0]);
  Node *tail = head;

  for (int i = 1; i < arr.size(); i++)
  {
    insertAtTail(tail, arr[i]);
  }

  print(head);

  insertAtHead(head, 1);
  print(head);

  insertAtTail(tail, 6);
  print(head);

  insertAtPos(head, 4, 99);
  print(head);
}
