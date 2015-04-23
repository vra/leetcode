#include<iostream>

struct ListNode
{
	int val;
	ListNode* next;

	ListNode(int v) : val(v), next(NULL){}
};

ListNode* removeElements(ListNode* head, int val) 
{
	//首先判断头节点是否为要删除的节点
	while (head != NULL && head->val == val)
	{

		ListNode* pTmp = head;
		head = head->next;
		delete pTmp;
	}

	if (head == NULL)
	{
		return head;
	}

	ListNode* p = head;
	ListNode* q = head->next;

	//之前已经确保head不为NULL，所以while中判断条件可以简化
	while (q != NULL)
	{
		if (q->val == val)
		{
			ListNode* pTmp = q;
			p->next = q->next;

			delete pTmp;
		}
		else
		{
			p = q;
		}

		q = p->next;
	}

	return head;
}

int main()
{
	ListNode* root = new ListNode(1);
	
	root->next = new ListNode(2);
	root->next->next = new ListNode(3);
	root->next->next->next = new ListNode(4);
	root->next->next->next->next = new ListNode(5);
	root->next->next->next->next->next = new ListNode(6);

	root = removeElements(root, 6);

	return 0;
}

