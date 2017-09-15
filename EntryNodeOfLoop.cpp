/*
题目描述:一个链表中包含环，请找出该链表的环的入口结点。
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
	第一步，找环中相汇点。分别用p1，p2指向链表头部，p1每次走一步，p2每次走二步，直到p1==p2找到在环中的相汇点。
	第二步，找环的入口。接上步，当p1==p2时，p2所经过节点数为2x,p1所经过节点数为x,设环中有n个节点,
	p2比p1多走一圈有2x=n+x; n=x;可以看出p1实际走了一个环的步数，再让p2指向链表头部，p1位置不变，p1,p2每次走一步直到p1==p2; 此时p1指向环的入口。
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
		时间复杂度为O（n），两个指针，一个在前面，另一个紧邻着这个指针，在后面。
		两个指针同时向前移动，每移动一次，前面的指针的next指向NULL。
		也就是说：访问过的节点都断开，最后到达的那个节点一定是尾节点的下一个，
		也就是循环的第一个。
		这时候已经是第二次访问循环的第一节点了，第一次访问的时候我们已经让它指向了NULL，
		所以到这结束。
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
	STL中的set有一个特性就是不能插入相同元素，这样只需遍历原List一次就可以判断出有没有环，
	还有环的入口地址。s.insert(node).second这里在插入的同时也判断了插入是否成功，
	如果不成功表明set中已经有该元素了，该元素就是环的入口元素。
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