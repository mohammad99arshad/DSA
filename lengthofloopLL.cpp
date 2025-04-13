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

int countLoopLength(Node *nodePresent)
{
  int count = 1;
  Node *temp = nodePresent->next;
  while (temp != nodePresent)
  {
    count++;
    temp = temp->next;
  }
  return count;
}

int lengthofloop(Node *head)
{
  Node *slow = head;
  Node *fast = head;

  while (fast != nullptr && fast->next != nullptr)
  {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
    {
      return countLoopLength(slow);
    }
  }
  return 0;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5};
  Node *head = new Node(arr[0]);
  Node *tail = head;

  for (int i = 1; i < arr.size(); i++)
  {
    tail->next = new Node(arr[i]);
    tail = tail->next;
  }

  tail->next = head->next->next; // Create a loop starting from the 3rd node

  int loopLength = lengthofloop(head);
  if (loopLength)
    cout << "Loop detected. Length = " << loopLength << endl;
  else
    cout << "No loop detected." << endl;

  return 0;
}
