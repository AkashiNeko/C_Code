//**********************************************************//
//															//
//		data:   2022-5-4									//
//		author: Akashi (氟氟)								//
//		github: https://github.com/AkashiNeko/C_Code		//
//		gitee:  https://gitee.com/AkashiNeko/C_Code			//
//		QQ:     1006554341									//
//															//
//**********************************************************//

#define _CRT_SECURE_NO_WARNINGS 1 //scanf

#include <stdio.h>  //printf scanf
void add_num(int arr[50][50], int order) 
{
	struct coor {
		int x;
		int y;
	}place, search;
	//依次放置的数（从1开始）
	int num = 1;
	//设置填数坐标
	place.x = 0;
	place.y = order / 2;
	//在第一行中间填1
	arr[place.x][place.y] = 1;
	//向数组中填入2~阶数的平方
	for (num = 2; num <= order * order; num++)  
	{
		//设置搜索坐标
		search.x = place.x;
		search.y = place.y;
		//搜索行向上移动
		if (search.x == 0)
			search.x = order - 1;
		else
			search.x--;
		//搜索列向右移动
		if (search.y == order - 1)
			search.y = 0;
		else
			search.y++;
		//判断搜索位置是否未填数字
		if (arr[search.x][search.y] == 0)
		{
			//搜索位置未填数字，则将填数位置移动到搜索位置
			place.x = search.x;
			place.y = search.y;
		}
		else
		{
			//搜索位置已填数字，则将填数位置移动到原位置下方
			place.x++;
		}
		//在填数位置填入数字
		arr[place.x][place.y] = num;
	}
}
int main()
{
	int arr[50][50], input, i, j, sum;
	printf("输入幻方阶数(奇数): ");

	//输入一个奇数
	while (1)
	{
		scanf("%d", &input);
		if (input % 2 == 1 && input > 1 && input < 100)
			break;
		printf("非法输入，请输入一个奇数: ");
	}

	//初始化数组
	for (i = 0; i < input; i++)
		for (j = 0; j < input; j++)
			arr[i][j] = 0;

	//填数字
	add_num(arr, input);

	//打印结果
	for (i = 0; i < input; i++)
	{
		printf("\n");
		for (j = 0; j < input; j++)
			printf("%3d ", arr[i][j]);
	}

	//验证结果
	printf("\n\n验证\n");
	printf("\n>> 行:\n");
	for (i = 0; i < input; i++)
	{
		sum = 0;
		for (j = 0; j < input; j++)
		{
			printf("%d", arr[i][j]);
			sum += arr[i][j];
			if (j == input - 1)
				printf(" = %d", sum);
			else
				printf(" + ");
		}
		printf("\n");
	}
	printf("\n>> 列:\n");
	for (j = 0; j < input; j++)
	{
		sum = 0;
		for (i = 0; i < input; i++)
		{
			printf("%d", arr[i][j]);
			sum += arr[i][j];
			if (i == input - 1)
				printf(" = %d", sum);
			else
				printf(" + ");
		}
		printf("\n");
	}
	printf("\n>> 对角线:\n");
	//主对角线
	sum = 0;
	for (i = 0; i < input; i++)
	{
		printf("%d", arr[i][i]);
		sum += arr[i][i];
		if (i == input - 1)
			printf(" = %d", sum);
		else
			printf(" + ");
	}
	printf("\n");
	//副对角线
	sum = 0;
	for (i = 0; i < input; i++)
	{
		printf("%d", arr[i][input - i - 1]);
		sum += arr[i][input - i - 1];
		if (i == input - 1)
			printf(" = %d", sum);
		else
			printf(" + ");
	}
	printf("\n");

	while (1); //让程序运行完不自动关闭
	return 0;
}