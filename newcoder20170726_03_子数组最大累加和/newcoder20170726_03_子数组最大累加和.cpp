// 25_03_SubArrayMaxSum.cpp : 定义控制台应用程序的入口点。
//

//给定一个数组arr，返回子数组的最大累加和。
//例如，arr = [1, -2, 3, 5, -2, 6, -1]，所有的子数组中，[3, 5, -2, 6]可以
//累加出最大的和12，所以返回12。

#include "stdafx.h"
#include <limits>
#include <iostream>
using namespace std;
int main()
{

	//int arr[] = { 1, -2, 3, 5, -2, 6, -1 };
	int arr[] = { -1, -2, -3,-5, -2, -6, -1 };

	int cur = 0, max = -INT_MAX;
	int startIdx, endIdx;
	for (int i = 0; i != sizeof(arr) / sizeof(int); ++i)
	{
		cur += arr[i];
		if (cur > max) {
			max = cur;
			endIdx = i;
		}

		if (cur < 0) {
			startIdx = i + 1;
			cur = 0;
		}
	}

	cout << max << endl;
	return 0;
}

