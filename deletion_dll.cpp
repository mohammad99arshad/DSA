#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *prev;
};

void deleteAtHead(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    return;
  }
  Node *prev = head;
  head = head->next;
  head->prev = nullptr;
  prev->next = nullptr;
  delete prev;
}
void deleteAtTail(Node *head)
{
  Node *prev = head;
}