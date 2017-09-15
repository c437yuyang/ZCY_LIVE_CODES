// 25_02_SmallSum.cpp : 定义控制台应用程序的入口点。
//

//数组小和的定义如下：
//例如，数组s = [1, 3, 5, 2, 4, 6]，在s[0]的左边小于或等于s[0]的
//数的和为0，在s[1]的左边小于或等于s[1]的数的和为1，在s[2]
//的左边小于或等于s[2]的数的和为1 + 3 = 4，在s[3]的左边小于或
//等于s[3]的数的和为1，在s[4]的左边小于或等于s[4]的数的和
//为1 + 3 + 2 = 6，在s[5]的左边小于或等于s[5]的数的和为
//1 + 3 + 5 + 2 + 4 = 15，所以s的小和为0 + 1 + 4 + 1 + 6 + 15 = 27。
//给定一个数组s，实现函数返回s的小和。

#include "stdafx.h"
#include <iostream>
using namespace std;
int getSmallSum(int arr[], int len);
int func(int s[], int l, int r);
int merge(int s[], int left, int mid, int right);
void swap(int arr[], int index1, int index2);

int getSmallSum(int arr[], int len) {

	return func(arr, 0, len - 1);
}

int func(int s[], int l, int r) {
	if (l == r) {
		return 0;
	}
	int mid = (l + r) / 2;
	return func(s, l, mid) + func(s, mid + 1, r) + merge(s, l, mid, r);
}

int merge(int s[], int left, int mid, int right) {
	int len = right - left + 1;
	int *h = new int[len]();
	int hi = 0;
	int i = left;
	int j = mid + 1;
	int smallSum = 0;
	while (i <= mid && j <= right) {
		if (s[i] <= s[j]) {
			smallSum += s[i] * (right - j + 1);
			h[hi++] = s[i++];
		}
		else {
			h[hi++] = s[j++];
		}
	}
	for (; (j < right + 1) || (i < mid + 1); j++, i++) {
		h[hi++] = i > mid ? s[j] : s[i];
	}
	for (int k = 0; k != len; k++) {
		s[left++] = h[k];
	}
	delete[] h;
	return smallSum;
}

void swap(int arr[], int index1, int index2) {
	int tmp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = tmp;
}

void merge1(int *arr, int p, int  q, int  r);
void mergeSort(int *arr, int p, int r);
int main()
{

	int arr[] = { 3, 1, 2, 4, 6, 2, 7, 8, 1 };
	cout << getSmallSum(arr, sizeof(arr) / sizeof(int));

	mergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	return 0;
}


void mergeSort(int *arr, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		mergeSort(arr, p, q);
		mergeSort(arr, q + 1, r);
		merge1(arr, p, q, r);
	}

}

void merge1(int *arr, int p, int  q, int  r)
{
	int n1 = q - p + 1;
	int n2 = r - q; // r-(q+1)+1

	int *L = new int[n1 + 1]();
	int *R = new int[n2 + 1]();
	//左边的数组赋值给左边
	for (int i = 0; i != n1; ++i)
		L[i] = arr[p + i];

	//右半部分的数组赋值给右边
	for (int i = 0; i != n2; ++i)
		R[i] = arr[q + 1 + i];

	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
	for (int k = p, i = 0, j = 0; k != r; ++k)
	{
		if (L[i] < R[j])
			arr[k] = L[i++];
		else
			arr[k] = R[j++];
	}
	delete[] L;
	delete[] R;
}
