//ͳ�������ַ������������Ч�Ӵ����Ⱥ��Լ��Ƿ�����Ч�����Ӵ�

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
	//dp[0] = 0; //�ʼֻ��һ���ַ���ʼ��Ϊ0,����ֱ�ӳ�ʼ��Ϊ0�ˣ��Ͳ���Ҫд��
	for (idx = 1; idx != strlen(str); ++idx)
	{
		//if (str[idx] == '(') dp[idx] = 0; //Ĭ��Ϊ0������д��
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
