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
bool isPalindrome(Node *head)
{
  if (!head && !head->next)
    return true;
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
    if (temp->data != st.top())
      return false;
    temp = temp->next;
    st.pop();
  }
  return true;
}

int main()
{
  vector<int> arr = {1, 2, 3, 2, 1};
  Node *head = new Node(arr[0]);
  Node *tail = head;

  for (int i = 1; i < arr.size(); i++)
  {
    tail->next = new Node(arr[i]);
    tail = tail->next;
  }
  if (isPalindrome(head))
    cout << "The linked list is a palindrome." << endl;
  else
    cout << "The linked list is not a palindrome." << endl;

  return 0;
}