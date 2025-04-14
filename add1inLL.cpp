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

// Reverses the linked list and returns new head
Node *reverse(Node *head)
{
  Node *prev = nullptr;
  Node *curr = head;
  while (curr)
  {
    Node *nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
  }
  return prev;
}

Node *addinLL(Node *&head)
{
  head = reverse(head); // directly updating head
  Node *temp = head;
  int carry = 1;

  while (temp && carry)
  {
    temp->data += carry;
    if (temp->data < 10)
    {
      carry = 0;
    }
    else
    {
      temp->data = 0;
      if (!temp->next)
        break;
    }
    if (carry)
      temp = temp->next;
  }

  if (!temp && carry)
  {
    Node *newNode = new Node(1);
    newNode->next = head;
    head = newNode;
  }

  head = reverse(head); // again directly updating head
  return head;
}

void printList(Node *head)
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
  vector<int> arr = {1, 2, 3}; // represents 123
  Node *head = new Node(arr[0]);
  Node *tail = head;

  for (int i = 1; i < arr.size(); i++)
  {
    tail->next = new Node(arr[i]);
    tail = tail->next;
  }

  cout << "Original List: ";
  printList(head);

  addinLL(head); // no need to assign the return value

  cout << "Updated List (after adding 1): ";
  printList(head);

  return 0;
}
