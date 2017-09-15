// 25_02_SmallSum.cpp : �������̨Ӧ�ó������ڵ㡣
//

//����С�͵Ķ������£�
//���磬����s = [1, 3, 5, 2, 4, 6]����s[0]�����С�ڻ����s[0]��
//���ĺ�Ϊ0����s[1]�����С�ڻ����s[1]�����ĺ�Ϊ1����s[2]
//�����С�ڻ����s[2]�����ĺ�Ϊ1 + 3 = 4����s[3]�����С�ڻ�
//����s[3]�����ĺ�Ϊ1����s[4]�����С�ڻ����s[4]�����ĺ�
//Ϊ1 + 3 + 2 = 6����s[5]�����С�ڻ����s[5]�����ĺ�Ϊ
//1 + 3 + 5 + 2 + 4 = 15������s��С��Ϊ0 + 1 + 4 + 1 + 6 + 15 = 27��
//����һ������s��ʵ�ֺ�������s��С�͡�

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
	//��ߵ����鸳ֵ�����
	for (int i = 0; i != n1; ++i)
		L[i] = arr[p + i];

	//�Ұ벿�ֵ����鸳ֵ���ұ�
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
