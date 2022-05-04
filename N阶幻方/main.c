//**********************************************************//
//															//
//		data:   2022-5-4									//
//		author: Akashi (����)								//
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
	//���η��õ�������1��ʼ��
	int num = 1;
	//������������
	place.x = 0;
	place.y = order / 2;
	//�ڵ�һ���м���1
	arr[place.x][place.y] = 1;
	//������������2~������ƽ��
	for (num = 2; num <= order * order; num++)  
	{
		//������������
		search.x = place.x;
		search.y = place.y;
		//�����������ƶ�
		if (search.x == 0)
			search.x = order - 1;
		else
			search.x--;
		//�����������ƶ�
		if (search.y == order - 1)
			search.y = 0;
		else
			search.y++;
		//�ж�����λ���Ƿ�δ������
		if (arr[search.x][search.y] == 0)
		{
			//����λ��δ�����֣�������λ���ƶ�������λ��
			place.x = search.x;
			place.y = search.y;
		}
		else
		{
			//����λ���������֣�������λ���ƶ���ԭλ���·�
			place.x++;
		}
		//������λ����������
		arr[place.x][place.y] = num;
	}
}
int main()
{
	int arr[50][50], input, i, j, sum;
	printf("����÷�����(����): ");

	//����һ������
	while (1)
	{
		scanf("%d", &input);
		if (input % 2 == 1 && input > 1 && input < 100)
			break;
		printf("�Ƿ����룬������һ������: ");
	}

	//��ʼ������
	for (i = 0; i < input; i++)
		for (j = 0; j < input; j++)
			arr[i][j] = 0;

	//������
	add_num(arr, input);

	//��ӡ���
	for (i = 0; i < input; i++)
	{
		printf("\n");
		for (j = 0; j < input; j++)
			printf("%3d ", arr[i][j]);
	}

	//��֤���
	printf("\n\n��֤\n");
	printf("\n>> ��:\n");
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
	printf("\n>> ��:\n");
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
	printf("\n>> �Խ���:\n");
	//���Խ���
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
	//���Խ���
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

	while (1); //�ó��������겻�Զ��ر�
	return 0;
}