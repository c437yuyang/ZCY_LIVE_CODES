// 24_03_ZCY_NO2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

//对给定数组中累加和等于aim的最长子数组，全是正数的情况下
int LongestSumSubArrayLengthInPositiveArray(int arr[], int n, int aim)
{
	int left = 0, right = 0;
	int max = 0;
	int sum = arr[0];

	while (right < n)
	{
		if (sum == aim) {
			max = std::max(max, right - left + 1);
			printf("左指针:arr[%d] %d\t右指针:arr[%d] %d\n", left, arr[left], right, arr[right]);
			//此时相等了，则下一刻必须要left向左移，不然不管怎么都是大于aim的
			sum -= arr[left++];


		}
		else if (sum > aim)
			sum -= arr[left++];
		else //sum<aim
		{
			sum += arr[++right];
			if (right == n) break; //这种情况只可能发生在遍历到最后，小于aim,right继续加，这个时候不管怎么都不可能再加出aim了，所以break
		}

	}

	return max;

}


//正负数都可以的情况
int LongestSumSubArrayLength(int arr[], int n, int aim)
{

	std::map<int, int> subSumFirstIdx;//记录某个值最早出现的地方

	subSumFirstIdx.insert(std::map<int, int>::value_type(0, -1)); //也可以简单点直接用下标操作
	int sum = 0;
	int maxLen = 0;
	for (int i = 0; i != n; ++i)
	{
		sum += arr[i];
		auto it = subSumFirstIdx.find(sum - aim);
		if (it != subSumFirstIdx.end()) //找到了aim-sum的记录
			maxLen = std::max(maxLen, i - it->second);

		if (subSumFirstIdx.find(sum) == subSumFirstIdx.end()) //没有记录过
			subSumFirstIdx[sum] = i;

	}
	return maxLen;

}

//对给定数组中累加和小于等于aim的最长子数组
int LongestSubarrayLessSumAwesomeSolution(int arr[], int n, int k)
{
	int *min_val = new int[n];
	int *min_idx = new int[n];
	min_val[n - 1] = arr[n - 1];
	min_idx[n - 1] = n - 1;
	for (int i = n - 2; i != -1; --i)
	{
		if (min_val[i + 1] <= 0)
		{
			min_idx[i] = min_idx[i + 1];
			min_val[i] = min_val[i + 1] + arr[i];
		}
		else
		{
			min_idx[i] = i;
			min_val[i] = arr[i];
		}
	}

	int maxLen = 0;
	int sum = 0;
	int end = 0;
	for (int i = 0; i != n; ++i)
	{
		while (end < n && sum + min_val[end] <= k)
		{
			sum += min_val[end];
			end = min_idx[end] + 1;
		}
		sum -= end > i ? arr[i] : 0;
		maxLen = std::max(maxLen, end - i);
		end = std::max(end, i + 1);
	}
	return maxLen;

}


int main()
{

	int arr[20] = { 7,7,9,3,8,9,6,2,5,5,10,1,9,4,3,4,4,3,7,7 }; //4
																//int arr[20] = { 3,4,3,2,3,3,10,5,6,10,10,8,4,10,4,7,6,1,8,6};//5
	int aim = 15;
	cout << LongestSumSubArrayLengthInPositiveArray(arr, 20, aim) << endl;

	int arr1[20] = { 1,-1,-3,1,-5,3,3,1,5,1,2,0,4,2,-4,-5,-1,4,1,-4 };//15
	int aim1 = 10;
	cout << LongestSumSubArrayLength(arr1, 20, aim1) << endl;

	int arr2[10] = { 7,0,-2,2,5,2,4,0,5,-5 };//5
	int aim2 = 10;

	cout << LongestSubarrayLessSumAwesomeSolution(arr2, 10, aim2) << endl;


	return 0;
}

