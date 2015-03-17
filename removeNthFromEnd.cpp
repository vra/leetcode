#include <iostream>

using namespace std;


struct ListNode
{
	int val;
	ListNode* next;

	ListNode(int x) : val(x), next(NULL){}
};

ListNode *removeNthFromEnd(ListNode *head, int n) 
{
	ListNode** t1 = &head;        
	ListNode* t2 = head;

	for (int i = 1; i < n; i++)
	{
		t2 = t2->next;
	}

	while (t2->next != NULL)
	{
		t1 = &((*t1)->next);

		t2 = t2->next;
	}

	//注意此处不能写成： t1 = &((*t1)->next); 这种形式不会改变head，导致输出错误！（二级指针的问题）
	*t1 = ((*t1)->next);

	return head;
        
}

int main()
{
	ListNode a(1);
	ListNode b(2);
//	a.next = &b;

//	cout << a.val << a.next->val << endl;

	ListNode* result = removeNthFromEnd(&a, 1);

	cout << result->next << endl;

	return 0;
}
