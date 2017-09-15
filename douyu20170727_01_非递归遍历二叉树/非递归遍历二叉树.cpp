#include <iostream>
#include <algorithm>
#include <BinaryTreeNode.h>
#include <stack>
using namespace std;



//替换这个typedef就可以针对各种版本的二叉树了
typedef shared_ptr<BinaryTreeNode<int>> ipBTN;


#pragma region 递归版本
void recurPreOrder(ipBTN head)
{
	if (head != NULL)
	{
		cout << head->elem << " ";
		recurPreOrder(head->left);
		recurPreOrder(head->right);
	}
}

void recurInOrder(ipBTN head)
{
	if (head != NULL)
	{
		recurInOrder(head->left);
		cout << head->elem << " ";
		recurInOrder(head->right);

	}
}

void recurPostOrder(ipBTN head)
{
	if (head != NULL)
	{
		recurPostOrder(head->left);
		recurPostOrder(head->right);
		cout << head->elem << " ";
	}
}
#pragma endregion



#pragma region 非递归版本
void preOrder(ipBTN head)
{
	stack<ipBTN> s;
	s.push(head);

	while (!s.empty())
	{
		ipBTN tmp = s.top();
		s.pop();
		cout << tmp->elem << " ";
		if (tmp->right != NULL)
			s.push(tmp->right);
		if (tmp->left != NULL)
			s.push(tmp->left);
	}
}


void inOrder(ipBTN head)
{
	stack<ipBTN> s;
	while (!s.empty() || head != NULL)
	{
		if (head != NULL) {
			s.push(head);
			head = head->left;
		}
		else {
			ipBTN tmp = s.top();
			s.pop();
			cout << tmp->elem << " ";
			head = tmp->right;
		}
	}

}


void postOrder(ipBTN head)
{
	stack<ipBTN> s1;
	stack<ipBTN> s2;
	s1.push(head);

	while (!s1.empty())
	{
		ipBTN tmp = s1.top();
		s1.pop();
		s2.push(tmp);
		//cout << tmp->elem << " ";

		if (tmp->left != NULL)
			s1.push(tmp->left);

		if (tmp->right != NULL)
			s1.push(tmp->right);

	}

	while (!s2.empty())
	{
		ipBTN tmp = s2.top();
		s2.pop();
		cout << tmp->elem << " ";
	}

}

//只用一个栈的版本,没有搞懂，照着敲过来的
void postOrder2(ipBTN head)
{
	if (head != NULL) {
		stack<ipBTN> s;
		s.push(head);
		ipBTN c = NULL;
		while (!s.empty()) {
			c = s.top();
			if (c->left != NULL && head != c->left && head != c->right) {
				s.push(c->left);
			}
			else if (c->right != NULL && head != c->right) {
				s.push(c->right);
			}
			else {
				cout << s.top()->elem << " ";
				s.pop();
				head = c;
			}

		}

	}
}
#pragma endregion



int main()
{
	typedef BinaryTreeNode<int> iBTN;
	ipBTN head = make_shared<iBTN>(5);
	head->left = make_shared<iBTN>(3);
	head->right = make_shared<iBTN>(8);
	head->left->left = make_shared<iBTN>(2);
	head->left->right = make_shared<iBTN>(4);
	head->left->left->left = make_shared<iBTN>(1);
	head->right->left = make_shared<iBTN>(7);
	head->right->left->left = make_shared<iBTN>(6);
	head->right->right = make_shared<iBTN>(10);
	head->right->right->left = make_shared<iBTN>(9);
	head->right->right->right = make_shared<iBTN>(11);

	printTree(head);
	cout << endl;

	recurInOrder(head);
	cout << endl;

	inOrder(head);
	cout << endl;

	recurPreOrder(head);
	cout << endl;


	preOrder(head);
	cout << endl;


	recurPostOrder(head);
	cout << endl;

	postOrder(head);
	cout << endl;
	
	postOrder2(head);
	cout << endl;

	system("pause");
	return 0;
}