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

int MiddleofLL(Node *head)
{
  Node *temp = head;
  int count = 0;
  while (temp != nullptr)
  {
    temp = temp->next;
    count++;
  }

  int mid = count / 2; // round() is not needed for int division
  temp = head;
  for (int i = 0; i < mid; i++)
  {
    temp = temp->next;
  }
  return temp->data;
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
  vector<int> arr = {3, 4, 5, 6, 7};

  Node *head = new Node(arr[0]);
  Node *tail = head;

  for (int i = 1; i < arr.size(); i++)
  {
    tail->next = new Node(arr[i]);
    tail = tail->next;
  }

  print(head);

  int middle = MiddleofLL(head);
  cout << "Middle node: " << middle << endl;

  return 0;
}
