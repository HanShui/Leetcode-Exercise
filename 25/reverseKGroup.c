#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
  struct ListNode vhead;
  vhead.val = 0;
  vhead.next = head;

  struct ListNode *p[k];
  struct ListNode *lp, *rp;

  if(k==1)
    return vhead.next;

  if(vhead.next)
    p[0] = vhead.next;
  else
    return NULL;

  for(int i=0;i<k-1;i++)
    {
      if(p[i]&&p[i]->next)
        p[i+1] = p[i]->next;
      else
        return vhead.next;
    }
  lp = &vhead;
  rp = p[k-1]->next;

  //reverse 1..k
  lp->next = p[k-1];
  for(int i=k-1;i>0;i--)
    {
      p[i]->next = p[i-1];
    }
  rp = reverseKGroup(rp, k);
  p[0]->next = rp;
  return vhead.next;
}

int main()
{
  struct ListNode nodes[5];
  nodes[0].val = 1;
  nodes[1].val = 2;
  nodes[2].val = 3;
  nodes[3].val = 4;
  nodes[4].val = 5;
  nodes[0].next = &nodes[1];
  nodes[1].next = &nodes[2];
  nodes[2].next = &nodes[3];
  nodes[3].next = &nodes[4];
  nodes[4].next = NULL;

  struct ListNode *p;
  p = reverseKGroup(nodes, 3);
  for(;p!=NULL;p=p->next)
    {
      printf("%d->",p->val);
    }
  printf("\n");
}
