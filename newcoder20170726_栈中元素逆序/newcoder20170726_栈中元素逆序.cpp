// 25_01_zcy_ReverseStackUsingRecursive.cpp : 定义控制台应用程序的入口点。
//

//一个栈依次压入1、2、3、4、5，那么从栈顶到栈底分别为5、4、
//3、2、1。将这个栈转置后，从栈顶到栈底为1、2、3、4、5，
//也就是实现栈中元素的逆序，但是只能用递归函数来实现，不
//能用其他数据结构。

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