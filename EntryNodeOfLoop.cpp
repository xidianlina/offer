/*
��Ŀ����:һ�������а����������ҳ�������Ļ�����ڽ�㡣
*/

#include <iostream>
#include <set>

using namespace std;

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
	/*
	function first
	��һ�����һ������㡣�ֱ���p1��p2ָ������ͷ����p1ÿ����һ����p2ÿ���߶�����ֱ��p1==p2�ҵ��ڻ��е����㡣
	�ڶ������һ�����ڡ����ϲ�����p1==p2ʱ��p2�������ڵ���Ϊ2x,p1�������ڵ���Ϊx,�軷����n���ڵ�,
	p2��p1����һȦ��2x=n+x; n=x;���Կ���p1ʵ������һ�����Ĳ���������p2ָ������ͷ����p1λ�ò��䣬p1,p2ÿ����һ��ֱ��p1==p2; ��ʱp1ָ�򻷵���ڡ�
	*/
	ListNode* EntryNodeOfLoop(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
			return NULL;
		ListNode *p1 = head;
		ListNode *p2 = head;
		while (p1 != NULL&&p2 != NULL)
		{
			p1 = p1->next;
			p2 = p2->next->next;
			if (p1 == p2)
			{
				p2 = head;
				while (p1 != p2)
				{
					p1 = p1->next;
					p2 = p2->next;
				}
				if (p1 == p2)
					return p1;
			}
		}
		return NULL;
	}
	
		/*
		function second
		ʱ�临�Ӷ�ΪO��n��������ָ�룬һ����ǰ�棬��һ�����������ָ�룬�ں��档
		����ָ��ͬʱ��ǰ�ƶ���ÿ�ƶ�һ�Σ�ǰ���ָ���nextָ��NULL��
		Ҳ����˵�����ʹ��Ľڵ㶼�Ͽ�����󵽴���Ǹ��ڵ�һ����β�ڵ����һ����
		Ҳ����ѭ���ĵ�һ����
		��ʱ���Ѿ��ǵڶ��η���ѭ���ĵ�һ�ڵ��ˣ���һ�η��ʵ�ʱ�������Ѿ�����ָ����NULL��
		���Ե��������
		*/
	ListNode* EntryNodeOfLoop2(ListNode* pHead)
	{
		if (!pHead->next)
			return NULL;
		ListNode* previous = pHead;
		ListNode* front = pHead->next;
		while (front)
		{
			previous->next = NULL;
			previous = front;
			front = front->next;
		}
		return previous;
	}

	/*
	function third
	STL�е�set��һ�����Ծ��ǲ��ܲ�����ͬԪ�أ�����ֻ�����ԭListһ�ξͿ����жϳ���û�л���
	���л�����ڵ�ַ��s.insert(node).second�����ڲ����ͬʱҲ�ж��˲����Ƿ�ɹ���
	������ɹ�����set���Ѿ��и�Ԫ���ˣ���Ԫ�ؾ��ǻ������Ԫ�ء�
	*/
	ListNode* EntryNodeOfLoop3(ListNode* pHead)
	{
		set<ListNode*> s;
		ListNode* node = pHead;
		while (node != NULL) {
			if (s.insert(node).second)
				node = node->next;
			else
				return node;
		}
		return node;
	}
};