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

int lengthOfLinkedList(Node *head)
{
  int count = 0;
  Node *temp = head;

  while (temp != nullptr)
  {
    count++;
    temp = temp->next;
  }

  return count;
}

int main()
{
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);

  cout << "Length of linked list: " << lengthOfLinkedList(head) << endl;

  return 0;
}
