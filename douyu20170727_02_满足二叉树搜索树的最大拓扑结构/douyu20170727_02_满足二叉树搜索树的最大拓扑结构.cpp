// douyu20170727_02_满足二叉树搜索树的最大拓扑结构.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include "binarytreenode.h"
#include <stack>
#include <queue>
using namespace std;

/*
二、找到二叉树中符合搜索二叉树条件的最大拓扑结构
给定一棵二叉树的头节点head，已知所有节点的值都不一样，返回其中最大的且符合搜索二叉树条件的最大拓扑结构的大小
*/


//还没做，只是把java版本的版本2看懂了。。
//这种涉及到二叉树的其实最好还是用java做，不用考虑内存，不需要用指针


#pragma region 版本1，暴力求解

int maxTopoSize(ipBTN head)
{
	int res = 1; //头结点肯定能找到

	if (head == NULL) return 0;


}

int process(ipBTN head) 
{
	



}




#pragma endregion



int main()
{


	system("pause");
	return 0;
}