//*****************************************************//
//                                                     //
//    date:    2022-6-7                                //
//    author:  Akashi (氟氟)                            //
//    github:  https://github.com/AkashiNeko/C_Code    //
//    QQ:      1006554341                              //
//                                                     //
//*****************************************************//

#include <vcruntime.h>  //size_t, NULL
#include <assert.h>     //assert

#include <stdio.h>      //printf 测试用

/***************************************/
/****    string部分库函数的模拟实现   ****/
/***************************************/
/****        1.  my_strlen          ****/
/****        2.  my_strcpy          ****/
/****        3.  my_strcat          ****/
/****        4.  my_strcmp          ****/
/****        5.  my_strncpy         ****/
/****        6.  my_strncat         ****/
/****        7.  my_strncmp         ****/
/****        8.  my_strstr          ****/
/****        9.  my_memcpy          ****/
/****        10. my_memmove         ****/
/****        11. my_memcmp          ****/
/****        12. my_memset          ****/
/***************************************/

size_t my_strlen(const char* str)
{
	//strlen - 计算字符串str的长度
	//http://www.cplusplus.com/reference/cstring/strlen/
	char* p = str;
	assert(p);
	while (*p)
		p++;
	return p - str;
}//my_strlen

char* my_strcpy(char* dest, const char* src)
{
	// strcpy - 将字符串src的内容拷贝到dest
	// http://www.cplusplus.com/reference/cstring/strcpy/
	char* ret = dest;
	assert(dest && src);
	while (*dest++ = *src++);
	return ret;
} // my_strcpy

char* my_strcat(char* dest, const char* src)
{
	// strcat - 将字符串src的内容追加到dest末尾
	// http://www.cplusplus.com/reference/cstring/strcat/
	char* ret = dest;
	assert(dest && src);
	while (*dest)
	{
		assert(dest != src);
		dest++;
	}
	while (*dest++ = *src++);
	return ret;
} // my_strcat

int my_strcmp(const char* str1, const char* str2)
{
	// strcmp - 将字符串str1和str2每个字符的ASCII码值进行比较
	// http://www.cplusplus.com/reference/cstring/strcmp/
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return 0;
		str1++;
		str2++;
	}
	return *str1 - *str2;
} // my_strcmp

char* my_strncpy(char* dest, const char* src, size_t num)
{
	// strncpy - 将字符串src的前num个字符拷贝到dest中
	// http://www.cplusplus.com/reference/cstring/strncpy/
	char* ret = dest;
	while (num && (*dest++ = *src++))
		num--;
	while (num--)
		*dest++ = '\0';
	return ret;
} // my_strncpy

char* my_strncat(char* dest, const char* src, size_t num)
{
	// strncat - 将字符串src的前num个字符追加到dest末尾
	// http://www.cplusplus.com/reference/cstring/strncat/
	char* ret = dest;
	assert(dest && src);
	while (*dest)
		dest++;
	while (num && (*dest++ = *src++))
		num--;
	if(num == 0)
		*dest = '\0';
	return ret;
} // my_strncat

int my_strncmp(const char* str1, const char* str2, size_t num)
{
	// strncmp - 将字符串str1和str2的前num个字符的ASCII码值进行比较
	// http://www.cplusplus.com/reference/cstring/strncmp/
	int ret;
	assert(str1 && str2);
	while(num--)
		if (ret = (*str1++ - *str2++))
			return ret;
	return 0;
} // my_strncmp

char* my_strstr(const char* str1, const char* str2)
{
	// strstr - 在字符串str1中查找子串str2
	// http://www.cplusplus.com/reference/cstring/strstr/
	const char* temp = str1;
	const char* s1 = str1;
	const char* s2 = str2;
	assert(str1 && str2);
	while (*str1)
	{
		str1++;
		if (*str1 == *str2)
		{
			s1 = str1;
			s2 = str2;
			while (*s1++ == *s2++)
			{
				if (*s2 == '\0')
					return (char*)str1;
			}
		}
	}
	return NULL;
} // my_strstr

void* my_memcpy(void* dest, const void* src, size_t num)
{
	// memcpy - 从内存src的位置开始复制num个字节的数据到dest的位置
	// http://www.cplusplus.com/reference/cstring/memcpy/
	void* ret = dest;
	assert(dest && src);
	while (num--)
		*((char*)dest)++ = *((char*)src)++;
	return ret;
} // my_memcpy

