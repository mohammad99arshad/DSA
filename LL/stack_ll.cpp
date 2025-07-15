#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int x)
  {
    data = x;
    next = nullptr;
  }
};

class Stack
{
  Node *top;

public:
  Stack()
  {
    top = nullptr;
  }

  void push(int x)
  {
    Node *temp = new Node(x);
    temp->next = top;
    top = temp;
  }

  void pop()
  {
    if (top == nullptr)
    {
      cout << "Stack Underflow\n";
      return;
    }
    Node *temp = top;
    top = top->next;
    cout << temp->data << " popped\n";
    delete temp;
  }

  void peek()
  {
    if (top == nullptr)
      cout << "Stack is empty\n";
    else
      cout << "Top: " << top->data << "\n";
  }

  void display()
  {
    if (top == nullptr)
    {
      cout << "Stack is empty\n";
      return;
    }
    Node *temp = top;
    cout << "Stack: ";
    while (temp != nullptr)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << "\n";
  }
};

int main()
{
  Stack s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.display();
  s.peek();
  s.pop();
  s.display();
  return 0;
}
