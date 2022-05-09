#include "game.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//������Ļ��ӡ����
void setrd(int x, int y)
{
	COORD rd;
	rd.X = x;
	rd.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), rd);
}

//���˵�
bool menu()
{
	SetConsoleTextAttribute(hConsole, 0x0e);
	setrd(10, 3);
	cout << "=== ������ ===" << endl << endl;
	setrd(12, 5);
	cout << "1. ��ʼ" << endl;
	setrd(12, 7);
	cout << "2. �˳�" << endl;
	setrd(0, 0);
	while (1)
	{
		if (GetAsyncKeyState('1'))
		{
			SetConsoleTextAttribute(hConsole, 0x0b);
			setrd(12, 5);
			cout << "1. ��ʼ" << endl;
			Sleep(MENU_SLEEP);
			system("cls");
			return false;
		}
		else if (GetAsyncKeyState('2'))
		{
			SetConsoleTextAttribute(hConsole, 0x0b);
			setrd(12, 7);
			cout << "2. �˳�" << endl;
			Sleep(MENU_SLEEP);
			system("cls");
			SetConsoleTextAttribute(hConsole, 0x0f);
			return true;
		}
	}
}

//ģʽѡ��˵�  0-�����  1-������
int model_select()
{
	SetConsoleTextAttribute(hConsole, 0x0e);
	setrd(12, 3);
	cout << "ѡ���Ⱥ���";
	setrd(12, 5);
	cout << "1. ������";
	setrd(12, 7);
	cout << "2. ��������";
	setrd(0, 0);
	while (1)
	{
		if (GetAsyncKeyState('1'))
		{
			SetConsoleTextAttribute(hConsole, 0x0b);
			setrd(12, 5);
			cout << "1. ������" << endl;
			SetConsoleTextAttribute(hConsole, 0x0e);
			Sleep(MENU_SLEEP);
			system("cls");
			return 0;
		}
		else if (GetAsyncKeyState('2'))
		{
			SetConsoleTextAttribute(hConsole, 0x0b);
			setrd(12, 7);
			cout << "2. ��������" << endl;
			SetConsoleTextAttribute(hConsole, 0x0e);
			Sleep(MENU_SLEEP);
			system("cls");
			return 1;
		}
	}
}

