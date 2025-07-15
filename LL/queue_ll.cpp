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

class Queue
{
  Node *front;
  Node *rear;

public:
  Queue()
  {
    front = rear = nullptr;
  }

  void enqueue(int x)
  {
    Node *temp = new Node(x);
    if (rear == nullptr)
    {
      front = rear = temp;
    }
    else
    {
      rear->next = temp;
      rear = temp;
    }
  }

  void dequeue()
  {
    if (front == nullptr)
    {
      cout << "Queue Underflow\n";
      return;
    }
    Node *temp = front;
    front = front->next;
    if (front == nullptr)
      rear = nullptr;
    cout << temp->data << " dequeued\n";
    delete temp;
  }

  void peek()
  {
    if (front == nullptr)
      cout << "Queue is empty\n";
    else
      cout << "Front: " << front->data << "\n";
  }

  void display()
  {
    if (front == nullptr)
    {
      cout << "Queue is empty\n";
      return;
    }
    Node *temp = front;
    cout << "Queue: ";
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
  Queue q;
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.display();
  q.peek();
  q.dequeue();
  q.display();
  return 0;
}
