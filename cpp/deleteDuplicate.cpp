#include <iostream>

using namespace std;

struct ListNode 
{
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  
};	 

class Solution 
{
public:
    ListNode *deleteDuplicates(ListNode *head) 
	{
		if (head == NULL)
		{
			return NULL;
		}
        ListNode* p = head;
		ListNode* q = head->next;

		bool hasDuplicate = false;

		while (q != NULL)
		{
			if (q->val == p->val)
			{
				hasDuplicate = true;
				q = q->next;
			}
			else
			{
				p->next = q;
				q = q->next;
				p = p->next;

				hasDuplicate = false;
			}
			
		}

		if (hasDuplicate)
		{
			p->next = NULL;
		}

		return head;
    }

	 ListNode* deleteDuplicates2(ListNode* head) {
        if (head == NULL) return head;

        ListNode* cur = head;
        while(cur->next != NULL) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
            }
            else cur = cur->next;
        }
        return head;
    }
};

int main()
{
	Solution s;
	ListNode* head = new ListNode(1);
	head->next = new ListNode(1);
	head->next->next = new ListNode(1);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = new ListNode(3);


	head = s.deleteDuplicates(head);

	return 0;

}
