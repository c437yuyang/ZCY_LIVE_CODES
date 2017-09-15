// 25_03_SubArrayMaxSum.cpp : �������̨Ӧ�ó������ڵ㡣
//

//����һ������arr�����������������ۼӺ͡�
//���磬arr = [1, -2, 3, 5, -2, 6, -1]�����е��������У�[3, 5, -2, 6]����
//�ۼӳ����ĺ�12�����Է���12��

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

