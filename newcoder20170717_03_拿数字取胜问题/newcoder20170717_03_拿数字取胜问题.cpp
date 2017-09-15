// 24_01_ZCY_NO.3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
template<class T>
inline T max(const T& _lhs, const T& _rhs) { return _lhs > _rhs ? _lhs : _rhs; }
template<class T>
inline T min(const T& _lhs, const T& _rhs) { return _lhs < _rhs ? _lhs : _rhs; }

#pragma region win1_�����ݹ�

int f(int arr[], int i, int j);
int s(int arr[], int i, int j);

int win1(int arr[], int len)
{
	if (arr == NULL) return 0;

	//return max(f(arr, 0, len - 1), s(arr, 0, len - 1));

	//һ���ݹ�ʵ��
	int sum = 0;
	for (int k = 0; k != len; ++k)
	{
		sum += arr[k];
	}
	int fmax = f(arr, 0, len - 1);
	return max(fmax, sum - fmax);
}

//��Ϊ�ȷ������ջ�õķ���
int f(int arr[], int i, int j)
{
	if (i == j) //ֻ��һ����
		return arr[i];
	return max(arr[i] + s(arr, i + 1, j), arr[j] + s(arr, i, j - 1));

	//���Լ�����⣬��Щ��һ��
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
	return min(f(arr, i + 1, j), f(arr, i, j - 1)); //���߿϶���Ҫ�ȷ����õ����ٵ����
}

#pragma endregion

#pragma region win2_ʹ�����ű�
int win2(int *arr, int len)
{
	const int w = len;
	int *f = new int[len*len](); //�ȹ������ű�����ʼ��Ϊ0
	int *s = new int[len*len]();

	for (int j = 0; j != len; ++j) //һ�еı���
	{
		f[j*len + j] = arr[j]; //��f��Խ��߸�ֵΪ������Ӧֵ
		for (int i = j - 1; i >= 0; --i) //һ�У���������
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

#pragma region win3_ֻ�����ȷ��ߵ���������ݹ�
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

#pragma region ֻʹ��һ�ű�
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
			if (i == j - 1) { //��һ�Խ��ߵ�ֵ
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

