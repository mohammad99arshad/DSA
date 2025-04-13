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

int lengthOfLoop(Node *head)
{
  if (!head || !head->next)
    return 0;

  Node *slow = head;
  Node *fast = head;

  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
    {
      // Cycle detected, now count the length
      int count = 1;
      Node *temp = slow->next;
      while (temp != slow)
      {
        count++;
        temp = temp->next;
      }
      return count;
    }
  }

  return 0; // No cycle
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

  tail->next = head->next->next; // Creating a cycle at node with value 3

  int loopLength = lengthOfLoop(head);
  if (loopLength)
    cout << "Loop detected. Length = " << loopLength << endl;
  else
    cout << "No loop detected." << endl;

  return 0;
}
