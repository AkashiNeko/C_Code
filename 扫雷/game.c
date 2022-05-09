#include "game.h"

int menu()
{
	char ch, select = 0;
	setrd(2, 2);
	setcl(MENU_COLOR);
	printf("==== ɨ�� ====");
	setrd(2, 10);
	setcl(TIP_COLOR);
	printf("[��][��] �ƶ�");
	setrd(2, 12);
	printf("[Enter] ѡ��");

	print_menu:

	setrd(4, 4);
	if (select == 0) setcl(SEL_COLOR);
	else setcl(MENU_COLOR);
	printf(" 1. ��ʼ ");

	setrd(4, 6);
	if (select == 1) setcl(SEL_COLOR);
	else setcl(MENU_COLOR);
	printf(" 2. ���� ");

	setrd(4, 8);
	if (select == 2) setcl(SEL_COLOR);
	else setcl(MENU_COLOR);
	printf(" 3. �˳� ");

	setrd(0, 0);
	while (1)
	{
        if (_kbhit())
            switch (ch = _getch())
            {
            case -32: //�����
                ch = _getch();
                switch(ch)
				{
				case 72: //��
					if (select == 0)
						select = 2;
					else
						select--;
					goto print_menu;
					break;
				case 80: //��
					if (select == 2)
						select = 0;
					else
						select++;
					goto print_menu;
					break;
				default:
					break;
				}
				break;
			case 13: //�س�
				setcl(0x0f);
				system("cls");
				return select;
			default:
				break;
			}
	}
}

void print_tips(int size, int color, char* str)
{
	if (size < 11)
		size = 12;
	setrd(4, size + 4);
	setcl(color);
	printf("%s", str);
	setcl(0x0f);
	printf("           ");
	setrd(0, 0);
}

void clear_tips(int size)
{
	setrd(3, size + 4);
	setcl(0x0f);
	printf("                        ");
	//�ÿո񸲸�
}

void menu_set(int* psize, int* pmine)
{
	char ch, select = 0;
	setrd(2, 2);
	setcl(MENU_COLOR);
	printf("==== ���� ====");
	setcl(TIP_COLOR);
	setrd(2, 16);
	printf("[ESC]     ����   ");
	goto select_menu;

print_menu_set:

	setrd(3, 4);
	if (select == 0) setcl(SEL_COLOR);
	else setcl(MENU_COLOR);
	printf("��ͼ��С");

	setrd(13, 4);
	if (select == 3) setcl(0x1b);
	else setcl(0x0a);
	if (*psize < 10)
		printf(" ");
	printf("%d", *psize);

	setrd(3, 6);
	if (select == 1) setcl(SEL_COLOR);
	else setcl(MENU_COLOR);
	printf("���׸���");

	setrd(13, 6);
	if(select == 4) setcl(0x1b);
	else setcl(0x0a);
	if (*pmine < 10)
		printf(" ");
	printf("%d", *pmine);

	setrd(3, 8);
	if (select == 2) setcl(SEL_COLOR);
	else setcl(MENU_COLOR);
	printf("���ز˵�");

	setrd(0, 0);
	while (1)
	{
		if (_kbhit())
		{
			switch (ch = _getch())
			{
			case -32: //�����
				ch = _getch();
				switch (ch)
				{
				case 72: //��
					switch (select)
					{
					case 0: select = 2; break;
					case 1: select = 0; break;
					case 2: select = 1; break;
					case 3:
						if (*psize < 20)
						{
							(*psize)++;
							if (*pmine = ((*psize) - 1) * ((*psize) - 1))
								*pmine = (int)(*psize * *psize * 0.2 + 0.5);
						}
						break;
					case 4:
						if (*pmine < 400)
						{
							(*pmine)++;
							if (*pmine > (*psize * *psize))
								(*psize)++;
						}
						break;
					}
					goto print_menu_set;
					break;
				case 80: //��
					switch (select)
					{
					case 0: select = 1; break;
					case 1: select = 2; break;
					case 2: select = 0; break;
					case 3:
						if (*psize > 3)
						{
							(*psize)--;
							if (*pmine > *psize * *psize)
								*pmine = *psize * *psize;
						}
						break;
					case 4: if (*pmine > 1) (*pmine)--; break;
					}
					goto print_menu_set;
				default:
					break;
				case 75:  //��
				case 77:; //��
				}
			case 13:	  //�س�
				switch (select)
				{
				case 2: //����
					return;
				case 0: select = 3;
					goto edit_num;
				case 1: select = 4;
					goto edit_num;
				case 3: select = 0;
					goto select_menu;
				case 4: select = 1;
					goto select_menu;
				}
			edit_num:
				setcl(TIP_COLOR);
				setrd(2, 10);
				printf("[��][��]  ��/��");
				setrd(2, 12);
				printf("[��]      ȷ�� ");
				setrd(2, 14);
				printf("[Enter]   ȷ�� ");
				goto print_menu_set;
			select_menu:
				setcl(TIP_COLOR);
				setrd(2, 10);
				printf("[��][��]  �ƶ�  ");
				setrd(2, 12);
				printf("[��]      ѡ�� ");
				setrd(2, 14);
				printf("[Enter]   ѡ��  ");
				goto print_menu_set;
			case 27: //ESC
				return;
			default:
				break;
			}
		}
	}
}

