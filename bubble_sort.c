//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//    date:   2022-6-2
//    author: Akashi (氟氟)
//    github: https://github.com/AkashiNeko/C_Code
//    QQ:     1006554341
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

#include <stdio.h>	//使用例中的printf

void bubble_sort(void* arr, size_t num, size_t size, int (*compare)(const void*, const void*))
{
	/******************************************************************/
	/****    arr       要排序的数组的首元素地址                        ****/
	/****    num       要排序的元素个数                               ****/
	/****    size      要排序的数据类型大小（比如int为4，char为1）       ****/
	/****    compare   比较两个元素的int型函数指针                     ****/
	/******************************************************************/
	/****    compare的使用方式和qsort的compar相同，可参考：             ****/
	/****    https://www.cplusplus.com/reference/cstdlib/qsort/    ****/
	/******************************************************************/

	size_t i, j, k;
	char temp;
	int isSorted = 1;
	for (i = 0; i < num; i++)
	{
		//每趟冒泡排序
		isSorted = 1; //假设已经有序
		for (j = 0; j < num - i - 1; j++)
		{
			//判断是否需要交换元素
			if (compare((char*)arr + size * j, (char*)arr + size * (j + 1)) > 0)
			{
				//满足compare的交换元素条件
				for (k = 0; k < size; k++)
				{
					//由于不知道传进来的元素类型是什么，不能直接交换元素
					//所以通过char型指针分别交换每个内存字节上的数据
					temp = *((char*)arr + size * j + k);
					*((char*)arr + size * j + k) = *((char*)arr + size * (j + 1) + k);
					*((char*)arr + size * (j + 1) + k) = temp;
					isSorted = 0; //发生交换，说明数组仍然无序
				}
			}
		}
		if (isSorted) break; //已经有序，结束
	}
}

//以下为使用用例
int cmp_num(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
int main()
{
	int arr[10] = { 2,4,7,5,3,9,1,8,0,6 };
	printf("排序前: ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	//调用bubble_sort
	bubble_sort(arr, 10, sizeof(int), cmp_num);

	printf("\n排序后: ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}