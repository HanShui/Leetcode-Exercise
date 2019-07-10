#include <stdio.h>
#include <stdlib.h>


struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head){
  struct ListNode vhead;
  vhead.val = 0;
  vhead.next = head;

  struct ListNode *p1, *p2;
  struct ListNode *l_p1, *r_p2;
  p1 = &vhead;
  p2 = &vhead;
  l_p1 = &vhead;
  r_p2 = &vhead;
  if(p1->next)
    p1 = p1->next;
  else
    return vhead.next;

  while(p1&&p2)
    {
      if(p1->next != NULL)
        {
          p2 = p1->next;
        }
      else
        return vhead.next;
      r_p2 = p2->next;
      //swap p1&p2
      l_p1->next = p2;
      p2->next = p1;
      p1->next = r_p2;
      //step forward
      l_p1 = p1;
      p1 = r_p2;
    }

  return vhead.next;
}

int main()
{
  struct ListNode nodes[4];
  struct ListNode *p;
  p = nodes;

  nodes[0].val = 1;
  nodes[1].val = 2;
  nodes[2].val = 3;
  nodes[3].val = 4;

  nodes[0].next = &nodes[1];
  nodes[1].next = &nodes[2];
  nodes[2].next = &nodes[3];
  nodes[3].next = NULL;

  p = swapPairs(p);
  for(;p!=NULL;p=p->next)
    {
      printf("%d->",p->val);
    }
  printf("\n");
  return 0;
}
