// 25_01_zcy_ReverseStackUsingRecursive.cpp : �������̨Ӧ�ó������ڵ㡣
//

//һ��ջ����ѹ��1��2��3��4��5����ô��ջ����ջ�׷ֱ�Ϊ5��4��
//3��2��1�������ջת�ú󣬴�ջ����ջ��Ϊ1��2��3��4��5��
//Ҳ����ʵ��ջ��Ԫ�ص����򣬵���ֻ���õݹ麯����ʵ�֣���
//�����������ݽṹ��

#include "stdafx.h"
#include <stack>
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;
void printStack(stack<int> s);
void reverseStack(stack<int>& s);
int getAndRemoveLastElement(stack<int>& s);
int main()
{
	stack<int> s;
	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);

	printStack(s);

	reverseStack(s);
	printStack(s);

	system("pause");
	return 0;
}

void printStack(stack<int> s)
{
	list<int> v;
	while (!s.empty())
	{
		v.push_front(s.top());
		s.pop();
	}

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

void reverseStack(stack<int>& s)
{
	if (s.empty()) return;
	int i = getAndRemoveLastElement(s);
	reverseStack(s);
	s.push(i);
}

int getAndRemoveLastElement(stack<int>& s)
{
	int result = s.top();
	s.pop();
	if (s.empty())
		return result;
	else
	{
		int last = getAndRemoveLastElement(s);
		s.push(result);
		return last;
	}
}