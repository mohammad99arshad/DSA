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

void insertAtHead(Node *&head, int d)
{
  Node *newNode = new Node(d);
  newNode->next = head;
  if (head != nullptr)
  {
    head->prev = newNode;
  }
  head = newNode;
}
void insertAtTail(Node *&head, int d)
{
  Node *tail = head;
  while (tail->next != nullptr)
  {
    tail = tail->next;
  }
  Node *newNode = new Node(d);
  tail->next = newNode;
  newNode->prev = tail;
}
void insertAtPos(Node *&head, int pos, int d)
{
  if (pos == 1)
  {
    insertAtHead(head, d);
    return;
  }
  Node *tail = head;
  int count = 0;
  while (count < pos - 1 && tail->next != nullptr)
  {
    tail = tail->next;
    count++;
  }
  Node *newNode = new Node(d);
  newNode->next = tail->next;
  newNode->prev = tail;
  if (tail->next != nullptr)
  {
    tail->next->prev = newNode;
  }
  tail->next = newNode;
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
