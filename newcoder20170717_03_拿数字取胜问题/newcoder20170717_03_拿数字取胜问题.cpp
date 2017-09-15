// 24_01_ZCY_NO.3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
template<class T>
inline T max(const T& _lhs, const T& _rhs) { return _lhs > _rhs ? _lhs : _rhs; }
template<class T>
inline T min(const T& _lhs, const T& _rhs) { return _lhs < _rhs ? _lhs : _rhs; }

#pragma region win1_暴力递归

int f(int arr[], int i, int j);
int s(int arr[], int i, int j);

int win1(int arr[], int len)
{
	if (arr == NULL) return 0;

	//return max(f(arr, 0, len - 1), s(arr, 0, len - 1));

	//一个递归实现
	int sum = 0;
	for (int k = 0; k != len; ++k)
	{
		sum += arr[k];
	}
	int fmax = f(arr, 0, len - 1);
	return max(fmax, sum - fmax);
}

//作为先发者最终获得的分数
int f(int arr[], int i, int j)
{
	if (i == j) //只有一个数
		return arr[i];
	return max(arr[i] + s(arr, i + 1, j), arr[j] + s(arr, i, j - 1));

	//我自己的理解，有些不一样
	//int sum = 0;
	//for (int k=i;k<=j;++k)
	//{
	//	sum += arr[k];
	//}
	//return max(sum - s(arr, i + 1, j), sum - s(arr, i, j - 1));

}

int s(int arr[], int i, int j)
{
	if (i == j)
		return 0;
	return min(f(arr, i + 1, j), f(arr, i, j - 1)); //后发者肯定想要先发者拿的最少的情况
}

#pragma endregion

#pragma region win2_使用两张表
int win2(int *arr, int len)
{
	const int w = len;
	int *f = new int[len*len](); //先构建两张表，都初始化为0
	int *s = new int[len*len]();

	for (int j = 0; j != len; ++j) //一行的遍历
	{
		f[j*len + j] = arr[j]; //对f表对角线赋值为数组相应值
		for (int i = j - 1; i >= 0; --i) //一列，从下往上
		{
			f[i*len + j] = max(arr[i] + s[(i + 1)*len + j], arr[j] + s[i*len + j - 1]);
			s[i*len + j] = min(f[(i + 1)*len + j], f[i*len + j - 1]);
		}
	}
	int score = max(f[0 * len + len - 1], s[0 * len + len - 1]);
	delete[] f;
	delete[] s;
	return score;
}
#pragma endregion

#pragma region win3_只关心先发者的情况暴力递归
int p(int *arr, int i, int j);
int win3(int *arr, int len)
{
	int sum = 0;
	for (int k = 0; k != len; ++k)
	{
		sum += arr[k];
	}
	int fscore = p(arr, 0, len - 1);
	return max(fscore, sum - fscore);
}
int p(int *arr, int i, int j)
{
	if (i == j) return arr[i];
	if (i + 1 == j) return max(arr[i], arr[j]);

	return max(
		arr[i] + min(p(arr, i + 2, j), p(arr, i + 1, j - 1)),
		arr[j] + min(p(arr, i + 1, j - 1), p(arr, i, j - 2))
	);
}
#pragma endregion

#pragma region 只使用一张表
int win4(int *arr, int len)
{

	int sum = 0;
	for (int k = 0; k != len; ++k)
	{
		sum += arr[k];
	}

	int *p = new int[len*len]();
	for (int j = 0; j != len; ++j)
	{
		p[j * len + j] = arr[j];
		for (int i = j - 1; i >= 0; --i)
		{
			if (i == j - 1) { //隔一对角线的值
				p[i * len + j] = max(arr[i], arr[j]);
				continue;
			}
			p[i * len + j] = max(
				arr[i] + min(p[(i + 2) * len + j], p[(i + 1)*len + j - 1]),
				arr[j] + min(p[(i + 1) * len + j - 1], p[i * len + j - 2])
			);
		}
	}
	int fscore = p[0 * len + len - 1];
	delete[]p;
	return max(fscore, sum - fscore);
}
#pragma endregion



int main()
{
	int arr[] = { 1,2,3,4,5,6 };
	int score1 = win1(arr, sizeof(arr) / sizeof(int));
	int score2 = win2(arr, sizeof(arr) / sizeof(int));
	int score3 = win3(arr, sizeof(arr) / sizeof(int));
	int score4 = win4(arr, sizeof(arr) / sizeof(int));

	return 0;
}