void set_mine(short map[COL_MAX][COL_MAX], int size, int mine)
{
	int i, j, a, b, x, y;
	srand((unsigned)time(NULL));
	for (b = 0; b < mine; b++)
	{
		do
		{
			x = rand() % size;
			y = rand() % size;
		} while (map[x][y] == 9);
		map[x][y] = 9;
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (map[i][j] == 9)
				continue;
			int num[8] = { 0,0,0,0,0,0,0,0 };
			if (i == 0) //�ϱ߽�
				a = i + 1;
			else if (i == size - 1) //�±߽�
				a = i - 1;
			else //ɨ��λ��λ�ڷ����±߽紦
			{
				num[0] = map[i - 1][j];
				num[4] = map[i + 1][j];
				if (j == 0) //�ǽ���߽� 5
				{
					num[1] = map[i - 1][j + 1];
					num[2] = map[i][j + 1];
					num[3] = map[i + 1][j + 1];
				}
				else if (i == size - 1) //�ǽ��ұ߽� 5
				{
					num[1] = map[i - 1][j - 1];
					num[2] = map[i][j - 1];
					num[3] = map[i + 1][j - 1];
				}
				else //�м����� 8
				{
					for (b = 0; b < 3; b++)
					{
						num[b + 1] = map[i - 1 + b][j - 1];
						num[b + 5] = map[i - 1 + b][j + 1];
					}
				}
				goto mid;
			}
			//ɨ��λ��λ�����±߽紦
			num[2] = map[a][j];
			if (j == 0) //��� 3
			{
				num[0] = map[i][j + 1];
				num[1] = map[a][j + 1];
			}
			else if (j == size - 1) //�ҽ� 3
			{
				num[0] = map[i][j - 1];
				num[1] = map[a][j - 1];
			}
			else //�ǽǱ߽� 5
			{
				num[0] = map[i][j - 1];
				num[1] = map[i][j + 1];
				num[3] = map[a][j - 1];
				num[4] = map[a][j + 1];
			}
		mid:
			for (b = 0; b < 8; b++)
				if (num[b] == 9)
					map[i][j]++;
		}
	}
}

