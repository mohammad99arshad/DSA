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

void deletionBack(Node *&head, int n)
{
  if (!head)
    return;

  int count = 0;
  Node *temp = head;

  // Step 1: Count the number of nodes
  while (temp)
  {
    count++;
    temp = temp->next;
  }

  // If the node to be deleted is the head
  if (n == count)
  {
    Node *newHead = head->next;
    delete head;
    head = newHead;
    return;
  }

  // Step 2: Go to the node just before the one to be deleted
  temp = head;
  for (int i = 1; i < count - n; i++)
  {
    temp = temp->next;
  }

  // Step 3: Delete the target node
  Node *del = temp->next;
  temp->next = del->next;
  delete del;
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
  vector<int> arr = {1, 2, 3, 4, 5};
  int N = 3;

  Node *head = new Node(arr[0]);
  Node *tail = head;
  for (int i = 1; i < arr.size(); i++)
  {
    tail->next = new Node(arr[i]);
    tail = tail->next;
  }

  deletionBack(head, N);
  print(head);

  return 0;
}