//��ʼ������
void resetMap(char arr[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			arr[i][j] = P0;
}

//��ӡ����
void printMap(char map[3][3])
{
	SetConsoleTextAttribute(hConsole, C0);
	cout << endl;
	cout << "       1   2   3   " << endl;
	cout << "      --- --- ---  " << endl;
	cout << "   A |   |   |   | " << endl;
	cout << "      --- --- ---  " << endl;
	cout << "   B |   |   |   | " << endl;
	cout << "      --- --- ---  " << endl;
	cout << "   C |   |   |   | " << endl;
	cout << "      --- --- ---  " << endl;

}

//��ӡ����
void printPiece(char map[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			switch (map[i][j]) //�������ϴ�ӡ����
			{
			case P0:
				setrd(7 + j * 4, 3 + i * 2);
				cout << P0; 
				break;
			case P1:
				SetConsoleTextAttribute(hConsole, C1);
				setrd(7 + j * 4, 3 + i * 2);
				cout << P1;
				break;
			case P2:
				SetConsoleTextAttribute(hConsole, C2);
				setrd(7 + j * 4, 3 + i * 2);
				cout << P2;
				break;
			case P3:
				SetConsoleTextAttribute(hConsole, C3);
				setrd(7 + j * 4, 3 + i * 2);
				cout << P3;
				break;
			default:
				break;
			}
		}
}

//�������
void player_chess(char map[3][3])
{
	int i, s_x = N, s_y = N;
	setrd(3, 10);
	SetConsoleTextAttribute(hConsole, 0x08);
	cout << "�������б���б�";
	while (1) //������������
	{
		if (GetAsyncKeyState('A')) //����A
		{
			if (s_y == A) continue;
			setrd(0, 3);
			SetConsoleTextAttribute(hConsole, 0x06);
			cout << "-> A";
			SetConsoleTextAttribute(hConsole, C0);
			setrd(0, 5);
			cout << "   B";
			setrd(0, 7);
			cout << "   C";
			if (s_x == N)
			{
				for (i = 0; i < 3; i++)
				{
					//����1�пհ׻�ΪP3
					if (map[0][i] == P0) map[0][i] = P3;
					//��������P3��Ϊ�հ�
					if (map[1][i] == P3) map[1][i] = P0;
					if (map[2][i] == P3) map[2][i] = P0;
				}
			}
			else
			{
				//����1�е�s_x�пհ׻�ΪP3
				if (map[0][s_x] == P0) map[0][s_x] = P3;
				//�������е�s_x��P3��Ϊ�հ�
				if (map[1][s_x] == P3) map[1][s_x] = P0;
				if (map[2][s_x] == P3) map[2][s_x] = P0;
			}
			printPiece(map);
			s_y = A;
			setrd(0, 0);
			goto tips;
		}
		else if (GetAsyncKeyState('B')) //����B
		{
			if (s_y == B) continue;
			setrd(0, 5);
			SetConsoleTextAttribute(hConsole, 0x06);
			cout << "-> B";
			SetConsoleTextAttribute(hConsole, C0);
			setrd(0, 3);
			cout << "   A";
			setrd(0, 7);
			cout << "   C";
			if (s_x == N)
			{
				for (i = 0; i < 3; i++)
				{
					//����2�пհ׻�ΪP3
					if (map[1][i] == P0) map[1][i] = P3;
					//��������P3��Ϊ�հ�
					if (map[0][i] == P3) map[0][i] = P0;
					if (map[2][i] == P3) map[2][i] = P0;
				}
			}
			else
			{
				//����2�е�s_x�пհ׻�ΪP3
				if (map[1][s_x] == P0) map[1][s_x] = P3;
				//�������е�s_x��P3��Ϊ�հ�
				if (map[0][s_x] == P3) map[0][s_x] = P0;
				if (map[2][s_x] == P3) map[2][s_x] = P0;
			}
			printPiece(map);
			s_y = B;
			setrd(0, 0);
			goto tips;
		}
		else if (GetAsyncKeyState('C')) //����C
		{
			if (s_y == C) continue;
			setrd(0, 7);
			SetConsoleTextAttribute(hConsole, 0x06);
			cout << "-> C";
			SetConsoleTextAttribute(hConsole, C0);
			setrd(0, 3);
			cout << "   A";
			setrd(0, 5);
			cout << "   B";
			if (s_x == N)
			{
				for (i = 0; i < 3; i++)
				{
					//����3�пհ׻�ΪP3
					if (map[2][i] == P0) map[2][i] = P3;
					//��������P3��Ϊ�հ�
					if (map[1][i] == P3) map[1][i] = P0;
					if (map[0][i] == P3) map[0][i] = P0;
				}
			}
			else
			{
				//����3�е�s_x�пհ׻�ΪP3
				if (map[2][s_x] == P0) map[2][s_x] = P3;
				//�������е�s_x��P3��Ϊ�հ�
				if (map[1][s_x] == P3) map[1][s_x] = P0;
				if (map[0][s_x] == P3) map[0][s_x] = P0;
			}
			printPiece(map);
			s_y = C;
			setrd(0, 0);
			goto tips;
		}
		else if (GetAsyncKeyState('1')) //����1
		{
			if (s_x == 0) continue;
			setrd(7, 1);
			SetConsoleTextAttribute(hConsole, 0x06);
			cout << "1";
			SetConsoleTextAttribute(hConsole, C0);
			setrd(11, 1);
			cout << "2";
			setrd(15, 1);
			cout << "3";
			if (s_y == N)
			{
				for (i = 0; i < 3; i++)
				{
					//����1�пհ׻�ΪP3
					if (map[i][0] == P0) map[i][0] = P3;
					//��������P3��Ϊ�հ�
					if (map[i][1] == P3) map[i][1] = P0;
					if (map[i][2] == P3) map[i][2] = P0;
				}
			}
			else
			{
				//����1�е�s_y�пհ׻�ΪP3
				if (map[s_y][0] == P0) map[s_y][0] = P3;
				//�������е�s_y��P3��Ϊ�հ�
				if (map[s_y][1] == P3) map[s_y][1] = P0;
				if (map[s_y][2] == P3) map[s_y][2] = P0;
			}
			printPiece(map);
			s_x = 0;
			setrd(0, 0);
			goto tips;
		}
		else if (GetAsyncKeyState('2')) //����2
		{
			if (s_x == 1) continue;
			setrd(11, 1);
			SetConsoleTextAttribute(hConsole, 0x06);
			cout << "2";
			SetConsoleTextAttribute(hConsole, C0);
			setrd(7, 1);
			cout << "1";
			setrd(15, 1);
			cout << "3";
			if (s_y == N)
			{
				for (i = 0; i < 3; i++)
				{
					//����2�пհ׻�ΪP3
					if (map[i][1] == P0) map[i][1] = P3;
					//��������P3��Ϊ�հ�
					if (map[i][0] == P3) map[i][0] = P0;
					if (map[i][2] == P3) map[i][2] = P0;
				}
			}
			else
			{
				//����2�е�s_y�пհ׻�ΪP3
				if (map[s_y][1] == P0) map[s_y][1] = P3;
				//�������е�s_y��P3��Ϊ�հ�
				if (map[s_y][0] == P3) map[s_y][0] = P0;
				if (map[s_y][2] == P3) map[s_y][2] = P0;
			}
			printPiece(map);
			s_x = 1;
			setrd(0, 0);
			goto tips;
		}
		else if (GetAsyncKeyState('3')) //����3
		{
			if (s_x == 2) continue;
			setrd(15, 1);
			SetConsoleTextAttribute(hConsole, 0x06);
			cout << "3";
			SetConsoleTextAttribute(hConsole, C0);
			setrd(7, 1);
			cout << "1";
			setrd(11, 1);
			cout << "2";
			if (s_y == N)
			{
				for (i = 0; i < 3; i++)
				{
					//����3�пհ׻�ΪP3
					if (map[i][2] == P0) map[i][2] = P3;
					//��������P3��Ϊ�հ�
					if (map[i][0] == P3) map[i][0] = P0;
					if (map[i][1] == P3) map[i][1] = P0;
				}
			}
			else
			{
				//����3�е�s_y�пհ׻�ΪP3
				if (map[s_y][2] == P0) map[s_y][2] = P3;
				//�������е�s_y��P3��Ϊ�հ�
				if (map[s_y][0] == P3) map[s_y][0] = P0;
				if (map[s_y][1] == P3) map[s_y][1] = P0;
			}
			printPiece(map);
			s_x = 2;
			setrd(0, 0);
			goto tips;
		}
		else if (GetAsyncKeyState(VK_RETURN)) //�س�
		{
			if (s_y == N)
			{
				setrd(3, 10);
				SetConsoleTextAttribute(hConsole, 0x0c);
				cout << "�������б�(A,B,C)  ";
				setrd(0, 0);
				continue;
			}
			if (s_x == N)
			{
				setrd(3, 10);
				SetConsoleTextAttribute(hConsole, 0x0c);
				cout << "�������б�(1,2,3)  ";
				setrd(0, 0);
				continue;
			}
			if (map[s_y][s_x] != P3)
			{
				setrd(3, 10);
				SetConsoleTextAttribute(hConsole, 0x0c);
				cout << "��λ���Ѵ�����������";
				setrd(0, 0);
				continue;
			}
			break;
		}
		if (false)
		{
		tips:
			//δѡ���б�
			if (s_y == N)
			{
				setrd(3, 10);
				SetConsoleTextAttribute(hConsole, 0x08);
				cout << "�������б�(A,B,C)  ";
				setrd(0, 0);
				continue;
			}
			//δѡ���б�
			if (s_x == N)
			{
				setrd(3, 10);
				SetConsoleTextAttribute(hConsole, 0x08);
				cout << "�������б�(1,2,3)  ";
				setrd(0, 0);
				continue;
			}
			//ѡ�񴦴�����������
			if (map[s_y][s_x] != P3)
			{
				setrd(3, 10);
				SetConsoleTextAttribute(hConsole, 0x08);
				cout << "��λ���Ѵ�����������";
				setrd(0, 0);
				continue;
			}
			//��������
			setrd(3, 10);
			SetConsoleTextAttribute(hConsole, 0x08);
			cout << "���»س�ȷ������        ";
			setrd(0, 0);
		}
	} //�����������
	map[s_y][s_x] = P1;
	printPiece(map);
	Sleep(100);
	SetConsoleTextAttribute(hConsole, C0);
	switch (s_y)
	{
	case 0:
		setrd(0, 3);
		cout << "   A";
		break;
	case 1:
		setrd(0, 5);
		cout << "   B";
		break;
	case 2:
		setrd(0, 7);
		cout << "   C";
		break;
	default:
		return;
	}
	setrd(7, 1);
	cout << "1   2   3";
}

//��Ϸ״̬�ж�  0-���� 1-���ʤ 2-����ʤ 3-ƽ��
int game_state(char map[3][3])
{
	int a, i, j;
	for (a = 0; a < 3; a++)
	{
		if (map[a][0] != P0 && map[a][0] == map[a][1] && map[a][1] == map[a][2]) //��a��������ͬ
			if (map[a][0] == P1) //��a�е�������P1
				return plr_win;
			else				 //��a�е�������P2
				return cpt_win;
		if (map[0][a] != P0 && map[0][a] == map[1][a] && map[1][a] == map[2][a]) //��a��������ͬ
			if (map[0][a] == P1) //��a�е�������P1
				return plr_win;
			else				 //��a�е�������P2
				return cpt_win;
	}
	//�ж����Խ�������
	if (map[0][0] != P0 && map[0][0] == map[1][1] && map[1][1] == map[2][2]) //���Խ���������ͬ
		if (map[0][0] == P1) //���Խ��ߵ�������P1
			return plr_win;
		else				 //���Խ��ߵ�������P2
			return cpt_win;
	//�жϸ��Խ�������
	if (map[0][2] != P0 && map[0][2] == map[1][1] && map[1][1] == map[2][0]) //���Խ���������ͬ
		if (map[0][2] == P1) //���Խ��ߵ�������P1
			return plr_win;
		else				 //���Խ��ߵ�������P2
			return cpt_win;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (map[i][j] == P0)
				return cont;
	return draw;
}

//��������
void computer_chess(char map[3][3])
{
	int i, j, space_num = 0;
	char* space[8];
	setrd(3, 10);
	SetConsoleTextAttribute(hConsole, 0x08);
	cout << "�ȴ���������\t\t\t";
	setrd(0, 0);
	//�м�û����ʱ�����м�
	if (map[1][1] == P0)
	{
		map[1][1] = P2;
		return;
	}
	//�������������Լ���������ʱ
	for (i = 0; i < 3; i++)
	{
		//�ж�3�����Ƿ�����ͬ���Լ�������
		if (map[i][0] == P2 && map[i][2] == P0 && map[i][0] == map[i][1]) //i,0 = i,1
		{
			map[i][2] = P2;
			return;
		}
		if (map[i][1] == P2 && map[i][0] == P0 && map[i][1] == map[i][2]) //i,1 = i,2
		{
			map[i][0] = P2;
			return;
		}
		if (map[i][0] == P2 && map[i][1] == P0 && map[i][0] == map[i][2]) //i,0 = i,2
		{
			map[i][1] = P2;
			return;
		}
		//�ж�3�����Ƿ�����ͬ���Լ�������
		if (map[0][i] == P2 && map[2][i] == P0 && map[0][i] == map[1][i]) //0,i = 1,i
		{
			map[2][i] = P2;
			return;
		}
		if (map[1][i] == P2 && map[0][i] == P0 && map[1][i] == map[2][i]) //1,i = 2,i
		{
			map[0][i] = P2;
			return;
		}
		if (map[0][i] == P2 && map[1][i] == P0 && map[0][i] == map[2][i]) //0,i = 2,i
		{
			map[1][i] = P2;
			return;
		}
	}
	//�ж����Խ������Ƿ�����ͬ���Լ���������
	if (map[0][0] == P2 && map[2][2] == P0 && map[0][0] == map[1][1]) //0,0 = 1,1 -> 2,2
	{
		map[2][2] = P2;
		return;
	}
	if (map[1][1] == P2 && map[0][0] == P0 && map[1][1] == map[2][2]) //1,1 = 2,2 -> 0,0
	{
		map[0][0] = P2;
		return;
	}
	//�жϸ��Խ������Ƿ�����ͬ���Լ���������
	if (map[0][2] == P2 && map[2][0] == P0 && map[0][2] == map[1][1]) //0,2 = 1,1 -> 2,0
	{
		map[2][0] = P2;
		return;
	}
	if (map[1][1] == P2 && map[0][2] == P0 && map[1][1] == map[2][0]) //1,1 = 2,0 -> 0,2
	{
		map[0][2] = P2;
		return;
	}

	//����������û���Լ��������ӣ�������ҵ�������ʱ
	for (i = 0; i < 3; i++)
	{
		//�ж�3�����Ƿ�����ͬ�ĶԷ�������
		if (map[i][0] == P1 && map[i][2] == P0 && map[i][0] == map[i][1]) //i,0 = i,1
		{
			map[i][2] = P2;
			return;
		}
		if (map[i][1] == P1 && map[i][0] == P0 && map[i][1] == map[i][2]) //i,1 = i,2
		{
			map[i][0] = P2;
			return;
		}
		if (map[i][0] == P1 && map[i][1] == P0 && map[i][0] == map[i][2]) //i,0 = i,2
		{
			map[i][1] = P2;
			return;
		}
		//�ж�3�����Ƿ�����ͬ�ĶԷ�������
		if (map[0][i] == P1 && map[2][i] == P0 && map[0][i] == map[1][i]) //0,i = 1,i
		{
			map[2][i] = P2;
			return;
		}
		if (map[1][i] == P1 && map[0][i] == P0 && map[1][i] == map[2][i]) //1,i = 2,i
		{
			map[0][i] = P2;
			return;
		}
		if (map[0][i] == P1 && map[1][i] == P0 && map[0][i] == map[2][i]) //0,i = 2,i
		{
			map[1][i] = P2;
			return;
		}
	}
	//�ж����Խ������Ƿ�����ͬ����ҵ�������
	if (map[0][0] == P1 && map[2][2] == P0 && map[0][0] == map[1][1]) //0,0 = 1,1 -> 2,2
	{
		map[2][2] = P2;
		return;
	}
	if (map[1][1] == P1 && map[0][0] == P0 && map[1][1] == map[2][2]) //1,1 = 2,2 -> 0,0
	{
		map[0][0] = P2;
		return;
	}
	//�жϸ��Խ������Ƿ�����ͬ����ҵ�������
	if (map[0][2] == P1 && map[2][0] == P0 && map[0][2] == map[1][1]) //0,2 = 1,1 -> 2,0
	{
		map[2][0] = P2;
		return;
	}
	if (map[1][1] == P1 && map[0][2] == P0 && map[1][1] == map[2][0]) //1,1 = 2,0 -> 0,2
	{
		map[0][2] = P2;
		return;
	}

	//����������û���Լ���������Ҳû����ҵ�������ʱ
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (map[i][j] == P0)
			{
				space[space_num] = &map[i][j];
				space_num++;
			}
	if (space_num == 0)
		return;
	*space[rand() % space_num] = P2;
	SetConsoleTextAttribute(hConsole, C0);
}



/*
       1   2   3
      --- --- ---
   A | O |   |   |
      --- --- ---
   B |   | X |   |
      --- --- ---
   C |   |   |   |
      --- --- ---
*/