void print_map(short map[COL_MAX][COL_MAX], int size, short display[COL_MAX][COL_MAX])
{
	int i, j;
	char col[19] = "������������������"; //ȫ������
	char row[41] = "���£ãģţƣǣȣɣʣˣ̣ͣΣϣУѣңӣ�"; //ȫ����ĸ
	setcl(MAP_COLOR);
	for (i = 0; i < size; i++) //��ӡ���ұ߽�
	{
		setrd(2, i + 2);//��߽�
		if (i < 9) // i+1<10 ��ӡȫ������
			printf("%c%c", col[2 * i], col[2 * i + 1]);
		else //i+1>=10 ��ӡ�������
			printf("%d", i + 1);
		setrd(4 + 2 * size, i + 2);
		printf("��"); //�ұ߽�
	}
	setrd(2, 1); //��ӡ���Ͻ�
	printf("��");
	for (i = 0; i < size; i++) //��ӡ�ϱ߽�
		printf("%c%c", row[2 * i], row[2 * i + 1]);
	setrd(4, size + 2);
	for (i = 0; i < size + 1; i++) //��ӡ�±߽�
		printf("��");
	setrd(2, 2 + size); //��ӡ���½�
	printf("��");
	setrd(4 + 2 * size, 1); //��ӡ���Ͻ�
	printf("��");
	//��ӡ�м�����
	setcl(UNKNOW_COLOR);
	for (i = 0; i < size; i++)
	{
		setrd(4, i + 2);
		for (j = 0; j < size; j++)
			printf("��");
	}
	setcl(MENU_COLOR);
	setrd(12 + size * 2, 2);
	printf("[��]");
	setrd(8 + size * 2, 4);
	printf("[��][��][��]");
	setrd(8 + size * 2, 6);
	printf("��������ƶ�");
	setrd(9 + size * 2, 8);
	printf("[��]  ���");
	setrd(9 + size * 2, 10);
	printf("[��]  ����");
	setrd(9 + size * 2, 12);
	printf("[��]  �ؿ�");
	setrd(9 + size * 2, 14);
	printf("[��]  �˳�");
}

void print_all_mine(short map[COL_MAX][COL_MAX], int size, int state, short display[COL_MAX][COL_MAX])
{
	int i, j;
	char num[17] = "����������������";
	if (state)
	{
		print_tips(size, 0x0a, "���׳ɹ�!");
		char col[19] = "������������������"; //ȫ������
		char row[41] = "���£ãģţƣǣȣɣʣˣ̣ͣΣϣУѣңӣ�"; //ȫ����ĸ
		setcl(0xaf);
		for (i = 0; i < size; i++) //��ӡ���ұ߽�
		{
			setrd(2, i + 2);//��߽�
			if (i < 9) // i+1<10 ��ӡȫ������
				printf("%c%c", col[2 * i], col[2 * i + 1]);
			else //i+1>=10 ��ӡ�������
				printf("%d", i + 1);
			setrd(4 + 2 * size, i + 2);
			printf("��"); //�ұ߽�
		}
		setrd(2, 1); //��ӡ���Ͻ�
		printf("��");
		for (i = 0; i < size; i++) //��ӡ�ϱ߽�
			printf("%c%c", row[2 * i], row[2 * i + 1]);
		setrd(4, size + 2);
		for (i = 0; i < size + 1; i++) //��ӡ�±߽�
			printf("��");
		setrd(2, 2 + size); //��ӡ���½�
		printf("��");
		setrd(4 + 2 * size, 1); //��ӡ���Ͻ�
		printf("��");
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (map[i][j] == 9)
				{
					setrd(4 + j * 2, i + 2);
					setcl(0xfd);
					printf(MINE);
				}
				else
				{
					print_ele(map, i, j);
				}
			}
		}
	}
	else
	{
		print_tips(size, 0x0c, "����ʧ��!");
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (display[i][j] == 2 || map[i][j] == 9)
				{
					setrd(4 + j * 2, i + 2);
					if (display[i][j] == 2 && map[i][j] != 9)		 //��Ǵ���
					{
						setcl(0xfc);
						printf(SIGN_MINE);
					}
					else if (display[i][j] != 2 && map[i][j] == 9)	 //��δ���
					{
						setcl(0x40);
						printf(MINE);
					}
					else											 //�����ȷ
					{
						setcl(0xa0);
						printf(MINE);
					}
				}
				else
				{
					print_ele(map, i, j);
				}
			}
		}
	}
	
	setrd(0, 0);
}

