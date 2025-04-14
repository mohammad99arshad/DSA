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

// Function to print the linked list
void printList(Node *head)
{
  Node *temp = head;
  while (temp)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

// Function to sort the linked list of 0's, 1's, and 2's by changing links
void sort0s1s(Node *head)
{
  if (!head || !head->next)
    return;

  // Counting the occurrences of 0's, 1's, and 2's
  int count0 = 0, count1 = 0, count2 = 0;
  Node *temp = head;
  while (temp)
  {
    if (temp->data == 0)
      count0++;
    else if (temp->data == 1)
      count1++;
    else if (temp->data == 2)
      count2++;
    temp = temp->next;
  }

  // Rebuild the list with 0's, 1's, and 2's in order
  temp = head;
  while (count0--)
  {
    temp->data = 0;
    temp = temp->next;
  }
  while (count1--)
  {
    temp->data = 1;
    temp = temp->next;
  }
  while (count2--)
  {
    temp->data = 2;
    temp = temp->next;
  }
}

int main()
{
  vector<int> arr = {1, 1, 0, 2, 0, 1, 0, 2};
  Node *head = new Node(arr[0]);
  Node *tail = head;

  for (int i = 1; i < arr.size(); i++)
  {
    tail->next = new Node(arr[i]);
    tail = tail->next;
  }

  cout << "Original List: ";
  printList(head);

  sort0s1s(head);

  cout << "Updated List: ";
  printList(head);

  return 0;
}
