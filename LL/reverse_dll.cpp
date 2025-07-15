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

Node *reverseDLL(Node *head)
{
  if (head == nullptr || head->next == nullptr)
    return head;

  stack<Node *> st;
  Node *temp = head;

  while (temp != nullptr)
  {
    st.push(temp);
    temp = temp->next;
  }

  Node *newHead = st.top();
  st.pop();
  temp = newHead;
  temp->prev = nullptr;

  while (!st.empty())
  {
    temp->next = st.top();
    st.top()->prev = temp;
    temp = temp->next;
    st.pop();
  }

  temp->next = nullptr;
  return newHead;
}

void printList(Node *head)
{
  while (head != nullptr)
  {
    cout << head->data << " ";
    head = head->next;
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
    Node *newNode = new Node(arr[i]);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }

  cout << "Original List: " << endl;
  printList(head);

  head = reverseDLL(head);

  cout << "Reversed List: " << endl;
  printList(head);

  return 0;
}
