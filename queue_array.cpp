#include <bits/stdc++.h>
using namespace std;

class queuee
{
public:
  int front = -1;
  int rear = -1;
  int q[20];

  void enqueue(int x)
  {
    if (rear == 19)
    {
      cout << "queue overflow\n";
    }
    else
    {
      if (front == -1)
      {
        front = 0;
      }
      rear++;
      q[rear] = x;
    }
  }
  void dequeue()
  {
    if (front == -1 || front > rear)
    {
      cout << "queue is empty\n";
    }
    else
    {
      cout << q[front] << " is dequeued\n";
      front++;
    }
  }
  int size()
  {
    if (front == -1 || front > rear)
    {
      return 0;
    }
    else
    {
      return rear - front + 1;
    }
  }
};

int main()
{
  queuee q;
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  cout << "size of queue is " << q.size() << "\n";
  q.dequeue();
  cout << "size of queue is " << q.size() << "\n";
  q.dequeue();
  cout << "size of queue is " << q.size() << "\n";
  return 0;
}