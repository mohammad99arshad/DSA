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

int revereseLL(Node *&head)
{
  Node *temp = head;
  stack<int> st;
  while (temp != nullptr)
  {
    st.push(temp->data);
    temp = temp->next;
  }
  temp = head;
  while (temp != nullptr)
  {
    temp->data = st.top();
    st.pop();
    temp = temp->next;
  }
}
void printList(Node *head)
{
  while (head != NULL)
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
    tail->next = new Node(arr[i]);
    tail = tail->next;
  }

  cout << "Original List: " << endl;
  printList(head);

  revereseLL(head);

  cout << "Reversed List: " << endl;
  printList(head);

  return 0;
}