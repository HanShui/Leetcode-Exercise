#include <stdio.h>
#include <stdlib.h>

//Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
  //double pt
  struct ListNode *p,*q,*d;
  struct ListNode virtual;
  virtual.val = 0;
  virtual.next = head;
  p = &virtual;
  q = &virtual;
  for(int i =0;i<n;i++)
    {
      q = q->next;
    }
  while(q->next != NULL)
    {
      p = p->next;
      q = q->next;
    }
  d = p->next;
  if (d==head)
    head = head->next;
  p->next = d->next;
  //free(d);
  return head;
}

int main()
{
  /*
  int n = 2;

  struct ListNode* SListHead;
  struct ListNode* p;
  struct ListNode node[5];

  SListHead = node;
  for(int i=0;i<4;i++)
    {
      node[i].val = i+1;
      node[i].next = &node[i+1];
    }
  node[4].val = 5;
  node[4].next = NULL;
  */

  int n = 1;
  struct ListNode* SListHead;
  struct ListNode* p;
  struct ListNode node[1];
  SListHead = node;
  node[0].val = 1;
  node[0].next = NULL;

  SListHead = removeNthFromEnd(SListHead, n);
  for(p=SListHead;p&&p->next;p=p->next)
    {
      printf("%d\n",p->val);
    }
  return 0;
}
