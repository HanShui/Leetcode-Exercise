#include <stdlib.h>
#include <stdio.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
  struct ListNode* p1 = l1;
  struct ListNode* p2 = l2;

  struct ListNode* p;
  /* virtual head */
  struct ListNode Lhead;
  p = &Lhead;
  Lhead.val = 0;
  Lhead.next = NULL;

  while(p1&&p2)
    {
      if(p1->val <= p2->val)
        {
          p->next = p1;
          p1 = p1->next;
          p = p->next;
        }
      else
        {
          p->next = p2;
          p2 = p2->next;
          p = p->next;
        }
    }
  if(p1)
    {
      p->next = p1;
    }
  else
    {
      p->next = p2;
    }
  return Lhead.next;
}

int main()
{
  struct ListNode l1[3];
  struct ListNode l2[3];
  struct ListNode* L;
  struct ListNode* p;

  l1[0].val = 1;
  l1[1].val = 2;
  l1[2].val = 4;
  l1[0].next = &l1[1];
  l1[1].next = &l1[2];
  l1[2].next = NULL;

  l2[0].val = 1;
  l2[1].val = 3;
  l2[2].val = 4;
  l2[0].next = &l2[1];
  l2[1].next = &l2[2];
  l2[2].next = NULL;

  L = mergeTwoLists(l1, l2);

  for(p=L;p!=NULL;p=p->next)
    {
      printf("%d->",p->val);
    }
  printf("\n");
  return 0;
}
