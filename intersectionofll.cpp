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

int getLength(Node *head)
{
  int len = 0;
  while (head)
  {
    len++;
    head = head->next;
  }
  return len;
}

Node *intersectionNode(Node *headA, Node *headB)
{
  int lenA = getLength(headA);
  int lenB = getLength(headB);

  while (lenA > lenB)
  {
    headA = headA->next;
    lenA--;
  }
  while (lenB > lenA)
  {
    headB = headB->next;
    lenB--;
  }

  while (headA && headB)
  {
    if (headA == headB)
      return headA;
    headA = headA->next;
    headB = headB->next;
  }

  return nullptr;
}

int main()
{
  Node *intersect = new Node(8);
  intersect->next = new Node(10);

  Node *headA = new Node(3);
  headA->next = new Node(7);
  headA->next->next = intersect;

  Node *headB = new Node(99);
  headB->next = new Node(1);
  headB->next->next = intersect;

  Node *result = intersectionNode(headA, headB);
  if (result)
    cout << "Intersection at node with data = " << result->data << endl;
  else
    cout << "No intersection" << endl;

  return 0;
}
