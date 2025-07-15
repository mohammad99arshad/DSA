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

void deleteAtHead(Node *&head)
{
  if (head == nullptr)
    return;
  Node *temp = head;
  head = head->next;
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

  Node *temp = head;
  while (temp->next->next != nullptr)
  {
    temp = temp->next;
  }

  delete temp->next;
  temp->next = nullptr;
}

void deleteAtpos(Node *&head, int pos)
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

  while (count < pos - 1 && temp->next != nullptr)
  {
    temp = temp->next;
    count++;
  }

  if (temp->next == nullptr)
    return;

  Node *del = temp->next;
  temp->next = temp->next->next;
  delete del;
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
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);

  print(head);
  deleteAtHead(head);
  print(head);
  deleteAtTail(head);
  print(head);
  deleteAtpos(head, 2);
  print(head);

  return 0;
}
