/*
��Ŀ����:����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩��
���ؽ��Ϊ���ƺ��������head����ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
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