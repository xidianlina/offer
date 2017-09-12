/*
题目描述:输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/

#include <iostream>
#include <map>

using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode* next;
	struct RandomListNode* random;
	RandomListNode(int x):label(x),next(NULL),random(NULL){}
};

class Solution {
public:
	RandomListNode* Clone(RandomListNode* head)
	{
		map<RandomListNode*, RandomListNode*> map;
		if (head == NULL)
			return NULL;
		RandomListNode* cur = head;
		while (cur)
		{
			map[cur] = new RandomListNode(cur->label);
			cur = cur->next;
		}
		cur = head;
		while (cur)
		{
			map[cur]->next = map[cur->next];
			map[cur]->random = map[cur->random];
			cur = cur->next;
		}
		return map[head];
	}
};