void print_ele(short map[COL_MAX][COL_MAX], int i, int j)
{
	setrd(4 + j * 2, i + 2);
	//ȫ������ ������ʾ�׵�����
	char num[17] = "����������������";
	if (map[i][j] == 0)
	{
		setcl(BG_COLOR);
		printf(SPACE);
	}
	else if (map[i][j] == 9)
	{
		setcl(MINE_COLOR);
		printf(MINE);
	}
	else
	{
		setcl(BG_COLOR + map[i][j]);
		printf("%c%c", num[2 * (map[i][j] - 1)], num[2 * (map[i][j] - 1) + 1]);
	}
}

int play(short map[COL_MAX][COL_MAX], int size, short display[COL_MAX][COL_MAX])
{
	char ch;
	int over = 0;
	struct coordinate {
		int x;
		int y;
	}plr; //player
	//������ҳ�ʼ����
	plr.x = size / 2;
	plr.y = size / 2;
	print_plrcr(plr.x, plr.y, map, display, 1);
	while (1)
	{
		if (_kbhit())
		{
			switch (ch = _getch())
			{
			case -32:
				if (over)
					break;
				ch = _getch();
				print_plrcr(plr.x, plr.y, map, display, 0); //���ԭλ��
				switch (ch)
				{
				case 72: //��
					if (plr.x == 0)
						plr.x = size - 1;
					else
						plr.x--;
					print_plrcr(plr.x, plr.y, map, display, 1);
					print_tips(size, 0x07, "�����ƶ�");
					break;
				case 80: //��
					if (plr.x == size - 1)
						plr.x = 0;
					else
						plr.x++;
					print_plrcr(plr.x, plr.y, map, display, 1);
					print_tips(size, 0x07, "�����ƶ�");
					break;
				case 75: //��
					if (plr.y == 0)
						plr.y = size - 1;
					else
						plr.y--;
					print_plrcr(plr.x, plr.y, map, display, 1);
					print_tips(size, 0x07, "�����ƶ�");
					break;
				case 77: //��
					if (plr.y == size - 1)
						plr.y = 0;
					else
						plr.y++;
					print_plrcr(plr.x, plr.y, map, display, 1);
					print_tips(size, 0x07, "�����ƶ�");
					break;
				}
				break;

			case 90:  //Z
			case 122: //z
				if (over)
				{
					clear_tips(size);
					return 2;
				}
				switch (display[plr.x][plr.y])
				{
				case 2:
					display[plr.x][plr.y] = 0;
					print_plrcr(plr.x, plr.y, map, display, 1);
					print_tips(size, 0x07, "ȡ�����");
					break;
				case 0:
					display[plr.x][plr.y] = 2;
					print_plrcr(plr.x, plr.y, map, display, 1);
					print_tips(size, 0x07, "�����");
					break;
				case 1:
					print_tips(size, 0x0c, "��λ���޷������");
					break;
				}
				if (state(map, display, size)) //���׳ɹ�
				{
					print_all_mine(map, size, 1, display);
					over = 1;
				}
				break;
			case 88:  //X
			case 120: //x 
				if (over)
				{
					clear_tips(size);
					return 2;
				}
				switch (display[plr.x][plr.y])
				{
				case 0:
					if (map[plr.x][plr.y] == 9)
					{
						print_all_mine(map, size, 0, display);
						over = 1;
						break;
					}
					else //���״�����������
					{
						mine_clearance(plr.x, plr.y, map, display, size);
					}
					print_plrcr(plr.x, plr.y, map, display, 1);
					print_tips(size, 0x07, "����");
					break;
				case 1:
					print_tips(size, 0x0c, "��λ���ѱ��Ų����");
					break;
				case 2:
					print_tips(size, 0x0c, "���Ȱ�[��]ȡ�����");
					break;
				}
				break;
			case 82:  //R
			case 114: //r
				clear_tips(size);
				return 2;
			case 69:  //E
			case 101: //e
			case 27:  //ESC
				return 1;
			}
		}
	}
}