void* my_memmove(void* dest, const void* src, size_t num)
{
	// memmove - 从内存src的位置开始复制num个字节的数据到dest的位置
	// http://www.cplusplus.com/reference/cstring/memmove/
	void* ret = dest;
	assert(dest && src);
	if (src > dest)
		while (num--)
			*((char*)dest)++ = *((char*)src)++;
	else
		while (num--)
			*((char*)dest + num) = *((char*)src + num);
	return ret;
} // my_memmove

int my_memcmp(const void* ptr1, const void* ptr2, size_t num)
{
	// memcmp - 比较从ptr1和ptr2指针开始的num个字节
	// http://www.cplusplus.com/reference/cstring/memcmp/
	int ret;
	assert(ptr1 && ptr2);
	while (num--)
		if (ret = (*((char*)ptr1)++ - *((char*)ptr2)++))
			return ret;
	return 0;
} // my_memcmp

void* my_memset(void* ptr, int value, size_t num)
{
	// memset - 将ptr指向的内存块的前num个字节设置为指定值
	// https://www.cplusplus.com/reference/cstring/memset/
	void* ret = ptr;
	assert(ptr);
	while (num--)
		*((char*)ptr)++ = value;
	return ret;
} // my_memset



/****  测试用例  ****/

int main()
{
	int i;
	int ret;

	// 1.my_strlen
	char str1[] = "abcdef";
	printf("1.  %d\n", my_strlen(str1));

	// 2.my_strcpy
	char str2[20] = "Hello";
	char str3[] = "qwq";
	printf("2.  %s\n", my_strcpy(str2, str3));

	// 3.my_strcat
	char str4[20] = "Hello C";
	char str5[] = "++";
	printf("3.  %s\n", my_strcat(str4, str5));

	// 4.my_strcmp
	char str6[] = "abcfd";
	char str7[] = "abcdf";
	ret = my_strcmp(str6, str7);
	if(ret > 0)
		printf("4.  %s > %s\n", str6, str7);
	else if(ret < 0)
		printf("4.  %s < %s\n", str6, str7);
	else
		printf("4.  %s == %s\n", str6, str7);

	// 5.my_strncpy
	char str8[20] = "xxxxx World";
	char str9[] = "Hello";
	printf("5.  %s\n", my_strncpy(str8, str9, 5));

	// 6.my_strncat
	char str10[20] = "Hello ";
	char str11[] = "C++";
	printf("6.  %s\n", my_strncat(str10, str11, 1));

	// 7.my_strncmp
	char str12[] = "abcdfg";
	char str13[] = "abcdef";
	printf("7.  %d\n", my_strncmp(str12, str13, 4));

	// 8.my_strstr
	char str14[] = "abbbcdebbef";
	char str15[] = "bbe";
	char* str16 = my_strstr(str14, str15);
	if (str16 == NULL)
		printf("8.  找不到\n");
	else
		printf("8.  %s\n", str16);

	// 9.my_memcpy
	int arr1[5] = { 1,2,3,4,5 };
	int arr2[10] = { 0 };
	my_memcpy(arr2, arr1, 20);
	printf("9.  ");
	for (i = 0; i < 10; i++)
		printf("%d ", arr2[i]);
	printf("\n");

	// 10.my_memmove
	int arr3[10] = { 0,1,2,3,4,5,6,7,8,9 };
	my_memmove(arr3, arr3 + 2, 20);
	printf("10. ");
	for (i = 0; i < 10; i++)
		printf("%d ", arr3[i]);
	printf("\n");

	// 11.my_memcmp
	int arr4[] = { 1,2,3,4,5 };
	int arr5[] = { 1,2,3,4,6 };
	printf("11. %d\n", my_memcmp(arr4, arr5, 20));

	// 12.my_memset
	int arr6[8] = { 1,2,3,4,5,6,7,8 };
	my_memset(arr6, 0, 20);
	printf("12. ");
	for (i = 0; i < 8; i++)
		printf("%d ", arr6[i]);
	printf("\n");

	return 0;
}
