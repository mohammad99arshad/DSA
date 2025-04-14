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

Node *deleteOccurrence(Node *head, int target)
{
  Node *temp = head;

  while (temp)
  {
    if (temp->data == target)
    {
      Node *prev = temp->prev;
      Node *next = temp->next;

      if (prev)
        prev->next = next;
      else
      {
        head = next;
        if (head)
          head->prev = nullptr;
      }

      if (next)
        next->prev = prev;

      Node *del = temp;
      temp = next;
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
  vector<int> arr = {1, 2, 3, 4, 1, 5};
  Node *head = new Node(arr[0]);
  Node *tail = head;

  for (int i = 1; i < arr.size(); i++)
  {
    Node *newNode = new Node(arr[i]);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }

  cout << "Before deletion: ";
  print(head);

  head = deleteOccurrence(head, 1);

  cout << "After deletion: ";
  print(head);

  return 0;
}
