//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//    date:   2022-6-14
//    author: Akashi (氟氟)
//    github: https://github.com/AkashiNeko/C_Code
//    QQ:     1006554341
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

#include <stdio.h>  // printf
#include <stdlib.h> // atoi
#include <limits.h> // INT_MAX, INT_MIN

int my_atoi(const char* str)
{
	// atoi - 字符串转整数 (ascii to integer)
	// https://cplusplus.com/reference/cstdlib/atoi/

	if (str == NULL)
		return 0;

	//返回值的正负
	int sign = 1;
	//返回值
	long long int ret = 0;
	//位权重
	long long int weight = 1;
	//移动的指针
	char* p = NULL;

	//删首空
	while (*str == ' ')
		str++;

	//判断正负
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	p = str;
	
	//寻找到数字字符部分的末尾
	while (*p >= '0' && *p <= '9')
		p++;

	//根据每个数字字符的权重计算结果
	while (p-- != str)
	{
		ret += sign * weight * ((long long int)*p - '0');
		//结果过大
		if (ret >= INT_MAX)
			return (int)INT_MAX;
		//结果过小
		if (ret <= INT_MIN)
			return (int)INT_MIN;

		weight *= 10;
	}
	return ret;
} // my_atoi

//测试

int main()
{
	char* input[] = {
		//测试用例↓
		"20",
		"-123",
		"123ab456",
		"qwq",
		"",
		"9999999999999",
		"   -123",
		"0012",

		//↑在此处添加测试用例↑
		NULL
	};
	int i = 0;
	while (input[i] != NULL)
	{
		printf("example: \"%s\"\n", input[i]);
		printf("atoi   : %d\n", atoi(input[i]));
		printf("my_atoi: %d\n\n", my_atoi(input[i]));
		i++;
	}
	return 0;
}