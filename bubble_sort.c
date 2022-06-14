//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//    date:   2022-6-2
//    author: Akashi (����)
//    github: https://github.com/AkashiNeko/C_Code
//    QQ:     1006554341
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

#include <stdio.h>	//ʹ�����е�printf

void bubble_sort(void* arr, size_t num, size_t size, int (*compare)(const void*, const void*))
{
	/******************************************************************/
	/****    arr       Ҫ������������Ԫ�ص�ַ                        ****/
	/****    num       Ҫ�����Ԫ�ظ���                               ****/
	/****    size      Ҫ������������ʹ�С������intΪ4��charΪ1��       ****/
	/****    compare   �Ƚ�����Ԫ�ص�int�ͺ���ָ��                     ****/
	/******************************************************************/
	/****    compare��ʹ�÷�ʽ��qsort��compar��ͬ���ɲο���             ****/
	/****    https://www.cplusplus.com/reference/cstdlib/qsort/    ****/
	/******************************************************************/

	size_t i, j, k;
	char temp;
	int isSorted = 1;
	for (i = 0; i < num; i++)
	{
		//ÿ��ð������
		isSorted = 1; //�����Ѿ�����
		for (j = 0; j < num - i - 1; j++)
		{
			//�ж��Ƿ���Ҫ����Ԫ��
			if (compare((char*)arr + size * j, (char*)arr + size * (j + 1)) > 0)
			{
				//����compare�Ľ���Ԫ������
				for (k = 0; k < size; k++)
				{
					//���ڲ�֪����������Ԫ��������ʲô������ֱ�ӽ���Ԫ��
					//����ͨ��char��ָ��ֱ𽻻�ÿ���ڴ��ֽ��ϵ�����
					temp = *((char*)arr + size * j + k);
					*((char*)arr + size * j + k) = *((char*)arr + size * (j + 1) + k);
					*((char*)arr + size * (j + 1) + k) = temp;
					isSorted = 0; //����������˵��������Ȼ����
				}
			}
		}
		if (isSorted) break; //�Ѿ����򣬽���
	}
}

//����Ϊʹ������
int cmp_num(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
int main()
{
	int arr[10] = { 2,4,7,5,3,9,1,8,0,6 };
	printf("����ǰ: ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	//����bubble_sort
	bubble_sort(arr, 10, sizeof(int), cmp_num);

	printf("\n�����: ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}