//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//    date:   2022-6-12
//    author: Akashi (氟氟)
//    github: https://github.com/AkashiNeko/C_Code
//    QQ:     1006554341
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

#include <stdlib.h>	//malloc

/********************************************/
/****    创建长度可变的一维数组和二维数组   ****/
/****     如果创建失败则返回空指针NULL     ****/
/********************************************/
/****          1. CreatIntArr1           ****/
/****          2. CreatIntArr2           ****/
/********************************************/

int* CreatIntArr1(size_t size)
{
	//开辟数组的空间
	int* arr = (int*)malloc(size * sizeof(int));
	if (arr == NULL)
		return NULL;

	//将每个元素初始化为0
	while (size--)
		arr[size] = 0;
	
	return arr;
}

int** CreatIntArr2(size_t row, size_t col)
{
	size_t ArrSize = row * col;

	//开辟存放每行首元素地址的指针数组的空间
	int** arr = (int**)malloc(row * sizeof(int*));
	if (arr == NULL)
		return NULL;

	//开辟二维数组的空间
	int* head = (int*)malloc(ArrSize * sizeof(int));
	if (head == NULL)
		return NULL;

	//将arr中每个元素指向二维数组的每行
	while (row--)
		arr[row] = col * row + head;

	//将每个元素初始化为0
	while (ArrSize--)
		head[ArrSize] = 0;

	return arr;
}

//使用

int main()
{
	//创建5个元素的int型一维数组
	int* arr1 = CreatIntArr1(5);

	//判断是否创建失败
	if (arr1 == NULL)
	{
		perror("CreatIntArr1");
		return 0;
	}

	//使用 arr1[0]、arr1[2] ……

	//使用完后释放空间
	free(arr1);
	arr1 = NULL;


	//创建一个3行4列的int型二维数组
	int** arr2 = CreatIntArr2(3, 4);

	//判断是否创建失败
	if (arr2 == NULL)
	{
		perror("CreatIntArr2");
		return 0;
	}

	//使用 arr2[0][1]、arr2[3][2] ……

	//使用完后释放空间
	free(arr2);
	arr2 = NULL;

	return 0;
}