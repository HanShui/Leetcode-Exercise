/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
  struct ListNode* p1;
  struct ListNode* p2;
  struct ListNode* p_res;
  struct ListNode* p_res_pre;
  int addon = 0;
  result = (struct ListNode*) malloc (sizeof(struct ListNode));
  if(result == NULL) return NULL;
  p_res = result;
  p_res_pre = NULL;

  for(p1=l1,p2=l2;p1!=NULL && p2!=NULL;p1=p1->next,p2=p2->next)
    {
      p_res->val = (p1->val + p2->val + addon)%10;
      addon = (p1->val + p2->val + addon)/10;
      p_res->next = (struct ListNode *) malloc (sizeof(struct ListNode));
      p_res_pre = p_res;
      p_res = p_res->next;
      if(p_res == NULL) return NULL;
    }

  if(p1==NULL && p2!=NULL)
    {
      for(;p2!=NULL;p2=p2->next)
        {
          p_res->val = (p2->val + addon)%10;
          addon = (p2->val + addon)/10;
          p_res->next = (struct ListNode *) malloc (sizeof(struct ListNode));
          p_res_pre = p_res;
          p_res = p_res->next;
          if(p_res == NULL) return NULL;
        }
    }

  if(p1!=NULL && p2==NULL)
    {
      for(;p1!=NULL;p1=p1->next)
        {
          p_res->val = (p1->val + addon)%10;
          addon = (p1->val + addon)/10;
          p_res->next = (struct ListNode *) malloc (sizeof(struct ListNode));
          p_res_pre = p_res;
          p_res = p_res->next;
          if(p_res == NULL) return NULL;
        }
    }

  if(addon == 1)
    {
      p_res->val = addon;
      addon = 0;
      p_res->next = NULL;
    }
  else
    {
      free(p_res);
      p_res_pre -> next = NULL;
    }

  return result;
}