void print_plrcr(int x, int y, short map[COL_MAX][COL_MAX], short display[COL_MAX][COL_MAX], int plr)
{
	char num[17] = "����������������";
	setrd(4 + y * 2, 2 + x);
	if (plr == 1) //�����û�����
	{
		switch (display[x][y])
		{
		case 0:
			setcl(PLR_COLOR);
			printf("��");
			break;
		case 1:
			if (map[x][y] == 0)
			{
				setcl(PLR_COLOR);
				printf(SPACE);
			}
			else
			{
				setcl(PLR_COLOR + map[x][y]);
				printf("%c%c", num[2 * (map[x][y] - 1)], num[2 * (map[x][y] - 1) + 1]);
			}
			break;
		case 2:
			setcl(PLR_COLOR);
			printf(SIGN_MINE);
			break;
		}
	}
	else
	{
		switch (display[x][y])
		{
		case 0:
			setcl(UNKNOW_COLOR);
			printf("��");
			break;
		case 1:
			print_ele(map, x, y);
			break;
		case 2:
			setcl(UNKNOW_COLOR);
			printf(SIGN_MINE);
			break;
		}
	}
	setrd(4 + y * 2, 2 + x);
}

void initial_area(short map[COL_MAX][COL_MAX], int size, short display[COL_MAX][COL_MAX])
{
	int i, j, r, zero = 0;
	short arr[400][2];
	srand((unsigned)time(NULL));
	for (i = 0; i < size; i++) //�ж��Ƿ��п�λ
	{
		for (j = 0; j < size; j++)
		{
			if (map[i][j] == 0)
			{
				arr[zero][0] = i;
				arr[zero][1] = j;
				zero++;
			}
		}
	}
	if (zero == 0)
		return;
	r = rand() % zero;
	i = arr[r][0];
	j = arr[r][1];
	mine_clearance(i, j, map, display, size);
}

void mine_clearance(int x, int y, short map[COL_MAX][COL_MAX], short display[COL_MAX][COL_MAX], int size)
{
	if (map[x][y] == 9)
		return;
	if (display[x][y] == 0)
		display[x][y] = 1;
	if (map[x][y] > 0)
		return;
	print_ele(map, x, y);
	if (x != 0 && display[x - 1][y] == 0) //��������
	{
		if (map[x - 1][y] == 0)
			mine_clearance(x - 1, y, map, display, size);
		else if (map[x - 1][y] < 9)
		{
			display[x - 1][y] = 1;
			print_ele(map, x - 1, y);
		}
	}
	if (x != size - 1 && display[x + 1][y] == 0) //��������
	{
		if (map[x + 1][y] == 0)
			mine_clearance(x + 1, y, map, display, size);
		else if (map[x + 1][y] < 9)
		{
			display[x + 1][y] = 1;
			print_ele(map, x + 1, y);
		}
	}
	if (y != 0 && display[x][y - 1] == 0) //��������
	{
		if (map[x][y - 1] == 0)
			mine_clearance(x, y - 1, map, display, size);
		else if (map[x][y - 1] < 9)
		{
			display[x][y - 1] = 1;
			print_ele(map, x, y - 1);
		}
	}
	if (y != size - 1 && display[x][y + 1] == 0) //��������
	{
		if (map[x][y + 1] == 0)
			mine_clearance(x, y + 1, map, display, size);
		else if (map[x][y + 1] < 9)
		{
			display[x][y + 1] = 1;
			print_ele(map, x, y + 1);
		}
	}
}

int state(short map[COL_MAX][COL_MAX], short display[COL_MAX][COL_MAX], int size)
{
	int s1 = 1, s2 = 1, i, j;
	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			if (map[i][j] == 9)
				if (display[i][j] != 2)
					return 0; //λ�������׵�δ��ע
				else //display[i][j] == 2
					continue; //λ���������ұ�ע
			else // map[i][j] != 9
				if (display[i][j] == 2)
					return 0; //λ�������׵���ע
	return 1; //����ȫ����ע��ȷ����Ϸ����
}