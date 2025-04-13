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

void deleteAtHead(Node *&head)
{
  if (head == nullptr || head->next == nullptr)
  {
    delete head;
    head = nullptr;
    return;
  }
  Node *temp = head;
  head = head->next;
  head->prev = nullptr;
  temp->next = nullptr;
  delete temp;
}

void deleteAtTail(Node *&head)
{
  if (head == nullptr || head->next == nullptr)
  {
    delete head;
    head = nullptr;
    return;
  }
  Node *tail = head;
  while (tail->next != nullptr)
  {
    tail = tail->next;
  }
  Node *newTail = tail->prev;
  newTail->next = nullptr;
  tail->prev = nullptr;
  delete tail;
}

void deleteAtPos(Node *&head, int pos)
{
  if (head == nullptr)
    return;

  if (pos == 1)
  {
    deleteAtHead(head);
    return;
  }

  Node *temp = head;
  int count = 1;
  while (count < pos && temp != nullptr)
  {
    temp = temp->next;
    count++;
  }

  if (temp == nullptr)
    return;

  if (temp->next == nullptr)
  {
    deleteAtTail(head);
    return;
  }

  Node *prev = temp->prev;
  Node *next = temp->next;

  prev->next = next;
  next->prev = prev;

  temp->next = nullptr;
  temp->prev = nullptr;
  delete temp;
}

int main()
{
  // Creating a doubly linked list: 1 <-> 2 <-> 3 <-> 4
  Node *head = new Node(1);
  Node *second = new Node(2);
  Node *third = new Node(3);
  Node *fourth = new Node(4);

  head->next = second;
  second->prev = head;
  second->next = third;
  third->prev = second;
  third->next = fourth;
  fourth->prev = third;

  print(head);

  deleteAtHead(head);
  print(head);

  deleteAtTail(head);
  print(head);

  deleteAtPos(head, 2);
  print(head);

  return 0;
}
