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

int searchElement(Node *head, int element)
{
  int pos = 1;
  Node *temp = head;
  while (temp != nullptr)
  {
    if (temp->data == element)
    {
      return pos;
    }
    temp = temp->next;
    pos++;
  }
  return -1;
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
  Node *head = new Node(4);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);

  print(head);

  int element = 3;
  int position = searchElement(head, element);

  if (position != -1)
    cout << "Element found at position: " << position << endl;
  else
    cout << "Element not found" << endl;

  return 0;
}
