//统计括号字符串，求最大有效子串长度和以及是否是有效括号子串

#include "stdafx.h"
#include <string>
#include <algorithm>
bool isValid(const char* str)
{
	int idx = 0;
	int count = 0;
	for (idx = 0; idx != strlen(str); ++idx)
	{
		if (str[idx] == ')' && (--count) < 0) return false;
		if (str[idx] == '(') ++count;

	}
	return count == 0;
}

int maxValidLength(const char * str)
{
	int idx = 0;
	int *dp = new int[strlen(str)]();
	//dp[0] = 0; //最开始只有一个字符，始终为0,但是直接初始化为0了，就不需要写了
	for (idx = 1; idx != strlen(str); ++idx)
	{
		//if (str[idx] == '(') dp[idx] = 0; //默认为0，不用写了
		if (str[idx] == ')')
		{
			int pre = idx - dp[idx - 1] - 1;
			dp[idx] = dp[idx - 1] + 2 + (pre > 0 ? dp[pre - 1] : 0);
		}
	}
	int maxLen = *std::max_element(dp, dp + strlen(str));
	delete[] dp;
	return maxLen;
}


int main()
{
	const char * str1 = "((())())";
	const char * str2 = "(())(()(()))";
	const char * str3 = "()(()()(";

	bool b1 = isValid(str1);
	bool b2 = isValid(str2);
	bool b3 = isValid(str3);
	int len1 = maxValidLength(str1);
	int len2 = maxValidLength(str2);
	int len3 = maxValidLength(str3);


	return 0;
}
