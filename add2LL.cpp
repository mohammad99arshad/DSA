#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *head)
{
  ListNode *temp = head;
  while (temp)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;
}

class Solution
{
public:
  ListNode *reverse(ListNode *head)
  {
    ListNode *prev = nullptr;
    ListNode *temp = head;
    while (temp)
    {
      ListNode *newHead = temp->next;
      temp->next = prev;
      prev = temp;
      temp = newHead;
    }
    return prev;
  }

  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    l1 = reverse(l1);
    l2 = reverse(l2);

    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;
    int carry = 0;

    while (l1 || l2 || carry)
    {
      int sum = carry;
      if (l1)
      {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2)
      {
        sum += l2->val;
        l2 = l2->next;
      }
      carry = sum / 10;
      temp->next = new ListNode(sum % 10);
      temp = temp->next;
    }
    return reverse(dummy->next);
  }
};

int main()
{
  vector<int> v1 = {2, 4, 9};
  vector<int> v2 = {5, 6, 4, 9};

  ListNode *l1 = new ListNode(v1[0]);
  ListNode *tail1 = l1;
  for (int i = 1; i < v1.size(); i++)
  {
    tail1->next = new ListNode(v1[i]);
    tail1 = tail1->next;
  }

  ListNode *l2 = new ListNode(v2[0]);
  ListNode *tail2 = l2;
  for (int i = 1; i < v2.size(); i++)
  {
    tail2->next = new ListNode(v2[i]);
    tail2 = tail2->next;
  }

  Solution().addTwoNumbers(l1, l2);

  cout << "Result: ";
  printList(l1);

  return 0;
}
